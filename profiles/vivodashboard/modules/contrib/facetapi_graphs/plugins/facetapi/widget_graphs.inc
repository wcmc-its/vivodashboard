<?php

/**
 * @file
 * Widgets for facets rendered as links.
 */

/**
 * Widget that renders facets as a list of clickable links.
 */
class FacetAPIGraphsWidgetGraphs extends FacetapiWidget {

  /**
   * Overrides constructor to reset the key.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
  }

  /**
   * Renders the Graph.
   */
  public function execute() {
    $miniid = substr($this->id, 9);
    $element = &$this->build[$this->facet['field alias']];
    $all = $this->buildListItems($element);

    /*
     *  Check if there is data returned at all else bail
     */
    if (isset($all)) {
      $keys = array_keys($all['data']);
    }

    if ((!isset($all) || (count($all['data']) == 0) || (count($all['data'][$keys[0]]) == 0))) {
      // TODO: make this listen to the setting on the Widget.
      if ($this->build['#settings']->settings['empty_behavior'] == 'text') {
        // Provide a rather long summary of the empty text.
        $element['#markup'] = text_summary($this->build['#settings']->settings['empty_text']['value'], $this->build['#settings']->settings['empty_text']['format'], 65000);
      }
      return;
    }

    $rows = $all['data'];
    $x_labels = $all['labels'];
    $graph = charts_graphs_get_graph($this->settings->settings[$miniid . 'engine']);
    $graph->set_data($rows, $x_labels);
    /*
     * Set our options.
     */
    $engine = $this->settings->settings[$miniid . 'engine'];
    $graph->title = $this->settings->settings[$miniid . 'title'];
    $graph->type = $this->settings->settings[$miniid . $engine];

    $graph->width = (!empty($this->settings->settings[$miniid . 'width'])) ? $this->settings->settings[$miniid . 'width'] : 500;
    $graph->height = (!empty($this->settings->settings[$miniid . 'height'])) ? $this->settings->settings[$miniid . 'height'] : 400;

    $graph->y_min = (!empty($this->settings->settings[$miniid . 'y_min'])) ? $this->settings->settings[$miniid . 'y_min'] : NULL;
    $graph->y_max = (!empty($this->settings->settings[$miniid . 'y_max'])) ? $this->settings->settings[$miniid . 'y_max'] : NULL;
    $graph->y_step = (!empty($this->settings->settings[$miniid . 'y_step'])) ? $this->settings->settings[$miniid . 'y_step'] : NULL;
    $graph->y_legend = (!empty($this->settings->settings[$miniid . 'y_legend'])) ? $this->settings->settings[$miniid . 'y_legend'] : NULL;
    $graph->background_colour = (!empty($this->settings->settings[$miniid . 'background_colour'])) ? $this->settings->settings[$miniid . 'background_colour'] : NULL;
    $graph->series_colours = (!empty($this->settings->settings[$miniid . 'series_colours'])) ?
                              explode(',', $this->settings->settings[$miniid . 'series_colours']) :
                              array('#123456', '#654321', '#1177ff');
    $graph->showlegend = $this->settings->settings[$miniid . 'showlegend'];
    $graph->zoom = $this->settings->settings[$miniid . 'showzoom'];
    /*
     * And lets render!
     */
    $element = $graph->get_chart();
  }

  /**
   * Builds the list items.
   *
   * Recursive function that converts the render array into an array that can
   * be passed to the graph.
   *
   * @param array $build
   *   The facet's render array.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  protected function buildListItems($build) {
    $me = $this->getBuild();
    $key = $me['#facet']['field alias'];
    $settings = $this->settings->settings;
    $result = array(
      'data' => array(
        $this->key => array(),
      ),
      'labels' => array(),
    );
    // Builds rows.
    $items = array();
    foreach ($build as $value => $item) {
      if ((($item['#active']) && (count($item['#item_children']) > 0)) || (!empty($settings['show_expanded']))) {
        $result = $result + $this->buildListItems($item['#item_children']);
      }
      else {
        $result['data'][$key][] = $item['#count'];
        $result['labels'][] = $item['#markup'];
      }
    }
    return $result;
  }

  /**
   * Adds the soft limit setting.
   */
  public function settingsForm(&$form, &$form_state) {

    drupal_add_js(drupal_get_path('module', 'facetapi_graphs') . '/plugins/facetapi/widget_graphs.js');
    drupal_add_css(drupal_get_path('module', 'facetapi_graphs') . '/plugins/facetapi/widget_graphs.css');

    $miniid = substr($this->id, 9);

    $form['widget']['widget_settings'][$miniid][$this->id][$miniid . 'title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => $this->settings->settings[$miniid . 'title'],
      '#weight' => -20,
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'] = array(
      '#type' => 'fieldset',
      '#title' => t('Graph Settings'),
      '#description' => t('Settings for the Flot Graph.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
      '#weight' => 0,
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'width'] = array(
      '#type' => 'textfield',
      '#title' => t('Canvas width'),
      '#description' => t('Canvas width, for libraries that support it you can supply a percentage, otherwise, provide a number for pixels. Defaults to 600px when input is invalid.'),
      '#default_value' => $this->settings->settings[$miniid . 'width'],
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'height'] = array(
      '#type' => 'textfield',
      '#title' => t('Canvas height'),
      '#description' => t('Canvas height in pixels only.  Defaults to 500px when input is invalid.'),
      '#default_value' => $this->settings->settings[$miniid . 'height'],
    );

    $engines = array();
    $types = array();
    $api_names = array();

    foreach ($apis = $this->charts_graphs_apis() as $api) {
      $engines[$api->name] = $api->nice_name;
      $types[$api->name] = $api->chart_types;
      $api_names[] = $api->name;
    }

    sort($api_names);

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'engine'] = array(
      '#type' => 'select',
      '#title' => t('Charting Engine'),
      '#options' => $engines,
      '#default_value' => $this->settings->settings[$miniid . 'engine'],
    );

    $current_engine = empty($this->settings->settings[$miniid . 'engine']) ?
      $api_names[0] :
      $this->settings->settings[$miniid . 'engine'];

    foreach ($types as $engine => $type) {
      $default = !empty($this->settings->settings[$miniid . $engine]) ?
        $this->settings->settings[$miniid . $engine] :
        $default = array_shift(array_keys($type)
      );
      $hidden = NULL;

      if ($engine != $current_engine) {
        $hidden = 'facetapi_graphs_chart_types_hidden';
      }

      $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . $engine] = array(
        '#type' => 'radios',
        '#title' => t('Chart Type'),
        '#options' => $type,
        '#required' => TRUE,
        '#default_value' => $default,
        '#prefix' => sprintf(
          '<div class="facetapi_graphs_chart_types facetapi_graphs_%s_chart_types %s">',
          $engine,
          $hidden
        ),
        '#suffix' => '</div>',
      );
    }

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'y_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Minimun value of Y Axis'),
      '#default_value' => ($this->settings->settings[$miniid . 'y_min']) ? $this->settings->settings[$miniid . 'y_min'] : '',
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'y_max'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximun value of Y Axis'),
      '#default_value' => ($this->settings->settings[$miniid . 'y_max']) ? $this->settings->settings[$miniid . 'y_max'] : '',
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'y_step'] = array(
      '#type' => 'textfield',
      '#title' => t('Step value of Y Axis'),
      '#default_value' => ($this->settings->settings[$miniid . 'y_step']) ? $this->settings->settings[$miniid . 'y_step'] : '',
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'y_legend'] = array(
      '#type' => 'textfield',
      '#title' => t('Y Legend'),
      '#default_value' => $this->settings->settings[$miniid . 'y_legend'],
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'background_colour'] = array(
      '#type' => 'textfield',
      '#title' => t('Graph background colour'),
      '#description' => t('Define the colour in hexadecimal: #RRGGBB'),
      '#default_value' => $this->settings->settings[$miniid . 'background_colour'],
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'series_colours'] = array(
      '#type' => 'textfield',
      '#title' => t('Series colours'),
      '#description' => t('Define the colour of each series as a comma separated list of hexadecimal colour definitions. Ex: #123456,#654321,#1177ff'),
      '#default_value' => $this->settings->settings[$miniid . 'series_colours'],
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'showlegend'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show Legend'),
      '#description' => t('Show or hide the legend, if the library supports it.'),
      '#default_value' => $this->settings->settings[$miniid . 'showlegend'],
    );

    $form['widget']['widget_settings'][$miniid][$this->id]['graphs'][$miniid . 'showzoom'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show Zoom (flot only)'),
      '#description' => t('Show or hide the zoom, if the library supports it.'),
      '#default_value' => $this->settings->settings[$miniid . 'showzoom'],
    );

    // @see http://drupal.org/node/1370342
    $form['widget']['widget_settings'][$miniid][$this->id][$miniid . 'nofollow'] = array(
      '#type' => 'checkbox',
      '#title' => t('Prevent crawlers from following facet links'),
      '#default_value' => !empty($this->settings->settings[$miniid . 'nofollow']),
      '#description' => t('Add the <code>rel="nofollow"</code> attribute to facet links to maximize SEO by preventing crawlers from indexing duplicate content and getting stuck in loops.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );
  }

  /**
   * Returns defaults for the settings this widget provides.
   *
   * All settings are keyd uniquely so they wont override
   * settings from other possible widgets (eg. links).
   */
  public function getDefaultSettings() {
    $miniid = substr($this->id, 9);
    return array(
      $miniid . 'title' => $this->facet['label'],
      $miniid . 'showzoom' => 0,
      $miniid . 'engine' => 'flot',
      $miniid . 'nofollow' => 1,
      $miniid . 'width' => '500',
      $miniid . 'height' => '400',
      $miniid . 'y_min' => NULL,
      $miniid . 'y_max' => NULL,
      $miniid . 'y_step' => NULL,
      $miniid . 'y_legend' => NULL,
      $miniid . 'background_colour' => '#fff',
      $miniid . 'series_colours' => NULL,
      $miniid . 'showlegend' => 1,
    );
  }

  /**
   * Helper function to get different libraries.
   *
   * @param string $library
   *   The name of the used library eg. flot.
   *
   * @see charts_graphs_apis()
   */
  protected function charts_graphs_apis($library = NULL) {
    $function = function_exists('chart_graphs_apis') ?
    'chart_graphs_apis' :
    'charts_graphs_apis';
    if ($library === NULL) {
      return call_user_func($function);
    }
    else {
      return call_user_func($function, $library);
    }
  }

  /**
   * Helper function that returns a list of graphtypes for a certain library.
   *
   * @param string $library
   *   The name of the used library eg. flot.
   *
   * @see charts_graphs_apis()
   */
  protected function charts_graphs_get_graph($library) {
    $function = function_exists('chart_graphs_get_graph') ?
    'chart_graphs_get_graph' :
    'charts_graphs_get_graph';
    return call_user_func($function, $library);
  }
}
