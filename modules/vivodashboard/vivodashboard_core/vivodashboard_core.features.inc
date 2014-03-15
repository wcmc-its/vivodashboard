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
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
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
          "search_api_language" : {
            "table" : "search_api_db_authorships",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "publication_title" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_title",
            "type" : "string",
            "boost" : "1.0"
          },
          "publication_timestamp" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_timestamp",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_year" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_year",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_month" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_month",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_graph_year" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_graph_year",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_graph_month" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_graph_month",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_journal" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_journal",
            "type" : "string",
            "boost" : "1.0"
          },
          "publication_journal_ranking" : {
            "table" : "search_api_db_authorships",
            "column" : "publication_journal_ranking",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "publication_types" : {
            "table" : "search_api_db_authorships_publication_types",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "publication_author_names" : {
            "table" : "search_api_db_authorships_publication_author_names",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "publication_author_types" : {
            "table" : "search_api_db_authorships_publication_author_types",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "publication_author_affiliations" : {
            "table" : "search_api_db_authorships_publication_author_affiliations",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "publication_author_firstlast_affiliations" : {
            "table" : "search_api_db_authorships_publication_author_firstlast_affilia",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          }
        },
        "publications" : {
          "search_api_language" : {
            "table" : "search_api_db_publications",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "publication_title" : {
            "table" : "search_api_db_publications",
            "column" : "publication_title",
            "type" : "string",
            "boost" : "1.0"
          },
          "publication_timestamp" : {
            "table" : "search_api_db_publications",
            "column" : "publication_timestamp",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_year" : {
            "table" : "search_api_db_publications",
            "column" : "publication_year",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_month" : {
            "table" : "search_api_db_publications",
            "column" : "publication_month",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_graph_year" : {
            "table" : "search_api_db_publications",
            "column" : "publication_graph_year",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_graph_month" : {
            "table" : "search_api_db_publications",
            "column" : "publication_graph_month",
            "type" : "integer",
            "boost" : "1.0"
          },
          "publication_journal" : {
            "table" : "search_api_db_publications",
            "column" : "publication_journal",
            "type" : "string",
            "boost" : "1.0"
          },
          "publication_journal_ranking" : {
            "table" : "search_api_db_publications",
            "column" : "publication_journal_ranking",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "publication_types" : {
            "table" : "search_api_db_publications_publication_types",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "publication_author_names" : {
            "table" : "search_api_db_publications_publication_author_names",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "publication_author_types" : {
            "table" : "search_api_db_publications_publication_author_types",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "publication_author_affiliations" : {
            "table" : "search_api_db_publications_publication_author_affiliations",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "publication_author_firstlast_affiliations" : {
            "table" : "search_api_db_publications_publication_author_firstlast_affili",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_citations" : {
            "table" : "search_api_db_publications",
            "column" : "field_citations",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
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
    "enabled" : "0"
  }');
  return $items;
}
