<?php
/**
 * @file
 * Contains VivoDashboardAuthorPositionsMigration.
 */

class VivoDashboardAuthorPositionsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'dependencies' => array('Publications', 'Authors', 'Authorships'),
    'entity_type' => 'node',
    'entity_bundle' => 'publication',
    'csv_uri' => 'private://csv/publications.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
    ),
    'csv_options' => array(
      'track_changes' => FALSE,
    ),
    'map_options' => array(
      'track_last_imported' => FALSE,
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->systemOfRecord = Migration::DESTINATION;

    $this->addFieldMapping('nid', 'nid');
  }

  /**
   * Overrides VivoDashboardCsvImportBase::prepareRow().
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->nid = $this->handleSourceMigration('Publications', $row->uri);

    $publication = entity_metadata_wrapper('node', $row->nid);
    $authorship_rids = $publication->authorships->raw();

    // Find first and last authorships.
    reset($authorship_rids);
    $first_delta = key($authorship_rids);
    end($authorship_rids);
    $last_delta = key($authorship_rids);

    // We only want to specify first/last authors when a publication has
    // more than one authorship.
    $more_than_one = (count($authorship_rids) > 1);

    // Pre-cache all relation entities.
    relation_load_multiple($authorship_rids);

    // $count = count($authorship_rids);
    // drush_print_r("Publication {$row->nid} has {$count} authorships.");

    // Loop through in order. Authorships here have been sorted by rank. We
    // only say an author is first/last when a value for author rank has been
    // explicitly saved (not only based on the array of authorships).
    foreach ($publication->authorships as $delta => $authorship) {
      $saved_position = $authorship->field_author_position->value();
      $saved_rank = $authorship->field_author_rank->value();

      // Remove any saved position values when there is only one authorship now.
      if (!$more_than_one && $saved_position) {
        $authorship->field_author_position->set(NULL);
        $authorship->save();
      }
      elseif (!$more_than_one) {
        continue;
      }

      $save = FALSE;

      // Specify as first author.
      if ($delta == $first_delta && $saved_position != 'first' && $saved_rank) {
        $authorship->field_author_position->set('first');
        $save = TRUE;
      }
      // Specify as last author.
      elseif ($delta == $last_delta && $saved_position != 'last' && $saved_rank) {
        $authorship->field_author_position->set('last');
        $save = TRUE;
      }
      // Remove position, it's no longer valid.
      elseif ($saved_position) {
        $authorship->field_author_position->set(NULL);
        $save = TRUE;
      }

      if ($save) {
        // TODO: Mark publication for reindexing.
        $authorship->save();
      }
    }

    // Avoid hitting memory limits.
    entity_get_controller('relation')->resetCache($authorship_rids);
    entity_get_controller('node')->resetCache(array($row->nid));

    return TRUE;
  }
}