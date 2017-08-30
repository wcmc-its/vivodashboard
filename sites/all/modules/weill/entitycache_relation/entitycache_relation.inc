<?php
/**
 * Contains EntityCacheRelationController class.
 */

/**
 * Relation entity controller with persistent cache.
 */
class EntityCacheRelationController extends RelationController {

  public function resetCache(array $ids = NULL) {
    EntityCacheControllerHelper::resetEntityCache($this, $ids);
    parent::resetCache($ids);
  }
  
  public function load($ids = array(), $conditions = array()) {
    return EntityCacheControllerHelper::entityCacheLoad($this, $ids, $conditions);
  }
}