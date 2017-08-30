<?php
/**
 * @file
 * Views hook implementations for the Search API Grouping module.
 */

/**
 * Implements hook_views_data_alter().
 *
 * If field's are denormalized we can use all the single field value handlers on
 * them too. Adjust the views data accordingly.
 */
function search_api_grouping_views_data_alter(&$data) {
  try {
    // Only modify views data if the related search api module is enabled.
    if (!module_exists('search_api_views')) {
      return;
    }
    foreach (search_api_index_load_multiple(FALSE) as $index) {
      $table_key = 'search_api_index_' . $index->machine_name;
      if (isset($data[$table_key]) && strpos($index->item_type, 'denormalized-') === 0) {
        try {
          $wrapper = $index->entityWrapper(NULL);
        }
        catch (EntityMetadataWrapperException $e) {
          watchdog_exception('search_api_views', $e, "%type while retrieving metadata for index %index: !message in %function (line %line of %file).", array('%index' => $index->name), WATCHDOG_WARNING);
          continue;
        }
        $denormalization_fields = DenormalizedEntityIndexHijack::getDenormalizeProcessorFields($index);
        $denormalization_fields = drupal_map_assoc(array_keys($denormalization_fields));
        foreach ($index->getFields() as $key => $field) {
          $tmp = $wrapper;
          $group = '';
          $name = '';
          $parts = explode(':', $key);
          if (count(array_intersect($denormalization_fields, $parts))) {
            // We've to unpack nested fields to see of the are marked as multi
            // valued because of the original field.
            $wrap_level = 0;
            foreach ($parts as $i => $part) {
              $wrap_level++;
              if (!isset($tmp->$part)) {
                continue 2;
              }
              $tmp = $tmp->$part;
              $info = $tmp->info();
              $group = ($group ? $group . ' » ' . $name : ($name ? $name : ''));
              $name = $info['label'];
              if ($i < count($parts) - 1) {
                $wrap_level--;
                // Unwrap lists.
                $level = search_api_list_nesting_level($info['type']);
                for ($j = 0; $j < $level; ++$j) {
                  $tmp = $tmp[0];
                }
              }
            }
            $type = search_api_grouping_unwrap_field_type($field['type'], $wrap_level);
            $inner_type = search_api_extract_inner_type($field['type']);

            // Add our own special sort handler.
            if ($type == $inner_type) {
              $id = $key;
              if (strpos($id, ':')) {
                entity_views_field_definition($id, $tmp->info(), $data[$table_key]);
              }
              $id = _entity_views_field_identifier($id, $data[$table_key]);

              $data[$table_key][$id]['sort']['handler'] = 'SearchApiGroupingViewsHandlerSort';
              if (isset($data[$table_key][$id]['field'])) {
                $data[$table_key][$id]['field']['click sortable'] = TRUE;
              }
            }
          }
        }
      }
    }
  }
  catch (Exception $e) {
    watchdog_exception('search_api_grouping', $e);
  }
}

/**
 * Unwraps a field type to a certain level.
 *
 * @param string $type
 *   The field type.
 * @param int $level
 *   The levels to unwrap.
 *
 * @return string
 *   The unwrapped field type.
 */
function search_api_grouping_unwrap_field_type($type, $level) {
  for ($i = 0; $i < $level; $i++) {
    $type = substr($type, 5, -1);
  }
  return $type;
}
