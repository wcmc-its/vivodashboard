<?php

/**
 *
 */
class VivoDasbhboardChartsgraphsFlot extends ChartsGraphsFlot {

  /**
   * Function that renders data.
   */
  public function get_chart() {
    $element = parent::get_chart();

    $options = $element['#options'];
    $data = &$element['#data'][0];

    $options->hoverable = TRUE;

    $options->series->bars->fillColor = '#800000';
    $options->series->highlightColor = '#B00000';

    $options->grid->backgroundColor = '#fff';
    $options->grid->tickColor = '#fff';
    $options->grid->labelMargin = 5;
    $options->grid->margin = (object) array('bottom' => 10);

    $options->yaxis->tickColor = '#f0f0f0';
    $options->yaxis->tickSize = 1;
    $options->yaxis->tickDecimals = 0;

    // Find the largest bar.
    $largest = 0;
    foreach ($data->data as $item) {
      if (isset($item[1]) && $item[1] > $largest) {
        $largest = $item[1];
      }
    }

    $rowSize = 1;

    // Aim to have 6 rows on the yaxis (including 0).
    if ($largest/5 > 1) {
      $rowSize = ceil($largest/5);
    }

    // Round large row sizes.
    if ($largest > 500) {
      $rowSize = ceil($rowSize / 100) * 100;
    }
    elseif ($largest > 50) {
      $rowSize = ceil($rowSize / 10) * 10;
    }

    $options->yaxis->tickSize = $rowSize;

    // When the number of bars is small we adjust the widths so we don't end up
    // with fat bars. The way Flot sizes bars is a little confusing.
    // See http://stackoverflow.com/questions/15634018/consistent-bar-widths-in-flot-charts
    $num_bars = count($data->data);
    if ($num_bars < 4) {
      $num_spaces = 4;
      $options->xaxis->min = -($num_spaces - $num_bars) / 2;
      $options->xaxis->max = $num_bars - 1 + ($num_spaces - $num_bars) / 2;
    }

    if ($num_bars > 24) {
      $options->xaxis->show = FALSE;
    }
    elseif ($num_bars > 12) {
      $options->xaxis->rotateTicks = 135;
      $options->grid->labelMargin = 1;
    }

    // Add Flot plugin for rotating labels.
    drupal_add_js(libraries_get_path('flot-tickrotor') . '/jquery.flot.tickrotor.js', array('weight' => 10));

    // Attach JS for tooltips on hover.
    drupal_add_js(drupal_get_path('module', 'vivodashboard_core') . '/plugins/charts_graphs/vivodashboard_chartsgraphs_flot.js', array('weight' => 10));

    return $element;
  }

}
