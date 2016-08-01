<?php
/**
 * Drush integration for the VIVO Dashboard CSV Import module.
 */


/**
 * Implements hook_drush_command().
 */
function vivodashboard_csv_import_drush_command() {
  $items['clean-orphaned-items'] = array(
    'description' => 'Remove imported items that no longer appear in CSVs.',
    'examples' => array(
      'drush clear-orphaned-items' => dt('Clear all leftover items for all migrations.'),
    ),
  );
  return $items;
}

/**
 * Drush command callback to clean items no longer in VIVO.
 */
function drush_vivodashboard_csv_import_clean_orphaned_items() {
  $migrations = migrate_migrations();
  foreach ($migrations as $name => $migration) {
    if (method_exists($migration, 'cleanOrphanedItems')) {
      $migration->cleanOrphanedItems();
    }
  }
}
