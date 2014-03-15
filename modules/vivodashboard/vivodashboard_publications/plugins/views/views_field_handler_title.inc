<?php

/**
 * Views field handler to conditionally add period at the end of the title.
 *
 * @see vivodashboard_publications_views_data_alter()
 */
class vivodashboard_publications_field_handler_title extends entity_views_handler_field_text {

  public function option_definition() {
    $options = parent::option_definition();
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
  }

  /**
   * Override entity_views_handler_field_text::render() to append periods.
   */
  public function render($values) {
    $output = parent::render($values);
    if (!empty($output) && $this->options['ending_period'] && !preg_match("/[0-9.!?,;:\"\']$/", $output)) {
      $output .= '.';
    }
    return $output;
  }
}
