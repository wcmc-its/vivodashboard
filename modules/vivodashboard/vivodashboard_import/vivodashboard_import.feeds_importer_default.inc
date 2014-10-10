<?php
/**
 * @file
 * vivodashboard_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function vivodashboard_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'journal_rankings';
  $feeds_importer->config = array(
    'name' => 'Journal Rankings',
    'description' => 'Imports SCImago journal rankings from TSV file into a taxonomy vocabulary.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => '2',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => '0',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => '1',
            'target' => 'description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'journal_rankings',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['journal_rankings'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_authors';
  $feeds_importer->config = array(
    'name' => 'VIVO Authors',
    'description' => 'Used by vivo_authorships importer to import authors as nodes.',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '100',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '60',
        'cache_time' => 1209600,
      ),
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
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'URI',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Label',
            'target' => 'title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'http://weill.cornell.edu/vivo/ontology/wcmc#primaryAffiliation',
            'target' => 'field_primary_institution',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'http://weill.cornell.edu/vivo/ontology/wcmc#cwid',
            'target' => 'field_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#type',
            'target' => 'import:node:field_rdf_type',
            'importer' => 'vivo_types',
            'age' => '2419200',
          ),
          7 => array(
            'source' => 'http://vivoweb.org/ontology/core#relatedBy [http://vivoweb.org/ontology/core#PrimaryPosition] http://vivoweb.org/ontology/core#relates [http://xmlns.com/foaf/0.1/Organization] URI',
            'target' => 'import:node:field_primary_department',
            'importer' => 'vivo_departments',
            'age' => '2419200',
          ),
          8 => array(
            'source' => 'http://vivoweb.org/ontology/core#relatedBy [http://vivoweb.org/ontology/core#Position] http://vivoweb.org/ontology/core#relates [http://xmlns.com/foaf/0.1/Organization] URI',
            'target' => 'import:node:field_department',
            'importer' => 'vivo_departments',
            'age' => '2419200',
          ),
          9 => array(
            'source' => 'http://purl.obolibrary.org/obo/ARG_2000028 [] http://www.w3.org/2006/vcard/ns#hasName [] http://www.w3.org/2006/vcard/ns#givenName',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'http://purl.obolibrary.org/obo/ARG_2000028 [] http://www.w3.org/2006/vcard/ns#hasName [] http://www.w3.org/2006/vcard/ns#familyName',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'author',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_authors'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_authors_vcard';
  $feeds_importer->config = array(
    'name' => 'VIVO Authors (Vcard)',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '100',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '60',
        'cache_time' => 1209600,
      ),
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
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'URI',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'URI',
            'target' => 'title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#type',
            'target' => 'import:node:field_rdf_type',
            'importer' => 'vivo_types',
            'age' => '2419200',
          ),
          5 => array(
            'source' => 'http://purl.obolibrary.org/obo/ARG_2000028 [] http://www.w3.org/2006/vcard/ns#hasName [] http://www.w3.org/2006/vcard/ns#givenName',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'http://purl.obolibrary.org/obo/ARG_2000028 [] http://www.w3.org/2006/vcard/ns#hasName [] http://www.w3.org/2006/vcard/ns#familyName',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'author',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_authors_vcard'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_authorships';
  $feeds_importer->config = array(
    'name' => 'VIVO Authorships',
    'description' => 'Used by vivo_publications importer to import authors as relations. See vivodashboard_import.feeds.inc',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '10',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '30',
        'cache_time' => 1209600,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'RelationFeedsProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'unique_enpoints' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'URI',
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'http://vivoweb.org/ontology/core#rank',
            'target' => 'field_author_rank',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'http://vivoweb.org/ontology/core#relates [http://www.w3.org/2006/vcard/ns#Kind] URI',
            'target' => 'import:relation:authors',
            'importer' => 'vivo_authors_vcard',
            'age' => 'last',
          ),
          3 => array(
            'source' => 'http://vivoweb.org/ontology/core#relates [http://xmlns.com/foaf/0.1/Person] URI',
            'target' => 'import:relation:authors',
            'importer' => 'vivo_authors',
            'age' => 'last',
          ),
          4 => array(
            'source' => 'http://vivoweb.org/ontology/core#relates [http://purl.org/ontology/bibo/Article] URI',
            'target' => 'authorship:endpoint:0',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'http://vivoweb.org/ontology/core#relates [http://www.w3.org/2006/vcard/ns#Kind] URI',
            'target' => 'authorship:endpoint:1',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'http://vivoweb.org/ontology/core#relates [http://xmlns.com/foaf/0.1/Person] URI',
            'target' => 'authorship:endpoint:1',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'authorship',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_authorships'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_departments';
  $feeds_importer->config = array(
    'name' => 'VIVO Departments',
    'description' => 'Used by vivo_authors importer to import departments as taxonomy terms.',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '100',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '30',
        'cache_time' => 1209600,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'URI',
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Label',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'http://vivoweb.org/ontology/core#subOrganizationWithin',
            'target' => 'import:taxonomy_term:field_institution',
            'importer' => 'vivo_institutions',
            'age' => '1440',
          ),
          4 => array(
            'source' => 'http://vivoweb.org/ontology/core#subOrganizationWithin [] http://vivoweb.org/ontology/core#subOrganizationWithin',
            'target' => 'import:taxonomy_term:field_institution',
            'importer' => 'vivo_institutions',
            'age' => '1440',
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'departments',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_departments'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_funding_organizations';
  $feeds_importer->config = array(
    'name' => 'VIVO Funding Organizations',
    'description' => 'Used by vivo_publications importer to import organizations as taxonomy terms.',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '100',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '30',
        'cache_time' => 1209600,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'URI',
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Label',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'organizations',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_funding_organizations'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_institutions';
  $feeds_importer->config = array(
    'name' => 'VIVO Institutions',
    'description' => 'Used by vivo_departments importer to import institutions as taxonomy terms.',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '100',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '30',
        'cache_time' => 1209600,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'URI',
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Label',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#type',
            'target' => 'import:taxonomy_term:field_rdf_type',
            'importer' => 'vivo_types',
            'age' => '1440',
          ),
          3 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'institutions',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_institutions'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_journals';
  $feeds_importer->config = array(
    'name' => 'VIVO Journals',
    'description' => 'Used by vivo_publications importer to import journal taxonomy terms.',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '100',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '30',
        'cache_time' => 1209600,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'URI',
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Label',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'http://purl.org/ontology/bibo/issn',
            'target' => 'field_issn',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'journals',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_journals'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_publications';
  $feeds_importer->config = array(
    'name' => 'VIVO Publications',
    'description' => 'Imports publications and their related individuals from VIVO via linked data requests.',
    'fetcher' => array(
      'plugin_key' => 'LdImportVivoClassFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '5',
        'pre_fetch' => 1,
        'retries' => '3',
        'timeout' => '60',
        'cache_time' => 1209600,
      ),
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
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'URI',
            'target' => 'guid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Label',
            'target' => 'title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Label',
            'target' => 'field_full_title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'http://purl.org/ontology/bibo/pageStart',
            'target' => 'field_page_start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'http://purl.org/ontology/bibo/pageEnd',
            'target' => 'field_page_end',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'http://vivoweb.org/ontology/core#dateTimeValue [] http://vivoweb.org/ontology/core#dateTime',
            'target' => 'field_date:start',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'http://purl.org/ontology/bibo/volume',
            'target' => 'field_volume',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'http://purl.org/ontology/bibo/number',
            'target' => 'field_issue',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'http://purl.org/ontology/bibo/doi',
            'target' => 'field_doi',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'http://purl.org/ontology/bibo/pmid',
            'target' => 'field_pmid',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'http://vivoweb.org/ontology/core#pmcid',
            'target' => 'field_pmcid',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'http://weill.cornell.edu/vivo/ontology/wcmc#scopusDocId',
            'target' => 'field_scopus_id',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'http://vivoweb.org/ontology/core#hasPublicationVenue',
            'target' => 'import:node:field_journal',
            'importer' => 'vivo_journals',
            'age' => '2419200',
          ),
          15 => array(
            'source' => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#type',
            'target' => 'import:node:field_rdf_type',
            'importer' => 'vivo_types',
            'age' => '2419200',
          ),
          16 => array(
            'source' => 'http://vivoweb.org/ontology/core#FundingOrganization',
            'target' => 'import:node:field_funding',
            'importer' => 'vivo_funding_organizations',
            'age' => '2419200',
          ),
          17 => array(
            'source' => 'http://purl.org/spar/c4o/hasGlobalCitationFrequency [] http://www.w3.org/2000/01/rdf-schema#label',
            'target' => 'field_citations',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'http://vivoweb.org/ontology/core#relatedBy [http://vivoweb.org/ontology/core#Authorship] URI',
            'target' => 'publication_authorships',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'publication',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_publications'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vivo_types';
  $feeds_importer->config = array(
    'name' => 'VIVO Types',
    'description' => 'Used by multiple importers to import rdf:type items as taxonomy terms.',
    'fetcher' => array(
      'plugin_key' => 'LdImportFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'LdImportParser',
      'config' => array(
        'use_caching' => 1,
        'batch_limit' => '100',
        'pre_fetch' => 0,
        'retries' => '3',
        'timeout' => '30',
        'cache_time' => 1209600,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'URI',
            'target' => 'url',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Label',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'URI',
            'target' => 'field_uri:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'rdf_types',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vivo_types'] = $feeds_importer;

  return $export;
}
