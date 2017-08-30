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
  $facet->name = 'search_api@authorships::organizations';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'organizations';
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
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::organizations'] = $facet;

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
  $facet->name = 'search_api@authorships::publication_author_firstlast_affiliations';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_author_firstlast_affiliations';
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
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => 0,
    'limit_active_items' => 0,
  );
  $export['search_api@authorships::publication_author_firstlast_affiliations'] = $facet;

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
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_author_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships::publication_graph_year';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_graph_year';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@authorships::publication_graph_year'] = $facet;

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
  $facet->name = 'search_api@authorships::publication_timestamp';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = '';
  $facet->facet = 'publication_timestamp';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
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
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'date_range',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'date_granularity' => 'MINUTE',
  );
  $export['search_api@authorships::publication_timestamp'] = $facet;

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
  $facet->name = 'search_api@authorships:block:organizations';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'organizations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'date_ranges' => array(
      'add_range' => 'Add a new date range',
    ),
    'ranges' => array(
      'past_hour' => array(
        'label' => 'Past hour',
        'machine_name' => 'past_hour',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '0',
        'delete' => 0,
      ),
      'past_24_hours' => array(
        'label' => 'Past 24 hours',
        'machine_name' => 'past_24_hours',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '24',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '1',
        'delete' => 0,
      ),
      'past_week' => array(
        'label' => 'Past week',
        'machine_name' => 'past_week',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '7',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '2',
        'delete' => 0,
      ),
      'past_month' => array(
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '3',
        'delete' => 0,
      ),
      'past_year' => array(
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '4',
        'delete' => 0,
      ),
    ),
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@authorships:block:organizations'] = $facet;

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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
      'force_date_range' => array(
        'status' => 0,
        'weight' => '-38',
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
    'include' => 'Weill Cornell Medical College, Cornell University',
    'limit' => 12,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'ranges' => array(
      'past_hour' => array(
        'label' => 'Past hour',
        'machine_name' => 'past_hour',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '0',
        'delete' => 0,
      ),
      'past_24_hours' => array(
        'label' => 'Past 24 hours',
        'machine_name' => 'past_24_hours',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '24',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '1',
        'delete' => 0,
      ),
      'past_week' => array(
        'label' => 'Past week',
        'machine_name' => 'past_week',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '7',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '2',
        'delete' => 0,
      ),
      'past_month' => array(
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '3',
        'delete' => 0,
      ),
      'past_year' => array(
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '4',
        'delete' => 0,
      ),
    ),
    'date_ranges' => array(
      'add_range' => 'Add a new date range',
    ),
    'format' => '-5 years',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'auto-submit-delay' => '2000',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '0.1',
    'round-precision' => '1',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'auto-submit-delay' => '2000',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@authorships:block:publication_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:block:publication_timestamp';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'block';
  $facet->facet = 'publication_timestamp';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'date_range',
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
        'status' => 1,
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
      'force_date_range' => array(
        'status' => 0,
        'weight' => '-38',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'date_ranges' => array(
      'add_range' => 'Add a new date range',
    ),
    'ranges' => array(
      'past_month' => array(
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '31',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '-10',
        'delete' => 0,
      ),
      'past_year' => array(
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '+',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '-9',
        'delete' => 0,
      ),
      'past_two_years' => array(
        'label' => 'Past two years',
        'machine_name' => 'past_two_years',
        'date_range_start_op' => '+',
        'date_range_start_amount' => '2',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '-8',
        'delete' => 0,
      ),
    ),
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
    'format' => '-5 years',
    'rewrite_items' => 1,
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
      'force_date_range' => array(
        'status' => 1,
        'weight' => '-38',
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
    'auto-submit-delay' => '2000',
    'range_simple' => '10',
    'range_advanced' => '',
    'empty_text' => array(
      'value' => 'No dates available.',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '1',
    'round-precision' => '0',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
    'format' => '-10 years',
  );
  $export['search_api@authorships:block:publication_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@authorships:facetapi_graphs_graphs:publication_graph_year';
  $facet->searcher = 'search_api@authorships';
  $facet->realm = 'facetapi_graphs_graphs';
  $facet->facet = 'publication_graph_year';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_graphs',
    'filters' => array(),
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'graphsflot' => 'bar',
    'graphsvivodashboard_flot' => 'bar',
    'empty_text' => array(
      'value' => 'No results for your query.',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@authorships:facetapi_graphs_graphs:publication_graph_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations::endpoints_target_node:field_primary_department';
  $facet->searcher = 'search_api@citations';
  $facet->realm = '';
  $facet->facet = 'endpoints_target_node:field_primary_department';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'authorship' => 0,
      ),
      'facets' => array(
        'publication_author_names' => 0,
        'publication_article_type' => 0,
        'publication_category' => 0,
        'field_author_position' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_author_names' => '',
      'facet_items_publication_article_type' => '',
      'facet_items_publication_category' => '',
      'facet_items_field_author_position' => '',
      'enabled' => 0,
      'hide' => 0,
      'single_year' => '0',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@citations::endpoints_target_node:field_primary_department'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations::field_author_position';
  $facet->searcher = 'search_api@citations';
  $facet->realm = '';
  $facet->facet = 'field_author_position';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => 50,
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'authorship' => 0,
      ),
      'facets' => array(
        'publication_author_names' => 0,
        'endpoints_target_node:field_primary_department' => 0,
        'publication_article_type' => 0,
        'publication_category' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_author_names' => '',
      'facet_items_endpoints_target_node:field_primary_department' => '',
      'facet_items_publication_article_type' => '',
      'facet_items_publication_category' => '',
      'enabled' => 0,
      'hide' => 0,
      'single_year' => '0',
    ),
    'facet_mincount' => 1,
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['search_api@citations::field_author_position'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations::organizations';
  $facet->searcher = 'search_api@citations';
  $facet->realm = '';
  $facet->facet = 'organizations';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@citations::organizations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations::publication_article_type';
  $facet->searcher = 'search_api@citations';
  $facet->realm = '';
  $facet->facet = 'publication_article_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => 50,
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'authorship' => 0,
      ),
      'facets' => array(
        'publication_author_names' => 0,
        'endpoints_target_node:field_primary_department' => 0,
        'publication_category' => 0,
        'field_author_position' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_author_names' => '',
      'facet_items_endpoints_target_node:field_primary_department' => '',
      'facet_items_publication_category' => '',
      'facet_items_field_author_position' => '',
      'enabled' => 0,
      'hide' => 0,
      'single_year' => '0',
    ),
    'facet_mincount' => 1,
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['search_api@citations::publication_article_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations::publication_author_names';
  $facet->searcher = 'search_api@citations';
  $facet->realm = '';
  $facet->facet = 'publication_author_names';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'authorship' => 0,
      ),
      'facets' => array(
        'endpoints_target_node:field_primary_department' => 0,
        'publication_article_type' => 0,
        'publication_category' => 0,
        'field_author_position' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_endpoints_target_node:field_primary_department' => '',
      'facet_items_publication_article_type' => '',
      'facet_items_publication_category' => '',
      'facet_items_field_author_position' => '',
      'enabled' => 0,
      'hide' => 0,
      'single_year' => '0',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 1,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@citations::publication_author_names'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations::publication_category';
  $facet->searcher = 'search_api@citations';
  $facet->realm = '';
  $facet->facet = 'publication_category';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => 50,
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'authorship' => 0,
      ),
      'facets' => array(
        'publication_author_names' => 0,
        'endpoints_target_node:field_primary_department' => 0,
        'publication_article_type' => 0,
        'field_author_position' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_author_names' => '',
      'facet_items_endpoints_target_node:field_primary_department' => '',
      'facet_items_publication_article_type' => '',
      'facet_items_field_author_position' => '',
      'enabled' => 0,
      'hide' => 1,
      'single_year' => '0',
    ),
    'facet_mincount' => 1,
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['search_api@citations::publication_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:endpoints_source_node';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'endpoints_source_node';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:endpoints_source_node'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:endpoints_source_node:field_citations';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'endpoints_source_node:field_citations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:endpoints_source_node:field_citations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:endpoints_target_node:field_primary_department';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'endpoints_target_node:field_primary_department';
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
      'natural' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '10',
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
  );
  $export['search_api@citations:block:endpoints_target_node:field_primary_department'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:field_author_position';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'field_author_position';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@citations:block:field_author_position'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:organizations';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'organizations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '3',
    'nofollow' => 1,
    'show_expanded' => 0,
    'ranges' => array(
      'past_hour' => array(
        'label' => 'Past hour',
        'machine_name' => 'past_hour',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '0',
        'delete' => 0,
      ),
      'past_24_hours' => array(
        'label' => 'Past 24 hours',
        'machine_name' => 'past_24_hours',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '24',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '1',
        'delete' => 0,
      ),
      'past_week' => array(
        'label' => 'Past week',
        'machine_name' => 'past_week',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '7',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '2',
        'delete' => 0,
      ),
      'past_month' => array(
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '3',
        'delete' => 0,
      ),
      'past_year' => array(
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '4',
        'delete' => 0,
      ),
    ),
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
    'date_ranges' => array(
      'add_range' => 'Add a new date range',
    ),
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@citations:block:organizations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_article_type';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_article_type';
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
    'nofollow' => 0,
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@citations:block:publication_article_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_author_affiliations';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_affiliations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_author_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_author_firstlast_affiliations';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_firstlast_affiliations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_author_firstlast_affiliations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_author_names';
  $facet->searcher = 'search_api@citations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
  );
  $export['search_api@citations:block:publication_author_names'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_author_types';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_types';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_author_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_authors_joined';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_authors_joined';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_authors_joined'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_category';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_category';
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
    'soft_limit' => '10',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@citations:block:publication_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_graph_month';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_graph_month';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_graph_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_graph_year';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_graph_year';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_graph_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_journal';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_journal';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_journal'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_journal_ranking';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_journal_ranking';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_journal_ranking'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_month';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_month';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_percentile_rank';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_percentile_rank';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_percentile_rank'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_timestamp';
  $facet->searcher = 'search_api@citations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@citations:block:publication_timestamp'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_title';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_title';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_title'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_types';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_types';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:publication_year';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'publication_year';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:publication_year'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@citations:block:search_api_language';
  $facet->searcher = 'search_api@citations';
  $facet->realm = 'block';
  $facet->facet = 'search_api_language';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@citations:block:search_api_language'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications::organizations';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'organizations';
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
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@publications::organizations'] = $facet;

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
  $facet->name = 'search_api@publications::publication_author_firstlast_affiliations';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_author_firstlast_affiliations';
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
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => 0,
    'limit_active_items' => 0,
  );
  $export['search_api@publications::publication_author_firstlast_affiliations'] = $facet;

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
    'flatten' => '0',
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
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'individual_parent' => 0,
    'limit_active_items' => 0,
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
  $facet->name = 'search_api@publications::publication_timestamp';
  $facet->searcher = 'search_api@publications';
  $facet->realm = '';
  $facet->facet = 'publication_timestamp';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'author' => 0,
        'page' => 0,
        'publication' => 0,
      ),
      'facets' => array(
        'publication_types' => 0,
        'publication_journal_ranking' => 0,
        'publication_author_names' => 0,
        'publication_author_types' => 0,
        'publication_author_firstlast_affiliations' => 0,
        'publication_author_affiliations' => 0,
        'publication_journal' => 0,
        'publication_graph_month' => 0,
        'publication_year' => 0,
        'publication_graph_year' => 0,
        'publication_month' => 0,
      ),
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_publication_types' => '',
      'facet_items_publication_journal_ranking' => '',
      'facet_items_publication_author_names' => '',
      'facet_items_publication_author_types' => '',
      'facet_items_publication_author_firstlast_affiliations' => '',
      'facet_items_publication_author_affiliations' => '',
      'facet_items_publication_journal' => '',
      'facet_items_publication_graph_month' => '',
      'facet_items_publication_year' => '',
      'facet_items_publication_graph_year' => '',
      'facet_items_publication_month' => '',
      'enabled' => 1,
      'hide' => 0,
      'single_year' => '0',
    ),
    'facet_mincount' => '0',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'date_range',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'date_granularity' => 'MINUTE',
  );
  $export['search_api@publications::publication_timestamp'] = $facet;

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
  $facet->name = 'search_api@publications:block:organizations';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'organizations';
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '3',
    'nofollow' => 1,
    'show_expanded' => 0,
    'ranges' => array(
      'past_hour' => array(
        'label' => 'Past hour',
        'machine_name' => 'past_hour',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '0',
        'delete' => 0,
      ),
      'past_24_hours' => array(
        'label' => 'Past 24 hours',
        'machine_name' => 'past_24_hours',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '24',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '1',
        'delete' => 0,
      ),
      'past_week' => array(
        'label' => 'Past week',
        'machine_name' => 'past_week',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '7',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '2',
        'delete' => 0,
      ),
      'past_month' => array(
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '3',
        'delete' => 0,
      ),
      'past_year' => array(
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '4',
        'delete' => 0,
      ),
    ),
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
    'date_ranges' => array(
      'add_range' => 'Add a new date range',
    ),
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
  );
  $export['search_api@publications:block:organizations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_author_affiliations';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_author_affiliations';
  $facet->enabled = FALSE;
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
      'empty_months' => array(
        'status' => 0,
        'weight' => '-40',
      ),
      'convert_months' => array(
        'status' => 0,
        'weight' => '-40',
      ),
      'force_date_range' => array(
        'status' => 0,
        'weight' => '-38',
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
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => 'Weill Cornell Medical College, Cornell University',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'date_ranges' => array(
      'add_range' => 'Add a new date range',
    ),
    'ranges' => array(
      'past_hour' => array(
        'label' => 'Past hour',
        'machine_name' => 'past_hour',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '0',
        'delete' => 0,
      ),
      'past_24_hours' => array(
        'label' => 'Past 24 hours',
        'machine_name' => 'past_24_hours',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '24',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '1',
        'delete' => 0,
      ),
      'past_week' => array(
        'label' => 'Past week',
        'machine_name' => 'past_week',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '7',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '2',
        'delete' => 0,
      ),
      'past_month' => array(
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '3',
        'delete' => 0,
      ),
      'past_year' => array(
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '4',
        'delete' => 0,
      ),
    ),
    'format' => '-5 years',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
        'status' => 0,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 1,
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
      'empty_months' => array(
        'status' => 0,
        'weight' => '-39',
      ),
      'force_date_range' => array(
        'status' => 0,
        'weight' => '-37',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'format' => '-5 years',
    'rewrite_items' => 1,
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'auto-submit-delay' => '2000',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'slider-step' => '0.1',
    'round-precision' => '1',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
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
    'auto-submit-delay' => '2000',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@publications:block:publication_month'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@publications:block:publication_timestamp';
  $facet->searcher = 'search_api@publications';
  $facet->realm = 'block';
  $facet->facet = 'publication_timestamp';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'date_range',
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
        'status' => 1,
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
      'force_date_range' => array(
        'status' => 0,
        'weight' => '-38',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'ranges' => array(
      'past_month' => array(
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '31',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '-10',
        'delete' => 0,
      ),
      'past_year' => array(
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '+',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '-9',
        'delete' => 0,
      ),
      'past_two_years' => array(
        'label' => 'Past two years',
        'machine_name' => 'past_two_years',
        'date_range_start_op' => '+',
        'date_range_start_amount' => '2',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '-8',
        'delete' => 0,
      ),
    ),
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
    'date_ranges' => array(
      'add_range' => 'Add a new date range',
    ),
    'empty_text' => array(
      'value' => '',
      'format' => 'filtered_html',
    ),
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
    'format' => '-5 years',
    'rewrite_items' => 1,
  );
  $export['search_api@publications:block:publication_timestamp'] = $facet;

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
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'exclude_items' => array(
        'status' => 0,
        'weight' => '-48',
      ),
      'rewrite_items' => array(
        'status' => 1,
        'weight' => '-47',
      ),
      'narrow_results' => array(
        'status' => 0,
        'weight' => '-46',
      ),
      'show_if_minimum_items' => array(
        'status' => 0,
        'weight' => '-45',
      ),
      'deepest_level_items' => array(
        'status' => 0,
        'weight' => '-44',
      ),
      'graph_combo_filter' => array(
        'status' => 0,
        'weight' => '-43',
      ),
      'include_items' => array(
        'status' => 0,
        'weight' => '-42',
      ),
      'year_limit' => array(
        'status' => 0,
        'weight' => '-41',
      ),
      'empty_years' => array(
        'status' => 0,
        'weight' => '-40',
      ),
      'empty_months' => array(
        'status' => 0,
        'weight' => '-39',
      ),
      'convert_months' => array(
        'status' => 0,
        'weight' => '-38',
      ),
      'force_date_range' => array(
        'status' => 0,
        'weight' => '-37',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'format' => '-5 years',
    'rewrite_items' => 1,
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
      'force_date_range' => array(
        'status' => 1,
        'weight' => '-38',
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
    'auto-submit-delay' => '2000',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'yfacet' => '',
    'include' => '',
    'limit' => 12,
    'format' => '-10 years',
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
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@publications:facetapi_graphs_graphs:publication_graph_year'] = $facet;

  return $export;
}
