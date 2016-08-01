<?php
/**
 * @file
 * Contains VivoDashboardAuthorsMigration.
 */

class VivoDashboardAuthorsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'dependencies' => array('RdfTypes', 'Departments'),
    'entity_type' => 'node',
    'entity_bundle' => 'author',
    'csv_uri' => 'private://csv/authors.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
      2 => array('first_name', 'First name'),
      3 => array('last_name', 'Last name'),
      4 => array('cwid', 'CWID'),
      5 => array('affiliation', 'Affiliation'),
      6 => array('departments', 'Departments'),
      7 => array('types', 'RDF Types'),
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('title', 'label');
    $this->addFieldMapping('field_uri', 'uri');
    $this->addFieldMapping('field_primary_institution', 'affiliation');
    $this->addFieldMapping('field_id', 'cwid');
    $this->addFieldMapping('field_first_name', 'first_name');
    $this->addFieldMapping('field_last_name', 'last_name');

    $this->addFieldMapping('field_department', 'departments')->separator('|')->sourceMigration('Departments');
    $this->addFieldMapping('field_department:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_rdf_type', 'types')->separator('|')->sourceMigration('RdfTypes');
    $this->addFieldMapping('field_rdf_type:source_type')->defaultValue('tid');
  }

  /**
   * Overrides VivoDashboardCsvImportBase::prepareRow().
   */
  public function prepareRow($row) {
    // Format a label if possible, otherwise let the parent class generate one.
    if (empty($row->label) && !empty($row->first_name) && !empty($row->last_name)) {
      $row->label = "{$row->last_name}, {$row->first_name}";
    }
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }
}