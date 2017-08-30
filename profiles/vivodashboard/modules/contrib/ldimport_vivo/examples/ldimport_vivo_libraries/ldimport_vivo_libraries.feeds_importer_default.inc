<?php
/**
 * @file
 * ldimport_vivo_libraries.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ldimport_vivo_libraries_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_libraries';
  $feeds_importer->config = array(
    'name' => 'VIVO Libraries',
    'description' => 'Creates nodes from VIVO individuals of type http://vivoweb.org/ontology/core#Library',
    'fetcher' => array(
      'plugin_key' => 'LdImportVivoClassFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'URI',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Label',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'http://vivoweb.org/ontology/core#overview',
            'target' => 'field_vivo_overview',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'http://vivo.library.cornell.edu/ns/0.1#cornellOrganizedEndeavorHasLeadParticipantPerson [] http://www.w3.org/2000/01/rdf-schema#label',
            'target' => 'field_vivo_headedby',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'http://vivoweb.org/ontology/core#webpage [] http://vivoweb.org/ontology/core#linkURI',
            'target' => 'field_vivo_webpage',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'vivo_library',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_libraries'] = $feeds_importer;

  return $export;
}
