<?php
/**
 * @file
 * Contains VivoDashboardRdfTypesMigration.
 */

class VivoDashboardRdfTypesMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'entity_type' => 'term',
    'entity_bundle' => 'rdf_types',
    'csv_uri' => 'private://csv/rdf_types.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('name', 'label');
    $this->addFieldMapping('field_uri', 'uri');
  }
}