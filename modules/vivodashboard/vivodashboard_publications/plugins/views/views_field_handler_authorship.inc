<?php

/**
 * Views field handler to conditionally link entities to their VIVO URI.
 *
 * @see vivodashboard_publications_views_data_alter()
 */
class vivodashboard_publications_field_handler_authorship extends entity_views_handler_field_entity {

  public function option_definition() {
    $options = parent::option_definition();
    $options['vivo_link'] = array('default' => FALSE);
    $options['vivo_namespace'] = array('default' => 'http://vivo.institution.edu');
    $options['ending_period'] = array('default' => FALSE);
    return $options;
  }

  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['ending_period'] = array(
      '#type' => 'checkbox',
      '#title' => t('Ending period'),
      '#description' => t('Append a period to the end when there is no final punctuation.'),
      '#default_value' => $this->options['ending_period'],
    );
    $form['vivo_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link to VIVO'),
      '#description' => t('Link this field to its VIVO URI, depending on the namespace.'),
      '#default_value' => $this->options['vivo_link'],
      '#dependency' => array('edit-options-display' => array('label', 'id')),
    );
    $form['vivo_namespace'] = array(
      '#type' => 'textfield',
      '#title' => 'VIVO namespace',
      '#description' => 'Optionally enter a namespace or domain. A link will be rendered only when the VIVO URI matches this string.',
      '#default_value' => $this->options['vivo_namespace'],
      '#states' => array(
        'visible' => array(
          'input[name="options[vivo_link]"]' => array('checked' => TRUE),
        ),
      ),
    );
  }

  /**
   * Override entity_views_handler_field_entity::render() to append periods.
   */
  public function render($values) {
    $output = parent::render($values);
    if (!empty($output) && $this->options['ending_period'] && !preg_match("/[0-9.!?,;:]$/", $output)) {
      $output .= '. ';
    }
    return $output;
  }

  /**
   * Render a value as a link to the entity if applicable.
   */
  public function render_entity_link($entity, $values) {
    $text = parent::render_entity_link($entity, $values);

    if ($this->options['vivo_link'] && empty($this->options['link_to_entity'])) {

      $entity_type = $this->field_entity_type;
      if (!is_object($entity) && isset($entity) && $entity !== FALSE) {
        $entity = entity_load_single($entity_type, $entity);
      }

      // For authorship relations we need to get the VIVO URL from the node.
      if ($entity_type == 'relation' && is_object($entity)) {
        $authorship = entity_metadata_wrapper('relation', $entity);
        try {
          $author = $authorship->endpoints[1]->value();
          $entity = $author;
          $entity_type = 'node';
        }
        catch (Exception $e) {
          // Do nothing, just fail to provide a link.
        }
      }

      if (is_object($entity) && ($items = field_get_items($entity_type, $entity, 'field_uri'))) {
        $uri = $items[0]['url'];
        $namespace = $this->options['vivo_namespace'];
        if (empty($namespace) || ($namespace && substr_count($uri, $namespace))) {
          return l($text, $uri, array('html' => TRUE, 'absolute' => TRUE));
        }
      }
    }

    return $text;
  }
}
