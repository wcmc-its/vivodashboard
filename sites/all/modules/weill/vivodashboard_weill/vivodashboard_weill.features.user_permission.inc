<?php
/**
 * @file
 * vivodashboard_weill.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vivodashboard_weill_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access citation lookup tool'.
  $permissions['access citation lookup tool'] = array(
    'name' => 'access citation lookup tool',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'citation_lookup',
  );

  return $permissions;
}
