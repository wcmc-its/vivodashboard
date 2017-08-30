<?php

/**
 * @file
 * Widgets for facets rendered as links.
 */

/**
 * Widget that renders facets as a list of clickable links.
 */
class FacetAPIGraphsWidgetGraphsComboData extends FacetapiWidget {

  /**
   * Overrides constructor to reset the key.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    $this->key = $facet['name'];
  }

  /**
   * Renders the data.
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];
    $all = $this->buildListItems($element);

    $element = array(
      '#theme' => 'item_list',
      '#items' => $all,
      '#attributes' => $this->build['#attributes'],
    );
  }

  /**
   * Builds the items.
   *
   * Recursive function that converts the render array into an array that can be
   * passed to theme_item_list().
   *
   * @param array $build
   *   The facet's render array.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  protected function buildListItems($build) {
    $settings = $this->settings->settings;
    $result = array(
      'data' => array(),
    );
    // Builds rows.
    $items = array();
    foreach ($build as $value => $item) {
      if ((($item['#active']) && (count($item['#item_children']) > 0)) || (!empty($settings['show_expanded']))) {
        return $this->buildListItems($item['#item_children']);
      }
      else {
        $result['data'][$item['#indexed_value']] = array(
          'name' => $item['#markup'],
          'count' => $item['#count'],
          'path' => $item['#path'],
        );
      }
    }
    return $result['data'];
  }

  /**
   * Returns defaults for the settings this widget provides.
   */
  public function getDefaultSettings() {
    return array(
      'title' => $this->facet['label'],
      'nofollow' => 1,
    );
  }

}
