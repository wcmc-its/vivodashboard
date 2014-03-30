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

    $format = $this->settings->settings['format'];
    $start = date('Y', strtotime($this->settings->settings['format']));
    $end = date('Y');

    if (!$active && $start && $end) {
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

