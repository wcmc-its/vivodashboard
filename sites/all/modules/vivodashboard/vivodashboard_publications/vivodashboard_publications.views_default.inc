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
  $view->name = 'citations_chart';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_citations';
  $view->human_name = 'Citations: Chart';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Citations Chart';
  $handler->display->display_options['css_class'] = 'view-large-table view-publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'vivo_search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '86400';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '86400';
  $handler->display->display_options['cache']['index_purge'] = 0;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_id' => 'field_id',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_author_rank' => 'field_author_rank',
    'field_author_position' => 'field_author_position',
    'field_rdf_type' => 'field_rdf_type',
    'field_department' => 'field_department',
    'name' => 'name',
    'field_date' => 'field_date',
    'title' => 'title',
    'field_article_type' => 'field_article_type',
    'field_category' => 'field_category',
    'field_percentile_rank' => 'field_percentile_rank',
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
    'field_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
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
    'field_article_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_percentile_rank' => array(
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
  $handler->display->display_options['relationships']['endpoints_source_node']['table'] = 'search_api_index_citations';
  $handler->display->display_options['relationships']['endpoints_source_node']['field'] = 'endpoints_source_node';
  $handler->display->display_options['relationships']['endpoints_source_node']['label'] = 'Publication';
  /* Relationship: Indexed Relation: node (target endpoint) */
  $handler->display->display_options['relationships']['endpoints_target_node']['id'] = 'endpoints_target_node';
  $handler->display->display_options['relationships']['endpoints_target_node']['table'] = 'search_api_index_citations';
  $handler->display->display_options['relationships']['endpoints_target_node']['field'] = 'endpoints_target_node';
  $handler->display->display_options['relationships']['endpoints_target_node']['label'] = 'Author';
  /* Relationship: Node: Journal */
  $handler->display->display_options['relationships']['field_journal']['id'] = 'field_journal';
  $handler->display->display_options['relationships']['field_journal']['table'] = 'entity_node';
  $handler->display->display_options['relationships']['field_journal']['field'] = 'field_journal';
  $handler->display->display_options['relationships']['field_journal']['relationship'] = 'endpoints_source_node';
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
  /* Field: Indexed Relation: Author Position */
  $handler->display->display_options['fields']['field_author_position']['id'] = 'field_author_position';
  $handler->display->display_options['fields']['field_author_position']['table'] = 'search_api_index_citations';
  $handler->display->display_options['fields']['field_author_position']['field'] = 'field_author_position';
  $handler->display->display_options['fields']['field_author_position']['label'] = 'Author position';
  /* Field: Node: Article Type */
  $handler->display->display_options['fields']['field_article_type']['id'] = 'field_article_type';
  $handler->display->display_options['fields']['field_article_type']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_article_type']['field'] = 'field_article_type';
  $handler->display->display_options['fields']['field_article_type']['relationship'] = 'endpoints_source_node';
  /* Field: Node: Category */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['relationship'] = 'endpoints_source_node';
  /* Field: Node: Percentile Rank */
  $handler->display->display_options['fields']['field_percentile_rank']['id'] = 'field_percentile_rank';
  $handler->display->display_options['fields']['field_percentile_rank']['table'] = 'entity_node';
  $handler->display->display_options['fields']['field_percentile_rank']['field'] = 'field_percentile_rank';
  $handler->display->display_options['fields']['field_percentile_rank']['relationship'] = 'endpoints_source_node';
  /* Sort criterion: Indexed Relation: Publication Timestamp */
  $handler->display->display_options['sorts']['publication_timestamp']['id'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['table'] = 'search_api_index_citations';
  $handler->display->display_options['sorts']['publication_timestamp']['field'] = 'publication_timestamp';
  $handler->display->display_options['sorts']['publication_timestamp']['order'] = 'DESC';
  /* Sort criterion: Indexed Relation: Publication Title */
  $handler->display->display_options['sorts']['publication_title']['id'] = 'publication_title';
  $handler->display->display_options['sorts']['publication_title']['table'] = 'search_api_index_citations';
  $handler->display->display_options['sorts']['publication_title']['field'] = 'publication_title';
  /* Filter criterion: Indexed Relation: Publication Percentile Rank */
  $handler->display->display_options['filters']['publication_percentile_rank']['id'] = 'publication_percentile_rank';
  $handler->display->display_options['filters']['publication_percentile_rank']['table'] = 'search_api_index_citations';
  $handler->display->display_options['filters']['publication_percentile_rank']['field'] = 'publication_percentile_rank';
  $handler->display->display_options['filters']['publication_percentile_rank']['operator'] = 'not empty';
  /* Filter criterion: node (source endpoint): Citations (indexed) */
  $handler->display->display_options['filters']['endpoints_source_node_field_citations']['id'] = 'endpoints_source_node_field_citations';
  $handler->display->display_options['filters']['endpoints_source_node_field_citations']['table'] = 'search_api_index_citations';
  $handler->display->display_options['filters']['endpoints_source_node_field_citations']['field'] = 'endpoints_source_node_field_citations';
  $handler->display->display_options['filters']['endpoints_source_node_field_citations']['operator'] = '>';
  $handler->display->display_options['filters']['endpoints_source_node_field_citations']['value'] = '0';
  /* Filter criterion: Indexed Relation: Publication Year */
  $handler->display->display_options['filters']['publication_year']['id'] = 'publication_year';
  $handler->display->display_options['filters']['publication_year']['table'] = 'search_api_index_citations';
  $handler->display->display_options['filters']['publication_year']['field'] = 'publication_year';
  $handler->display->display_options['filters']['publication_year']['operator'] = '>=';
  $handler->display->display_options['filters']['publication_year']['value'] = '0';
  /* Filter criterion: Indexed Relation: Publication Year */
  $handler->display->display_options['filters']['publication_year_1']['id'] = 'publication_year_1';
  $handler->display->display_options['filters']['publication_year_1']['table'] = 'search_api_index_citations';
  $handler->display->display_options['filters']['publication_year_1']['field'] = 'publication_year';
  $handler->display->display_options['filters']['publication_year_1']['operator'] = '<=';
  $handler->display->display_options['filters']['publication_year_1']['value'] = '5000';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'citations/chart';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'CSV';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Export';
  $handler->display->display_options['tab_options']['weight'] = '10';
  $export['citations_chart'] = $view;

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
  $handler->display->display_options['cache']['type'] = 'vivo_search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
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
  /* Field: Indexed Relation: First/Last Author Position */
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
  /* Field: Relation: Organization */
  $handler->display->display_options['fields']['organization_list']['id'] = 'organization_list';
  $handler->display->display_options['fields']['organization_list']['table'] = 'views_entity_relation';
  $handler->display->display_options['fields']['organization_list']['field'] = 'organization_list';
  $handler->display->display_options['fields']['organization_list']['label'] = 'Organizations';
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
  $handler->display->display_options['filters']['publication_author_types']['operator'] = 'not empty';
  $handler->display->display_options['filters']['publication_author_types']['value'] = array();

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'publications/export/csv';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'CSV';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Export';
  $handler->display->display_options['tab_options']['weight'] = '3';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

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
  $handler->display->display_options['cache']['type'] = 'vivo_search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['index_purge'] = 0;
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
  $handler->display->display_options['path'] = 'publications';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Graph';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
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
  $handler->display->display_options['cache']['type'] = 'vivo_search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['index_purge'] = 0;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '60';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 30, 40, 50, 60, 70, 80, 90, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
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
  /* Field: Indexed Node: Authorships */
  $handler->display->display_options['fields']['authorships']['id'] = 'authorships';
  $handler->display->display_options['fields']['authorships']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['authorships']['field'] = 'authorships';
  $handler->display->display_options['fields']['authorships']['label'] = '';
  $handler->display->display_options['fields']['authorships']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['authorships']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['authorships']['bypass_access'] = 0;
  $handler->display->display_options['fields']['authorships']['vivo_link'] = 1;
  $handler->display->display_options['fields']['authorships']['vivo_namespace'] = 'http://vivo.med.cornell.edu/individual/cwid-';
  $handler->display->display_options['fields']['authorships']['ending_period'] = 0;
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
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
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
  /* Field: Indexed Node: PMID */
  $handler->display->display_options['fields']['field_pmid']['id'] = 'field_pmid';
  $handler->display->display_options['fields']['field_pmid']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_pmid']['field'] = 'field_pmid';
  $handler->display->display_options['fields']['field_pmid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pmid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pmid']['alter']['text'] = '<div class="field-pmid">PMID <span><a href="https://www.ncbi.nlm.nih.gov/pubmed/[field_pmid]" target="_blank">[field_pmid]</a></span></div>';
  /* Field: Indexed Node: PMCID */
  $handler->display->display_options['fields']['field_pmcid']['id'] = 'field_pmcid';
  $handler->display->display_options['fields']['field_pmcid']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_pmcid']['field'] = 'field_pmcid';
  $handler->display->display_options['fields']['field_pmcid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pmcid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pmcid']['alter']['text'] = '; PMCID: [field_pmcid]';
  /* Field: Indexed Node: RDF Type */
  $handler->display->display_options['fields']['field_rdf_type']['id'] = 'field_rdf_type';
  $handler->display->display_options['fields']['field_rdf_type']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_rdf_type']['field'] = 'field_rdf_type';
  $handler->display->display_options['fields']['field_rdf_type']['label'] = '';
  $handler->display->display_options['fields']['field_rdf_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rdf_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rdf_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rdf_type']['list']['mode'] = 'first';
  $handler->display->display_options['fields']['field_rdf_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_rdf_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_rdf_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Scopus ID */
  $handler->display->display_options['fields']['field_scopus_id']['id'] = 'field_scopus_id';
  $handler->display->display_options['fields']['field_scopus_id']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_scopus_id']['field'] = 'field_scopus_id';
  $handler->display->display_options['fields']['field_scopus_id']['label'] = '';
  $handler->display->display_options['fields']['field_scopus_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_scopus_id']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Citations */
  $handler->display->display_options['fields']['field_citations']['id'] = 'field_citations';
  $handler->display->display_options['fields']['field_citations']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_citations']['field'] = 'field_citations';
  $handler->display->display_options['fields']['field_citations']['label'] = '';
  $handler->display->display_options['fields']['field_citations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_citations']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_citations']['alter']['text'] = '<div class="field-citations"><a href="http://www.scopus.com/inward/record.url?partnerID=HzOxMe3b&scp=[field_scopus_id]" target="_blank">Times Cited <span>[field_citations]</span></a></div>';
  $handler->display->display_options['fields']['field_citations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_citations']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_citations']['element_wrapper_class'] = 'citations';
  $handler->display->display_options['fields']['field_citations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_citations']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_citations']['empty_zero'] = TRUE;
  /* Field: Indexed Node: DOI */
  $handler->display->display_options['fields']['field_doi']['id'] = 'field_doi';
  $handler->display->display_options['fields']['field_doi']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_doi']['field'] = 'field_doi';
  $handler->display->display_options['fields']['field_doi']['label'] = '';
  $handler->display->display_options['fields']['field_doi']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_doi']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_doi']['alter']['text'] = '<div class="field-doi"><a href="http://dx.doi.org/[field_doi]" target="_blank">DOI</a></div>';
  $handler->display->display_options['fields']['field_doi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_doi']['hide_empty'] = TRUE;
  /* Field: Indexed Node: DOI */
  $handler->display->display_options['fields']['field_doi_1']['id'] = 'field_doi_1';
  $handler->display->display_options['fields']['field_doi_1']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_doi_1']['field'] = 'field_doi';
  $handler->display->display_options['fields']['field_doi_1']['label'] = '';
  $handler->display->display_options['fields']['field_doi_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_doi_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_doi_1']['alter']['text'] = '<div class="field-getit"><a href="http://sfxhosted.exlibrisgroup.com/cmc?sid=Entrez:PubMed&id=doi:[field_doi_1]" target="_blank">GET IT</a></div>';
  $handler->display->display_options['fields']['field_doi_1']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: PMID */
  $handler->display->display_options['fields']['field_pmid_1']['id'] = 'field_pmid_1';
  $handler->display->display_options['fields']['field_pmid_1']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_pmid_1']['field'] = 'field_pmid';
  $handler->display->display_options['fields']['field_pmid_1']['label'] = '';
  $handler->display->display_options['fields']['field_pmid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pmid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pmid_1']['alter']['text'] = '<div class="field-getit"><a href="http://sfxhosted.exlibrisgroup.com/cmc?sid=Entrez:PubMed&id=pmid:[field_pmid_1]" target="_blank">GET IT</a></div>';
  $handler->display->display_options['fields']['field_pmid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pmid_1']['empty'] = '[field_doi_1]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Title:</strong> [field_full_title]<br>
  <strong>Journal:</strong> [field_journal]<br>
  <strong>Type:</strong> [field_rdf_type] <br>
  <strong>Year:</strong> [field_date]<br>
  [field_pmid]
  [field_citations]
  [field_doi]
  [field_pmid_1]';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Indexed Node: Volume */
  $handler->display->display_options['fields']['field_volume_1']['id'] = 'field_volume_1';
  $handler->display->display_options['fields']['field_volume_1']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_volume_1']['field'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume_1']['label'] = '';
  $handler->display->display_options['fields']['field_volume_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_volume_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_volume_1']['alter']['text'] = ';[field_volume_1]';
  $handler->display->display_options['fields']['field_volume_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_volume_1']['hide_empty'] = TRUE;
  /* Field: Indexed Node: Page Start */
  $handler->display->display_options['fields']['field_page_start_1']['id'] = 'field_page_start_1';
  $handler->display->display_options['fields']['field_page_start_1']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_page_start_1']['field'] = 'field_page_start';
  $handler->display->display_options['fields']['field_page_start_1']['label'] = '';
  $handler->display->display_options['fields']['field_page_start_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_start_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_start_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_page_start_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Indexed Node: Page End */
  $handler->display->display_options['fields']['field_page_end_1']['id'] = 'field_page_end_1';
  $handler->display->display_options['fields']['field_page_end_1']['table'] = 'search_api_index_publications';
  $handler->display->display_options['fields']['field_page_end_1']['field'] = 'field_page_end';
  $handler->display->display_options['fields']['field_page_end_1']['label'] = '';
  $handler->display->display_options['fields']['field_page_end_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_page_end_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_end_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div>[authorships]</div>
  <div>[field_full_title]</div>
  <div>[field_journal]</div>
  <div>[field_date]</div>
  <div>[field_volume_1]</div>
  <div>[field_issue]</div>
  <div>[field_page_start_1]</div>
  <div>[field_page_end_1]</div>
  <div>[field_pmid]</div>
  <div>[field_pmcid]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['publications_list'] = $view;

  return $export;
}
