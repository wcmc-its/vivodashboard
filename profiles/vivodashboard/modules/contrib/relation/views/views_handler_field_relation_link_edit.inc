<?php

/**
 * @file
 * Definition of views_handler_field_relation_link_edit.
 */

/**
 * Field handler to present a link relation edit.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_relation_link_edit extends views_handler_field_relation_link {

  /**
   * Renders the link.
   */
  function render_link($relation, $values) {
    // Ensure that relation_ui module enabled.
    if (!module_exists('relation_ui')) {
      return;
    }

    // Ensure user has access to edit this relation.
    if (!user_access('edit relations')) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $relation_uri = entity_uri('relation', $relation);
    $this->options['alter']['path'] = $relation_uri['path'] . "/edit";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Edit');
    return $text;
  }
}
