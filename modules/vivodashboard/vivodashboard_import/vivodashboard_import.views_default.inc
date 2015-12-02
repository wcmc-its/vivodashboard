<?php
/**
 * @file
 * vivodashboard_import.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vivodashboard_import_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'import_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'feeds_log';
  $view->human_name = 'Import Log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Import log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'import vivo_publications feeds';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '100, 500, 1000, 5000';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'request_time',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'log_time_1' => 'log_time_1',
    'importer_name' => 'importer_name',
    'request_time' => 'request_time',
    'message' => 'message',
    'severity' => 'severity',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'log_time_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'importer_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'request_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'severity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Note: Log entries expire after two weeks. To locate a particular publication or author after they have been imported, use the <a href="/import/list">imported content list</a>.</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results.';
  /* Field: Feeds log: Log time */
  $handler->display->display_options['fields']['log_time_1']['id'] = 'log_time_1';
  $handler->display->display_options['fields']['log_time_1']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['log_time_1']['field'] = 'log_time';
  $handler->display->display_options['fields']['log_time_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['log_time_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['log_time_1']['custom_date_format'] = 'g:i:s';
  $handler->display->display_options['fields']['log_time_1']['second_date_format'] = 'long';
  /* Field: Feeds log: Importer name */
  $handler->display->display_options['fields']['importer_name']['id'] = 'importer_name';
  $handler->display->display_options['fields']['importer_name']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['importer_name']['field'] = 'importer_name';
  $handler->display->display_options['fields']['importer_name']['label'] = 'Importer';
  $handler->display->display_options['fields']['importer_name']['link'] = '1';
  /* Field: Feeds log: Request time */
  $handler->display->display_options['fields']['request_time']['id'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['request_time']['field'] = 'request_time';
  $handler->display->display_options['fields']['request_time']['label'] = 'Import batch started';
  $handler->display->display_options['fields']['request_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['request_time']['date_format'] = 'medium';
  $handler->display->display_options['fields']['request_time']['second_date_format'] = 'long';
  /* Field: Feeds log: Log message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = 'Message';
  /* Field: Feeds log: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  /* Sort criterion: Feeds log: Feeds log ID */
  $handler->display->display_options['sorts']['flid']['id'] = 'flid';
  $handler->display->display_options['sorts']['flid']['table'] = 'feeds_log';
  $handler->display->display_options['sorts']['flid']['field'] = 'flid';
  $handler->display->display_options['sorts']['flid']['order'] = 'DESC';
  /* Sort criterion: Feeds log: Log time */
  $handler->display->display_options['sorts']['log_time']['id'] = 'log_time';
  $handler->display->display_options['sorts']['log_time']['table'] = 'feeds_log';
  $handler->display->display_options['sorts']['log_time']['field'] = 'log_time';
  $handler->display->display_options['sorts']['log_time']['order'] = 'DESC';
  /* Filter criterion: Feeds log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'feeds_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['group'] = 1;
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator_id'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  $handler->display->display_options['filters']['severity']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'allwords';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'importer_name' => 'importer_name',
    'message' => 'message',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'import/log';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Log';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['import_log'] = $view;

  $view = new view();
  $view->name = 'journal_rankings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Journal Rankings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publication Journals';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations_1' => 'views_bulk_operations_1',
    'name' => 'name',
    'field_issn' => 'field_issn',
    'field_ranking' => 'field_ranking',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_issn' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ranking' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'This page lets you update journal rankings for journal taxonomy terms in bulk after new <a href="/admin/structure/taxonomy/journal_rankings/imported">ranking data</a> has been imported.

After updating the journals, you must re-index <a href="/admin/config/search/search_api/index/publications">publications</a> and <a href="/admin/config/search/search_api/index/authorships">authorships</a> before facets will show the new rankings.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Bulk operations: Taxonomy term */
  $handler->display->display_options['fields']['views_bulk_operations_1']['id'] = 'views_bulk_operations_1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['views_bulk_operations_1']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['entity_load_capacity'] = '50';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Update Ranking',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'description' => 'description',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::vivodashboard_core_term_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Update ranking',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Journal term';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Taxonomy term: ISSN */
  $handler->display->display_options['fields']['field_issn']['id'] = 'field_issn';
  $handler->display->display_options['fields']['field_issn']['table'] = 'field_data_field_issn';
  $handler->display->display_options['fields']['field_issn']['field'] = 'field_issn';
  /* Field: Taxonomy term: Ranking */
  $handler->display->display_options['fields']['field_ranking']['id'] = 'field_ranking';
  $handler->display->display_options['fields']['field_ranking']['table'] = 'field_data_field_ranking';
  $handler->display->display_options['fields']['field_ranking']['field'] = 'field_ranking';
  $handler->display->display_options['fields']['field_ranking']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'journals' => 'journals',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: ISSN (field_issn) */
  $handler->display->display_options['filters']['field_issn_value_1']['id'] = 'field_issn_value_1';
  $handler->display->display_options['filters']['field_issn_value_1']['table'] = 'field_data_field_issn';
  $handler->display->display_options['filters']['field_issn_value_1']['field'] = 'field_issn_value';
  $handler->display->display_options['filters']['field_issn_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_issn_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_issn_value_1']['expose']['operator_id'] = 'field_issn_value_1_op';
  $handler->display->display_options['filters']['field_issn_value_1']['expose']['label'] = 'ISSN (field_issn)';
  $handler->display->display_options['filters']['field_issn_value_1']['expose']['operator'] = 'field_issn_value_1_op';
  $handler->display->display_options['filters']['field_issn_value_1']['expose']['identifier'] = 'field_issn_value_1';
  $handler->display->display_options['filters']['field_issn_value_1']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_issn_value_1']['group_info']['label'] = 'Has ISSN';
  $handler->display->display_options['filters']['field_issn_value_1']['group_info']['identifier'] = 'issn';
  $handler->display->display_options['filters']['field_issn_value_1']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_issn_value_1']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Yes',
      'operator' => 'not empty',
      'value' => ' value',
    ),
    2 => array(
      'title' => 'No',
      'operator' => 'empty',
      'value' => 'value',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );

  /* Display: Publication Journals */
  $handler = $view->new_display('page', 'Publication Journals', 'page');
  $handler->display->display_options['path'] = 'admin/structure/taxonomy/journal_rankings/update';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Journal Rankings: Bulk Update';
  $handler->display->display_options['menu']['weight'] = '-30';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Ranking Data */
  $handler = $view->new_display('page', 'Ranking Data', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ranking Data';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'This page lists all of the journal ranking data that has been <a href="/import/journal_rankings">imported</a>. ';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Journal';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Feeds item: Item GUID */
  $handler->display->display_options['fields']['guid']['id'] = 'guid';
  $handler->display->display_options['fields']['guid']['table'] = 'feeds_item';
  $handler->display->display_options['fields']['guid']['field'] = 'guid';
  $handler->display->display_options['fields']['guid']['label'] = 'ISSN';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Ranking';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'journal_rankings' => 'journal_rankings',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'allwords';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Journal';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Feeds item: Item GUID */
  $handler->display->display_options['filters']['guid']['id'] = 'guid';
  $handler->display->display_options['filters']['guid']['table'] = 'feeds_item';
  $handler->display->display_options['filters']['guid']['field'] = 'guid';
  $handler->display->display_options['filters']['guid']['operator'] = 'contains';
  $handler->display->display_options['filters']['guid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['guid']['expose']['operator_id'] = 'guid_op';
  $handler->display->display_options['filters']['guid']['expose']['label'] = 'ISSN';
  $handler->display->display_options['filters']['guid']['expose']['operator'] = 'guid_op';
  $handler->display->display_options['filters']['guid']['expose']['identifier'] = 'guid';
  $handler->display->display_options['filters']['guid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'admin/structure/taxonomy/journal_rankings/imported';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Journal Rankings: Imported';
  $handler->display->display_options['menu']['weight'] = '-40';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Imported';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $export['journal_rankings'] = $view;

  return $export;
}
