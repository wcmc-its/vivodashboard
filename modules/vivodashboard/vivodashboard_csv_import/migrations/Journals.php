<?php
/**
 * @file
 * Contains VivoDashboardJournalsMigration.
 */

class VivoDashboardJournalsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'entity_type' => 'term',
    'entity_bundle' => 'journals',
    'csv_uri' => 'private://csv/journals.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
      2 => array('issn', 'ISSN'),
      3 => array('eissn', 'EISSN'),
      4 => array('isbn13', 'ISBN13'),
      5 => array('isbn10', 'ISBN10'),
      6 => array('types', 'RDF Types'),
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('name', 'label');
    $this->addFieldMapping('field_uri', 'uri');
    $this->addFieldMapping('field_issn', 'issn');
    $this->addFieldMapping('field_eissn', 'eissn');
  }
}