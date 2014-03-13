<?php
/**
 * @file
 * vivodashboard_publications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vivodashboard_publications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vivodashboard_publications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function vivodashboard_publications_default_search_api_index() {
  $items = array();
  $items['authorships'] = entity_import('search_api_index', '{
    "name" : "Authorships",
    "machine_name" : "authorships",
    "description" : null,
    "server" : "database",
    "item_type" : "relation",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "publication_author_affiliations" : { "type" : "list\\u003Cstring\\u003E" },
        "publication_author_firstlast_affiliations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "publication_author_names" : { "type" : "list\\u003Cstring\\u003E" },
        "publication_author_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "publication_graph_month" : { "type" : "integer" },
        "publication_graph_year" : { "type" : "integer" },
        "publication_journal" : { "type" : "string" },
        "publication_journal_ranking" : { "type" : "decimal" },
        "publication_month" : { "type" : "integer" },
        "publication_timestamp" : { "type" : "integer" },
        "publication_title" : { "type" : "string" },
        "publication_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "publication_year" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : { "fields" : [] } },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-48",
          "settings" : { "default" : "0", "bundles" : { "authorship" : "authorship" } }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-47", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-46", "settings" : { "mode" : false } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "publications" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "ignored_types" : "http:\\/\\/weill.cornell.edu\\/vivo\\/ontology\\/wcmc#Erratum, http:\\/\\/purl.org\\/ontology\\/bibo\\/Book" }
        }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['publications'] = entity_import('search_api_index', '{
    "name" : "Publications",
    "machine_name" : "publications",
    "description" : null,
    "server" : "database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "publication_author_affiliations" : { "type" : "list\\u003Cstring\\u003E" },
        "publication_author_firstlast_affiliations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "publication_author_names" : { "type" : "list\\u003Cstring\\u003E" },
        "publication_author_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "publication_graph_month" : { "type" : "integer" },
        "publication_graph_year" : { "type" : "integer" },
        "publication_journal" : { "type" : "string" },
        "publication_journal_ranking" : { "type" : "decimal" },
        "publication_month" : { "type" : "integer" },
        "publication_timestamp" : { "type" : "integer" },
        "publication_title" : { "type" : "string" },
        "publication_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "publication_year" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : { "fields" : [] } },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-49",
          "settings" : { "default" : "0", "bundles" : { "publication" : "publication" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-47", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-46", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "publications" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "ignored_types" : "http:\\/\\/weill.cornell.edu\\/vivo\\/ontology\\/wcmc#Erratum, http:\\/\\/purl.org\\/ontology\\/bibo\\/Book" }
        }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
