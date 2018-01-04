<?php

/**
 * Search API data alteration callback to attach properties for facets.
 */
class VivodashboardPublicationsAlterCallback extends SearchApiAbstractAlterCallback
{

    public function supportsIndex(SearchApiIndex $index)
    {
        return $index->getEntityType() === 'node' || $index->getEntityType() === 'relation';
    }

    public function alterItems(array &$items)
    {
        
        $last_indexed = variable_get('vivo_search_api_last_indexed', array());
        $last_indexed[$this->index->machine_name] = time();
        variable_set('vivo_search_api_last_indexed', $last_indexed);
        
        switch ($this->index->getEntityType()) {

            case 'node':
                $this->alterNodeItems($items);
                break;

            case 'relation':
                $this->alterRelationItems($items);
                break;
        }
    }

    public function alterNodeItems(array &$items, $target_author = NULL)
    {
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

            if (isset($wrapper->field_article_type) && $wrapper->field_article_type->raw()) {
                $item->publication_article_type = $wrapper->field_article_type->raw();
            }

            if (isset($wrapper->field_category) && $wrapper->field_category->raw()) {
                $item->publication_category = $wrapper->field_category->raw();
            }

            if (isset($wrapper->field_percentile_rank) && $wrapper->field_percentile_rank->raw()) {
                $item->publication_percentile_rank = $wrapper->field_percentile_rank->raw();
            }

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

                $author_names = array();
                
                foreach ($wrapper->authors as $delta => $author) {
                    
                    //for publication_authors_joined we care about *all* authors
                    $author_names[] = $this->formatAuthorName($author->title->value());

                    // If we're indexing authorships we only care about one author.
                    if ($target_author && ($target_author->nid != $author->nid->value())) {
                        continue;
                    }

                    // Add author name.
                    //*
                    $dept_name = '';
                    $author_cwid = db_query('SELECT a.cwid, a.first_name, a.last_name FROM {node} n LEFT JOIN {violin_wcmc_author} a ON n.nid = a.entity_id WHERE n.title = :author_name AND a.cwid <> :cwid', array(':author_name'=>$author->title->value(), ':cwid'=>""))->fetchObject();
                      if(!empty($author_cwid->cwid)) {
                        $dept_role = db_query("SELECT u.dept_name, MIN(a.weillCornellEduStartDate) as weillCornellEduStartDate, MAX(a.weillCornellEduEndDate) as weillCornellEduEndDate FROM violin_appointments a LEFT JOIN violin_org_units u ON a.weillCornellEduDepartment = u.dept_id WHERE weillCornellEduCWID = :cwid AND u.dept_name NOT IN('Weill Cornell Medical College', 'Weill Cornell Graduate College') GROUP BY u.dept_name ORDER BY a.weillCornellEduEndDate DESC, a.weillCornellEduStartDate DESC", array(':cwid'=>$author_cwid->cwid))->fetchObject();
                        if(!empty($dept_role->dept_name)) {
                          $dept_name = ' - ' . $dept_role->dept_name;
                        }
                      }
                    //*/
                      $item->publication_author_names[] = $author_cwid->first_name . ' ' . $author_cwid->last_name . $dept_name;
                    // $item->publication_author_names[] = $this->formatAuthorName($author->title->value()) . $dept_name;
                    
                    // Add field_rdf_type values for author.
                    foreach ($author->field_rdf_type->value() as $term) {
                        $item->publication_author_types[$term->tid] = $term->tid;
                        // $item->publication_author_types[$term->name] = $term->name;
                    }

                }
                
                $first_n_authors = 48;
                
                //when more than 50, use the first N and the last 2 . Previously 8 and count check was for 10
                if(count($author_names) > 50) {
                  $start = array_slice($author_names, 0, $first_n_authors);
                  $end = array_slice($author_names, -2);
                  $short_author_names = array_merge($start, array("(…)"), $end);
                }
                else {
                  $short_author_names = $author_names;  
                }
                
                //If the joined names wont fit in to the index column 255 limit
                //Try and build it with less first authors
                $joined = implode("|", $short_author_names);

                while(strlen($joined) > 255 && $first_n_authors >= 1) {
                 
                  $start = array_slice($author_names, 0, $first_n_authors);
                  $end = array_slice($author_names, -2);
                  $short_author_names = array_merge($start, array("(…)"), $end);                    
                  $joined = implode("|", $short_author_names);
                  
                  $first_n_authors--;
                }
                
                //fallback to truncate
                if(strlen($joined) > 255) {
                  $joined = substr($joined, 0, 254).'…';
                }
                
                $item->publication_authors_joined = $joined;
            }
        }
    }

    public function alterRelationItems(array &$items)
    {
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

    public function resetProperties(&$item)
    {
        $item->publication_title = NULL;
        $item->publication_article_type = NULL;
        $item->publication_category = NULL;
        $item->publication_percentile_rank = NULL;
        $item->publication_year = NULL;
        $item->publication_month = NULL;
        $item->publication_timestamp = NULL;
        $item->publication_graph_year = NULL;
        $item->publication_graph_month = NULL;
        $item->publication_journal = NULL;
        $item->publication_journal_ranking = NULL;
        $item->publication_types = array();
        $item->publication_author_names = array();
        $item->publication_authors_joined = null;
        $item->publication_author_types = array();
        $item->publication_author_affiliations = array();
        $item->publication_author_firstlast_affiliations = array();
    }


    // format author name
    public function formatAuthorName($name){
        $fmt_name = '';
        if(!empty($name)){
            // check if author name is of the pattern %,%
            if(!strpos($name, ',')){
                $fmt_name =  $name;
            }else {
                $parts = explode(',', $name);
                $fmt_name = $parts[1].' '.$parts[0];
            }
        }
        return $fmt_name ;
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
    public function propertyInfo()
    {
        return array(
            'publication_title' => array(
                'label' => t('Publication Title'),
                'type' => 'text',
            ),
            'publication_article_type' => array(
                'label' => t('Publication Article Type'),
                'type' => 'text',
            ),
            'publication_category' => array(
                'label' => t('Publication Category'),
                'type' => 'list<text>',
            ),
            'publication_percentile_rank' => array(
                'label' => t('Publication Percentile Rank'),
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
            'publication_authors_joined' => array(
                'label' => t('Publication Authors ranked and joined (pipe separated)'),
                'type' => 'text',
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
    public function configurationForm()
    {
        $form['ignored_types'] = array(
            '#title' => 'Ignored publication types',
            '#description' => t('Exclude certain publications from the search index based on their rdf:type values. Enter a comma-separated list of VIVO URIs. Publications with any of these types will be excluded.'),
            '#type' => 'textarea',
            '#default_value' => isset($this->options['ignored_types']) ? $this->options['ignored_types'] : '',
        );
        return $form;
    }
}
