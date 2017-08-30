<?php
/**
 * @file
 * Contains VivoDashboardCsvSource.
 */

class VivoDashboardCsvSource extends MigrateSourceCSV {

  protected $file;

  /**
   * Overrides MigrateSourceCSV::performRewind().
   */
  public function performRewind() {
    // Close any previously-opened handle.
    if (!is_null($this->csvHandle)) {
      fclose($this->csvHandle);
      $this->csvHandle = NULL;
    }

    // Load up the first row, skipping the header(s) if necessary.
    $this->csvHandle = fopen($this->file, 'r');
    for ($i = 0; $i < $this->headerRows; $i++) {
      $this->getNextLine();
    }

    // Start where we left off.
    if ($this->activeMigration && ($previousRowNumber = $this->loadRowNumber())) {
      for ($r = 1; $r < $previousRowNumber; $r++) {
        $this->getNextLine();
        $this->rowNumber = $r;
      }
    }
    // or start fresh.
    else {
      $this->importStart();
      $this->rowNumber = 1;
    }
  }

  /**
   * Overrides MigrateSourceCSV::getNextRow().
   */
  public function getNextRow() {
    $row = parent::getNextRow();

    // Track every row from the CSV, not just valid/changed items.
    if ($row) {
      $keys = $this->activeMigration->prepareKey($this->activeMap->getSourceKey(), $row);
      $this->trackItem(reset($keys));
    }

    // If the row is empty we hit the end of the file.
    if (empty($row)) {
      $this->importComplete();
    }

    return $row;
  }

  /**
   * Helper to decide if we should skip migrating - Migration class calls this.
   */
  public function shouldSkipMigration($migration_name) {
    // File has not changed and there is no row number indicating stored which
    // indicates a partial import.
    return (!$this->fileHasChanged($migration_name) && !$this->loadRowNumber($migration_name));
  }

  /**
   * Helper to check whether or not a CSV has changed.
   */
  protected function fileHasChanged($migration_name) {
    $current_filesize = isset($this->file) ? filesize($this->file) : 0;
    $previous_filesize = variable_get("vivodashboard_csv_import_filesize_{$migration_name}", 0);

    if ($previous_filesize && ($previous_filesize == $current_filesize)) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Persist data about the migration progress - Migration class calls this.
   */
  public function recordProgress($migration_name) {
    variable_set("vivodashboard_csv_import_row_{$migration_name}", $this->rowNumber);
  }

  /**
   * Loads last CSV row number from the database.
   */
  protected function loadRowNumber($migration_name = NULL) {
    if (!$migration_name) {
      $migration_name = $this->activeMigration->getMachineName();
    }
    return variable_get("vivodashboard_csv_import_row_{$migration_name}", NULL);
  }

  /**
   * Prepare to import a CSV from the beginning.
   *
   * This is different from ::preImport(), which runs every time we continue
   * running a migration from where we left off.
   */
  protected function importStart($migration_name = NULL) {
    if (!$migration_name) {
      $migration_name = $this->activeMigration->getMachineName();
    }

    db_delete('migrate_clean')->condition('migration', $migration_name)->execute();
  }

  /**
   * Clean up state after an import has completed.
   *
   * This is different from ::postImport(), which runs even when the time limit
   * has been reached without finishing the CSV.
   */
  protected function importComplete($migration_name = NULL) {
    if (!$migration_name) {
      $migration_name = $this->activeMigration->getMachineName();
    }

    // Wipe out all row pointers.
    $this->rowNumber = NULL;
    variable_set("vivodashboard_csv_import_row_{$migration_name}", NULL);

    // Update the filesize.
    variable_set("vivodashboard_csv_import_filesize_{$migration_name}", filesize($this->file));

    if ($this->activeMigration) {
      $this->activeMigration->cleanOrphanedItems();
    }

    db_delete('migrate_clean')->condition('migration', $migration_name)->execute();
  }

  /**
   * Helper to track CSV rows in the migrate_clean table.
   */
  protected function trackItem($source_id) {
    if (!empty($source_id)) {
      $migration_name = strtolower($this->activeMigration->getMachineName());
      db_insert('migrate_clean')->fields(array('id' => $source_id, 'migration' => $migration_name))->execute();
    }
  }
}