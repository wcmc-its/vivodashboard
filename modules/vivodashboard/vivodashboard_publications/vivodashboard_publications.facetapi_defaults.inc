<?php
/**
 * @file
 * vivodashboard_publications.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function vivodashboard_publications_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_author_affiliations';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_author_affiliations';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'reverse_dependency' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_author_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_author_names';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_author_names';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_author_names'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_author_types';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_author_types';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_author_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_journal';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_journal';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_journal'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_journal_ranking';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_journal_ranking';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_journal_ranking'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_month';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_month';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'authorship' => 0,
      ),
      'facets' => array(
        'publication_types' => 0,
        'publication_journal_ranking' => 0,
        'publication_author_names' => 0,
        'publication_author_types' => 0,
        'publication_author_firstlast_affiliations' => 0,
        'publication_author_affiliations' => 0,
        'publication_journal' => 0,
        'publication_year' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_types' => '',
      'facet_items_publication_journal_ranking' => '',
      'facet_items_publication_author_names' => '',
      'facet_items_publication_author_types' => '',
      'facet_items_publication_author_firstlast_affiliations' => '',
      'facet_items_publication_author_affiliations' => '',
      'facet_items_publication_journal' => '',
      'facet_items_publication_year' => '',
      'enabled' => 1,
      'hide' => 1,
      'single_year' => '1',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_types';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_types';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_year';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_year';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'reverse_dependency' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_author_affiliations';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_affiliations';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'autocomplete',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 1,
    'remove_selected' => 1,
    'auto_submit' => 1,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@authorships:block:publication_author_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_author_firstlast_affiliations';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_firstlast_affiliations';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-42',
      ),
      'empty_years' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'empty_months' => array(
        'status' => 0,
        'weight' => '-40',
      ),
      'convert_months' => array(
        'status' => 0,
        'weight' => '-39',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
  );
  $export['search_api@authorships:block:publication_author_firstlast_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_author_names';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_names';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'autocomplete',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 1,
    'remove_selected' => 1,
    'auto_submit' => 1,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@authorships:block:publication_author_names'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_author_types';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_types';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '3',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@authorships:block:publication_author_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_journal';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_journal';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'autocomplete',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 1,
    'remove_selected' => 1,
    'auto_submit' => 1,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@authorships:block:publication_journal'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_journal_ranking';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_journal_ranking';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'search_api_ranges_ui_slider',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1000',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '0.1',
    'round-precision' => '1',
  );
  $export['search_api@authorships:block:publication_journal_ranking'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_month';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_month';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'search_api_ranges_ui_slider',
    'filters' => array(),
    'active_sorts' => array(
      'natural' => 'natural',
      'display' => 'display',
      'active' => 'active',
      'count' => 'count',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'natural' => '-50',
      'display' => '-49',
      'active' => '-48',
      'count' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'natural' => '4',
      'display' => '4',
      'active' => '3',
      'count' => '3',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
  );
  $export['search_api@authorships:block:publication_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_timestamp';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_timestamp';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@authorships:block:publication_timestamp'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_types';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_types';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '3',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@authorships:block:publication_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_year';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_year';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'search_api_ranges_ui_slider',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '5',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 1,
    'remove_selected' => 0,
    'auto_submit' => 1,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => '10',
    'range_advanced' => '',
    'empty_text' => array(
      'value' => 'No dates available.',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@authorships:block:publication_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_author_affiliations';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_author_affiliations';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'reverse_dependency' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_author_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_author_names';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_author_names';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'reverse_dependency' => FALSE,
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_author_names'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_author_types';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_author_types';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'reverse_dependency' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_author_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_graph_month';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_graph_month';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'author' => 0,
        'page' => 0,
        'book' => 0,
        'faq' => 0,
        'publication' => 0,
      ),
      'facets' => array(
        'publication_year' => 0,
        'publication_graph_year' => 0,
        'field_journal' => 0,
        'field_rdf_type' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_year' => '',
      'facet_items_publication_graph_year' => '',
      'facet_items_field_journal' => '',
      'facet_items_field_rdf_type' => '',
      'enabled' => 1,
      'hide' => 1,
      'single_year' => '1',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_graph_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_graph_year';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_graph_year';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'author' => 0,
        'page' => 0,
        'book' => 0,
        'faq' => 0,
        'publication' => 0,
      ),
      'facets' => array(
        'publication_year' => 0,
        'publication_graph_month' => 0,
        'field_journal' => 0,
        'field_rdf_type' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_year' => '',
      'facet_items_publication_graph_month' => '',
      'facet_items_field_journal' => '',
      'facet_items_field_rdf_type' => '',
      'enabled' => 1,
      'hide' => 0,
      'single_year' => '0',
      'reverse_dependency' => FALSE,
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_graph_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_journal';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_journal';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_journal'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_journal_ranking';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_journal_ranking';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_journal_ranking'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_month';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_month';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'author' => 0,
        'page' => 0,
        'book' => 0,
        'faq' => 0,
        'publication' => 0,
      ),
      'facets' => array(
        'publication_year' => 'publication_year',
        'publication_journal_ranking' => 0,
        'publication_journal' => 0,
        'publication_types' => 0,
        'publication_author_names' => 0,
        'publication_author_affiliations' => 0,
        'publication_author_types' => 0,
        'publication_graph_month' => 0,
        'publication_graph_year' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_publication_journal_ranking' => '',
      'facet_items_publication_journal' => '',
      'facet_items_publication_types' => '',
      'facet_items_publication_author_names' => '',
      'facet_items_publication_author_affiliations' => '',
      'facet_items_publication_author_types' => 'book',
      'facet_items_publication_graph_month' => '',
      'facet_items_publication_graph_year' => '',
      'facet_items_publication_year' => '',
      'enabled' => 1,
      'hide' => 1,
      'single_year' => '1',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_types';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_types';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'reverse_dependency' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::publication_year';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_year';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'article' => 0,
        'author' => 0,
        'page' => 0,
        'book' => 0,
        'faq' => 0,
        'publication' => 0,
      ),
      'facets' => array(
        'publication_author_types' => 0,
        'publication_author_names' => 0,
        'publication_author_affiliations' => 0,
        'publication_month' => 0,
        'field_journal' => 0,
        'field_rdf_type' => 0,
      ),
      'force_deactivation' => 0,
      'regex' => 0,
      'facet_items_publication_author_types' => '',
      'facet_items_publication_author_names' => '',
      'facet_items_publication_author_affiliations' => '',
      'facet_items_publication_month' => '',
      'facet_items_field_journal' => '',
      'facet_items_field_rdf_type' => '',
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
      'reverse_dependency' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::publication_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_author_affiliations';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_affiliations';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'autocomplete',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'add_count' => 1,
    'remove_selected' => 1,
    'auto_submit' => 1,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@publications:block:publication_author_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_author_firstlast_affiliations';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_firstlast_affiliations';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-42',
      ),
      'empty_years' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'convert_months' => array(
        'status' => 0,
        'weight' => '-40',
      ),
      'empty_months' => array(
        'status' => 0,
        'weight' => '-40',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'range_simple' => 10,
    'range_advanced' => '',
    'round-precision' => '0',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
  );
  $export['search_api@publications:block:publication_author_firstlast_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_author_names';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_names';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'autocomplete',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'add_count' => 1,
    'remove_selected' => 1,
    'auto_submit' => 1,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@publications:block:publication_author_names'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_author_types';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_types';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-42',
      ),
      'convert_months' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'empty_years' => array(
        'status' => 0,
        'weight' => '-41',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '3',
    'nofollow' => 1,
    'show_expanded' => 0,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'exclude' => 'Agent, Person, Thing, Unknown Person',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
    'transform' => 'capitalize_first',
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@publications:block:publication_author_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_journal';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_journal';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'autocomplete',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 1,
    'remove_selected' => 1,
    'auto_submit' => 1,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@publications:block:publication_journal'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_journal_ranking';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_journal_ranking';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'search_api_ranges_ui_slider',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1000',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '0.1',
    'round-precision' => '1',
  );
  $export['search_api@publications:block:publication_journal_ranking'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_month';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_month';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'search_api_ranges_ui_slider',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-42',
      ),
      'empty_years' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'convert_months' => array(
        'status' => 1,
        'weight' => '-40',
      ),
      'empty_months' => array(
        'status' => 0,
        'weight' => '-40',
      ),
    ),
    'active_sorts' => array(
      'natural' => 'natural',
      'display' => 'display',
      'active' => 'active',
      'count' => 'count',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'natural' => '-50',
      'display' => '-49',
      'active' => '-48',
      'count' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'natural' => '4',
      'display' => '4',
      'active' => '3',
      'count' => '3',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'range_simple' => 10,
    'range_advanced' => '',
    'round-precision' => '0',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
  );
  $export['search_api@publications:block:publication_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_types';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_types';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-42',
      ),
      'convert_months' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'empty_years' => array(
        'status' => 0,
        'weight' => '-41',
      ),
    ),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '3',
    'nofollow' => 1,
    'show_expanded' => 0,
    'add_count' => 0,
    'remove_selected' => 0,
    'auto_submit' => 0,
    'act_single' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'exclude' => 'Document, Information Resource, Thing',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@publications:block:publication_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_year';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_year';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'search_api_ranges_ui_slider',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '5',
    'nofollow' => 1,
    'show_expanded' => 0,
    'graphs_combotitle' => NULL,
    'graphs_comboshowzoom' => 0,
    'graphs_comboengine' => 'flot',
    'graphs_combonofollow' => 1,
    'graphs_combowidth' => '500',
    'graphs_comboheight' => '400',
    'graphs_comboy_min' => NULL,
    'graphs_comboy_max' => NULL,
    'graphs_comboy_step' => NULL,
    'graphs_comboy_legend' => NULL,
    'graphs_combobackground_colour' => '#fff',
    'graphs_comboseries_colours' => NULL,
    'graphs_comboshowlegend' => 1,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'range_simple' => '10',
    'range_advanced' => '',
    'empty_text' => array(
      'value' => 'No dates available.',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'add_count' => 1,
    'remove_selected' => 0,
    'auto_submit' => 1,
    'act_single' => 0,
    'slider-step' => '1',
    'round-precision' => '0',
  );
  $export['search_api@publications:block:publication_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:facetapi_graphs_graphs:publication_graph_month';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'facetapi_graphs_graphs';
  $facet->facet = 'publication_graph_month';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_graphs',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-42',
      ),
      'empty_years' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'convert_months' => array(
        'status' => 1,
        'weight' => '-39',
      ),
      'empty_months' => array(
        'status' => 1,
        'weight' => '-40',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'natural' => 0,
      'display' => 0,
      'active' => 0,
      'count' => 0,
    ),
    'sort_weight' => array(
      'indexed' => '-50',
      'natural' => '-49',
      'display' => '-48',
      'active' => '-47',
      'count' => '-46',
    ),
    'sort_order' => array(
      'indexed' => '4',
      'natural' => '4',
      'display' => '4',
      'active' => '3',
      'count' => '3',
    ),
    'empty_behavior' => 'text',
    'graphstitle' => '',
    'graphsshowzoom' => 0,
    'graphsengine' => 'vivodashboard_flot',
    'graphsnofollow' => 1,
    'graphswidth' => '100%',
    'graphsheight' => '450',
    'graphsy_min' => '',
    'graphsy_max' => '',
    'graphsy_step' => '',
    'graphsy_legend' => '',
    'graphsbackground_colour' => '',
    'graphsseries_colours' => '',
    'graphsshowlegend' => 0,
    'graphsd3' => 'LineGraph',
    'graphsflot' => 'bar',
    'graphsvivodashboard_flot' => 'bar',
    'empty_text' => array(
      'value' => 'No results for your query.',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => '12',
  );
  $export['search_api@publications:facetapi_graphs_graphs:publication_graph_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:facetapi_graphs_graphs:publication_graph_year';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'facetapi_graphs_graphs';
  $facet->facet = 'publication_graph_year';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_graphs',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'empty_years' => array(
        'status' => 1,
        'weight' => '-42',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'convert_months' => array(
        'status' => 0,
        'weight' => '-40',
      ),
    ),
    'active_sorts' => array(
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
      'natural' => 0,
    ),
    'sort_weight' => array(
      'display' => '-50',
      'active' => '-49',
      'count' => '-48',
      'indexed' => '-46',
      'natural' => '0',
    ),
    'sort_order' => array(
      'display' => '4',
      'active' => '3',
      'count' => '3',
      'indexed' => '4',
      'natural' => '4',
    ),
    'empty_behavior' => 'text',
    'graphstitle' => '',
    'graphsshowzoom' => 0,
    'graphsengine' => 'vivodashboard_flot',
    'graphsnofollow' => 1,
    'graphswidth' => '100%',
    'graphsheight' => '450',
    'graphsy_min' => '',
    'graphsy_max' => '',
    'graphsy_step' => '',
    'graphsy_legend' => '',
    'graphsbackground_colour' => '',
    'graphsseries_colours' => '',
    'graphsshowlegend' => 0,
    'graphsd3' => 'LineGraph',
    'graphsflot' => 'bar',
    'graphsvivodashboard_flot' => 'bar',
    'empty_text' => array(
      'value' => 'No results for your query.',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => '10',
  );
  $export['search_api@publications:facetapi_graphs_graphs:publication_graph_year'] = $facet;

  return $export;
}
