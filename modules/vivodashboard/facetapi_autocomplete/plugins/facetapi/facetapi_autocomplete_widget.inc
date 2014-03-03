<?php

/**
 * Widget that renders facets as a text input for autocomplete.
 *
 * @see facetapi_autocomplete_form()
 */
class FacetapiAutocompleteWidget extends FacetapiWidgetLinks {

  /**
   * Override parent::init() to avoid sorting.
   */
  public function init() {
    return;
  }

  /**
   * Renders the facet.
   */
  public function execute() {
    $count = &drupal_static('FacetapiAutocompleteWidget:execute', 0);
    $form_id = 'facetapi_autocomplete_form_' . ++$count;
    $build = &$this->build[$this->facet['field alias']];
    $build = drupal_get_form($form_id, $this, $build);
  }

  /**
   * Format the facet value to add as a URL param.
   */
  public function makeFacetValue($string) {
    return $this->facet['field alias'] . ':' . $string;
  }

  /**
   * Produce an array of values structured for the Select2 plugin.
   */
  public static function getAutocompleteValues($keywords, $build) {
    $values = array();
    $keywords = strtoupper(trim($keywords));

    if (empty($keywords)) {
      return $values;
    }

    foreach ($build as $item) {

      // Do not include active facet items.
      if (!empty($item['#active'])) {
        continue;
      }

      $indexed = strtoupper($item['#indexed_value']);
      $markup = strtoupper($item['#markup']);

      // Perform a very basic string match on the indexed and rendered values.
      if (strpos($indexed, $keywords) !== FALSE || strpos($markup, $keywords) !== FALSE) {
        $values[] = array(
          'id' => $item['#indexed_value'],
          'text' => $item['#markup'] . ' (' . $item['#count'] . ')',
        );
      }
    }

    // @todo - Use soft limit from facet settings.
    $values = array_slice($values, 0, 20);

    return $values;
  }
}
