<?php

/**
 * @file
 * Contains the VivoSearchApiCache class.
 */

/**
 * Plugin class for caching Search API views.
 * changes from base: 
 *  allows for invalidation based on a search index change as well as time
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
  }
  
  /**
   * Overrides SearchApiViewsCache::cache_get().
   */
  public function cache_get($type) {
    
    //figure out the last time an item in this index was processed
    $index = $this->get_index_machine_name();
    $last_indexed = variable_get('vivo_search_api_last_indexed', array());
    $changed = isset($last_indexed[$index])?$last_indexed[$index]:0;
    $cache = cache_get($this->get_results_key(), $this->table);
    
    //If we just got cached data from the parent class, we need to decide if it's still valid
    $cache_hit = parent::cache_get($type);    

    if($cache_hit && $changed > $cache->created ) {
      //So if theer was in indexed item since cache
      //invalidate our cache
      $this->cache_flush();
      
      //this should trigger the new query      
      return parent::cache_get($type);
    }
    else {
      return $cache_hit;  
    }
    
  }


}
