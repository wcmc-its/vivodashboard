<?php
/**
 * @file
 * vivodashboard_publications.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function vivodashboard_publications_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'authorship';
  $relation_type->label = 'Authorship';
  $relation_type->reverse_label = 'Author of';
  $relation_type->directional = 1;
  $relation_type->transitive = 1;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'node:publication',
  );
  $relation_type->target_bundles = array(
    0 => 'node:author',
  );
  $export['authorship'] = $relation_type;

  return $export;
}
