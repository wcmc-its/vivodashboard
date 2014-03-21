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
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
