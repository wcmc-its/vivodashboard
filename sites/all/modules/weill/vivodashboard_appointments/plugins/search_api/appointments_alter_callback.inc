<?php

/**
 * Search API data alteration callback to attach properties for facets.
 */
class VivodashboardAppointmentsAlterCallback extends SearchApiAbstractAlterCallback {

  /**
   * {@inheritdoc}
   */
  public function supportsIndex(SearchApiIndex $index) {
    return $index->getEntityType() === 'node' || $index->getEntityType() === 'relation';
  }

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    switch ($this->index->getEntityType()) {

      case 'node':
        $this->alterNodeItems($items);
        break;

      case 'relation':
        $this->alterRelationItems($items);
        break;
    }
  }

  /**
   * Alters items that are nodes (publications).
   */
  public function alterNodeItems(array &$items) {
    foreach ($items as $k => $item) {
      $item->organizations = array();
      $item->publication_author_firstlast_affiliations = array();

      $publication = entity_metadata_wrapper('node', $item);

      foreach ($publication->authors as $delta => $author) {
        $author_organizations = vivodashboard_appointments_relevant_organizations($publication, $author);

        $item->organizations = array_merge($item->organizations, $author_organizations);

        // Populate the first/last affiliation property with same organizations
        // only when the author is first or last. This property is part of the
        // vivodashboard_publications feature.
        if ($this->authorIsFirstOrLast($author, $publication)) {
          foreach ($author_organizations as $organization) {
            $item->publication_author_firstlast_affiliations[$organization] = $organization;
          }
        }
      }

      $item->organizations = array_unique($item->organizations);
    }
  }

  /**
   * Alters items that are relation entities (authorships).
   */
  public function alterRelationItems(array &$items) {
    foreach ($items as $k => $item) {
      $authorship = entity_metadata_wrapper('relation', $item);

      $item->organizations = $authorship->organization_list->value();

      // Populate the first/last affiliation property with same organizations
      // only when the author is first or last. This property is part of the
      // vivodashboard_publications feature.
      $item->publication_author_firstlast_affiliations = array();
      if ($this->authorshipIsFirstOrLast($authorship)) {
        $item->publication_author_firstlast_affiliations =  $item->organizations;
      }
    }
  }

  /**
   * Determine whether or not the author is first or last on the publication.
   */
  protected function authorIsFirstOrLast(EntityMetadataWrapper $author, EntityMetadataWrapper $publication) {
    $authors = $publication->authors->value();

    reset($authors);
    $first_author = current($authors);

    end($authors);
    $last_author = current($authors);

    if (is_object($first_author) && ($first_author->nid == $author->value()->nid)) {
      return TRUE;
    }

    if (is_object($last_author) && ($last_author->nid == $author->value()->nid)) {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Determine whether or not the author in an authorship is first or last.
   */
  protected function authorshipIsFirstOrLast(EntityMetadataWrapper $authorship) {
    $publication = $this->getPublicationForAuthorship($authorship);
    $author = $this->getAuthorForAuthorship($authorship);

    if ($publication && $author) {
      return $this->authorIsFirstOrLast($author, $publication);
    }

    return FALSE;
  }

  /**
   * Extract the publication node from an authorship.
   */
  protected function getPublicationForAuthorship(EntityMetadataWrapper $authorship) {
    list($source, $target) = field_get_items('relation', $authorship->value(), 'endpoints');
    $publication_node = node_load($source['entity_id']);
    return ($publication_node) ? entity_metadata_wrapper('node', $publication_node) : NULL;
  }

  /**
   * Extract the author node from an authorship.
   */
  protected function getAuthorForAuthorship(EntityMetadataWrapper $authorship) {
    list($source, $target) = field_get_items('relation', $authorship->value(), 'endpoints');
    $author_node = node_load($target['entity_id']);
    return $author_node ? entity_metadata_wrapper('node', $author_node) : NULL;
  }

  /**
   * Implements SearchApiAbstractAlterCallback::propertyInfo().
   */
  public function propertyInfo() {
    return array(
      'organizations' => array(
        'label' => t('Organization'),
        'type' => 'list<text>',
      ),
    );
  }

}
