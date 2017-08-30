<?php
/**
 * @file
 * vivodashboard_weill.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vivodashboard_weill_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
