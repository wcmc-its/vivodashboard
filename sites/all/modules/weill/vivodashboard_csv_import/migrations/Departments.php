<?php
/**
 * @file
 * Contains VivoDashboardDepartmentsMigration.
 */

class VivoDashboardDepartmentsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'dependencies' => array('RdfTypes', 'Institutions'),
    'entity_type' => 'term',
    'entity_bundle' => 'departments',
    'csv_uri' => 'private://csv/departments.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
      2 => array('parents', 'Parent organizations'),
      3 => array('grandparents', 'Grandparent organizations'),
      4 => array('types', 'RDF Types'),
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('name', 'label');
    $this->addFieldMapping('field_uri', 'uri');

    $this->addFieldMapping('field_institution', 'parents')->separator('|')->sourceMigration('Institutions');
    $this->addFieldMapping('field_institution:source_type')->defaultValue('tid');
  }
}