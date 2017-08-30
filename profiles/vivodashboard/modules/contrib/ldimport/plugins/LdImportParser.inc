<?php
/**
 * @file
 * Class definition for Linked Data Import parser plugin.
 */

/**
 * Class definition for LdImportParser.
 */
class LdImportParser extends FeedsParser {

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $uri_list = array();

    // Ideally fetcher is designed to provide a list of URIs. If not, we still
    // try and support other fetchers, expecting URIs on separate lines.
    if (method_exists($fetcher_result, 'getList')) {
      $uri_list = $fetcher_result->getList();
    }
    else {
      $raw = $fetcher_result->getRaw();
      foreach (explode("\n", $raw) as $uri) {
        $uri = trim($uri);
        if ($uri && valid_url($uri, TRUE)) {
          $uri_list[$uri] = $uri;
        }
      }
    }

    $uri_list = array_values($uri_list);

    $state = $source->state(FEEDS_PARSE);
    $state->total = count($uri_list);
    $state->parsed = 0;
    $state->retry = array();

    if ($this->config['debug']) {
      $message = t('Prepared list of @count URIs to be imported.', array('@count' => count($uri_list)));
      $source->log('import', $message, array(), WATCHDOG_DEBUG);
    }

    return new LdimportParserResult($uri_list, $this, $source);
  }

  /**
   * Pull the next item off the list to give to the processor.
   *
   * This is called by LdimportParserResult::shiftItem(). By handing off items
   * one at a time we reduce the chances of items getting lost when we hit
   * maximum execution times.
   *
   * Because we batch at the parser level, items handed to the processor are
   * considered "done" even if the processor fails to finish.
   */
  public function getItem($uri_list, $source) {
    $state = $source->state(FEEDS_PARSE);

    $start = ($state->pointer) ? $state->pointer : 0;
    $limit = $this->config['batch_limit'];
    $parsed = &$state->parsed;

    $debug = $this->config['debug'];
    $postpone_requests = empty($this->config['pre_fetch']);

    $graph = new Graphite();
    $graph->setDebug($debug);
    $this->setGraphiteConfig($graph);

    // Avoid stuck imports due to incorrect totals.
    if ($start >= count($uri_list)) {
      $state->progress(1, 2);
      return;
    }

    // Run through URIs until we hit the limit or finish the list.
    for ($i = $start; $i < count($uri_list) && $parsed < $limit; $i++) {
      $uri = $uri_list[$i];

      $attempts = !empty($this->config['retries']) ? $this->config['retries'] : 1;

      if ($debug) {
        $message = t('Attempting to import %uri - item @start of @total.', array('%uri' => $uri, '@start' => $i + 1, '@total' => count($uri_list)));
        $source->log('import', $message, array(), WATCHDOG_DEBUG);
      }

      for ($attempts; $attempts > 0; $attempts--) {
        $item = $graph->resource($uri);

        $has_data = ($postpone_requests) ? TRUE : $this->loadAndLog($item, $source, $debug);

        if ($has_data) {
          $state->created++;
          $state->parsed++;
          $state->pointer = $i + 1;
          $state->progress($state->total, $state->pointer);
          return $item;
        }

        if (!$has_data && $attempts === 1) {
          $message = t('Failed importing %uri after @n attempts.', array('%uri' => $uri, '@n' => $this->config['retries']));
          $source->log('import', $message, array(), WATCHDOG_WARNING);
          $state->failed++;
          $state->pointer = $i + 1;
          break;
        }
      }
    }

    return NULL;
  }

  /**
   * Overrides FeedsParser::getSourceElement().
   */
  public function getSourceElement(FeedsSource $source, FeedsParserResult $result, $element_key) {
    $item = $result->currentItem();

    $predicates = $this->getPredicates($element_key);

    $value = '';

    if ($values = $this->extractPropertyValues($item, $predicates, $source)) {
      $value = (count($values) == 1) ? reset($values) : $values;
    }

    return $value;
  }

  /**
   * Recursively retrieves data for each predicate in a mapping source.
   */
  public function extractPropertyValues(Graphite_Resource $item, $predicates, FeedsSource $source) {
    $debug = $this->config['debug'] && $this->config['debug_properties'];

    // If data has not been loaded for this resource do it now. This was likely
    // because pre_fetch was disabled.
    if (!$item->g->loaded($item->toString())) {
      $this->loadAndLog($item, $source, $this->config['debug']);
    }

    $values = array();
    $predicate = array_shift($predicates);

    // Handle special mapping keywords "URI" and "Label".
    if (strtolower($predicate['uri']) == 'uri') {
      $values[] = $item->toString();
      return $values;
    }
    elseif (strtolower($predicate['uri']) == 'label') {
      // Try to get the label property.
      $label = $item->label();
      if (!$label->isNull() && ($label = trim($label->toString()))) {
        $values[] = $this->convertEncoding($label);
      }
      // If there is no actual label, use ARC2's helper method to format one
      // using the local name of the URI.
      else {
        $uri = $item->toString();
        $resource = ARC2::getResource();
        $resource->setURI($uri);
        $values[] = $resource->extractTermLabel($uri);
      }
      return $values;
    }

    // Only proceed if there is data for this predicate.
    if ($property_values = $item->all($predicate['uri'])) {

      $next_predicate = current($predicates);

      foreach ($property_values as $property_value) {

        // Recurse into next predicate when there is one.
        if ($next_predicate && $property_value instanceof Graphite_Resource) {
          $next_item = $property_value;

          if ($debug) {
            $message = t('Retrieving property data for %uri while handling %predicate', array('@count' => $triples, '%uri' => $next_item->toString(), '%predicate' => $predicate['uri']));
            $source->log('import', $message, array(), WATCHDOG_DEBUG);
          }

          $this->loadAndLog($next_item, $source, $debug);

          if (!$predicate['filters'] || ($predicate['filters'] && $next_item->isType($predicate['filters']))) {
            $values = array_merge($values, $this->extractPropertyValues($next_item, $predicates, $source));
          }
        }
        // Add values.
        elseif (!$next_predicate) {
          $values[] = $this->convertEncoding($property_value->toString());
        }
      }
    }

    return $values;
  }

  /**
   * Turns a mapping string into an array of predicates, keyed by predicate URI,
   * with an array of rdf:type URIs as values.
   */
  public function getPredicates($string) {
    $predicates = array();

    $parts = explode(' ', $string);

    foreach ($parts as $k => $part) {

      // Even keys should always be predicate URIs.
      if ($k % 2 === 0) {

        $next_part = $k + 1;

        $types = '';
        if (isset($parts[$next_part])) {
          $types = $parts[$next_part];
          $types = strtr($types, array('[' => '', ']' => ''));
        }

        $predicate = array();
        $predicate['uri'] = $part;
        $predicate['filters'] = !empty($types) ? explode('|', $types) : array();
        $predicates[] = $predicate;
      }
    }

    return $predicates;
  }

  /**
   * Overrides FeedsParser::getMappingSources().
   *
   * This makes the Feeds mapping UI use text inputs instead of dropdowns.
   */
  public function getMappingSources() {
    return FALSE;
  }


  /**
   * Default settings.
   */
  public function configDefaults() {
    return array(
      'use_caching' => 1,
      'cache_time' => 60 * 60 * 24 * 7 * 2,
      'batch_limit' => 10,
      'pre_fetch' => TRUE,
      'retries' => 3,
      'timeout' => 30,
      'debug' => TRUE,
      'debug_properties' => TRUE,
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
      '#description' => t('Cache requested linked data during import.'),
      '#default_value' => $this->config['use_caching'],
    );
    $form['cache_time'] = array(
      '#type' => 'textfield',
      '#title' => t('Cache time'),
      '#description' => t('How long to cache data. Enter either seconds or a value for strtotime().'),
      '#default_value' => $this->config['cache_time'],
      '#states' => array(
        'visible' => array(
          '#edit-use-caching' => array('checked' => TRUE),
        ),
      ),
    );
    $form['batch_limit'] = array(
      '#type' => 'textfield',
      '#title' => t('Batch limit'),
      '#description' => t('How many items to retrieve in each Batch API pass. Keeping this low helps to avoid timeouts.'),
      '#default_value' => $this->config['batch_limit'],
      '#size' => 3,
    );
    $form['pre_fetch'] = array(
      '#type' => 'checkbox',
      '#title' => t('Pre-fetch items'),
      '#description' => t('Fetch property data during the parsing stage. Items will only be processed when property data is available. Disabling this allows items without property data to still be imported, which can sometimes be desirable i.e. when linked data is not being served correctly.'),
      '#default_value' => $this->config['pre_fetch'],
    );
    $form['retries'] = array(
      '#type' => 'textfield',
      '#title' => t('Retry limit'),
      '#description' => t('How many times to retry failed requests for URIs.'),
      '#default_value' => $this->config['retries'],
      '#size' => 3,
    );
    $form['timeout'] = array(
      '#type' => 'textfield',
      '#title' => t('Timeout'),
      '#description' => t('Amount of time, in seconds, to wait for linked data requests.'),
      '#default_value' => $this->config['timeout'],
      '#size' => 3,
    );
    $form['debug'] = array(
      '#type' => 'checkbox',
      '#title' => t('Debug'),
      '#description' => t('Add extra debug information to the Feeds log.'),
      '#default_value' => $this->config['debug'],
    );
    $form['debug_properties'] = array(
      '#type' => 'checkbox',
      '#title' => t('Debug properties'),
      '#description' => t('Add extra debug information to the Feeds log while retrieving property data. This can substantially bloat the log.'),
      '#default_value' => $this->config['debug_properties'],
      '#states' => array(
        'visible' => array(
          '#edit-debug' => array('checked' => TRUE),
        ),
      ),
    );
    return $form;
  }

  /**
   * Parser settings form validation.
   */
  public function configFormValidate(&$values) {
    $batch_limit = $values['batch_limit'];
    if (!is_numeric($batch_limit) || intval($batch_limit) != $batch_limit || $batch_limit <= 0) {
      form_set_error('batch_limit', t('Only positive integers are allowed.'));
    }
  }

  /**
   * Ensures data is encoded properly to avoid SQL errors.
   *
   * @see https://www.drupal.org/node/1428272#comment-7349918
   */
  private function convertEncoding($data) {
    if (extension_loaded('mbstring')) {
      $data = mb_convert_encoding($data, 'UTF-8', 'UTF-8');
    }
    return $data;
  }

  /**
   * Consolidates config for Graphite.
   */
  private function setGraphiteConfig(Graphite $graph) {
    $graph->setLang($GLOBALS['language']->language);
    $graph->setARC2Config(array('reader_timeout' => $this->config['timeout']));

    // Set up filesystem cache.
    if ($this->config['use_caching']) {
      $seconds = $this->config['cache_time'];
      if (!is_numeric($seconds) && strtotime($seconds)) {
        $seconds = strtotime($seconds) - time();
      }
      $cache_directory = file_directory_temp() . '/graphite';
      file_prepare_directory($cache_directory, FILE_CREATE_DIRECTORY);
      $graph->cacheDir($cache_directory, (int) $seconds);
    }
  }

  /**
   * Wraps Graphite::load() so that we can capture errors and log cache hits.
   */
  private function loadAndLog(Graphite_Resource $resource, FeedsSource $source, $debug = FALSE) {
    $uri = $resource->toString();
    $graph = $resource->g;

    // Log whether or not Graphite will be hitting the filesystem cache.
    // @see Graphite_Retriever::retrieve()
    if ($debug && !empty($graph->cacheDir)) {
      $filename = $graph->cacheDir . '/' . md5($graph->removeFragment($uri));
      if (file_exists($filename)) {
        if (filemtime($filename) + $graph->cacheAge > time()) {
          $message = t('Cached RDF available for %uri - no HTTP request will be made.', array('%uri' => $uri));
        }
        else {
          $message = t('Cached RDF exists for %uri - it has expired, new data will be requested.', array('%uri' => $uri));
        }
      }
      else {
        $message = t('Making HTTP request for %uri', array('%uri' => $uri));
      }
      $source->log('import', $message, array(), WATCHDOG_DEBUG);
    }

    // Graphite has no real debugging. This is the only way we can capture
    // HTTP request errors.
    ob_start();

    // Make HTTP request or load from cache.
    $triples = $resource->load();

    $errors = ob_get_contents();

    ob_end_clean();

    // Log success.
    if ($debug && $triples) {
      $message = t('Successfully retrieved @count triples for %uri', array('%uri' => $uri, '@count' => $triples));
      $source->log('import', $message, array(), WATCHDOG_DEBUG);
    }
    // Log failure.
    elseif (!$triples) {
      $errors = ($errors) ? $errors : 'No error message';
      $message = t('Failed to retrieve data for %uri - errors from Graphite library: !errors', array('%uri' => $uri, '!errors' => $errors));
      $source->log('import', $message, array(), WATCHDOG_ERROR);
    }

    return !empty($triples) ? TRUE : FALSE;
  }
}

/**
 * Class definition for LdimportParserResult.
 */
class LdimportParserResult extends FeedsParserResult {

  public function __construct($uri_list = array(), FeedsParser $parser, FeedsSource $source) {
    $this->items = $uri_list;
    $this->parser = $parser;
    $this->source = $source;
  }

  public function shiftItem() {
    $this->current_item = $this->parser->getItem($this->items, $this->source);
    return $this->current_item;
  }
}
