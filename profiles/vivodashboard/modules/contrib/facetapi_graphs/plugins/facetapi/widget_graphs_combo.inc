<?php

/**
 * @file
 * Widgets for facets rendered a graph where the data is a combination of
 * 2 different facets.
 * The 'other' facet is set through the ComboGraph filter
 * Note that the execute function is not implemented but used
 * from the parent class
 */

/**
 * Widget that renders facets as a graph based on this and a second facet.
 */
class FacetAPIGraphsWidgetGraphsCombo extends FacetAPIGraphsWidgetGraphs {

  /*
   * Which level of a hierarchy are we currently rendering.
   */
  protected $level;

  /*
   * If there are no active items in a hierarchy, only render the
   * items in the root.
   *
   */
  protected $renderroot;

  /**
   * Overrides constructor to reset the key.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet,
                              stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    // TODO Do we need the realm here too ? dont know.
    $this->key = $facet['name'];
    $this->level = 0;
    $this->renderroot = TRUE;
  }

  /**
   * Build the List Items.
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
  protected function buildListItems(&$build) {
    if ((!isset($this->settings->settings['filters']['graph_combo_filter'])) || ($this->settings->settings['filters']['graph_combo_filter']['status'] == 0)) {
      drupal_set_message("This type of facet must have a filter of type 'Graph Combo' before you can use it. " . $this->key, "error");
      return;
    }

    /*
     *  If there are more than 1 results to show, only show the deepest level
     *  if the facet is filtered by one of the results.
     *  This is to make sure that hierarchical taxonomies with a filter on
     *  parent & child
     *  render the child, and not the parent
     */
    if ($this->level == 0) {
      foreach ($build as $item) {
        if (($item['#active'] == 1) && (!(empty($item['#item_children'])))) {
          $this->renderroot = FALSE;
          break;
        }
      }
    }

    $result = array(
      'data' => array(),
      'labels' => array(),
    );

    // Builds rows.
    $items = array();
    foreach ($build as $value => $item) {
      if (!empty($item['#item_children']) && (!$this->renderroot)) {
        $this->level++;
        $childresults = $this->buildListItems($item['#item_children']);
        if (count(($childresults['data'])) > 0) {
          foreach ($childresults['data'] as $childkey => $childresult) {
            if (isset($result['data'][$childkey])) {
              $result['data'][$childkey] = $result['data'][$childkey] + $childresult;
            }
            else {
              $result['data'][$childkey] = $childresult;
            }
          }
          $result['labels'] = array_merge($result['labels'], $childresults['labels']);
        }
      }
      if (empty($item['#item_parents'])) {
        $this->level = 0;
      }
      if ((isset($item['#subitems'])) && (empty($childresults['data']))) {
        if (($this->renderroot) || ($this->level > 0)) {
          $result['labels'][] = $item['#markup'];
          foreach ($item['#subitems'] as $subitem) {
            $result['data'][$subitem['name']][$item['#markup']] = $subitem['count'];
          }
        }
      }
    }
    /*
     * We need to fill/pad all non-existent [data][keyxyz] values
     *with 0 else the graph wont work.
     */
    foreach ($result['labels'] as $key => $label) {
      foreach ($result['data'] as $valuekey => $value) {
        if (!isset($result['data'][$valuekey][$label])) {
          $item = array(
            $label => 0,
          );
          // Insert the missing name + value 0.
          $result['data'][$valuekey] = $this->ArrayInsert($result['data'][$valuekey], $item, $key);
        }
      }
    }
    // Make sure all labels are unique.
    $result['labels'] = array_unique($result['labels']);
    return $result;
  }

  /**
   * Local helper function to splice an array while keeping the keys.
   *
   * @param array $array
   *   input array
   * @param array $values
   *   keyed array to be inserted
   * @param int $offset
   *   place in the array where $values needs to be inserted
   */
  protected function ArrayInsert($array, $values, $offset) {
    return array_slice($array, 0, $offset, TRUE) + $values + array_slice($array, $offset, NULL, TRUE);
  }

  /**
   * Settings Form.
   *
   * @see FacetAPIGraphsWidgetGraphs::settingsForm()
   */
  public function settingsForm(&$form, &$form_state) {
    $miniid = substr($this->id, 9);
    if ((isset($this->settings->settings['filters']['graph_combo_filter'])) && ($this->settings->settings['filters']['graph_combo_filter']['status'] == 1)) {
      parent::settingsForm($form, $form_state);
    }
    else {
      $form['widget']['widget_settings'][$miniid][$this->id][$miniid . 'message'] = array(
        '#type' => 'markup',
        '#markup' => t("You must first add a filter of type 'Graph Combo' to this facet before you can select this option."),
        '#states' => array(
          'visible' => array(
            'select[name="widget"]' => array('value' => $this->id),
          ),
        ),
      );
    }
  }
}
