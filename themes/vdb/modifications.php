<?php

/**
 * Implements hook_page_alter().
 */
function vdb_page_alter(&$page) {
  drupal_add_css('http://fonts.googleapis.com/css?family=Open+Sans:400,400italic,600,700,700italic', array('type' => 'external'));
}

/**
 * Implements hook_preprocess_page().
 */
function vdb_preprocess_page(&$vars) {
  $menu1 = menu_navigation_links('main-menu', 0);
  $vars['menu_first'] = theme('links__system_main_menu', array(
    'links' => $menu1,
    'attributes' => array(
      'id' => 'main-menu-links',
    ),
  ));

  $menu2 = menu_navigation_links('main-menu', 1);
  $vars['menu_second'] = empty($menu2) ? '' : theme('links__system_main_menu', array(
    'links' => $menu2,
    'attributes' => array(
      'class' => array('tabs', 'primary'),
    ),
  ));

  $vars['tabs_first'] = menu_primary_local_tasks();
  $vars['tabs_second'] = menu_secondary_local_tasks();
}

/**
 * Overrides theme_facetapi_deactivate_widget().
 */
function vdb_facetapi_deactivate_widget($variables) {
  return '(x)';
}
