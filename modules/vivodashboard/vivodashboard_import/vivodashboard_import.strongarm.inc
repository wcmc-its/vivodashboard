<?php
/**
 * @file
 * vivodashboard_import.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vivodashboard_import_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'feeds_process_limit';
  $strongarm->value = 5;
  $export['feeds_process_limit'] = $strongarm;

  return $export;
}
