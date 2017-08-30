<?php
/**
 * @file
 * Drush commands for search api denormalized entity
 */

/**
 * Implements hook_drush_command().
 */
function search_api_grouping_drush_command() {
  $items = array();

  $items['search-api-grouping-generate'] = array(
    'description' => 'Generate the permutations of the denormalized entities.',
    'examples' => array(
      'search-api-grouping-generate' => dt('Generate the permutations of the denormalized entities.'),
      'drush sapi-gg' => dt('Alias to generate the permutations of the denormalized entities.'),
    ),
    'arguments' => array(
      'index_id' => dt('The numeric ID or machine name of an index.'),
    ),
    'aliases' => array('sapi-gg'),
  );
  $items['search-api-grouping-clean-tracking-table'] = array(
    'description' => 'Deletes orphaned ids from the tracking table.',
    'examples' => array(
      'search-api-grouping-clean-tracking-table' => dt('Deletes orphaned ids from the tracking table.'),
      'drush sapi-gct' => dt('Alias to deletes orphaned ids from the tracking table.'),
    ),
    'arguments' => array(
      'index_id' => dt('The numeric ID or machine name of an index.'),
    ),
    'aliases' => array('sapi-gct'),
  );

  $items['search-api-grouping-process-permutation-queue'] = array(
    'description' => 'Processes the queue to generate permutations.',
    'examples' => array(
      'search-api-grouping-process-permutation-queue' => dt('Processes the queue to generate permutations.'),
      'drush sapi-gpq' => dt('Alias to processes the queue to generate permutations.'),
    ),
    'arguments' => array(
      'timeout' => dt('The time limit on seconds. 0 removes the time limit.'),
    ),
    'aliases' => array('sapi-gpq'),
  );

  return $items;
}

/**
 * Generate the permutations of the denormalized entities.
 */
function drush_search_api_grouping_generate($index_id = NULL) {
  if (search_api_drush_static(__FUNCTION__)) {
    return;
  }

  $indexes = search_api_drush_get_index($index_id);
  if (empty($indexes)) {
    drush_log(dt('No indexes found', array()), 'warning');
    return;
  }

  foreach ($indexes as $index) {
    if ($index->datasource() instanceof SearchApiDenormalizedEntityDataSourceController) {
      drush_log(dt('!index: starting permutation gernerator.', array('!index' => $index->machine_name)), 'ok');

      $entity_type = $index->datasource()->getEntityType();
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', $entity_type)->execute();
      if (!empty($result[$entity_type])) {
        // Mark all found items as needs processing.
        db_update('search_api_denormalized_entity')
          ->fields(array(
            'needs_processing' => 1,
          ))
          ->condition('index_id', $index->id)
          ->condition('etid', array_keys($result[$entity_type]))
          ->condition('entity_type', $entity_type)
          ->execute();
      }
      // Now create the queue for the permutation generation.
      $index->datasource()->queuePermutationGeneration();

      drush_log(dt('!index successfully prepared.', array('!index' => $index->machine_name)), 'ok');
    }
    else {
      drush_log(dt('!index has no denormalized datasource - skipped', array('!index' => $index->machine_name)), 'notice');
    }
  }
  // And now we start the processing.
  drush_search_api_grouping_process_permutation_queue(0);
}

/**
 * Cleans the index table and ensures there are no orphaned ids.
 */
function drush_search_api_grouping_clean_tracking_table($index_id = NULL) {
  if (search_api_drush_static(__FUNCTION__)) {
    return;
  }

  $indexes = search_api_drush_get_index($index_id);
  if (empty($indexes)) {
    drush_log(dt('No indexes found', array()), 'warning');
    return;
  }

  foreach ($indexes as $index) {
    if ($index->datasource() instanceof SearchApiDenormalizedEntityDataSourceController) {
      drush_log(dt('!index: start cleaning.', array('!index' => $index->machine_name)), 'ok');
      $deleted_ids = $index->datasource()->cleanTable();
      drush_log(dt('!index: cleaning done. !amount orphaned items deleted.', array('!index' => $index->machine_name, '!amount' => $deleted_ids)), 'ok');
    }
    else {
      drush_log(dt('!index has no denormalized datasource - skipped', array('!index' => $index->machine_name)), 'notice');
    }
  }
}

/**
 * Processes queue items.
 */
function drush_search_api_grouping_process_permutation_queue($timeout = NULL) {
  $end = time() + (!empty($timeout) ? $timeout : 15);
  $queue = DrupalQueue::get('search_api_grouping_generate_permuatations');
  drush_log(dt(
    'The queue has currently !number items. Processing will !running.',
    array(
      '!number' => $queue->numberOfItems(),
      '!running' => ((!empty($timeout) ? dt('run for the next !timeout seconds', array('!timeout' => $timeout)) : t('process all items possible'))),
    )
  ), 'ok');
  $count = 0;
  while ((time() < $end || $timeout == 0) && ($item = $queue->claimItem())) {
    search_api_grouping_generate_permuatations($item->data);
    $queue->deleteItem($item);
    $count++;
    drush_log(dt('Processed item id !id.', array('!id' => $item->item_id)), 'ok');
  }
  drush_log(dt('Items processed !processed left items !left.', array('!processed' => $count, '!left' => $queue->numberOfItems())), 'ok');
}
