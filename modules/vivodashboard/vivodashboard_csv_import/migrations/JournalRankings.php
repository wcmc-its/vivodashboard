<?php
/**
 * @file
 * Contains VivoDashboardJournalRankingsMigration.
 */

class VivoDashboardJournalRankingsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'dependencies' => array('Journals'),
    'entity_type' => 'term',
    'entity_bundle' => 'journals',
    'csv_uri' => 'private://csv/journal_rankings.tsv',
    'csv_columns' => array(
      0 => array('name', 'Journal Name'),
      1 => array('ranking', 'Ranking'),
      2 => array('issn', 'ISSN'),
    ),
    'csv_options' => array(
      'delimiter' => "\t",
    ),
    'map_options' => array(
      'identifier' => 'id',
    ),
  );

  /**
   * Overrides Migration::__construct().
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->systemOfRecord = Migration::DESTINATION;

    $this->addFieldMapping('tid', 'matched_tid');
    $this->addFieldMapping('field_ranking', 'ranking');
  }

  /**
   * Overrides Migration::prepareKey().
   */
  public function prepareKey($source_key, $row) {
    // Create a unique ID because apparently there can be duplicate ISSNs.
    $row->id = $row->issn . '__' . md5($row->name);
    return array('id' => $row->id);
  }

  /**
   * Overrides VivoDashboardCsvImportBase::prepareRow().
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if (!empty($row->issn)) {
      $row->matched_tid = db_select('field_data_field_eissn', 'f')
        ->fields('f', array('entity_id'))
        ->condition('f.field_eissn_value', $row->issn)
        ->execute()
        ->fetchField();
    }

    if (empty($row->issn)) {
      $this->queueMessage(t('No ISSN included for @title.', array('@title' => $row->name)), MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
    if (empty($row->matched_tid)) {
      // $this->queueMessage(t('ISSN @issn does not match any imported journals.', array('@issn' => $row->issn)), MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }
  }
}