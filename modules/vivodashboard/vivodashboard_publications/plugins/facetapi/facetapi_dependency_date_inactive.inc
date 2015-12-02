<?php

/**
 * Adds a dependency on another facet being inactive.
 */
class VivodashboardPublicationsDateInactive extends FacetapiDependency {

  /**
   * Executes the dependency check.
   */
  public function execute() {
    if (!$this->settings['enabled']) {
      return;
    }

    $date_filter_active = !empty($this->activeItems['publication_year']);

    if ($date_filter_active) {
      $item = reset($this->activeItems['publication_year']);
      $range = explode(' TO ', trim($item['value'], '{[]}'));
      if ($range && $range[0] == $range[1]) {
        return (bool) $this->settings['single_year'];
      }
    }

    if ($this->settings['hide']) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Adds dependency settings to the form.
   */
  public function settingsForm(&$form, &$form_state) {
    $form[$this->id]['enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enabled'),
      '#description' => t('Enable showing/hiding of this facet based on the date filter.'),
      '#default_value' => $this->settings['enabled'],
    );
    $form[$this->id]['hide'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide when no date filter'),
      '#description' => t('Hide this facet when the user has not selected a date range.'),
      '#default_value' => $this->settings['hide'],
    );
    $form[$this->id]['single_year'] = array(
      '#type' => 'radios',
      '#title' => t('Single years'),
      '#description' => t('Choose whether to show this facet when the user has selected a single year range.'),
      '#default_value' => $this->settings['single_year'],
      '#options' => array(
        0 => 'Hide this facet when a single year is selected as a date range.',
        1 => 'Show this facet when a single year is selected as a date range.',
      ),
    );
  }

  /**
   * Returns defaults for settings.
   */
  public function getDefaultSettings() {
    return array(
      'enabled' => FALSE,
      'hide' => FALSE,
      'single_year' => 0,
    );
  }

}
