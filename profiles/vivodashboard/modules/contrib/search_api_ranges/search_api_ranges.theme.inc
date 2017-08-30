<?php

/**
 * @file
 * Theme functions for Min/Max UI Slider widget
 */

/**
 * Theme a jQuery slider.
 *
 * @param array $variables
 */
function theme_search_api_ranges_slider(array $variables) {
  $output = '';
  $output .= render($variables['slider']);

  return $output;
}
