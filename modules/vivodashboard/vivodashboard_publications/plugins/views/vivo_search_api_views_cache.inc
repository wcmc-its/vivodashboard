<?php

/**
 * @file
 * Contains the VivoSearchApiCache class.
 */

/**
 * Plugin class for caching Search API views.
 *
 * Changes from base:
 *  - Allows for invalidation based on a search index change as well as time.
 *  - Simplifies cache keys so results get cached for all user types.
 */
class VivoSearchApiViewsCache extends SearchApiViewsCache {


  function get_index_machine_name() {
    list(, $index) = explode('search_api_index_', $this->view->base_table);
    return $index;
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['index_purge'] = array('default' => 1);
    return $options;
  }

  function summary_title() {
    $title = parent::summary_title();
    $title .= ' <br/> Purge on updated index: '. ($this->options['index_purge']? 'Yes': 'No');
    return $title;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['index_purge'] = array(
      '#type' => 'checkbox',
      '#default_value' => $this->options['index_purge'],
      '#title' => t('Ignore these time settings when %index index has been updated', array('%index' => $this->get_index_machine_name()))
    );
    $form['warning']['#markup'] = t('WARNING: This cache plugin does not take into account user roles. This means that, if you use any node access controls, view results could be incorrect.');
    $form['warning']['#weight'] = -20;
  }

  /**
   * Overrides SearchApiViewsCache::cache_get().
   */
  public function cache_get($type) {

    // Figure out the last time an item in this index was processed.
    $index = $this->get_index_machine_name();
    $last_indexed = variable_get('vivo_search_api_last_indexed', array());
    $index_changed = isset($last_indexed[$index])?$last_indexed[$index]:0;
    $cache = cache_get($this->get_results_key(), $this->table);

    // If we just got cached data from the parent class, we need to decide if
    // it's still valid.
    $cache_hit = parent::cache_get($type);

    if($cache_hit && $this->options['index_purge'] && $index_changed > $cache->created ) {
      // So if there was an indexed item since cache invalidate our cache.
      $this->cache_flush();

      // This should trigger the new query.
      return parent::cache_get($type);
    }
    else {
      return $cache_hit;
    }
  }

  /**
   * Overrides SearchApiViewsCache::get_cache_key().
   */
  public function get_cache_key($key_data = array()) {
    global $user;

    // Removes all the user role bits so that all users get the same cache key.
    if (!isset($this->_results_key)) {
      $query = $this->getSearchApiQuery();
      $query->preExecute();
      $key_data += array(
        'query' => $query,
        'base_url' => $GLOBALS['base_url'],
        'current_page' => $this->view->get_current_page(),
      );
    }
    $key = md5(serialize($key_data));
    return $key;
  }
}
