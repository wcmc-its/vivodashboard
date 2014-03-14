<?php
/**
 * @file
 * vivodashboard_publications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vivodashboard_publications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'publications_export_csv';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_authorships';
  $view->human_name = 'Publications: Export (CSV)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['css_class'] = 'view-large-table view-publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items: ';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 30, 40, 50, 60, 70, 80, 90, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_author_rank' => 'field_author_rank',
    'field_author_position' => 'field_author_position',
    'field_rdf_type' => 'field_rdf_type',
    'field_department' => 'field_department',
    'name' => 'name',
    'field_date' => 'field_date',
    'title' => 'title',
    'field_volume' => 'field_volume',
    'field_issue' => 'field_issue',
    'field_rdf_type_1' => 'field_rdf_type_1',
    'field_page_end' => 'field_page_end',
    'field_page_start' => 'field_page_start',
    'field_doi' => 'field_doi',
    'field_pmid' => 'field_pmid',
    'field_pmcid' => 'field_pmcid',
    'field_funding' => 'field_funding',
    'field_uri' => 'field_uri',
    'field_citations' => 'field_citations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_last_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author_rank' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author_position' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rdf_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_department' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_volume' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_issue' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_rdf_type_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_page_end' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_page_start' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_doi' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pmid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pmcid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_funding' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uri' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_citations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results for your query.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Indexed Relation: node (source endpoint) */
  $handler->display->display_options['relationships']['endpoints_source_node']['id'] = 'endpoints_source_node';
  $handler->display->display_options['relationships']['endpoints_source_node']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['relationships']['endpoints_source_node']['field'] = 'endpoints_source_node';
  $handler->display->display_options['relationships']['endpoints_source_node']['label'] = 'Publication';
  /* Relationship: Indexed Relation: node (target endpoint) */
  $handler->display->display_options['relationships']['endpoints_target_node']['id'] = 'endpoints_target_node';
  $handler->display->display_options['relationships']['endpoints_target_node']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['relationships']['endpoints_target_node']['field'] = 'endpoints_target_node';
  $handler->display->display_options['relationships']['endpoints_target_node']['label'] = 'Author';
  /* Relationship: Node: Journal */
  $handler->display->display_options['relationships']['field_journal']['id'] = 'field_journal';
  $handler->display->display_options['relationships']['field_journal']['table'] = 'entity_node';
  $handler->display->display_options['relationships']['field_journal']['field'] = 'field_journal';
  $handler->display->display_options['relationships']['field_journal']['relationship'] = 'endpoints_source_node';
  /* Field: Node: ID */
  $handler->display->display_options['fields']['field_id']['id'] = 'field_id';
  $handler->display->display_options['fields']['field_id']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_id']['field'] = 'field_id';
  $handler->display->display_options['fields']['field_id']['relationship'] = 'endpoints_target_node';
  $handler->display->display_options['fields']['field_id']['label'] = 'Author CWID';
  /* Field: Node: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'endpoints_target_node';
  /* Field: Node: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'endpoints_target_node';
  /* Field: Indexed Relation: Author Rank */
  $handler->display->display_options['fields']['field_author_rank']['id'] = 'field_author_rank';
  $handler->display->display_options['fields']['field_author_rank']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['fields']['field_author_rank']['field'] = 'field_author_rank';
  $handler->display->display_options['fields']['field_author_rank']['label'] = 'Author rank';
  $handler->display->display_options['fields']['field_author_rank']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Indexed Relation: Author Position */
  $handler->display->display_options['fields']['field_author_position']['id'] = 'field_author_position';
  $handler->display->display_options['fields']['field_author_position']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['fields']['field_author_position']['field'] = 'field_author_position';
  $handler->display->display_options['fields']['field_author_position']['label'] = 'Author position';
  /* Field: Node: RDF Type */
  $handler->display->display_options['fields']['field_rdf_type']['id'] = 'field_rdf_type';
  $handler->display->display_options['fields']['field_rdf_type']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_rdf_type']['field'] = 'field_rdf_type';
  $handler->display->display_options['fields']['field_rdf_type']['relationship'] = 'endpoints_target_node';
  $handler->display->display_options['fields']['field_rdf_type']['label'] = 'Person type';
  $handler->display->display_options['fields']['field_rdf_type']['list']['separator'] = ';';
  $handler->display->display_options['fields']['field_rdf_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_rdf_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_rdf_type']['bypass_access'] = 0;
  /* Field: Node: Primary Department */
  $handler->display->display_options['fields']['field_primary_department']['id'] = 'field_primary_department';
  $handler->display->display_options['fields']['field_primary_department']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_primary_department']['field'] = 'field_primary_department';
  $handler->display->display_options['fields']['field_primary_department']['relationship'] = 'endpoints_target_node';
  $handler->display->display_options['fields']['field_primary_department']['label'] = 'Department with primary affiliation';
  $handler->display->display_options['fields']['field_primary_department']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_primary_department']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_primary_department']['bypass_access'] = 0;
  /* Field: Node: Primary Institution */
  $handler->display->display_options['fields']['field_primary_institution']['id'] = 'field_primary_institution';
  $handler->display->display_options['fields']['field_primary_institution']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_primary_institution']['field'] = 'field_primary_institution';
  $handler->display->display_options['fields']['field_primary_institution']['relationship'] = 'endpoints_target_node';
  $handler->display->display_options['fields']['field_primary_institution']['label'] = 'Primary institutional affiliation';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_journal';
  $handler->display->display_options['fields']['name']['label'] = 'Journal title';
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Node: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'year_month_day',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Node: Full Title */
  $handler->display->display_options['fields']['field_full_title']['id'] = 'field_full_title';
  $handler->display->display_options['fields']['field_full_title']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_full_title']['field'] = 'field_full_title';
  $handler->display->display_options['fields']['field_full_title']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_full_title']['label'] = 'Article title';
  /* Field: Node: Volume */
  $handler->display->display_options['fields']['field_volume']['id'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_volume']['field'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['relationship'] = 'endpoints_source_node';
  /* Field: Node: Issue */
  $handler->display->display_options['fields']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['relationship'] = 'endpoints_source_node';
  /* Field: Node: RDF Type */
  $handler->display->display_options['fields']['field_rdf_type_1']['id'] = 'field_rdf_type_1';
  $handler->display->display_options['fields']['field_rdf_type_1']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_rdf_type_1']['field'] = 'field_rdf_type';
  $handler->display->display_options['fields']['field_rdf_type_1']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_rdf_type_1']['label'] = 'Publication type';
  $handler->display->display_options['fields']['field_rdf_type_1']['list']['mode'] = 'first';
  $handler->display->display_options['fields']['field_rdf_type_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_rdf_type_1']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_rdf_type_1']['bypass_access'] = 0;
  /* Field: Node: Page End */
  $handler->display->display_options['fields']['field_page_end']['id'] = 'field_page_end';
  $handler->display->display_options['fields']['field_page_end']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_page_end']['field'] = 'field_page_end';
  $handler->display->display_options['fields']['field_page_end']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_page_end']['label'] = '';
  $handler->display->display_options['fields']['field_page_end']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['alter']['text'] = '-[field_page_end-value]';
  $handler->display->display_options['fields']['field_page_end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_end']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Node: Page Start */
  $handler->display->display_options['fields']['field_page_start']['id'] = 'field_page_start';
  $handler->display->display_options['fields']['field_page_start']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_page_start']['field'] = 'field_page_start';
  $handler->display->display_options['fields']['field_page_start']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_page_start']['label'] = 'Page range';
  $handler->display->display_options['fields']['field_page_start']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_page_start']['alter']['text'] = '[field_page_start-value][field_page_end]';
  $handler->display->display_options['fields']['field_page_start']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Node: DOI */
  $handler->display->display_options['fields']['field_doi']['id'] = 'field_doi';
  $handler->display->display_options['fields']['field_doi']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_doi']['field'] = 'field_doi';
  $handler->display->display_options['fields']['field_doi']['relationship'] = 'endpoints_source_node';
  /* Field: Node: PMID */
  $handler->display->display_options['fields']['field_pmid']['id'] = 'field_pmid';
  $handler->display->display_options['fields']['field_pmid']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_pmid']['field'] = 'field_pmid';
  $handler->display->display_options['fields']['field_pmid']['relationship'] = 'endpoints_source_node';
  /* Field: Node: PMCID */
  $handler->display->display_options['fields']['field_pmcid']['id'] = 'field_pmcid';
  $handler->display->display_options['fields']['field_pmcid']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_pmcid']['field'] = 'field_pmcid';
  $handler->display->display_options['fields']['field_pmcid']['relationship'] = 'endpoints_source_node';
  /* Field: Node: Funding */
  $handler->display->display_options['fields']['field_funding']['id'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_funding']['field'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_funding']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_funding']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_funding']['bypass_access'] = 0;
  /* Field: Node: VIVO URI */
  $handler->display->display_options['fields']['field_uri']['id'] = 'field_uri';
  $handler->display->display_options['fields']['field_uri']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_uri']['field'] = 'field_uri';
  $handler->display->display_options['fields']['field_uri']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_uri']['label'] = 'URL';
  $handler->display->display_options['fields']['field_uri']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_uri']['type'] = 'link_plain';
  /* Field: Node: Citations */
  $handler->display->display_options['fields']['field_citations']['id'] = 'field_citations';
  $handler->display->display_options['fields']['field_citations']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_citations']['field'] = 'field_citations';
  $handler->display->display_options['fields']['field_citations']['relationship'] = 'endpoints_source_node';
  $handler->display->display_options['fields']['field_citations']['label'] = 'Citation count';
  /* Sort criterion: Indexed Relation: Publication Timestamp */
  $handler->display->display_options['sorts']['publication_timestamp']['id'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['sorts']['publication_timestamp']['field'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['order'] = 'DESC';
  /* Sort criterion: Indexed Relation: Publication Title */
  $handler->display->display_options['sorts']['publication_title']['id'] = 'publication_title';
  $handler->display->display_options['sorts']['publication_title']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['sorts']['publication_title']['field'] = 'publication_title';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_author_rank']['id'] = 'field_author_rank';
  $handler->display->display_options['sorts']['field_author_rank']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['sorts']['field_author_rank']['field'] = 'field_author_rank';
  /* Filter criterion: Indexed Relation: Publication Author Types */
  $handler->display->display_options['filters']['publication_author_types']['id'] = 'publication_author_types';
  $handler->display->display_options['filters']['publication_author_types']['table'] = 'search_api_index_authorships';
  $handler->display->display_options['filters']['publication_author_types']['field'] = 'publication_author_types';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publications/export/csv';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'CSV';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Export';
  $handler->display->display_options['tab_options']['weight'] = '10';

  /* Display: Download */
  $handler = $view->new_display('views_data_export', 'Download', 'download');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'VIVO Dashboard Publications %timestamp-mmm %timestamp-dd %timestamp-yyyy.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'publications/export/csv/download';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $handler->display->display_options['return_path'] = 'publications/export/csv';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Download all */
  $handler = $view->new_display('views_data_export', 'Download all', 'download_all');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'VIVO Dashboard Publications %timestamp-mmm %timestamp-dd %timestamp-yyyy.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'publications/export/csv/download/all';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'publications/export/csv';
  $handler->display->display_options['segment_size'] = '100';
  $export['publications_export_csv'] = $view;

  $view = new view();
  $view->name = 'publications_export_doc';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_publications';
  $view->human_name = 'Publications: Export (DOC)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['css_class'] = 'view-publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items: ';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 30, 40, 50, 60, 70, 80, 90, 100';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'publication-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results for your query.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Node: Author Labels */
  $handler->display->display_options['fields']['author_labels']['id'] = 'author_labels';
  $handler->display->display_options['fields']['author_labels']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['author_labels']['field'] = 'author_labels';
  $handler->display->display_options['fields']['author_labels']['label'] = '';
  $handler->display->display_options['fields']['author_labels']['exclude'] = TRUE;
  $handler->display->display_options['fields']['author_labels']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author_labels']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['author_labels']['ending_period'] = 1;
  /* Field: Indexed Node: VIVO URI » The URL of the link. */
  $handler->display->display_options['fields']['field_uri_url']['id'] = 'field_uri_url';
  $handler->display->display_options['fields']['field_uri_url']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_uri_url']['field'] = 'field_uri_url';
  $handler->display->display_options['fields']['field_uri_url']['label'] = '';
  $handler->display->display_options['fields']['field_uri_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uri_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uri_url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['field_uri_url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Full Title */
  $handler->display->display_options['fields']['field_full_title']['id'] = 'field_full_title';
  $handler->display->display_options['fields']['field_full_title']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_full_title']['field'] = 'field_full_title';
  $handler->display->display_options['fields']['field_full_title']['label'] = '';
  $handler->display->display_options['fields']['field_full_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_full_title']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_full_title']['ending_period'] = 1;
  /* Field: Indexed Node: Journal */
  $handler->display->display_options['fields']['field_journal']['id'] = 'field_journal';
  $handler->display->display_options['fields']['field_journal']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_journal']['field'] = 'field_journal';
  $handler->display->display_options['fields']['field_journal']['label'] = '';
  $handler->display->display_options['fields']['field_journal']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_journal']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_journal']['alter']['text'] = '<em>[field_journal]</em>.';
  $handler->display->display_options['fields']['field_journal']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_journal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_journal']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_journal']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_journal']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_journal']['bypass_access'] = 0;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'year_month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Node: Issue */
  $handler->display->display_options['fields']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['label'] = '';
  $handler->display->display_options['fields']['field_issue']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['alter']['text'] = '([field_issue])';
  $handler->display->display_options['fields']['field_issue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue']['hide_empty'] = TRUE;
  /* Field: Indexed Node: Volume */
  $handler->display->display_options['fields']['field_volume']['id'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_volume']['field'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['label'] = '';
  $handler->display->display_options['fields']['field_volume']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_volume']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_volume']['alter']['text'] = '[field_volume][field_issue]:';
  $handler->display->display_options['fields']['field_volume']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Page End */
  $handler->display->display_options['fields']['field_page_end']['id'] = 'field_page_end';
  $handler->display->display_options['fields']['field_page_end']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_page_end']['field'] = 'field_page_end';
  $handler->display->display_options['fields']['field_page_end']['label'] = '';
  $handler->display->display_options['fields']['field_page_end']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['alter']['text'] = '-[field_page_end]';
  $handler->display->display_options['fields']['field_page_end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_end']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Indexed Node: Page Start */
  $handler->display->display_options['fields']['field_page_start']['id'] = 'field_page_start';
  $handler->display->display_options['fields']['field_page_start']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_page_start']['field'] = 'field_page_start';
  $handler->display->display_options['fields']['field_page_start']['label'] = '';
  $handler->display->display_options['fields']['field_page_start']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_start']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_page_start']['alter']['text'] = '; [field_volume][field_page_start][field_page_end]';
  $handler->display->display_options['fields']['field_page_start']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_start']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_page_start']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[author_labels] [field_full_title] [field_journal] [field_date][field_page_start].';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed Node: Publication Timestamp */
  $handler->display->display_options['sorts']['publication_timestamp']['id'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['table'] = 'search_api_index_publications';
  $handler->display->display_options['sorts']['publication_timestamp']['field'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Publication Title */
  $handler->display->display_options['sorts']['publication_title']['id'] = 'publication_title';
  $handler->display->display_options['sorts']['publication_title']['table'] = 'search_api_index_publications';
  $handler->display->display_options['sorts']['publication_title']['field'] = 'publication_title';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publications/export/doc';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'DOC';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Download */
  $handler = $view->new_display('views_data_export', 'Download', 'download');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'VIVO Dashboard Publications %timestamp-mmm %timestamp-dd %timestamp-yyyy.doc';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'publications/export/doc/download';

  /* Display: Download all */
  $handler = $view->new_display('views_data_export', 'Download all', 'download_all');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'VIVO Dashboard Publications %timestamp-mmm %timestamp-dd %timestamp-yyyy.doc';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'publications/export/doc/download/all';
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'publications/export/doc';
  $handler->display->display_options['segment_size'] = '100';
  $export['publications_export_doc'] = $view;

  $view = new view();
  $view->name = 'publications_graph';
  $view->description = 'Used only to activate facets. The result of this view gets hidden in code.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_publications';
  $view->human_name = 'Publications: Graph';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['css_class'] = 'view-publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '1';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '<p>Total: @total</p>';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publications/graph';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Graph';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Publications';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['publications_graph'] = $view;

  $view = new view();
  $view->name = 'publications_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_publications';
  $view->human_name = 'Publications: List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['css_class'] = 'view-publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'publication-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Results @start - @end of @total';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results for your query.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Indexed Node: Authors */
  $handler->display->display_options['relationships']['authors']['id'] = 'authors';
  $handler->display->display_options['relationships']['authors']['table'] = 'search_api_index_publications';
  $handler->display->display_options['relationships']['authors']['field'] = 'authors';
  /* Field: Indexed Node: Authorships */
  $handler->display->display_options['fields']['authorships']['id'] = 'authorships';
  $handler->display->display_options['fields']['authorships']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['authorships']['field'] = 'authorships';
  $handler->display->display_options['fields']['authorships']['label'] = '';
  $handler->display->display_options['fields']['authorships']['exclude'] = TRUE;
  $handler->display->display_options['fields']['authorships']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['authorships']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['authorships']['bypass_access'] = 0;
  $handler->display->display_options['fields']['authorships']['vivo_link'] = 1;
  $handler->display->display_options['fields']['authorships']['vivo_namespace'] = 'http://vivo.med.cornell.edu/individual/cwid-';
  $handler->display->display_options['fields']['authorships']['ending_period'] = 1;
  /* Field: Indexed Node: VIVO URI » The URL of the link. */
  $handler->display->display_options['fields']['field_uri_url']['id'] = 'field_uri_url';
  $handler->display->display_options['fields']['field_uri_url']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_uri_url']['field'] = 'field_uri_url';
  $handler->display->display_options['fields']['field_uri_url']['label'] = '';
  $handler->display->display_options['fields']['field_uri_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uri_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uri_url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['field_uri_url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title].';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_uri_url]';
  $handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['title']['ending_period'] = 1;
  /* Field: Indexed Node: Full Title */
  $handler->display->display_options['fields']['field_full_title']['id'] = 'field_full_title';
  $handler->display->display_options['fields']['field_full_title']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_full_title']['field'] = 'field_full_title';
  $handler->display->display_options['fields']['field_full_title']['label'] = '';
  $handler->display->display_options['fields']['field_full_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_title']['alter']['path'] = '[field_uri_url]';
  $handler->display->display_options['fields']['field_full_title']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_full_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_full_title']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_full_title']['ending_period'] = 1;
  /* Field: Indexed Node: Journal */
  $handler->display->display_options['fields']['field_journal']['id'] = 'field_journal';
  $handler->display->display_options['fields']['field_journal']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_journal']['field'] = 'field_journal';
  $handler->display->display_options['fields']['field_journal']['label'] = '';
  $handler->display->display_options['fields']['field_journal']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_journal']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_journal']['alter']['text'] = '<em>[field_journal].</em>';
  $handler->display->display_options['fields']['field_journal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_journal']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_journal']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_journal']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_journal']['bypass_access'] = 0;
  /* Field: Indexed Node: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['text'] = '[field_date]';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'year_month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Node: Issue */
  $handler->display->display_options['fields']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['label'] = '';
  $handler->display->display_options['fields']['field_issue']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['alter']['text'] = '([field_issue])';
  $handler->display->display_options['fields']['field_issue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue']['hide_empty'] = TRUE;
  /* Field: Indexed Node: Volume */
  $handler->display->display_options['fields']['field_volume']['id'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_volume']['field'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['label'] = '';
  $handler->display->display_options['fields']['field_volume']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_volume']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_volume']['alter']['text'] = '[field_volume][field_issue]:';
  $handler->display->display_options['fields']['field_volume']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Page End */
  $handler->display->display_options['fields']['field_page_end']['id'] = 'field_page_end';
  $handler->display->display_options['fields']['field_page_end']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_page_end']['field'] = 'field_page_end';
  $handler->display->display_options['fields']['field_page_end']['label'] = '';
  $handler->display->display_options['fields']['field_page_end']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['alter']['text'] = '-[field_page_end]';
  $handler->display->display_options['fields']['field_page_end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_end']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_page_end']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Indexed Node: Page Start */
  $handler->display->display_options['fields']['field_page_start']['id'] = 'field_page_start';
  $handler->display->display_options['fields']['field_page_start']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_page_start']['field'] = 'field_page_start';
  $handler->display->display_options['fields']['field_page_start']['label'] = '';
  $handler->display->display_options['fields']['field_page_start']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_start']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_page_start']['alter']['text'] = '; [field_volume][field_page_start][field_page_end]';
  $handler->display->display_options['fields']['field_page_start']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_start']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_page_start']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[authorships] [field_full_title] [field_journal] [field_date][field_page_start].';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Indexed Node: RDF Type */
  $handler->display->display_options['fields']['field_rdf_type']['id'] = 'field_rdf_type';
  $handler->display->display_options['fields']['field_rdf_type']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_rdf_type']['field'] = 'field_rdf_type';
  $handler->display->display_options['fields']['field_rdf_type']['label'] = '';
  $handler->display->display_options['fields']['field_rdf_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rdf_type']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_rdf_type']['element_wrapper_class'] = 'publication-type';
  $handler->display->display_options['fields']['field_rdf_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rdf_type']['list']['mode'] = 'first';
  $handler->display->display_options['fields']['field_rdf_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_rdf_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_rdf_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Citations */
  $handler->display->display_options['fields']['field_citations']['id'] = 'field_citations';
  $handler->display->display_options['fields']['field_citations']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_citations']['field'] = 'field_citations';
  $handler->display->display_options['fields']['field_citations']['label'] = 'Times cited';
  $handler->display->display_options['fields']['field_citations']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_citations']['element_wrapper_class'] = 'citations';
  $handler->display->display_options['fields']['field_citations']['element_default_classes'] = FALSE;
  /* Sort criterion: Indexed Node: Publication Timestamp */
  $handler->display->display_options['sorts']['publication_timestamp']['id'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['table'] = 'search_api_index_publications';
  $handler->display->display_options['sorts']['publication_timestamp']['field'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Publication Title */
  $handler->display->display_options['sorts']['publication_title']['id'] = 'publication_title';
  $handler->display->display_options['sorts']['publication_title']['table'] = 'search_api_index_publications';
  $handler->display->display_options['sorts']['publication_title']['field'] = 'publication_title';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publications/list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['publications_list'] = $view;

  return $export;
}
