<?php
/**
 * Contains VivoDashboardCsvMigrationBase.
 */

class VivoDashboardCsvMigrationBase extends Migration {

  protected $csvUri;
  protected $csvColumns;
  protected $targetType;
  protected $targetBundle;

  protected $forcedUpdate = FALSE;

  protected $memoryThreshold = 0.5;

  /**
   * Overrides Migration::__construct().
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->csvUri = $arguments['csv_uri'];
    $this->csvColumns = $arguments['csv_columns'];
    $this->targetType = $arguments['entity_type'];
    $this->targetBundle = $arguments['entity_bundle'];

    // If CSV file locations have been specified in settings.php we use those
    // instead of whatever is specified by the migration itself.
    $csv_files = variable_get('vivodashboard_csv_import_files', array());
    if (!empty($csv_files[$this->machineName])) {
      $this->csvUri = $csv_files[$this->machineName];
    }

    // Source.
    $csv_options = isset($arguments['csv_options']) ? $arguments['csv_options'] : array();
    $csv_options += array(
      'header_rows' => 0,
      'delimiter' => ',',
      'track_changes' => TRUE,
      'embedded_newlines' => TRUE,
      // embedded_newlines makes row counts much slower but improve accuracy
      // since some CSVs seem to contain newline data.
      // @see MigrateSourceCSV::computeCount()
    );
    $this->source = new VivoDashboardCsvSource($this->csvUri, $this->csvColumns, $csv_options);

    // Destination.
    $destination_class = 'MigrateDestination' . ucwords($this->targetType);
    $this->destination = new $destination_class($this->targetBundle);

    // Map.
    $map_options = isset($arguments['map_options']) ? $arguments['map_options'] : array();
    $map_options += array(
      'track_last_imported' => TRUE,
      'identifier' => 'uri',
    );
    $source_schema = array(
      $map_options['identifier'] => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $source_schema, $destination_class::getKeySchema(), 'default', $map_options);
  }

  /**
   * Overrides Migration::import().
   */
  public function import() {
    // Normally, if we run drush migrate-import --all, each migration will end
    // up processing the first row before recognizing that the time limit has
    // been reached. This prevents the migration from running at all.
    if ($this->timeOptionExceeded()) {
      return MigrationBase::RESULT_COMPLETED;
    }
    // Allow the source plugin to choose to skip the migration.
    if ($this->source->shouldSkipMigration($this->machineName) && !$this->forcedUpdate) {
      $this->displayMessage("CSV file has not changed for {$this->machineName} migration, skipping.", 'status');
      return MigrationBase::RESULT_COMPLETED;
    }
    return parent::import();
  }

  /**
   * Overrides Migration::prepareRow().
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Ensure every row has a label.
    if (empty($row->label) && isset($row->uri)) {
      $row->label = $this->makeLabel($row->uri);
    }

    // Hashes are created from row data as a way to check for changes, but if
    // the CSV row number changes it doesn't mean the data changed. We remove
    // this from the row data since it doesn't appear to be used anywhere.
    unset($row->csvrownum);

    return TRUE;
  }

  /**
   * Overrides Migration::postImport().
   */
  protected function postImport() {
    parent::postImport();
    $this->source->recordProgress($this->machineName);
  }

  /**
   * Overrides Migration::prepareUpdate().
   */
  public function prepareUpdate() {
    // Keep track of whether this migration is forcing an update of data.
    $this->forcedUpdate = TRUE;
    return parent::prepareUpdate();
  }

  /**
   * Helper to generate labels when once is not available.
   */
  protected function makeLabel($uri) {
    $resource = ARC2::getResource();
    return $resource->extractTermLabel($uri);
  }

  /**
   * Helper to remove imported items no longer in the CSV.
   */
  public function cleanOrphanedItems() {
    $migration_name = strtolower($this->machineName);

    // Migrations that only update existing records should not be cleaned.
    if ($this->getSystemOfRecord() !== Migration::SOURCE) {
      return;
    }

    // Find items in the map table that are no longer in the source data.
    $query = db_select("migrate_map_{$migration_name}", 'mm');
    $query->isNotNull('mm.destid1');
    $query->leftJoin('migrate_clean', 'mc', 'mm.sourceid1 = mc.id');
    $query->isNull('mc.id');
    $query->fields('mm', array('sourceid1', 'destid1'));

    $ids_to_clean = $query->execute()->fetchAllKeyed(0, 1);

    if (empty($ids_to_clean)) {
      return;
    }

    // Remove orphaned entities.
    $source_ids = array_keys($ids_to_clean);
    $destination_ids = array_values($ids_to_clean);

    // Clean from map table.
    $this->getMap()->deleteBulk($source_ids);

    // Some destinations use ::bulkRollback() some use ::rollback().
    $destination = $this->getDestination();
    if (method_exists($destination, 'bulkRollback')) {
      $destination->bulkRollback($destination_ids);
    }
    else {
      foreach ($destination_ids as $destination_id) {
        $destination->rollback(array($destination_id));
      }
    }

    self::displayMessage(
      t('Cleaned !count orphaned item no longer in the CSV for !name.',
        array('!count' => count($ids_to_clean), '!name' => $migration_name)), 'ok'
    );
  }
}