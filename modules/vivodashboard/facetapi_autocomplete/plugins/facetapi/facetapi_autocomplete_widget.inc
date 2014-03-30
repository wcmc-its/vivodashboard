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

    // Suppressing notices due to FacetAPI expecting a #title attribute.
    // @see facetapi_block_view()
    $this->build['#title'] = '';
  }

  /**
   * Format the facet value to add as a URL param.
   */
  public function makeFacetValue($string) {
    return $this->facet['field alias'] . ':' . $string;
  }
}
