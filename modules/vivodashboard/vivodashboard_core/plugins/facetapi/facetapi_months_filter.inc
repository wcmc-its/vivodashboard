<?php

/**
 * Plugin that converts numbers to months.
 */
class VivodashboardCoreConvertMonthsFilter extends FacetapiFilter {

  /**
   * Turn indexed integers into month names.
   */
  public function execute(array $build) {
    foreach ($build as $key => &$item) {
      $value = $item['#indexed_value'];
      if (is_numeric($value) && ($date = date_create_from_format('n', $value))) {
        $item['#markup'] = $date->format('M');
      }
    }
    return $build;
  }
}

