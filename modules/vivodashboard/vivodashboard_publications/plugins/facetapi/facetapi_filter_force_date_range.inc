<?php

/**
 * Plugin that activates date facets with default value when there is no value.
 */
class VivodashboardPublicationsForceDateRange extends FacetapiFilter {

  /**
   * Redirects when the facet is not active.
   */
  public function execute(array $build) {
    $adapter = $this->adapter;

    $facet_info = facetapi_facet_load($this->settings->facet, $this->settings->searcher);
    $active = $adapter->getActiveItems($facet_info);

    // Check to see if the 'publication_timestamp' facet is active. In that case
    // we do not want to force a date range.
    $date_filter_info = facetapi_facet_load('publication_timestamp', $this->settings->searcher);
    $date_filter_active = $adapter->getActiveItems($date_filter_info);

    $format = $this->settings->settings['format'];
    $start = date('Y', strtotime($this->settings->settings['format']));
    $end = date('Y');

    if (!$active && !$date_filter_active && $start && $end) {
      $path = $adapter->getFacetPath($facet_info, array(), FALSE);
      $query = $adapter->getQueryString($facet_info, array("[$start TO $end]"), FALSE);
      drupal_goto($path, array('query' => $query));
    }

    return $build;
  }

  /**
   * Adds settings to the filter form.
   */
  public function settingsForm(&$form, &$form_state) {
    $form['format'] = array(
      '#title' => t('Date range'),
      '#type' => 'textfield',
      '#description' => t("Enter a !link, relative to the current date.", array('!link' => l('PHP relative date format', 'http://www.php.net/manual/en/datetime.formats.relative.php'))),
      '#default_value' => $this->settings->settings['format'],
    );
  }

  /**
   * Returns an array of default settings.
   */
  public function getDefaultSettings() {
    return array(
      'format' => '-5 years',
    );
  }
}

