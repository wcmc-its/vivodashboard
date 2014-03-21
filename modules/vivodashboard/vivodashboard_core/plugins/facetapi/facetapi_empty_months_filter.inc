<?php

/**
 * Plugin that fills in months not returned in facet items.
 */
class VivodashboardCoreEmptyMonthsFilter extends FacetapiFilter {

  /**
   * Filters facet items.
   */
  public function execute(array $build) {
    if (!empty($build)) {
      foreach (range(1, 12) as $month) {
        if (!isset($build[$month])) {
          $build[$month] = reset($build);
          $build[$month]['#markup'] = $month;
          $build[$month]['#indexed_value'] = $month;
          // Give a small value so graphs will actually render something.
          $build[$month]['#count'] = 0.02;
        }
      }
    }
    return $build;
  }
}

