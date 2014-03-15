<?php

/**
 * Search API data alteration callback to attach properties for facets.
 */
class VivodashboardPublicationsAlterCallback extends SearchApiAbstractAlterCallback {

  public function supportsIndex(SearchApiIndex $index) {
    return $index->getEntityType() === 'node' || $index->getEntityType() === 'relation';
  }

  public function alterItems(array &$items) {
    switch ($this->index->getEntityType()) {

      case 'node':
        $this->alterNodeItems($items); break;

      case 'relation':
        $this->alterRelationItems($items); break;
    }
  }

  public function alterNodeItems(array &$items, $target_author = NULL) {
    $ignored_types = isset($this->options['ignored_types']) ? explode(',', $this->options['ignored_types']) : array();
    $ignored_types = array_map('trim', $ignored_types);

    foreach ($items as $i => &$item) {
      $this->resetProperties($item);
      $wrapper = entity_metadata_wrapper('node', $item);

      // Check the URIs for the publication types against the types we ignore
      // and remove this item entirely if there is a match.
      if ($ignored_types) {
        foreach ($wrapper->rdf_types->value() as $uri) {
          if (in_array($uri, $ignored_types, TRUE)) {
            unset($items[$i]);
            continue 2;
          }
        }
      }

      $item->publication_title = $item->title;

      // Attach date properties.
      if (isset($wrapper->field_date) && $wrapper->field_date->raw()) {
        $item->publication_timestamp = $wrapper->field_date->raw();
        $date = new DateObject($wrapper->field_date->raw());
        $item->publication_year = $date->format('Y');
        $item->publication_month = $date->format('n');
        $item->publication_graph_year = $date->format('Y');
        $item->publication_graph_month = $date->format('n');
      }

      // Attach journal property.
      if (isset($wrapper->field_journal) && $wrapper->field_journal->value()) {
        $journal_term = $wrapper->field_journal->value();
        $item->publication_journal = $journal_term->name;

        // Add journal ranking.
        $journal_wrapper = entity_metadata_wrapper('taxonomy_term', $journal_term);
        if ($ranking = $journal_wrapper->field_ranking->value()) {
          $item->publication_journal_ranking = $ranking;
        }
      }

      // Attach rdf type property.
      if (isset($wrapper->field_rdf_type) && $wrapper->field_rdf_type->value()) {
        foreach ($wrapper->field_rdf_type->value() as $term) {
          $item->publication_types[] = $term->tid;
          // $item->publication_types[] = $term->name;
        }
      }

      // Attach author-related propereties.
      if ($authors = $wrapper->authors->value()) {

        reset($authors);
        $first = key($authors);
        end($authors);
        $last = key($authors);

        foreach ($wrapper->authors as $delta => $author) {

          // If we're indexing authorships we only care about one author.
          if ($target_author && ($target_author->nid != $author->nid->value())) {
            continue;
          }

          // Add author name.
          $item->publication_author_names[] = $author->title->value();

          // Add field_rdf_type values for author.
          foreach ($author->field_rdf_type->value() as $term) {
            $item->publication_author_types[$term->tid] = $term->tid;
            // $item->publication_author_types[$term->name] = $term->name;
          }

          // Add primary department.
          if ($department = $author->field_primary_department->value()) {
            $item->publication_author_affiliations[$department->name] = $department->name;
          }

          // Add primary institution.
          if (($delta == $first || $delta == $last) && $author->field_primary_institution->value()) {
            $institution_name = $author->field_primary_institution->value();
            $item->publication_author_firstlast_affiliations[$institution_name] = $institution_name;
          }

          // Add department values for author.
          // foreach ($author->field_department->value() as $k => $term) {
          //   $item->publication_author_affiliations[$term->name] = $term->name;

          //   // Add the institutional affiliation if this is a first/last author.
          //   $department = entity_metadata_wrapper('taxonomy_term', $term);
          //   if (($delta == $first || $delta == $last) && !empty($department->field_institution[0])) {
          //     $item->publication_author_firstlast_affiliations[] = $department->field_institution[0]->tid->value();
          //     // $item->publication_author_firstlast_affiliations[] = $department->field_institution[0]->name->value();
          //   }

            // Restrict to institutions typed as vivo:University.
            // if (($delta == $first || $delta == $last)) {
            //   foreach ($author->field_department[$k]->field_institution->rdf_types->value() as $rdf_type) {
            //     if ($rdf_type == 'http://vivoweb.org/ontology/core#University') {
            //       $item->publication_author_firstlast_affiliations[] = $author->field_department[$k]->field_institution->name->value();
            //     }
            //   }
            // }
          // }
        }
      }
    }
  }

  public function alterRelationItems(array &$items) {
    foreach ($items as $id => $item) {
      $this->resetProperties($item);

      list($source, $target) = field_get_items('relation', $item, 'endpoints');
      $publication_node = node_load($source['entity_id']);
      $author_node = node_load($target['entity_id']);

      if (!$publication_node || $publication_node->type != 'publication') {
        continue;
      }

      $node_items = array($publication_node);
      $this->alterNodeItems($node_items, $author_node);

      foreach ($this->propertyInfo() as $property_name => $property) {
        $item->$property_name = $publication_node->$property_name;
      }
    }
  }

  public function resetProperties(&$item) {
    $item->publication_title = NULL;
    $item->publication_year = NULL;
    $item->publication_month = NULL;
    $item->publication_timestamp = NULL;
    $item->publication_graph_year = NULL;
    $item->publication_graph_month = NULL;
    $item->publication_journal = NULL;
    $item->publication_journal_ranking = NULL;
    $item->publication_types = array();
    $item->publication_author_names = array();
    $item->publication_author_types = array();
    $item->publication_author_affiliations = array();
    $item->publication_author_firstlast_affiliations = array();
  }

  /**
   * Implements SearchApiAbstractAlterCallback::propertyInfo().
   *
   * Exposes custom properties for Search API and Entity API.
   *
   * Note: Some properties below should be list<taxonomy_term> but are instead
   *   typed as list<text>. These properties are used for autocomplete facets,
   *   where text values are more appropriate. In most cases, however, using
   *   list<taxonomy_term> instead of list<text> will lead to
   *   more performant facet queries when using a database backend.
   */
  public function propertyInfo() {
    return array(
      'publication_title' => array(
        'label' => t('Publication Title'),
        'type' => 'text',
      ),
      'publication_timestamp' => array(
        'label' => t('Publication Timestamp'),
        'description' => t('Include the publication date as a timestamp.'),
        'type' => 'integer',
      ),
      'publication_year' => array(
        'label' => t('Publication Year'),
        'description' => t('Include the publication year (field_date) as an integer for facets.'),
        'type' => 'integer',
      ),
      'publication_month' => array(
        'label' => t('Publication Month'),
        'description' => t('Include the publication month (field_date) as an integer for facets.'),
        'type' => 'integer',
      ),
      'publication_graph_year' => array(
        'label' => t('Publication Year (Graphs)'),
        'description' => t('Include the publication year separately for graph facets.'),
        'type' => 'integer',
      ),
      'publication_graph_month' => array(
        'label' => t('Publication Month (Graphs)'),
        'description' => t('Include the publication month separately for graph facets.'),
        'type' => 'integer',
      ),
      'publication_journal' => array(
        'label' => t('Publication Journal'),
        'type' => 'text',
      ),
      'publication_journal_ranking' => array(
        'label' => t('Publication Journal Ranking'),
        'type' => 'decimal',
      ),
      'publication_types' => array(
        'label' => t('Publication Types'),
        'type' => 'list<taxonomy_term>',
        // 'type' => 'list<text>',
      ),
      'publication_author_names' => array(
        'label' => t('Publication Author Names'),
        'type' => 'list<text>',
      ),
      'publication_author_types' => array(
        'label' => t('Publication Author Types'),
        'type' => 'list<taxonomy_term>',
        // 'type' => 'list<text>',
      ),
      'publication_author_affiliations' => array(
        'label' => t('Publication Author Affiliations'),
        'type' => 'list<text>',
      ),
      'publication_author_firstlast_affiliations' => array(
        'label' => t('Publication First/Last Author Institutional Affiliations'),
        // 'type' => 'list<taxonomy_term>',
        'type' => 'list<text>',
      ),
    );
  }

  /**
   * Implements SearchApiAbstractAlterCallback::configurationForm().
   */
  public function configurationForm() {
    $form['ignored_types'] = array(
      '#title' => 'Ignored publication types',
      '#description' => t('Exclude certain publications from the search index based on their rdf:type values. Enter a comma-separated list of VIVO URIs. Publications with any of these types will be excluded.'),
      '#type' => 'textarea',
      '#default_value' => isset($this->options['ignored_types']) ? $this->options['ignored_types'] : '',
    );
    return $form;
  }
}
