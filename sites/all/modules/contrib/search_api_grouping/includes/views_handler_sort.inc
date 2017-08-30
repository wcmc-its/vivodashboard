<?php
/**
 * @file
 * Contains SearchApiGroupingViewsHandlerSort.
 */

/**
 * Avoid exceptions about fields that originally where lists but due the
 * denormalizing now are single valued and thus sortable.
 */
class SearchApiGroupingViewsHandlerSort extends SearchApiViewsHandlerSort {

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Adjust the type of this field to avoid exceptions in parent::query(). All
    // fields handled by this handler have proven to be single value really.
    // Thus just extract the inner type and set it.
    $index = $this->query->getIndex();
    $index->options['fields'][$this->real_field]['type'] = search_api_extract_inner_type($index->options['fields'][$this->real_field]['type']);
    return parent::query();
  }

}
