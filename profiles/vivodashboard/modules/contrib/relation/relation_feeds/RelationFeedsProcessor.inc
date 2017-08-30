<?php

/**
 * @file
 * Class definition of RelationFeedsProcessor.
 */

/**
 * Creates relations from feed items.
 */
class RelationFeedsProcessor extends FeedsProcessor {

  /**
   * {@inheritdoc}
   */
  public function entityType() {
    return 'relation';
  }

  /**
   * {@inheritdoc}
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Relations');
    return $info;
  }

  /**
   * {@inheritdoc}
   */
  protected function newEntity(FeedsSource $source) {
    $account = user_load($this->config['author']);
    $relation = relation_create($this->config['bundle'], array(), $account);
    return $relation;
  }

  /**
   * {@inheritdoc}
   */
  protected function entityLoad(FeedsSource $source, $rid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $relation = relation_load($rid, NULL, TRUE);
    }
    else {
      // We're replacing the existing relation. Only save the absolutely necessary.
      $relation = db_query("SELECT created, rid, vid, relation_type FROM {relation} WHERE rid = :rid", array(':rid' => $rid))->fetchObject();
      $relation->uid = $this->config['author'];
    }
    return $relation;
  }

  /**
   * {@inheritdoc}
   */
  protected function map(FeedsSource $source, FeedsParserResult $result, $target_item = NULL) {
    parent::map($source, $result, $target_item);
    if ($endpoints = $this->mapEndpoints($source, $result)) {
      $target_item->endpoints[LANGUAGE_NONE] = $endpoints;
    }
  }

  /**
   * Map endpoints to entity keys array
   *
   * @param FeedsSource $source
   *   Source information about this import.
   * @param FeedsParserResult $result
   *   The result of the parsing stage.
   *
   * @return array
   *   An array of mapped endpoint items
   */
  private function mapEndpoints(FeedsSource $source, FeedsParserResult $result) {
    $field = array();
    static $sources;
    if (!isset($sources)) {
      foreach ($this->config['mappings'] as $map) {
        // Each target can have multiple sources.
        $sources[$map['target']][] = $map['source'];
      }
    }
    $type = $this->getTypeInfo();
    if ($type->directional) {
      $endpoint_types = array('source_bundles', 'target_bundles');
    }
    else {
      $endpoint_types = array('source_bundles');
    }
    $item = $result->currentItem();
    foreach ($endpoint_types as $endpoint_type) {
      foreach ($type->{$endpoint_type} as $endpoint) {
        $endpoint = explode(':', $endpoint);
        // We're using GUID
        if (isset($sources[$endpoint_type . ':' . $endpoint[0] . ':' . $endpoint[1] . ':guid'])) {
          $endpoint_sources = $sources[$endpoint_type . ':' . $endpoint[0] . ':' . $endpoint[1] . ':guid'];
          $guids = array();
          foreach ($endpoint_sources as $endpoint_source) {
            if (empty($item[$endpoint_source])) {
              throw new FeedsValidationException(t('Missing GUID at source @source.', array(
                '@source' => $endpoint_source
              )));
            }
            $guids[] = $item[$endpoint_source];
          }
          $entity_feeds = db_select('feeds_item', 'f')
            ->condition('guid', $guids)
            ->condition('entity_type', $endpoint[0])
            ->fields('f', array('guid', 'entity_id', 'entity_type'))
            ->execute()
            ->fetchAllAssoc('guid');
          foreach ($guids as $guid) {
            if (!isset($entity_feeds[$guid])) {
              throw new FeedsValidationException(t('GUID @guid was not found.', array(
                '@guid' => $guid
              )));
            }
            $field[] = array('entity_type' => $entity_feeds[$guid]->entity_type, 'entity_id' => $entity_feeds[$guid]->entity_id);
          }
        }
        // We're using entity ID
        if (isset($sources[$endpoint_type . ':' . $endpoint[0] . ':' . $endpoint[1] . ':entity_id'])) {
          $endpoint_sources = $sources[$endpoint_type . ':' . $endpoint[0] . ':' . $endpoint[1] . ':entity_id'];
          foreach ($endpoint_sources as $endpoint_source) {
            if (empty($item[$endpoint_source])) {
              throw new FeedsValidationException(t('Missing entity id at source @source.', array(
                '@entity_id' => $endpoint_source
              )));
            }
            $field[] = array('entity_type' => $endpoint[0], 'entity_id' => $item[$endpoint_source]);
          }
        }
      }
    }
    return $field;
  }

  /**
   * Get configured relation type
   */
  protected function getTypeInfo() {
    $types = relation_get_types();
    return $types[$this->config['bundle']];
  }

  /**
   * {@inheritdoc}
   */
  protected function entityValidate($entity) {
    try {
      field_attach_validate('relation', $entity);
    }
    catch (FieldValidationException $e) {
      throw new FeedsValidationException(t('Relation validation failed.'));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function entitySave($entity) {
    relation_save($entity);
  }

  /**
   * {@inheritdoc}
   */
  protected function entityDeleteMultiple($rids) {
    relation_delete_multiple($rids);
  }

  /**
   * Overrides parent::expiryQuery().
   */
  protected function expiryQuery(FeedsSource $source, $time) {
    $select = parent::expiryQuery($source, $time);
    $select->condition('e.created', REQUEST_TIME - $time, '<');
    return $select;
  }

  /**
   * {@inheritdoc}
   */
  public function expiryTime() {
    return $this->config['expire'];
  }

  /**
   * {@inheritdoc}
   */
  public function configDefaults() {
    return array(
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
      'unique_enpoints' => 0
    ) + parent::configDefaults();
  }

  /**
   * {@inheritdoc}
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $form['unique_enpoints'] = array(
      '#type' => 'checkbox',
      '#title' => t('Unique endpoints'),
      '#description' => t('Use mapped endpoints as unique identifier for imported relations.'),
      '#default_value' => $this->config['unique_enpoints'],
    );
    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the relations to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );
    $period = drupal_map_assoc(array(FEEDS_EXPIRE_NEVER, 3600, 10800, 21600, 43200, 86400, 259200, 604800, 2592000, 2592000 * 3, 2592000 * 6, 31536000), 'feeds_format_expire');
    $form['expire'] = array(
      '#type' => 'select',
      '#title' => t('Expire relations'),
      '#options' => $period,
      '#description' => t('Select after how much time relations should be deleted. The relation\'s creation date will be used for determining the relation\'s age, see Mapping settings.'),
      '#default_value' => $this->config['expire'],
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function configFormSubmit(&$values) {
    if ($this->config['expire'] != $values['expire']) {
      feeds_reschedule($this->id);
    }
    parent::configFormSubmit($values);
  }

  /**
   * {@inheritdoc}
   */
  public function setTargetElement(FeedsSource $source, $target_relation, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_relation->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'feeds_source':
        // Get the class of the feed relation importer's fetcher and set the source
        // property. See feeds_relation_update() how $relation->feeds gets stored.
        if ($id = feeds_get_importer_id($this->config['bundle'])) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_relation->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See feeds_relation_insert().
          $target_relation->feeds['suppress_import'] = TRUE;
        }
        break;
      default:
        parent::setTargetElement($source, $target_relation, $target_element, $value);
        break;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();

    $targets['rid'] = array(
      'name' => t('Relation ID'),
      'description' => t('The rid of the relation. NOTE: use this feature with care, relation ids are usually assigned by Drupal.'),
      'optional_unique' => TRUE,
    );
    $targets['uid'] = array(
      'name' => t('User ID'),
      'description' => t('The Drupal user ID of the relation author.'),
    );
    $targets['created'] = array(
      'name' => t('Published date'),
      'description' => t('The UNIX time when a relation has been published.'),
    );
    $type = $this->getTypeInfo();
    if ($type->directional) {
      $endpoint_types = array('source_bundles' => t('Source'), 'target_bundles' => t('Target'));
    }
    else {
      $endpoint_types = array('source_bundles' => t('Endpoint'));
    }
    foreach ($endpoint_types as $endpoint_type => $endpoint_label) {
      foreach ($type->{$endpoint_type} as $endpoint) {
        $endpoint = explode(':', $endpoint);
        $entity = entity_get_info($endpoint[0]);
        $bundle_label = ($endpoint[1] == '*')
                          ? t('any type')
                          : $entity['bundles'][$endpoint[1]]['label'];
        $targets[$endpoint_type . ':' . $endpoint[0] . ':' . $endpoint[1] . ':guid'] = array(
          'name' => t('@type @entity of @bundle: Feeds GUID', array('@type' => $endpoint_label, '@entity' => $entity['label'], '@bundle' => $bundle_label)),
          'description' => t('The GUID of the entity if it was already imported via feeds.'),
        );
        $targets[$endpoint_type . ':' . $endpoint[0] . ':' . $endpoint[1] . ':entity_id'] = array(
          'name' => t('@type @entity of @bundle: Entity ID', array('@type' => $endpoint_label, '@entity' => $entity['label'], '@bundle' => $bundle_label)),
          'description' => t('The ID of the entity as it exists in Drupal.'),
        );
      }
    }

    // If the target content type is a Feed relation, expose its source field.
    if ($id = feeds_get_importer_id($this->config['bundle'])) {
      $name = feeds_importer($id)->config['name'];
      $targets['feeds_source'] = array(
        'name' => t('Feed source'),
        'description' => t('The content type created by this processor is a Feed relation, it represents a source itself. Depending on the fetcher selected on the importer "@importer", this field is expected to be for example a URL or a path to a file.', array('@importer' => $name)),
        'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    $entity_type = $this->entityType();
    $bundle = $this->bundle();
    drupal_alter('feeds_processor_targets', $targets, $entity_type, $bundle);
    return $targets;
  }

  /**
   * {@inheritdoc}
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($rid = parent::existingEntityId($source, $result)) {
      return $rid;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'rid':
          $rid = db_query("SELECT rid FROM {relation} WHERE rid = :rid", array(':rid' => $value))->fetchField();
          break;
        case 'feeds_source':
          if ($id = feeds_get_importer_id($this->config['bundle'])) {
            $rid = db_query("SELECT fs.feed_rid FROM {relation} r JOIN {feeds_source} fs ON r.rid = fs.feed_rid WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
          }
          break;
      }
      if ($rid) {
        // Return with the first rid found.
        return $rid;
      }
    }
    // If other unique targets didn't match this relation check if endpoints
    // are unique.
    if ($this->config['unique_enpoints']) {
      try {
        $endpoints = $this->mapEndpoints($source, $result);
      }
      catch (FeedsValidationException $f) {
        return 0;
      }
      $type = $this->getTypeInfo();
      $relations = relation_relation_exists($endpoints, $this->config['bundle'], $type->directional);
      if ($relations) {
        return key($relations);
      }
    }
    return 0;
  }
}
