<?php

/**
 * @file
 * Class definition for Linked Data Import's fetcher plugins.
 */

/**
 * Class definition for LdImportVivoClassFetcher.
 */
class LdImportVivoClassFetcher extends LdImportFetcher {

  /**
   * Gets the list of individual URIs for a particular class.
   */
  public function getURIs($source) {
    $source_config = $source->getConfigFor($this);
    $vivo_url = $source_config['site'];
    $class_uri = $source_config['class'];
    $uri_list = array();

    if (empty($vivo_url) || empty($class_uri)) {
      return $uri_list;
    }

    // This is the URL used for the RDF links on VIVO index pages.
    $target_url = url($vivo_url . '/listrdf', array('query' => array('vclass' => $class_uri)));

    $graph = new Graphite();
    $graph->setLang($GLOBALS['language']->language);
    $graph->setARC2Config(array('reader_timeout' => $this->config['timeout']));

    if ($this->config['use_caching']) {
      $cache_directory = file_directory_temp() . '/graphite';
      file_prepare_directory($cache_directory, FILE_CREATE_DIRECTORY);
      $graph->cacheDir($cache_directory, $this->config['cache_time']);
    }

    $graph->load($target_url);
    $list = $graph->allSubjects();

    if (!$list instanceof Graphite_ResourceList) {
      throw new Exception(t('An error occured fetching RDF from the VIVO URL: !url', array('!url' => $target_url)));
    }

    foreach ($list as $resource) {
      $uri = $resource->toString();
      $uri_list[$uri] = $uri;
    }

    return array_values($uri_list);
  }

  /**
   * Override parent::sourceForm().
   */
  public function sourceForm($source_config) {
    $form['site'] = array(
      '#type' => 'textfield',
      '#title' => t('VIVO Site URL'),
      '#description' => t('Enter the base URL for the VIVO site without a trailing slash (e.g. http://vivo.cornell.edu)'),
      '#default_value' => isset($source_config['site']) ? $source_config['site'] : '',
    );
    $form['class'] = array(
      '#type' => 'textfield',
      '#title' => t('VIVO Class URI'),
      '#description' => t('Enter the full URI for the class of individuals to import.'),
      '#default_value' => isset($source_config['class']) ? $source_config['class'] : '',
    );
    return $form;
  }

  /**
   * Override parent::sourceForm().
   */
  public function sourceFormValidate(&$values) {
    if (empty($values['site']) || empty($values['class'])) {
      return;
    }
    if (!valid_url($values['site'])) {
      form_set_error('feeds][site', t('The URL "%site" is not valid.', array('%site' => $values['site'])));
    }
    if (!valid_url($values['class'], TRUE)) {
      form_set_error('feeds][class', t('The URI "%class" is not valid.', array('%class' => $values['class'])));
    }
  }

  /**
   * Default settings.
   */
  public function configDefaults() {
    return array(
      'use_caching' => 1,
      'cache_time' => 60 * 60 * 24 * 7,
      'timeout' => 60,
    );
  }

  /**
   * Parser settings form.
   */
  public function configForm(&$form_state) {
    $form = array();
    $form['use_caching'] = array(
      '#type' => 'checkbox',
      '#title' => t('Cache requested data'),
      '#description' => t('Cache RDF lists retrieved from VIVO.'),
      '#default_value' => $this->config['use_caching'],
    );
    $form['cache_time'] = array(
      '#type' => 'textfield',
      '#title' => t('Cache time'),
      '#description' => t('How long, in seconds, to cache RDF lists.'),
      '#default_value' => $this->config['cache_time'],
      '#size' => 10,
    );
    $form['timeout'] = array(
      '#type' => 'textfield',
      '#title' => t('Timeout'),
      '#description' => t('How long, in seconds, to wait for RDF lists.'),
      '#default_value' => $this->config['timeout'],
      '#size' => 4,
    );
    return $form;
  }
}
