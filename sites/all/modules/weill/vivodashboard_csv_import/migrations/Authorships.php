<?php
/**
 * @file
 * Contains VivoDashboardAuthorsMigration.
 */

class VivoDashboardAuthorshipsMigration extends VivoDashboardCsvMigrationBase {

  public static $migrationArguments = array(
    'dependencies' => array('Publications', 'Authors'),
    'entity_type' => 'relation',
    'entity_bundle' => 'authorship',
    'csv_uri' => 'private://csv/authorships.csv',
    'csv_columns' => array(
      0 => array('uri', 'URI'),
      1 => array('label', 'Label'),
      2 => array('rank', 'Author rank'),
      3 => array('publication', 'Publication'),
      4 => array('author', 'Author'),
      5 => array('vcard', 'Vcard'),
    ),
  );

  /**
   * Overrides VivoDashboardCsvImportBase::__construct().
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_author_label', 'label');
    $this->addFieldMapping('field_author_rank', 'rank');

    $this->addFieldMapping('endpoints', NULL)->defaultValue(array());
  }

  /**
   * Overrides VivoDashboardCsvImportBase::prepareRow().
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Skip the authorship entirely when either relationship is missing.
    if (empty($row->publication) || (empty($row->author) && empty($row->vcard))) {
      $this->queueMessage('Authorship missing publication / author. Data: ' . var_export($row, TRUE), MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }

    // Prioritize authors who are people falling back to vcards.
    if (empty($row->author)) {
      $row->author = $row->vcard;
    }

    $row->publication_nid = $this->handleSourceMigration('Publications', $row->publication, NULL, $this);
    $row->author_nid = $this->handleSourceMigration('Authors', $row->author, NULL, $this);

    // Also skip the authorship entirely if we fail to look up an entity.
    if (empty($row->publication_nid) || empty($row->author_nid)) {
      $this->queueMessage('Endpoint node not found for authorship. Data: ' . var_export($row, TRUE), MigrationBase::MESSAGE_WARNING);
      return FALSE;
    }

    // Copy label from author where possible.
    if ($author = node_load($row->author_nid)) {
      $row->label = $author->title;
    }
  }

  /**
   * Prepares relation endpoints before saving relation.
   *
   * This is called by destination plugin MigrateDestinationEntity::prepare().
   */
  public function prepare(stdClass $relation, stdClass $row) {
    $relation->endpoints[LANGUAGE_NONE] = array(
      array('entity_type' => 'node', 'entity_id' => $row->publication_nid),
      array('entity_type' => 'node', 'entity_id' => $row->author_nid),
    );
  }

  /**
   * Overrides Migration::postImport().
   */
  public function postImport() {
    parent::postImport();
  }
}