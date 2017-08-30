<?php
/**
 * @file
 * vivodashboard_core.ultimate_cron.inc
 */

/**
 * Implements hook_default_ultimate_cron_job().
 */
function vivodashboard_core_default_ultimate_cron_job() {
  $export = array();

  $job = new stdClass();
  $job->disabled = FALSE; /* Edit this to true to make a default job disabled initially */
  $job->api_version = 3;
  $job->name = 'queue_feeds_source_import';
  $job->title = 'Queue: feeds_source_import';
  $job->settings = array(
    'settings' => array(
      'queue' => array(
        'lease_time' => '120',
        'time' => '120',
        'throttle' => 0,
      ),
      'general' => array(),
      'poorman' => array(),
    ),
    'scheduler' => array(
      'name' => '',
      'simple' => array(),
    ),
    'launcher' => array(
      'name' => '',
      'serial' => array(),
    ),
    'logger' => array(
      'name' => '',
      'database' => array(),
    ),
  );
  $export['queue_feeds_source_import'] = $job;

  $job = new stdClass();
  $job->disabled = FALSE; /* Edit this to true to make a default job disabled initially */
  $job->api_version = 3;
  $job->name = 'search_api_cron';
  $job->title = 'Default cron handler';
  $job->settings = array(
    'scheduler' => array(
      'name' => '',
      'simple' => array(
        'rules' => array(
          0 => '* * * * *',
        ),
      ),
    ),
    'launcher' => array(
      'name' => '',
      'serial' => array(),
    ),
    'logger' => array(
      'name' => '',
      'database' => array(),
    ),
    'settings' => array(
      'general' => array(),
      'poorman' => array(),
      'queue' => array(),
    ),
  );
  $export['search_api_cron'] = $job;

  $job = new stdClass();
  $job->disabled = FALSE; /* Edit this to true to make a default job disabled initially */
  $job->api_version = 3;
  $job->name = 'search_api_solr_cron';
  $job->title = 'Default cron handler';
  $job->settings = array(
    'scheduler' => array(
      'name' => '',
      'simple' => array(
        'rules' => array(
          0 => '* * * * *',
        ),
      ),
    ),
    'launcher' => array(
      'name' => '',
      'serial' => array(),
    ),
    'logger' => array(
      'name' => '',
      'database' => array(),
    ),
    'settings' => array(
      'general' => array(),
      'poorman' => array(),
      'queue' => array(),
    ),
  );
  $export['search_api_solr_cron'] = $job;

  return $export;
}
