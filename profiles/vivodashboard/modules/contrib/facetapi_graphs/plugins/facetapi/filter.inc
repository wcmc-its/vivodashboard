<?php

/**
 * @file
 * Filter that adds additional data from another facet to the current
 * results
 */

/**
 * Plugin that adds subitems from another facet to the current facet
 * This allows the FacetAPIComboGraphs widget to draw graphs with
 * multiple bars next to eachother
 */
class FacetapiFilterGraphCombo extends FacetapiFilter {

  protected $querytype;

  protected $facet;

  protected $facetbuild;

  /**
   * Contructs our Filter Graph Combo.
   *
   * @see FacetapiFilter::__construct()
   */
  public function __construct($id, $adapter, $settings) {
    parent::__construct($id, $adapter, $settings);
    $adapter = $this->adapter;
    $facets = facetapi_get_enabled_facets($adapter->getSearcher());
    $this->facet = $facets[$this->settings->facet];
    if (!($this->querytype == $this->facet['query types'])) {
      // eg. date, term.
      $this->querytype = $facets[$this->settings->facet]['query types'][0];
    }
    /*
     *  We first get a built facet without filter for the Y-Facet
     *  this will contain all possible values we can retrieve for the
     *  subfiltered results.
     *  We then later iterate through these options and, from the filtered
     *  results, only copy the count in.
     */
    if ($yfacetname = $this->settings->settings['yfacet']) {
      if ($yfacetinfo = facetapi_facet_load($yfacetname, $this->settings->searcher)) {
        $realm = facetapi_realm_load('facetapi_graphs_graphs_data_combo');

        $yfacetinstance = $this->adapter->getFacet($yfacetinfo);

        $freshprocessor = new FacetapiFacetProcessor($yfacetinstance);
        $freshprocessor->process();

        /*
        *  This will hold all our options.
        */
        $this->facet_build = $yfacetinstance->build($realm, $freshprocessor);
      }
    }

  }

  /**
   * The Settings Form.
   *
   * @see FacetapiFilter::settingsForm()
   */
  public function settingsForm(&$form, &$form_state) {
    $adapter = $this->adapter;
    $facets = facetapi_get_enabled_facets($adapter->getSearcher(), 'facetapi_graphs_graphs_data_combo');
    $yfacets = array();
    foreach ($facets as $facet) {
      $yfacets[$facet['name']] = $facet['label'];
    }

    $form['yfacet'] = array(
      '#type' => 'select',
      '#title' => t('Y Facet'),
      '#description' => t("Return subitems of the Y Facet for each value in the current facet.
          The Y facet values + counts will show on the Y axis of the graph. The results of the
          current facet will be shown on the x-axis. These facets are taken from the 'Data Combo Realm',
          thus they need to be active there."),
      '#options' => $yfacets,
      '#default_value' => $this->settings->settings['yfacet'],
      '#weight' => -10,
    );
  }

  /**
   * Implements FacetapiFilter::execute().
   *
   * This is a very weird Filter filter as it will try to
   * add subitems to each item in the $build array.
   */
  public function execute(array $build) {
    /*
     *  We have to add all missing keys to all returned subitems
     *  with a count of 0
     *  Else, the series would go out of step on the graph
     *  We collect all possible keys in $allkeys
     */
    $allkeys = array();
    reset($build);
    $first_key = key($build);

    /*
    *  First find the deepest level of hierarchical facets
    *  like filter on Month for date facets that show
    *  2012/Jan,Feb etc.
    */

    $build = $this->addsubitems($build);
    return $build;
  }

  /**
   * Fetches results for Y-Axis facet for a result on the X-Axis.
   */
  protected function addsubitems($build, $force = FALSE) {
    foreach ($build as $key => $item) {
      if ((($item['#active'] == 1) || (empty($item['#item_parents']))) || $force) {
        if ($results = $this->addFilter($this->settings->facet, $item['#indexed_value'])) {
          $mapfunction = $this->facet['map callback'];
          $renderresults = array();
          foreach ($results['search_api_facets'][$this->facet['field alias']] as $value) {
            $renderresults[] = str_replace('"', '', $value['filter']);
          }
          /*
           * This is where the magic is supposed to happen.
          */
          $rendered = call_user_func($mapfunction, $renderresults, $this->facet['map options']);
          if (!isset($results['search_api_facets'][$this->settings->settings['yfacet']])) {
            return "";
          }

          foreach ($results['search_api_facets'][$this->settings->settings['yfacet']] as $tpresult) {
            $labelkey = str_replace('"', '', $tpresult['filter']);
            if (isset($this->facet_build[$this->settings->settings['yfacet']][$this->settings->settings['yfacet']]['#items'][$labelkey])) {
              $label = $this->facet_build[$this->settings->settings['yfacet']][$this->settings->settings['yfacet']]['#items'][$labelkey]['name'];
              $build[$item['#indexed_value']]['#subitems'][$label]['name'] = $label;
              $build[$item['#indexed_value']]['#subitems'][$label]['count'] = $tpresult['count'];
              // TODO implement links in graphs.
              $build[$item['#indexed_value']]['#subitems'][$label]['path'] = '';
            }
          }
        }
        if ($item['#item_children']) {
          $build[$key]['#item_children'] = $this->addsubitems($item['#item_children'], ($item['#active'] == 1));
        }
      }
    }
    return $build;
  }

  /**
   * Does the filtering.
   *
   * Adds a filter to the index that our current facet belongs
   * to, then fires the query and returns the results.
   */
  protected function addFilter($field, $value) {
    $id = substr($this->adapter->getsearcher(), strpos($this->adapter->getsearcher(), '@') + 1);

    $index = search_api_index_load($id, TRUE);
    $query = $index->query(array(
      'parse mode' => 'terms',
      // Give this search a unique key.
      // Looks a bit funny as this is not a real unique id.
      'search id' => 'facetapicombo:hash',
      )
    );

    if ($this->querytype == 'date') {
      $regex = str_replace(array('^', '$'), '', FACETAPI_REGEX_DATE);
      $newvalue = preg_replace_callback($regex, array($this, 'replaceDateString'), $value);
      $filter = $query->createFilter('AND');
      $this->addFacetFilter($filter, $field, $newvalue);
    }
    else {
      $filter = $query->createFilter('AND');
      $filter->condition($field, $value, '=');
    }

    $query->filter($filter);

    $results = $query->execute();
    return $results;
  }

  /**
   * Sets default settings.
   * @see FacetapiFilter::getDefaultSettings()
   */
  public function getDefaultSettings() {
    return array(
      'yfacet' => "",
    );
  }

  /**
   * Replacement callback for replacing ISO dates with timestamps.
   *
   * Copied from the query_type_date.inc from facetapi.
   */
  public function replaceDateString($matches) {
    return strtotime($matches[0]);
  }

  /**
   * Helper method for setting a facet filter on a query or query filter object.
   *
   * Copied from the query_type_date.inc from facetapi.
   */
  protected function addFacetFilter($query_filter, $field, $filter) {
    /*
     * Integer (or other nun-string) filters might mess up some of the following
     * comparison expressions.
     */
    $filter = (string) $filter;
    if ($filter == '!') {
      $query_filter->condition($field, NULL);
    }
    elseif ($filter[0] == '[' && $filter[strlen($filter) - 1] == ']' && ($pos = strpos($filter, ' TO '))) {
      $lower = trim(substr($filter, 1, $pos));
      $upper = trim(substr($filter, $pos + 4, -1));
      if ($lower == '*' && $upper == '*') {
        $query_filter->condition($field, NULL, '<>');
      }
      else {
        if ($lower != '*') {
          /*
           * If we have a range with two finite boundaries, we set two
           * conditions (larger than the lower bound and less than the upper
           * bound) and therefore have to make sure that we have an AND
           * conjunction for those.
           */
          if ($upper != '*' && !($query_filter instanceof SearchApiQueryInterface || $query_filter->getConjunction() === 'AND')) {
            $original_query_filter = $query_filter;
            $query_filter = new SearchApiQueryFilter('AND');
          }
          $query_filter->condition($field, $lower, '>=');
        }
        if ($upper != '*') {
          $query_filter->condition($field, $upper, '<');
        }
      }
    }
    else {
      $query_filter->condition($field, $filter);
    }
    if (isset($original_query_filter)) {
      $original_query_filter->filter($query_filter);
    }
  }
}
