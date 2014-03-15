<?php
/**
 * @file
 * vivodashboard_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vivodashboard_core_taxonomy_default_vocabularies() {
  return array(
    'departments' => array(
      'name' => 'Departments',
      'machine_name' => 'departments',
      'description' => 'VIVO departments related to publication authors',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'institutions' => array(
      'name' => 'Institutions',
      'machine_name' => 'institutions',
      'description' => 'VIVO institutions related to departments',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'journal_rankings' => array(
      'name' => 'Journal Rankings',
      'machine_name' => 'journal_rankings',
      'description' => 'Contains journal rankings imported via Feeds. ISSN is stored as the Feeds GUID and used for journal lookups.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'journals' => array(
      'name' => 'Journals',
      'machine_name' => 'journals',
      'description' => 'VIVO journals related to publications',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'organizations' => array(
      'name' => 'Organizations',
      'machine_name' => 'organizations',
      'description' => 'VIVO organizations related to publications',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'rdf_types' => array(
      'name' => 'RDF Types',
      'machine_name' => 'rdf_types',
      'description' => 'VIVO rdf:type items',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
