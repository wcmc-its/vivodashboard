<?php
/**
 * @file
 * Contains the SearchApiDenormalizedEntityDataSourceController class.
 */

/**
 * Data source for all entities known to the Entity API.
 */
class SearchApiDenormalizedEntityDataSourceController extends SearchApiEntityDataSourceController {

  /**
   * The table used for tracking items. Set to NULL on subclasses to disable
   * the default tracking for an item type, or change the property to use a
   * different table for tracking.
   *
   * @var string
   */
  protected $table = 'search_api_denormalized_entity';

  /**
   * Return information on the ID field for this controller's type.
   *
   * @return array
   *   An associative array containing the following keys:
   *   - key: The property key for the ID field, as used in the item wrapper.
   *   - type: The type of the ID field. Has to be one of the types from
   *     search_api_field_types(). List types ("list<*>") are not allowed.
   */
  public function getIdFieldInfo() {
    return array(
      'key' => 'search_api_denormalized_entity_id',
      'type' => 'integer',
    );
  }

  /**
   * Get information on how many items have been indexed for a certain index.
   *
   * @param SearchApiIndex $index
   *   The index whose index status should be returned.
   *
   * @return array
   *   An associative array containing two keys (in this order):
   *   - indexed: The number of items already indexed in their latest version.
   *   - total: The total number of items that have to be indexed for this
   *     index.
   */
  public function getIndexStatus(SearchApiIndex $index) {
    $this->checkIndex($index);
    $indexed = db_select($this->table, 'i')
      ->condition($this->indexIdColumn, $index->id)
      ->condition($this->changedColumn, 0)
      ->countQuery()
      ->execute()
      ->fetchField();
    // Don't count permutations marked for deletion.
    $total = db_select($this->table, 'i')
      ->condition($this->indexIdColumn, $index->id)
      ->condition($this->changedColumn, 0, '>=')
      ->countQuery()
      ->execute()
      ->fetchField();
    return array('indexed' => $indexed, 'total' => $total);
  }

  /**
   * Load items of the type of this data source controller.
   *
   * @param array $ids
   *   The IDs of the items to load.
   *
   * @return array
   *   The loaded items, keyed by ID.
   */
  public function loadItems(array $ids) {

    // Fetch mapped entity ids.
    $entity_ids = db_select($this->table)
      ->fields($this->table, array($this->itemIdColumn, 'etid'))
      ->condition($this->itemIdColumn, $ids)
      ->condition('entity_type', $this->getEntityType())
      ->execute()
      ->fetchAll(PDO::FETCH_KEY_PAIR);
    $entities = entity_load($this->getEntityType(), $entity_ids);

    // Assign entities to item ids.
    $items = array();
    foreach ($entity_ids as $item_id => $entity_id) {
      // Ensure inconsistencies don't throw an error.
      if (isset($entities[$entity_id])) {
        $items[$item_id] = $entities[$entity_id];
      }
    }

    // If some items couldn't be loaded, remove them from tracking.
    if (count($items) != count($ids)) {
      $ids = array_flip($ids);
      $unknown = array_keys(array_diff_key($ids, $items));
      if ($unknown) {
        search_api_track_item_delete($this->type, $unknown);
      }
    }

    return $items;
  }

  /**
   * Ensures the consistency of the table.
   *
   * It can happen that an entity deletion happens unrecognized which then
   * creates inconsistencies in the tracking table. In the worst case  this
   * can lead to a WSOD e.g. if a non existing entity is loaded.
   */
  public function cleanTable() {
    $count = 0;
    // Fetch all available entity types in the table.
    $entity_types = db_select($this->table)
      ->fields($this->table, array('entity_type'))
      ->groupBy('entity_type')
      ->execute()
      ->fetchCol();
    // Now iterate over all entity types and check table for orphaned ids.
    if (!empty($entity_types)) {
      foreach ($entity_types as $entity_type) {
        $entity_info = entity_get_info($entity_type);
        $entity_type_primary_key = $entity_info['entity keys']['id'];
        $query = db_select($this->table)
          ->fields($this->table, array($this->itemIdColumn))
          ->condition('entity_type', $entity_type);
        $query->addJoin('LEFT', $entity_info['base table'], NULL, $entity_type_primary_key . ' = ' . $this->table . '.etid');
        $query->isNull($entity_type_primary_key);
        $orphaned_ids = $query->execute()
            ->fetchCol();
        // Get rid of orphaned ids.
        if (!empty($orphaned_ids)) {
          $count += count($orphaned_ids);
          search_api_track_item_delete($this->type, $orphaned_ids);
        }
      }
    }
    return $count;
  }

  /**
   * Initialize tracking of the index status of items for the given indexes.
   *
   * All currently known items of this data source's type should be inserted
   * into the tracking table for the given indexes, with status "changed". If
   * items were already present, these should also be set to "changed" and not
   * be inserted again.
   *
   * @param array $indexes
   *   The SearchApiIndex objects for which item tracking should be initialized.
   *
   * @throws SearchApiDataSourceException
   *   If any of the indexes doesn't use the same item type as this controller.
   */
  public function startTracking(array $indexes) {
    if (!$this->table) {
      return;
    }
    // We first clear the tracking table for all indexes, so we can just insert
    // all items again without any key conflicts.
    $this->stopTracking($indexes);

    $entity_type = $this->getEntityType();

    // Just insert the entities without the permutations and create the batch
    // to expand every entity.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', $entity_type)->execute();

    if (!empty($result[$entity_type])) {
      $insert = db_insert($this->table)
        ->fields(array(
          'index_id',
          $this->itemIdColumn,
          'entity_type',
          'etid',
          'changed',
          'needs_processing',
        ));
      $num_records = 0;
      foreach ($result[$entity_type] as $entity_id => $data) {
        foreach ($indexes as $index) {
          $denormalization_fields = DenormalizedEntityIndexHijack::getDenormalizeProcessorFields($index);
          $insert->values(array(
            'index_id' => $index->id,
            $this->itemIdColumn => $entity_type . '-' . $entity_id . str_repeat('-0', count($denormalization_fields)),
            'entity_type' => $entity_type,
            'etid' => $entity_id,
            'changed' => REQUEST_TIME,
            'needs_processing' => 1,
          ));
          // Execute in batches to avoid the memory overhead of all of those
          // records in the query object.
          if (++$num_records == 20) {
            $insert->execute();
            $num_records = 0;
          }
        }
      }
      $insert->execute();
    }

    // Create a new queue to generate permutations.
    $queue = DrupalQueue::get('search_api_grouping_generate_permuatations');
    $queue->deleteQueue();
    $queue->createQueue('search_api_grouping_generate_permuatations');
    // Is there a better way then re-queueing all indexes??
    db_update($this->table)
      ->fields(array('queued' => 0))
      ->condition('queued', 0, '>')
      ->execute();
    // Reuse cron function to re-create the queue.
    search_api_grouping_cron();
  }

  /**
   * Start tracking the index status for the given items on the given indexes.
   *
   * @param array $item_ids
   *   The IDs of new items to track.
   * @param array $indexes
   *   The indexes for which items should be tracked.
   *
   * @throws SearchApiDataSourceException
   *   If any of the indexes doesn't use the same item type as this controller.
   */
  public function trackItemInsert(array $item_ids, array $indexes) {
    $this->trackItemChange($item_ids, $indexes);
  }

  /**
   * Set the tracking status of the given items to "changed"/"dirty".
   *
   * Unless $dequeue is set to TRUE, this operation is ignored for items whose
   * status is not "indexed".
   *
   * @param array $item_ids
   *   Either an array with the IDs (entity id or denormalized item id) of the
   *   changed items. Or FALSE to mark all items as changed for the given
   *   indexes.
   * @param array $indexes
   *   The indexes for which the change should be tracked.
   * @param bool $dequeue
   *   If set to TRUE, also change the status of queued items.
   *
   * @throws SearchApiDataSourceException
   *   If any of the indexes doesn't use the same item type as this controller.
   */
  public function trackItemChange($item_ids, array $indexes, $dequeue = FALSE) {
    // Marking all items as changed deserves a special handling.
    if ($item_ids === FALSE) {
      return $this->startTracking($indexes);
    }

    $entity_type = $this->getEntityType();
    // Fetch the entity id's to deal with.
    if (!empty($item_ids)) {
      // Ensures the given $item_ids are entity ids.
      foreach ($item_ids as $item_id) {
        if (stristr($item_id, SEARCH_API_GROUPING_ENTITY_FIELD_SEPERATOR) !== FALSE) {
          $parts = explode(SEARCH_API_GROUPING_ENTITY_FIELD_SEPERATOR, $item_id);
          $entity_ids[$parts[1]] = $parts[1];
        }
        else {
          // As mixed array are silly - if the id isn't a denormalized one skip
          // the whole processing.
          $entity_ids = drupal_map_assoc($item_ids);
          break;
        }
      }
      // Load entities to deal with.
      $entities = entity_load($entity_type, $entity_ids);
    }
    else {
      // Load all entities.
      $entities = entity_load($entity_type, FALSE);
      $entity_ids = drupal_map_assoc(array_keys($entities));
    }

    foreach ($indexes as $index) {
      $this->checkIndex($index);

      // Creates the permutations for this entity an registers each permutation
      // as item in the table.
      $this->createPermutationItems($index, $entity_type, $entities);

      // Change only if all items or defined set of items can be adjusted.
      // This checks prevents db errors in cases where a specific set was
      // requested but the set wasn't available.
      if (empty($item_ids) || !empty($entity_ids)) {
        // @TODO Check if db_merge() can be used.
        // Update existing entries.
        $update = db_update($this->table)
          ->fields(array(
            $this->changedColumn => REQUEST_TIME,
          ))
          ->condition($this->indexIdColumn, $index->id)
          ->condition('entity_type', $entity_type)
          ->condition($this->changedColumn, 0, $dequeue ? '<=' : '=');
        if (!empty($item_ids)) {
          $update->condition('etid', $entity_ids, 'IN');
        }
        $affected_rows = $update->execute();
      }
    }
  }

  /**
   * Generates the permutation items for the given index.
   *
   * This part split's the given entity_ids into the related denormalized
   * ids and adds them to the tracking table. It also marks deprecated
   * denormalized ids as obsolete in the tracking table. These entries will
   * be removed from index during the next indexing.
   *
   * @param SearchApiIndex $index
   *   The index to deal with.
   * @param string $entity_type
   *   The entity type to handle.
   * @param array $entities
   *   Array with the entities to process. Keyed by the entity id.
   */
  public function createPermutationItems(SearchApiIndex $index, $entity_type, array $entities) {
    $denormalization_fields = DenormalizedEntityIndexHijack::getDenormalizeProcessorFields($index);
    $denomalized_item_ids = array();
    $item_ids_entity_id_mapping = array();

    foreach ($entities as $entity_id => $entity) {
      $ids = search_api_grouping_generate_pseudo_keys($entity, $entity_type, $denormalization_fields);
      // Avoid errors if there aren't any id's ready yet.
      if (!empty($ids)) {
        $item_ids_entity_id_mapping += array_combine($ids, array_fill(0, count($ids), $entity_id));
        $denomalized_item_ids = array_merge($denomalized_item_ids, $ids);
      }
    }

    if (!empty($denomalized_item_ids)) {
      // Mark obsolete permutations.
      $obsolete = db_update($this->table)
        ->fields(array($this->changedColumn => -2))
        ->condition($this->indexIdColumn, $index->id)
        ->condition($this->itemIdColumn, $denomalized_item_ids, 'NOT IN')
        ->condition('entity_type', $entity_type)
        ->condition('etid', array_keys($entities), 'IN')
        ->execute();

      // Ensure new permutations are inserted.
      $existing_keys = db_select($this->table)
        ->fields($this->table, array($this->itemIdColumn))
        ->condition($this->indexIdColumn, $index->id)
        ->condition('entity_type', $entity_type)
        ->condition($this->itemIdColumn, $denomalized_item_ids, 'IN')
        ->execute()
        ->fetchAll(PDO::FETCH_COLUMN, 0);
      $missing_keys = $denomalized_item_ids;
      if ($existing_keys) {
        $missing_keys = array_diff($denomalized_item_ids, $existing_keys);
      }
      if (!empty($missing_keys)) {
        $insert = db_insert($this->table)
          ->fields(array(
          $this->indexIdColumn,
          $this->itemIdColumn,
          'entity_type',
          'etid',
          $this->changedColumn,
        ));
        $num_records = 0;
        foreach ($missing_keys as $missing_key) {
          $insert->values(array(
            $index->id,
            $missing_key,
            $entity_type,
            $item_ids_entity_id_mapping[$missing_key],
            REQUEST_TIME,
          ));
          // Execute in batches to avoid the memory overhead of all of those
          // records in the query object.
          if (++$num_records == 20) {
            $insert->execute();
            $num_records = 0;
          }
        }
        $insert->execute();
      }
    }

    // Mark all processed items as processed.
    db_update('search_api_denormalized_entity')
      ->fields(array(
        'queued' => 0,
        'needs_processing' => 0,
      ))
      ->condition($this->indexIdColumn, $index->id)
      ->condition('etid', array_keys($entities))
      ->condition('entity_type', $entity_type)
      ->condition(db_or()
        ->condition('queued', 0, '>')
        ->condition('needs_processing', 0, '>')
      )
      ->execute();
  }

  /**
   * Get the unique ID of an item.
   *
   * @param object $item
   *   An item of this controller's type.
   *
   * @return string|NULL
   *   Either the unique ID of the item, or NULL if none is available.
   */
  public function getItemId($item) {
    return $item->item_id ? $item->item_id : NULL;
  }

  /**
   * Get a metadata wrapper for the item type of this data source controller.
   *
   * @param mixed $item
   *   Unless NULL, an item of the item type for this controller to be wrapped.
   * @param array $info
   *   Optionally, additional information that should be used for creating the
   *   wrapper. Uses the same format as entity_metadata_wrapper().
   *
   * @return EntityMetadataWrapper
   *   A wrapper for the item type of this data source controller, according to
   *   the info array, and optionally loaded with the given data.
   *
   * @see entity_metadata_wrapper()
   */
  public function getMetadataWrapper($item = NULL, array $info = array()) {
    // If the item isn't the object and a denormalized id is provided extract
    // the entity id to load and wrap the entity.
    if (!is_object($item) && is_scalar($item)) {
      $parts = explode(SEARCH_API_GROUPING_ENTITY_FIELD_SEPERATOR, $item);
      $item = $parts[1];
    }
    return entity_metadata_wrapper($this->entityType, $item, $info);
  }

  /**
   * Get a human-readable label for an item.
   *
   * @param object $item
   *   An item of this controller's type.
   *
   * @return string|NULL
   *   Either a human-readable label for the item, or NULL if none is available.
   */
  public function getItemLabel($item) {
    $label = entity_label($this->getEntityType(), $item);
    return $label ? $label : NULL;
  }

  /**
   * Removes obsolete permutations from the search index.
   *
   * @param array $items
   *   The items prepared for indexing. Has to be adjusted.
   * @param SearchApiIndex $index
   *   The search index to clear obsolete entries from.
   */
  public function removeObsoletePermutationsFromIndex(array &$items, SearchApiIndex $index) {
    $obsolete_items = db_select($this->table)
      ->fields($this->table, array($this->itemIdColumn))
      ->condition($this->indexIdColumn, $index->id)
      ->condition($this->changedColumn, -2)
      ->execute()
      ->fetchAll(PDO::FETCH_COLUMN, 0);
    if ($obsolete_items) {
      $items = array_diff_key($items, array_flip($obsolete_items));
      search_api_track_item_delete($this->type, $obsolete_items);
    }
  }

  /**
   * Queues the generation of the permutations.
   */
  public function queuePermutationGeneration() {
    // Remove queued timestamp after 6 hours assuming the update has failed.
    // So the queue item will created again.
    db_update($this->table)
      ->fields(array('queued' => 0))
      ->condition('queued', REQUEST_TIME - (3600 * 6), '<')
      ->condition('entity_type', $this->getEntityType())
      ->execute();

    // Now fetch all items marked with needs processing grouped by entity.
    $result = db_select($this->table)
      ->fields($this->table, array())
      ->condition('needs_processing', 1)
      ->condition('queued', 0)
      ->condition('entity_type', $this->getEntityType())
      ->groupBy('etid')
      ->execute();

    $queue = DrupalQueue::get('search_api_grouping_generate_permuatations');
    $queue_item = array();
    foreach ($result as $item) {
      $queue_item[$item->etid] = $item;
      // Store a bunch of items per queue item.
      if (count($queue_item) == 15) {
        if ($queue->createItem($queue_item)) {
          // Add timestamp to avoid queueing item more than once.
          db_update($this->table)
            ->fields(array('queued' => REQUEST_TIME))
            ->condition('etid', array_keys($queue_item))
            ->condition('entity_type', $this->getEntityType())
            ->execute();
          $queue_item = array();
        }
      }
    }
    // Store the last collection.
    if (!empty($queue_item)) {
      if ($queue->createItem($queue_item)) {
        // Add timestamp to avoid queueing item more than once.
        db_update($this->table)
          ->fields(array('queued' => REQUEST_TIME))
          ->condition('etid', array_keys($queue_item))
          ->condition('entity_type', $this->getEntityType())
          ->execute();
      }
    }
  }
}

/**
 * Class to hijack the protected method getProcessors().
 *
 * As this class extends SearchApiIndex it can access protected properties and
 * functions.
 */
class DenormalizedEntityIndexHijack extends SearchApiIndex {

  /**
   * Returns the fields to denormalize on.
   *
   * @param SearchApiIndex $index
   *   The index to fetch the configuration from.
   *
   * @return array
   *   The list of fields to use for denormalization.
   */
  public static function getDenormalizeProcessorFields(SearchApiIndex $index) {
    $processors = $index->getProcessors();
    if (!empty($processors['search_api_denormalized_entity_field'])) {
      return $processors['search_api_denormalized_entity_field']->getDenormalizationFields();
    }
    return array();
  }

  /**
   * Returns the permutation limit of a field.
   *
   * @param SearchApiIndex $index
   *   The index to fetch the configuration from.
   * @param string $field
   *   The field to get the limit for.
   *
   * @return int
   *   The number of permutations to generate from this field. 0 means no limit.
   */
  public static function getDenormalizeProcessorFieldLimit(SearchApiIndex $index, $field) {
    $processors = $index->getProcessors();
    if (!empty($processors['search_api_denormalized_entity_field'])) {
      return $processors['search_api_denormalized_entity_field']->getDenormalizationFieldLimit($field);
    }
    return array();
  }

  /**
   * Returns the fields to denormalize on.
   *
   * @param SearchApiIndex $index
   *   The index to fetch the configuration from.
   *
   * @return array
   *   The list of fields to use for denormalization.
   */
  public static function getGroupingProcessorFields(SearchApiIndex $index) {
    $processors = $index->getProcessors();
    if (!empty($processors['search_api_denormalized_entity_grouping'])) {
      return $processors['search_api_denormalized_entity_grouping']->getGroupingFields();
    }
    return array();
  }
}
