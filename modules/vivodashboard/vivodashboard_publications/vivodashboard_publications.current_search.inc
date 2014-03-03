<?php
/**
 * @file
 * vivodashboard_publications.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function vivodashboard_publications_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'authorships';
  $item->label = 'Authorships';
  $item->settings = array(
    'items' => array(
      'active' => array(
        'id' => 'active',
        'label' => 'Active',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 0,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'weight' => '-49',
      ),
      'reset' => array(
        'id' => 'reset_link',
        'label' => 'Reset',
        'text' => 'Clear all',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '-48',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '2',
    ),
  );
  $export['authorships'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'publications';
  $item->label = 'Publications';
  $item->settings = array(
    'items' => array(
      'active' => array(
        'id' => 'active',
        'label' => 'Active',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 0,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'weight' => '0',
      ),
      'reset' => array(
        'id' => 'reset_link',
        'label' => 'Reset',
        'text' => 'Clear all',
        'plural' => 0,
        'text_plural' => '',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '2',
    ),
  );
  $export['publications'] = $item;

  return $export;
}
