<?php
/**
 * @file
 * vivodashboard_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vivodashboard_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function vivodashboard_core_node_info() {
  $items = array(
    'author' => array(
      'name' => t('Author'),
      'base' => 'node_content',
      'description' => t('Author profiles imported from VIVO.'),
      'has_title' => '1',
      'title_label' => t('Label'),
      'help' => '',
    ),
    'publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('Publications imported from VIVO.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function vivodashboard_core_default_search_api_server() {
  $items = array();
  $items['database'] = entity_import('search_api_server', '{
    "name" : "Database",
    "machine_name" : "database",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "indexes" : {
        "authorships" : {
          "field_author_rank" : {
            "table" : "search_api_db_authorships",
            "column" : "field_author_rank",
            "type" : "integer",
            "boost" : "1.0"
          },
          "endpoints_source_node" : {
            "table" : "search_api_db_authorships_endpoints_source_node",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "endpoints_target_node" : {
            "table" : "search_api_db_authorships_endpoints_target_node",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_authorships",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          }
        },
        "publications" : { "search_api_language" : {
            "table" : "search_api_db_publications",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids_form" : [],
      "clean_ids" : false,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/vivo-dashboard",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "POST"
    },
    "enabled" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
