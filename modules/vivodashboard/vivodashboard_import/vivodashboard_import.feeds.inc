<?php

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * Adds custom Feeds mappers that run other Feeds importers.
 *
 * These mappers effectively chain Feeds importers together, piping URIs from
 * one importer to the next.
 */
function vivodashboard_import_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
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

  if ($entity_type == 'node' && $bundle_name == 'author') {
    $targets['primary_department'] = array(
      'name' => t('Custom: Primary Department'),
      'callback' => 'vivodashboard_import_mapping_callback_primary_department',
    );
  }
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

  // Populate field values.
  list(, $entity_type, $field_name) = explode(':', $target);
  $field_info = field_info_field($field_name);
  $is_multivalue_field = ($field_info['cardinality'] == 1) ? FALSE : TRUE;
  $wrapper = entity_metadata_wrapper($entity_type, $entity);

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
    $output = t('Using the <strong>@name</strong> importer to manage terms.', array('@name' => $config['importer']));
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
    if ($importer->parser instanceof LdimportParser && $importer->processor instanceof FeedsTermProcessor) {
      $importer_options[$id] = $importer->config['name'];
    }
  }
  return array(
    'importer' => array(
      '#type' => 'select',
      '#title' => 'Importer',
      '#description' => 'Select which importer to use in creating/managing terms.',
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
 * Implements hook_feeds_after_save().
 *
 * Loads authorship data for publications to create authors and add relations
 * between them. This needs to be handled in this hook instead of a mapper
 * because the NID is not yet available during mapping and is needed to form
 * the relation. We also need to preserve certain properties from the
 * authorship, such as rank and label.
 *
 * @todo Move all this to a Relation importer?
 */
function vivodashboard_import_feeds_after_save($source, $node, $item) {
  if ($source->id != 'vivo_publications') {
    return;
  }

  // Clear any existing authorships for this publication.
  $existing = relation_query('node', $node->nid, 0)->entityCondition('bundle', 'authorship')->execute();
  if ($existing) {
    relation_delete_multiple(array_keys($existing));
  }

  $authorships = array();

  // Fetch authorships and gather associated authors for this publication.
  foreach ($item->values('http://vivoweb.org/ontology/core#informationResourceInAuthorship') as $k => $authorship_data) {

    $authorship_uri = $authorship_data['value'];
    $authorship = new LdImportItem($authorship_uri);
    $author = ($data = $authorship->values('http://vivoweb.org/ontology/core#linkedAuthor')) ? $data[0] : array();
    $rank = ($data = $authorship->values('http://vivoweb.org/ontology/core#authorRank')) ? $data[0] : array();
    $label = ($data = $authorship->values('http://www.w3.org/2000/01/rdf-schema#label')) ? $data[0] : array();

    if (isset($author['value'])) {
      $author_uri = $author['value'];
      $authorships[$author_uri] = array(
        'uri' => $author_uri,
        'rank' => isset($rank['value']) ? $rank['value'] : NULL,
        'label' => isset($label['value']) ? str_replace('Authorship for ', '', $label['value']) : NULL,
        'authorship' => $authorship_uri,
        'index' => $k,
      );
    }
  }

  if (!$authorships) {
    return;
  }

  uasort($authorships, 'vivodashboard_import_sort_authorships');

  // Determine first/last authors.
  $first = $last = '';
  if (count($authorships) > 1) {
    reset($authorships);
    $first = key($authorships);
    end($authorships);
    $last = key($authorships);
  }

  $author_uris = array_keys($authorships);

  // Only import new authors or those created before this importer last ran.
  $uris_to_import = vivodashboard_import_uris_needing_update($author_uris, 'vivo_authors', $source->imported);
  if ($uris_to_import) {
    vivodashboard_import_run_importer($uris_to_import, 'vivo_authors');
  }

  $authors_items = vivodashboard_import_get_items($author_uris, 'vivo_authors', 'node', TRUE);

  // Create authorship relations for author nodes that were saved.
  foreach ($authors_items as $uri => $nid) {
    $endpoints = array();
    $endpoints[] = array('entity_type' => 'node', 'entity_id' => $node->nid);
    $endpoints[] = array('entity_type' => 'node', 'entity_id' => $nid);

    $relation = relation_create('authorship', $endpoints);
    $wrapper = entity_metadata_wrapper('relation', $relation);

    if (is_numeric($authorships[$uri]['rank'])) {
      $wrapper->field_author_rank->set((int) $authorships[$uri]['rank']);
    }

    if ($authorships[$uri]['label']) {
      $wrapper->field_author_label->set($authorships[$uri]['label']);
    }
    else {
      $author_node = node_load($nid);
      $title = ($author_node) ? $author_node->title : 'Unknown author';
      $wrapper->field_author_label->set($title);
    }

    if ($uri == $first) {
      $wrapper->field_author_position->set('first');
    }
    if ($uri == $last) {
      $wrapper->field_author_position->set('last');
    }

    relation_save($relation);
  }

  // Clear cache for the node since we just added relation data.
  entity_get_controller('node')->resetCache(array($node->nid));
}

/**
 * uasort() callback for sorting authorships by rank.
 *
 * The secondary sort is by array index, which should represent their order
 * from the RDF and is used as a fallback.
 */
function vivodashboard_import_sort_authorships($a, $b) {
  if (!$a['rank']) {
    $a['rank'] = 9999;
  }
  if (!$b['rank']) {
    $b['rank'] = 9999;
  }

  if ($a['rank'] < $b['rank']) {
    return -1;
  }
  if ($a['rank'] > $b['rank']) {
    return 1;
  }
  if ($a['index'] < $b['index']) {
    return -1;
  }
  if ($a['index'] > $b['index']) {
    return 1;
  }

  return 0;
}

/**
 * Feeds mapping callback for an author's primary department.
 *
 * We're already handling departmental positions in another mapping. However,
 * we also want to map *primary* departmental positions. It's not possible to
 * filter items with the LDimport module at this point, so we need to do it
 * with this custom mapper.
 *
 * - VIVO authors relate to positions via http://vivoweb.org/ontology/core#personInPosition
 * - Positions relate to departments via http://vivoweb.org/ontology/core#positionInOrganization
 * - Positions may have the rdf:type http://vivoweb.org/ontology/core#PrimaryPosition
 */
function vivodashboard_import_mapping_callback_primary_department($source, $node, $target, $values) {
  $position_uris = is_array($values) ? $values : array($values);

  $wrapper = entity_metadata_wrapper('node', $node);

  foreach ($position_uris as $position_uri) {
    $position = new LdImportItem($position_uri);
    $is_primary_position = FALSE;

    // We only care about positions typed as vivo:primaryPosition.
    foreach ($position->values('http://www.w3.org/1999/02/22-rdf-syntax-ns#type') as $rdf_type) {
      if (!empty($rdf_type['value']) && $rdf_type['value'] == 'http://vivoweb.org/ontology/core#PrimaryPosition') {
        $is_primary_position = TRUE;
      }
    }

    if (!$is_primary_position) {
      continue;
    }

    // Get the department associated with the position. We're assuming that a
    // department node has already been created by a previous mapping.
    foreach ($position->values('http://vivoweb.org/ontology/core#positionInOrganization') as $department) {
      if (!empty($department['value'])) {
        $department_uris = array($department['value']);
        $nids = vivodashboard_import_get_items($department_uris, 'vivo_departments', 'taxonomy_term');
        if ($nid = reset($nids)) {
          $wrapper->field_primary_department->set($nid);
        }
      }
    }
  }
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
