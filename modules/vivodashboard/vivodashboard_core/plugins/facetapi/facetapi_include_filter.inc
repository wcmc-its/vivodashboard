<?php

/**
 * Plugin that includes only specified facet items.
 */
class VivodashboardCoreIncludeFilter extends FacetapiFilter {

  /**
   * Filters facet items.
   */
  public function execute(array $build) {
    $include_list = preg_split('/[\n\r]+/', $this->settings->settings['include']);

    $filtered_build = array();
    foreach ($build as $key => $item) {
      $include = FALSE;
      foreach ($include_list as $include_item) {
        if (!empty($item)) {
          $string = strtolower($include_item);
          $include |= (strtolower($item['#indexed_value']) == $string || strtolower($item['#markup']) == $string);
        }
      }
      if ($include) {
        $filtered_build[$key] = $item;
      }
    }

    return $filtered_build;
  }

  /**
   * Adds settings to the filter form.
   */
  public function settingsForm(&$form, &$form_state) {
    $form['include'] = array(
      '#title' => t('Include items'),
      '#type' => 'textarea',
      '#description' => t("List of titles or values that should be included, matching either an item's title or value, case insensitive. Place each on a new line."),
      '#default_value' => $this->settings->settings['include'],
      '#rows' => 10,
    );
  }

  /**
   * Returns an array of default settings.
   */
  public function getDefaultSettings() {
    return array(
      'include' => '',
    );
  }
}

