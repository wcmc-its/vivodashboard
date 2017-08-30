<?php

/**
 * @file
 * Class definition for Linked Data Import fetcher plugin.
 */

/**
 * Class definition for LdImportFetcher.
 */
class LdImportFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    return new LdImportFetcherResult($this->getURIs($source));
  }

  /**
   * Gets the list of URIs entered by the user.
   */
  public function getURIs($source) {
    $source_config = $source->getConfigFor($this);
    $uri_list = array();

    if (empty($source_config['uri_list']) || (!$items = explode("\n", $source_config['uri_list']))) {
      return $uri_list;
    }

    // Gather entered URIs.
    foreach ($items as $v) {
      $v = trim($v);
      if ($v && valid_url($v, TRUE)) {
        $uri_list[$v] = $v;
      }
    }
    return array_values($uri_list);
  }

  /**
   * Implements FeedsFetcher::sourceForm().
   */
  public function sourceForm($source_config) {
    $form['uri_list'] = array(
      '#type' => 'textarea',
      '#title' => t('URI List'),
      '#description' => t('Enter a list of URIs for resources to be imported. Place each URI on a separate line.'),
      '#default_value' => isset($source_config['uri_list']) ? $source_config['uri_list'] : '',
      '#rows' => 15,
    );
    return $form;
  }

  /**
   * Implements FeedsFetcher::sourceFormValidate().
   */
  public function sourceFormValidate(&$values) {
    if (empty($values['uri_list'])) {
      return;
    }
    // Validate the list of URIs.
    if ($items = explode("\n", $values['uri_list'])) {
      foreach ($items as $v) {
        $v = trim($v);
        if ($v && !valid_url($v, TRUE)) {
          form_set_error('uri_list', t('The URI "%v" is not valid.', array('%v' => $v)));
        }
      }
    }
    else {
      form_set_error('uri_list', t('There is a problem with the list of URIs entered. Make sure they are valid and each is on a separate line.'));
    }
  }
}

/**
 * Class definition for LdImportFetcherResult.
 */
class LdImportFetcherResult extends FeedsFetcherResult {

  public function __construct(array $uri_list) {
    $this->uri_list = $uri_list;
  }

  public function getList() {
    return $this->uri_list;
  }
}
