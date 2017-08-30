<?php
/**
 * @file
 * ldimport_vivo_libraries.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ldimport_vivo_libraries_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ldimport_vivo_libraries_node_info() {
  $items = array(
    'vivo_library' => array(
      'name' => t('VIVO Library'),
      'base' => 'node_content',
      'description' => t('Example node type used by the ldimport_vivo_libraries module to import libraries from VIVO.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
