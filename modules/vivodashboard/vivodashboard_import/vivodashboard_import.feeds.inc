<?php
/**
 * @file
 * Feeds integration for the vivodashboard_import module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * Adds custom Feeds mappers that run other Feeds importers.
 *
 * These mappers effectively chain Feeds importers together, piping URIs from
 * one importer to the next.
 */
function vivodashboard_import_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {

  // Define importers for reference fields.
  field_info_instances($entity_type, $bundle_name);
  foreach (field_info_instances($entity_type, $bundle_name) as $field_name => $field) {
    $info = field_info_field($field_name);

    // Only supporting taxonomy fields for now.
    if ($info['type'] == 'taxonomy_term_reference') {
      $targets["import:{$entity_type}:{$field_name}"] = array(
        'name' => t("Import terms: $field_name"),
        'callback' => 'vivodashboard_import_mapping_callback',
        'summary_callback' => 'vivodashboard_import_mapping_summary_callback',
        'form_callback' => 'vivodashboard_import_mapping_form_callback',
      );
    }
  }

  // Special mapper to attach authorship URIs to publication nodes.
  // These get handled later in hook_feeds_after_save().
  if ($entity_type == 'node' && $bundle_name == 'publication') {
    $targets['publication_authorships'] = array(
      'name' => t('Authorships'),
      'callback' => 'vivodashboard_import_map_verbatim',
    );
  }

  // Special mapper to import authors while importing authorships.
  if ($entity_type == 'relation' && $bundle_name == 'authorship') {
    $targets["import:relation:authors"] = array(
      'name' => t("Import: Authors"),
      'callback' => 'vivodashboard_import_mapping_callback',
      'summary_callback' => 'vivodashboard_import_mapping_summary_callback',
      'form_callback' => 'vivodashboard_import_mapping_form_callback',
    );
    $targets["authorship:endpoint:0"] = array(
      'name' => t("Authorship: Publication"),
      'callback' => 'vivodashboard_import_authorship_endpoint_callback',
    );
    $targets["authorship:endpoint:1"] = array(
      'name' => t("Authorship: Author"),
      'callback' => 'vivodashboard_import_authorship_endpoint_callback',
    );
  }
}

/**
 * Feeds mapping callback.
 *
 * Populates Relation endpoints.
 *
 * This is used because the built-in endpoint mapping isn't so flexible.
 *
 * @see https://www.drupal.org/node/2354019
 */
function vivodashboard_import_authorship_endpoint_callback($source, $relation, $target, $values) {
  if (empty($values)) {
    return;
  }

  list(,,$endpoint) = explode(':', $target);
  $guids = is_array($values) ? $values : array($values);

  $matches = db_select('feeds_item', 'f')
    ->condition('guid', $guids, 'IN')
    ->condition('entity_type', 'node')
    ->fields('f', array('guid', 'entity_id', 'entity_type'))
    ->execute()
    ->fetchAllAssoc('guid');

  if ($matches) {
    $match = reset($matches);
    $relation->endpoints[LANGUAGE_NONE][$endpoint] = array('entity_type' => $match->entity_type, 'entity_id' => $match->entity_id);
  }
}

/**
 * Feeds mapping callback.
 *
 * Simply attaches values to the entity so they can be used later.
 *
 * @see vivodashboard_import_feeds_after_save().
 */
function vivodashboard_import_map_verbatim($source, $node, $target, $values, $config = array()) {
  $node->{$target} = !is_array($values) ? array($values) : $values;
}

/**
 * Feeds mapping callback.
 *
 * Runs a Feeds importer and maps the resulting items to the target field.
 */
function vivodashboard_import_mapping_callback($original_source, $entity, $target, $values, $config = array()) {
  if (empty($config['importer'])) {
    return;
  }

  $importer_id = $config['importer'];
  $uri_list = is_array($values) ? $values : array($values);
  $uri_list = array_unique(array_filter($uri_list));

  if (empty($uri_list) || !feeds_importer_load($importer_id)) {
    return;
  }

  // We check the age of previously imported items before running the importer.
  // Items that were imported more recently than the cutoff get skipped.
  // This should save a lot of requests.
  $minimum_age = !empty($config['age']) ? $config['age'] : 'last';
  $cutoff = ($minimum_age == 'last') ? $original_source->imported : (time() - ((int) $minimum_age * 60));

  $uris_needing_update = vivodashboard_import_uris_needing_update($uri_list, $importer_id, $cutoff);
  if ($uris_needing_update) {
    vivodashboard_import_run_importer($uris_needing_update, $importer_id);
  }

  // Populate field values on the target entity.
  // NOTE: If $field_name is not an actual field this just gets skipped,
  // which is what we want in cases where we are just creating entities.
  list(, $entity_type, $field_name) = explode(':', $target);

  if ($field_info = field_info_field($field_name)) {
    $is_multivalue_field = ($field_info['cardinality'] == 1) ? FALSE : TRUE;
    $wrapper = entity_metadata_wrapper($entity_type, $entity);

    // @todo - Handle entityreference fields?
    switch ($field_info['type']) {

      case 'taxonomy_term_reference':
        $tids = vivodashboard_import_get_items($uri_list, $importer_id, 'taxonomy_term');
        if ($tids && isset($wrapper->$field_name)) {
          $value = ($is_multivalue_field) ? $tids : reset($tids);
          $wrapper->$field_name->set($value);
        }
        break;
    }
  }
}

/**
 * Helper to find out which items need to be re-imported.
 */
function vivodashboard_import_uris_needing_update($uri_list, $importer_id, $cutoff_timestamp) {
  foreach ($uri_list as $k => $uri) {
    $last_imported_timestamp = vivodashboard_import_item_timestamp($uri, $importer_id);
    // Newer items can be skipped.
    if ($last_imported_timestamp > $cutoff_timestamp) {
      unset($uri_list[$k]);
    }
  }
  return $uri_list;
}

/**
 * Helper to get the timestamp for an imported Feeds item.
 */
function vivodashboard_import_item_timestamp($uri, $importer_id) {
  $timestamp = db_select('feeds_item')
      ->fields('feeds_item', array('imported'))
      ->condition('id', $importer_id)
      ->condition('url', $uri)
      ->execute()
      ->fetchField();
  return ($timestamp) ? $timestamp : 0;
}

/**
 * Helper to manually run a Feeds importer with a list of URIs.
 */
function vivodashboard_import_run_importer($uri_list, $importer_id, $suppress_messages = TRUE) {
  // Load the Feeds source this way to avoid static instances.
  $source = VivodashboardImportSource::instance($importer_id);

  if (empty($source->importer)) {
    drupal_set_message('The Feeds importer could not be loaded.');
    return;
  }

  $fetcher_result = new LdImportFetcherResult($uri_list);
  $parser_result = $source->importer->parser->parse($source, $fetcher_result);
  $source->importer->processor->process($source, $parser_result);

  // Clear any messages set by Feeds.
  if ($suppress_messages) {
    drupal_get_messages(NULL);
  }
}

/**
 * Helper to get entity IDs for Feeds items that have been imported already.
 */
function vivodashboard_import_get_items($uri_list, $importer_id, $entity_type, $key_by_uri = FALSE) {
  $entity_ids = array();
  $result = db_select('feeds_item')
      ->fields('feeds_item')
      ->condition('entity_type', $entity_type)
      ->condition('url', $uri_list, 'IN')
      ->condition('id', $importer_id)
      ->execute();
  while ($feeds_item = $result->fetchObject()) {
    $entity_ids[$feeds_item->url] = $feeds_item->entity_id;
  }
  return ($key_by_uri) ? $entity_ids : array_values($entity_ids);
}

/**
 * Feeds mapping summary callback.
 */
function vivodashboard_import_mapping_summary_callback($config, $target, $form, $form_state) {
  $output = '';

  if (!empty($config['importer'])) {
    $output = t('Using the <strong>@name</strong> importer to manage items.', array('@name' => $config['importer']));
  }
  else {
    $output = 'No importer selected.';
  }

  return $output;
}

/**
 * Feeds mapping form callback.
 */
function vivodashboard_import_mapping_form_callback($config, $target, $form, $form_state) {
  $importer_options = array();
  foreach (feeds_importer_load_all() as $id => $importer) {
    if ($importer->parser instanceof LdimportParser) {
      $importer_options[$id] = $importer->config['name'];
    }
  }
  return array(
    'importer' => array(
      '#type' => 'select',
      '#title' => 'Importer',
      '#description' => 'Select which importer to use in creating/managing items.',
      '#options' => $importer_options,
      '#default_value' => !empty($config['importer']) ? $config['importer'] : NULL,
    ),
    'age' => array(
      '#type' => 'textfield',
      '#title' => 'Minimum age',
      '#description' => 'Minimum item age in minutes. Existing items are only re-imported when they are older than this. Enter "last" to use the last imported date of the parent importer.',
      '#default_value' => !empty($config['age']) ? $config['age'] : 'last',
      '#size' => 6,
    ),
  );
}

/**
 * Implements hook_feeds_presave().
 */
function vivodashboard_feeds_presave($source, $entity, $item) {
  // Ensure authors always have titles.
  if (($source->id == 'vivo_authors' || $source->id == 'vivo_authors_vcard') && empty($entity->title)) {
    $wrapper = entity_metadata_wrapper('node', $entity);

    $first_name = $wrapper->field_first_name->value();
    $last_name = $wrapper->field_last_name->value();
    if ($first_name && $last_name) {
      $entity->title = "{$last_name}, {$first_name}";
    }
    else {
      $entity->title = 'Unknown';
    }
  }

  // Ensure authorships always default to the title of the author.
  if ($source->id == 'vivo_authorships') {
    $wrapper = entity_metadata_wrapper('relation', $entity);

    if (!$wrapper->field_author_label->value()) {
      list($source, $target) = field_get_items('relation', $entity, 'endpoints');
      if ($author = node_load($target['entity_id'])) {
        $wrapper->field_author_label->set($author->title);
      }
    }
  }
}

/**
 * Implements hook_feeds_after_save().
 */
function vivodashboard_import_feeds_after_save($source, $entity, $item) {

  // Triggers the Authorship import after a publication gets saved. We need to
  // do this here so we have an NID for the publication.
  if ($source->id == 'vivo_publications' && !empty($entity->publication_authorships)) {

    vivodashboard_import_run_importer($entity->publication_authorships, 'vivo_authorships');

    // For the authorships that were imported, sort by rank and determine
    // first/last author status.
    if ($saved = relation_query('node', $entity->nid, 0)->entityCondition('bundle', 'authorship')->execute()) {

      $authorships = relation_load_multiple(array_keys($saved));

      uasort($authorships, 'vivodashboard_import_sort_authorships');

      if (count($authorships) > 1) {
        $first = reset($authorships);
        $last = end($authorships);

        $wrapper = entity_metadata_wrapper('relation', $first);
        $wrapper->field_author_position->set('first');
        $wrapper->save();

        $wrapper = entity_metadata_wrapper('relation', $last);
        $wrapper->field_author_position->set('last');
        $wrapper->save();
      }
    }
  }

  // Try to get a mostSpecificType value for any items being saved that
  // use field_rdf_type, and shift that to be the first field value.
  if (!empty($entity->field_rdf_type) && $item instanceof Graphite_Resource) {

    $most_specific_type = $item->get('http://vitro.mannlib.cornell.edu/ns/vitro/0.7#mostSpecificType');

    if ($most_specific_type instanceof Graphite_Resource) {
      $uri = $most_specific_type->toString();

      // Look up the existing TID for this rdf type.
      $tid = db_select('feeds_item')
        ->fields('feeds_item', array('entity_id'))
        ->condition('id', 'vivo_types')
        ->condition('url', $uri)
        ->execute()
        ->fetchField();

      $field_items = &$entity->field_rdf_type[LANGUAGE_NONE];

      // Shift field values around.
      foreach ($field_items as $delta => $field_item) {
        if ($field_item['tid'] == $tid && $delta != 0) {
          $first_value = $field_items[0];
          $field_items[0] = $field_item;
          $field_items[$delta] = $first_value;
        }
      }

      // We don't know the $entity_type here...
      if (!empty($entity->nid)) {
        node_save($entity);
      }
      elseif (!empty($entity->tid)) {
        taxonomy_term_save($entity);
      }
    }
  }
}

/**
 * uasort() callback for sorting authorships by rank.
 */
function vivodashboard_import_sort_authorships($a, $b) {
  $a_rank = entity_metadata_wrapper('relation', $a)->field_author_rank->value();
  $b_rank = entity_metadata_wrapper('relation', $b)->field_author_rank->value();

  if (!$a_rank && $a_rank !== 0) {
    $a_rank = 9999;
  }
  if (!$b_rank && $b_rank !== 0) {
    $b_rank = 9999;
  }

  if ($a_rank < $b_rank) {
    return -1;
  }
  if ($a_rank > $b_rank) {
    return 1;
  }

  return 0;
}

/**
 * Replacement Feeds source class.
 *
 * Normally Feeds will use static instances for sources, meaning $source->state
 * will be preserved within a page load, preventing us from running an importer
 * more than once per page load.
 *
 * @see vivodashboard_import_run_importer()
 */
class VivodashboardImportSource extends FeedsSource {

  /**
   * Overrides FeedsSource::instance to omit static instances.
   */
  public static function instance($importer_id, $feed_nid = 0) {
    $class = variable_get('feeds_source_class', 'FeedsSource');
    return new $class($importer_id, $feed_nid);
  }
}
