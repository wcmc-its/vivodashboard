<?php

/**
 * Plugin that fills in years not returned in facet items.
 */
class VivodashboardCoreEmptyYearsFilter extends FacetapiFilter {

  /**
   * Filters facet items.
   */
  public function execute(array $build) {
    ksort($build);
    $oldest_year = key($build);
    $build = array_reverse($build, TRUE);
    $most_recent_year = key($build);

    if (!is_numeric($oldest_year) || !is_numeric($most_recent_year)) {
      return;
    }

    foreach (range($oldest_year, $most_recent_year) as $year) {
      if (!isset($build[$year])) {
        $build[$year] = $build[$most_recent_year];
        $build[$year]['#markup'] = $year;
        $build[$year]['#indexed_value'] = $year;
        $build[$year]['#count'] = 0.02;
      }
    }

    ksort($build);
    return $build;
  }
}

