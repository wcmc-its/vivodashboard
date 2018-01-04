<?php
/**
 * @file
 * vivodashboard_publications.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vivodashboard_publications_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'citations';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'citations/*' => 'citations/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'citations_chart' => 'citations_chart',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-citations' => array(
          'module' => 'current_search',
          'delta' => 'citations',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-G86nY0s9GGDbbilBXJIjTkTCI1I1ZcLx' => array(
          'module' => 'facetapi',
          'delta' => 'G86nY0s9GGDbbilBXJIjTkTCI1I1ZcLx',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-Jz4Xg8Z7tykN8Nn8CVrzisMZN6ThTl9Z' => array(
          'module' => 'facetapi',
          'delta' => 'Jz4Xg8Z7tykN8Nn8CVrzisMZN6ThTl9Z',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapi-g2IhwxbjQdAZQC9LxG4iuvekabi0AKsp' => array(
          'module' => 'facetapi',
          'delta' => 'g2IhwxbjQdAZQC9LxG4iuvekabi0AKsp',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'facetapi-01785NW3ytEYgf6AkIWBdvuurEx7Ir0V' => array(
          'module' => 'facetapi',
          'delta' => '01785NW3ytEYgf6AkIWBdvuurEx7Ir0V',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'facetapi-XTE1A0eWhFA0E3jTjx4jjVciSw0YjRGb' => array(
          'module' => 'facetapi',
          'delta' => 'XTE1A0eWhFA0E3jTjx4jjVciSw0YjRGb',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['citations'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'publications';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'publications_export_csv' => 'publications_export_csv',
        'publications_export_doc' => 'publications_export_doc',
        'publications_graph' => 'publications_graph',
        'publications_list' => 'publications_list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-publications' => array(
          'module' => 'current_search',
          'delta' => 'publications',
          'region' => 'sidebar_second',
          'weight' => '-26',
        ),
        'current_search-authorships' => array(
          'module' => 'current_search',
          'delta' => 'authorships',
          'region' => 'sidebar_second',
          'weight' => '-25',
        ),
        'facetapi-VN3StHRGlW7H3Jt1pTUn1feR1ZlgL5Ao' => array(
          'module' => 'facetapi',
          'delta' => 'VN3StHRGlW7H3Jt1pTUn1feR1ZlgL5Ao',
          'region' => 'sidebar_second',
          'weight' => '-24',
        ),
        'facetapi-zgXE3UetEc8mCPg5jsK6r1LXiyAkxfr9' => array(
          'module' => 'facetapi',
          'delta' => 'zgXE3UetEc8mCPg5jsK6r1LXiyAkxfr9',
          'region' => 'sidebar_second',
          'weight' => '-23',
        ),
        'facetapi-33WCP6A0HTy2tM8DjPNmZlCCdlTsGzLK' => array(
          'module' => 'facetapi',
          'delta' => '33WCP6A0HTy2tM8DjPNmZlCCdlTsGzLK',
          'region' => 'sidebar_second',
          'weight' => '-22',
        ),
        'facetapi-hYUnaC1SagSOXcjox4olW5eBkM7jGiu4' => array(
          'module' => 'facetapi',
          'delta' => 'hYUnaC1SagSOXcjox4olW5eBkM7jGiu4',
          'region' => 'sidebar_second',
          'weight' => '-21',
        ),
        'facetapi-Y8aWh8zwticTanQdj8aCYfFani4IgjTW' => array(
          'module' => 'facetapi',
          'delta' => 'Y8aWh8zwticTanQdj8aCYfFani4IgjTW',
          'region' => 'sidebar_second',
          'weight' => '-20',
        ),
        'facetapi-lkqcrnWHH0w8OReIFReY1SOXJ2AmemZn' => array(
          'module' => 'facetapi',
          'delta' => 'lkqcrnWHH0w8OReIFReY1SOXJ2AmemZn',
          'region' => 'sidebar_second',
          'weight' => '-19',
        ),
        'facetapi-5kkgzTkebYqtm1y12y31j3q0tOg806BM' => array(
          'module' => 'facetapi',
          'delta' => '5kkgzTkebYqtm1y12y31j3q0tOg806BM',
          'region' => 'sidebar_second',
          'weight' => '-18',
        ),
        'facetapi-0RhZw5nZBg0KwoCrm0qpPoPG0VraVSeY' => array(
          'module' => 'facetapi',
          'delta' => '0RhZw5nZBg0KwoCrm0qpPoPG0VraVSeY',
          'region' => 'sidebar_second',
          'weight' => '-17',
        ),
        'facetapi-m1taBjKoIjxP74RsDO1pffdpQ4KFJd1B' => array(
          'module' => 'facetapi',
          'delta' => 'm1taBjKoIjxP74RsDO1pffdpQ4KFJd1B',
          'region' => 'sidebar_second',
          'weight' => '-16',
        ),
        'facetapi-kQcASlR11zLcNoeq8gPZWtFWixMSTwPF' => array(
          'module' => 'facetapi',
          'delta' => 'kQcASlR11zLcNoeq8gPZWtFWixMSTwPF',
          'region' => 'sidebar_second',
          'weight' => '-15',
        ),
        'facetapi-WX1ZbR75Ed60ugYcJgDWf05Ko48nFZLT' => array(
          'module' => 'facetapi',
          'delta' => 'WX1ZbR75Ed60ugYcJgDWf05Ko48nFZLT',
          'region' => 'sidebar_second',
          'weight' => '-14',
        ),
        'facetapi-jOAmqHc51cRojDaN62S0gScUkpGdHsbC' => array(
          'module' => 'facetapi',
          'delta' => 'jOAmqHc51cRojDaN62S0gScUkpGdHsbC',
          'region' => 'sidebar_second',
          'weight' => '-13',
        ),
        'facetapi-fF7HXzukpX1KMR6HO2WWSPINK0BEJWv7' => array(
          'module' => 'facetapi',
          'delta' => 'fF7HXzukpX1KMR6HO2WWSPINK0BEJWv7',
          'region' => 'sidebar_second',
          'weight' => '-12',
        ),
        'facetapi-2Qhq5eTQbiGqyi7v1NKTfeRCDIhrJxPs' => array(
          'module' => 'facetapi',
          'delta' => '2Qhq5eTQbiGqyi7v1NKTfeRCDIhrJxPs',
          'region' => 'sidebar_second',
          'weight' => '-11',
        ),
        'facetapi-yJUR45ko5bcYeiOpC6RMOnwBkENm0gjo' => array(
          'module' => 'facetapi',
          'delta' => 'yJUR45ko5bcYeiOpC6RMOnwBkENm0gjo',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-WCRb4PTcVgwsmSTIn1CrUoIj2qKZCuCd' => array(
          'module' => 'facetapi',
          'delta' => 'WCRb4PTcVgwsmSTIn1CrUoIj2qKZCuCd',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-LPhNIlFioCrPjQTbha1ed1PwmKsPMx9x' => array(
          'module' => 'facetapi',
          'delta' => 'LPhNIlFioCrPjQTbha1ed1PwmKsPMx9x',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapi-zXYJQG56ZAbDXhPXcmCFQoC33NZgx9PP' => array(
          'module' => 'facetapi',
          'delta' => 'zXYJQG56ZAbDXhPXcmCFQoC33NZgx9PP',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'facetapi-CZ1p15WI0lL07I3K144vJUknF9SAyvDc' => array(
          'module' => 'facetapi',
          'delta' => 'CZ1p15WI0lL07I3K144vJUknF9SAyvDc',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['publications'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'publications_graph';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'publications_graph' => 'publications_graph',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi_graphs-0PxuzR1c1EJhl8qHbGNErYVN0GyqvG5e' => array(
          'module' => 'facetapi_graphs',
          'delta' => '0PxuzR1c1EJhl8qHbGNErYVN0GyqvG5e',
          'region' => 'content',
          'weight' => '5',
        ),
        'facetapi_graphs-vi56JgTc5M0cD1gN8zGFJMxg95mlGjVc' => array(
          'module' => 'facetapi_graphs',
          'delta' => 'vi56JgTc5M0cD1gN8zGFJMxg95mlGjVc',
          'region' => 'content',
          'weight' => '6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['publications_graph'] = $context;

  return $export;
}
