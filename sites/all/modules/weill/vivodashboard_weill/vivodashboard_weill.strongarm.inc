<?php
/**
 * @file
 * vivodashboard_weill.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function vivodashboard_weill_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_activate';
  $strongarm->value = 1;
  $export['simplesamlphp_auth_activate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_allowdefaultlogin';
  $strongarm->value = 1;
  $export['simplesamlphp_auth_allowdefaultlogin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_allowdefaultloginroles';
  $strongarm->value = array(
    2 => '2',
  );
  $export['simplesamlphp_auth_allowdefaultloginroles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_allowdefaultloginusers';
  $strongarm->value = '';
  $export['simplesamlphp_auth_allowdefaultloginusers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_allowsetdrupalpwd';
  $strongarm->value = 0;
  $export['simplesamlphp_auth_allowsetdrupalpwd'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_authsource';
  $strongarm->value = 'default-sp';
  $export['simplesamlphp_auth_authsource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_forcehttps';
  $strongarm->value = 1;
  $export['simplesamlphp_auth_forcehttps'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_installdir';
  $strongarm->value = 'private/simplesamlphp-1.13.2';
  $export['simplesamlphp_auth_installdir'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_logoutgotourl';
  $strongarm->value = 'http://live-vivo-dashboard.gotpantheon.com';
  $export['simplesamlphp_auth_logoutgotourl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_mailattr';
  $strongarm->value = 'mail';
  $export['simplesamlphp_auth_mailattr'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_registerusers';
  $strongarm->value = 1;
  $export['simplesamlphp_auth_registerusers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_roleevaleverytime';
  $strongarm->value = 0;
  $export['simplesamlphp_auth_roleevaleverytime'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_rolepopulation';
  $strongarm->value = '';
  $export['simplesamlphp_auth_rolepopulation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_unique_id';
  $strongarm->value = 'eduPersonPrincipalName';
  $export['simplesamlphp_auth_unique_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_user_name';
  $strongarm->value = 'displayName';
  $export['simplesamlphp_auth_user_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_user_register_original';
  $strongarm->value = 1;
  $export['simplesamlphp_auth_user_register_original'] = $strongarm;

  return $export;
}
