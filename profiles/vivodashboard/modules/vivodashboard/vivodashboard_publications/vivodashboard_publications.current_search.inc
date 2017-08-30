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
      'groups' => array(
        'id' => 'grouped_active_items',
        'label' => 'Groups',
        'field_pattern' => '[facetapi_facet:facet-label]:',
        'nofollow' => 1,
        'weight' => '-50',
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
        'weight' => '-49',
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
      'grouped' => array(
        'id' => 'grouped_active_items',
        'label' => 'Grouped',
        'field_pattern' => '[facetapi_facet:facet-label]:',
        'nofollow' => 1,
        'weight' => '-50',
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
        'weight' => '-49',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '2',
    ),
  );
  $export['publications'] = $item;

  return $export;
}
