<?php

/**
 * @file
 * Processor for configuring the denormalization per index.
 */

/**
 * Processor to configure and handle the denormalization per index.
 */
class SearchApiDenormalizedEntityField extends SearchApiAbstractProcessor {

  /**
   * Check if this index is supported.
   */
  public function supportsIndex(SearchApiIndex $index) {
    return ($index->datasource() instanceof SearchApiDenormalizedEntityDataSourceController);
  }

  /**
   * Return the settings form for this processor.
   */
  public function configurationForm() {
    $form = parent::configurationForm();

    $form['permutation_limit'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#title' => t('Permutation limits'),
      '#description' => t('Defines how man permutations should be processed. Can become handy if you just want to have one item of a muti-value field. Leave empty for no limit.'),
      '#weight' => 1,
    );

    $entity_type = $this->index->datasource()->getEntityType();
    $entity_info = entity_get_info($this->index->datasource()->getEntityType());
    $bundle_infos = field_info_instances($this->index->datasource()->getEntityType());
    $options = array();
    foreach ($form['fields']['#options'] as $field_name => $label) {
      if (stristr($field_name, ':')) {
        list($field_name, $property) = explode(':', $field_name, 2);
      }
      if (($field_info = field_info_field($field_name))) {
        $instance = field_read_instance($entity_type, $field_name, reset($field_info['bundles'][$entity_type]));
        if (!empty($field_info['cardinality']) && ($field_info['cardinality'] == FIELD_CARDINALITY_UNLIMITED || $field_info['cardinality'] > 1)) {
          $options[$field_name] = $instance['label'] . ' (' . $field_name . ')';
          $form['permutation_limit'][$field_name] = array(
            '#type' => 'textfield',
            '#title' => $instance['label'] . ' (' . $field_name . ')',
            '#size' => 4,
            '#maxlength' => 10,
            '#states' => array(
              'visible' => array(
                ':input[name$="[denormalization_field][' . $field_name . ']"]' => array('checked' => TRUE),
              ),
            ),
            '#default_value' => !empty($this->options['permutation_limit'][$field_name]) ? $this->options['permutation_limit'][$field_name] : NULL,
          );
        }
      }
    }
    $form['fields']['#options'] = $options;

    // Re-use but modify the default form element.
    $form['fields']['#type'] = 'checkboxes';
    unset($form['fields']['#attributes']);
    $form['fields']['#options'] = $form['fields']['#options'];

    $form['denormalization_field'] = $form['fields'];
    $form['fields']['#access'] = FALSE;

    $form['denormalization_field'] = array(
      '#title' => t('The field to use to denormalize the items to index.'),
      '#description' => t('The field hast to be selected for indexing to use it for denormalization.'),
      '#default_value' => isset($this->options['denormalization_field']) ? $this->options['denormalization_field'] : NULL,
    ) + $form['denormalization_field'];

    return $form;
  }

  /**
   * Returns the fields to denormalize on.
   *
   * @return array
   *   Associative list of fields to use for denormalization. The value in the
   *   array defines the permutation limit. 0 means no limit.
   */
  public function getDenormalizationFields() {
    $fields = &drupal_static(__FUNCTION__, array());
    if (empty($fields)) {
      $fields = array_filter($this->options['denormalization_field']);
      foreach ($fields as $field_name => $field) {
        $fields[$field_name] = 0;
        if (!empty($this->options['permutation_limit'][$field]) && is_numeric($this->options['permutation_limit'][$field])) {
          $fields[$field_name] = (int) $this->options['permutation_limit'][$field];
        }
      }
    }
    return $fields;
  }

  /**
   * Returns the permutation limit of a field.
   *
   * @param string $field
   *   The field to get the limit for.
   *
   * @return int
   *   The number of permutations to generate from this field. 0 means no limit.
   */
  public function getDenormalizationFieldLimit($field) {
    if (!empty($this->options['permutation_limit'][$field]) && is_numeric($this->options['permutation_limit'][$field])) {
      return (int) $this->options['permutation_limit'][$field];
    }
    return 0;
  }

  /**
   * Denormalizes items on behalf of multivalue fields.
   */
  public function preprocessIndexItems(array &$items) {
    // Run default pre-processing first.
    parent::preprocessIndexItems($items);

    // Reduce item data to its denormalized data set.
    foreach ($items as $item_id => $item) {
      $items[$item_id] = $this->createDocument($item, $item_id);
    }

    // Ensure obsolete permutations are removed from index.
    $this->index->datasource()->removeObsoletePermutationsFromIndex($items, $this->index);
  }


  /**
   * Create a denormalized item for indexing.
   *
   * @param array $item
   *   The item to index.
   * @param string $item_id
   *   The item id of the item to index.
   *
   * @return array
   *   Denormalized item to index.
   */
  protected function createDocument($item, $item_id) {
    $fields = $this->getDenormalizationFields();
    $parts = explode(SEARCH_API_GROUPING_ENTITY_FIELD_SEPERATOR, $item_id);
    // Unshift non delta values to ensure the $fields_index matches.
    $entity_type = array_shift($parts);
    $entity_id = array_shift($parts);

    $fields_index = array_flip(array_keys($fields));
    foreach ($item as $index => $data) {
      list($key) = explode(':', $index, 2);
      if (isset($fields[$key]) && !empty($data['value'])) {
        $item[$index]['value'] = array_intersect_key($data['value'], array($parts[$fields_index[$key]] => $parts[$fields_index[$key]]));
      }
    }
    return $item;
  }
}
