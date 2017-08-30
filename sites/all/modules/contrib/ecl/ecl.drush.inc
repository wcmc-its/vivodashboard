<?php

/**
 * @file ecl.drush.inc
 *   drush integration for caching entity content.
 */

/**
 * Implementation of hook_drush_help().
 */
function ecl_drush_help($section) {
  switch ($section) {
    case 'drush:entitycache-loader':
      return dt('Used without parameters, this command loads all the various content in the entities into cache using entity_load()');
  }
}

/**
 * Implementation of hook_drush_command().
 */
function ecl_drush_command() {
  $items = array();
  $items['entitycache-loader'] = array(
    'callback' => 'ecl_load_cache',
    'description' => dt('Load the cache with the various entities configured to use the cache'),
    'arguments' => array(
      'type' => dt('Optional. Only load the particular entity type objects into cache'),
    ),
    'options' => array(
      'limit' => dt('Set a limit on the number of entities that will get processed per batch run. Defaults to 50'),
      'bundle' => dt('Optionally filter by an entity bundle'),
      'cache-viewmodes' => dt('Attempt to cache view modes. Only works if display cache is enabled and configured for caching on a bundle view mode. Set to any non-empty value.'),
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('ecload'),
  );
  
  return $items;
}

/**
 * Load the cache bin with content from the various entities.
 * @param $type Optional. The specific type of entity that should
 *   get it's content cached.
 */
function ecl_load_cache($type = '') {
  $types = entity_get_info();
  if (!empty($type)) {
    if (!isset($types[$type])) {
      drush_die("Type $type is not supported");
    }
    else {
      $types = array($type => $types[$type]);
    }
  }
  $form_state = array(
    'values' => array(
      'ecl_entity_type' => $type,
      'ecl_bundle_type' => drush_get_option('bundle', ''),
      'ecl_cache_view_modes' => drush_get_option('cache-viewmodes', ''),
    ),
  );

  ecl_load_caches_form_submit(array(), $form_state);
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}
