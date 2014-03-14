<?php
/**
 * @file
 * vivodashboard_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vivodashboard_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
