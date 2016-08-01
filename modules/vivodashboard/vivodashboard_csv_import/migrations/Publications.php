<?php
/**
 * @file
 * Contains VivoDashboardPublicationsMigration.
 */

class VivoDashboardPublicationsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'dependencies' => array('RdfTypes', 'Journals'),
    'entity_type' => 'node',
    'entity_bundle' => 'publication',
    'csv_uri' => 'private://csv/publications.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
      2 => array('date', 'Date'),
      3 => array('journal', 'Journal'),
      4 => array('volume', 'Volume'),
      5 => array('number', 'Number'),
      6 => array('doi', 'DOI'),
      7 => array('pmid', 'PMID'),
      8 => array('pmcid', 'PMCID'),
      9 => array('scopus', 'Scopus ID'),
      10 => array('page_start', 'Page start'),
      11 => array('page_end', 'Page end'),
      12 => array('citations', 'Citation count'),
      13 => array('types', 'Types'),
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('title', 'label');
    $this->addFieldMapping('field_full_title', 'label');
    $this->addFieldMapping('field_uri', 'uri');
    $this->addFieldMapping('field_pmid', 'pmid');
    $this->addFieldMapping('field_pmcid', 'pmcid');
    $this->addFieldMapping('field_date', 'date');
    $this->addFieldMapping('field_volume', 'volume');
    $this->addFieldMapping('field_issue', 'number');
    $this->addFieldMapping('field_scopus_id', 'scopus');
    $this->addFieldMapping('field_page_start', 'page_start');
    $this->addFieldMapping('field_page_end', 'page_end');
    $this->addFieldMapping('field_citations', 'citations');

    $this->addFieldMapping('field_journal', 'journal')->sourceMigration('Journals');
    $this->addFieldMapping('field_journal:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_rdf_type', 'types')->separator('|')->sourceMigration('RdfTypes');
    $this->addFieldMapping('field_rdf_type:source_type')->defaultValue('tid');
  }

  /**
   * Overrides VivoDashboardCsvImportBase::prepareRow().
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }
}