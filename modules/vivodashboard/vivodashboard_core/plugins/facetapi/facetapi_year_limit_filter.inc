<?php

/**
 * Plugin that slices a range of years.
 */
class VivodashboardCoreYearLimitFilter extends FacetapiFilter {

  /**
   * Filters facet items.
   */
  public function execute(array $build = NULL) {
    // Exceptions are being thrown because Facet API is passing null instead
    // of an array. Workaround...
    if (!$build) {
      return array();
    }
    ksort($build);
    $build = array_reverse($build, TRUE);
    $build = array_slice($build, 0, $this->settings->settings['limit'], TRUE);
    return array_reverse($build, TRUE);
  }

  /**
   * Adds settings to the filter form.
   */
  public function settingsForm(&$form, &$form_state) {
    $form['limit'] = array(
      '#title' => t('Maximum number of years'),
      '#type' => 'textfield',
      '#description' => t("The maximum number of years to display, starting from the most recent."),
      '#default_value' => $this->settings->settings['limit'],
      '#size' => 3,
    );
  }

  /**
   * Returns an array of default settings.
   */
  public function getDefaultSettings() {
    return array(
      'limit' => 12,
    );
  }
}

