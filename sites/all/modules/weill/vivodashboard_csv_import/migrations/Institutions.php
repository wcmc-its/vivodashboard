<?php
/**
 * @file
 * Contains VivoDashboardInstitutionsMigration.
 */

class VivoDashboardInstitutionsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'dependencies' => array('RdfTypes'),
    'entity_type' => 'term',
    'entity_bundle' => 'institutions',
    'csv_uri' => 'private://csv/institutions.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
      2 => array('types', 'RDF Types'),
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('name', 'label');
    $this->addFieldMapping('field_uri', 'uri');
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