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
  $strongarm->value = '/oac/vivodashboard/private/simplesamlphp-1.13.2';
  $export['simplesamlphp_auth_installdir'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplesamlphp_auth_logoutgotourl';
  $strongarm->value = 'http://vivodashboard-dev.weill.cornell.edu';
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
  $strongarm->value = '2:eduPersonPrincipalName,@=,med.cornell.edu|3:mail,=,szd2013@med.cornell.edu|3:mail,=,drw2004@med.cornell.edu|3:mail,=,elc2013@med.cornell.edu|3:mail,=,tew2004@med.cornell.edu|3:mail,=,vinay@med.cornell.edu|3:mail,=,drw2003@med.cornell.edu|3:mail,=,meb7002@med.cornell.edu|3:mail,=,brm2032@med.cornell.edu|3:mail,=,jag2030@med.cornell.edu|3:mail,=,mam2068@qatar-med.cornell.edu|3:mail,=,rsm2003@qatar-med.cornell.edu|3:mail,=,jpm2009@qatar-med.cornell.edu|3:mail,=,ccole@med.cornell.edu|3:mail,=,elk2029@med.cornell.edu|3:mail,=,wil2009@med.cornell.edu|3:mail,=,tom2017@med.cornell.edu|3:mail,=,jes2002@med.cornell.edu|3:mail,=,jas2075@med.cornell.edu|3:mail,=,mip2047@med.cornell.edu|3:mail,=,tstaeva@med.cornell.edu|3:mail,=,jimperat@med.cornell.edu|3:mail,=,cak2012@med.cornell.edu|3:mail,=,myn2001@med.cornell.edu|3:mail,=,wit2005@med.cornell.edu|3:mail,=,jsa7002@med.cornell.edu|3:mail,=,johnsos@med.cornell.edu|3:mail,=,jyp2001@med.cornell.edu|3:mail,=,hap2004@med.cornell.edu|3:mail,=,eawood@med.cornell.edu|3:mail,=,blb2008@med.cornell.edu|3:mail,=,did2005@med.cornell.edu|3:mail,=,kcm2001@med.cornell.edu|3:mail,=,lim2026@med.cornell.edu|3:mail,=,pro2004@med.cornell.edu|3:mail,=,kjpain@med.cornell.edu|3:mail,=,ems2001@med.cornell.edu|3:mail,=,jcs2002@med.cornell.edu|3:mail,=,mawood@med.cornell.edu|3:mail,=,pog2004@med.cornell.edu|3:mail,=,slvuong@med.cornell.edu|3:mail,=,jjw2004@med.cornell.edu|3:mail,=,jah2048@med.cornell.edu|3:mail,=,irk2007@med.cornell.edu|3:mail,=,mrd2006@med.cornell.edu|3:mail,=,amc2056@med.cornell.edu|3:mail,=,gak2008@med.cornell.edu|3:mail,=,tre2003@med.cornell.edu|3:mail,=,paa2013@med.cornell.edu|3:mail,=,lur2015@med.cornell.edu|3:mail,=,jmg2015@qatar-med.cornell.edu|3:mail,=,hchemmi@med.cornell.edu|3:mail,=,jbarchas@med.cornell.edu|3:mail,=,fac2001@med.cornell.edu|3:mail,=,rgcryst@med.cornell.edu|3:mail,=,djd2003@med.cornell.edu|3:mail,=,mfink@med.cornell.edu|3:mail,=,formenti@med.cornell.edu|3:mail,=,lngirard@med.cornell.edu|3:mail,=,rdgranst@med.cornell.edu|3:mail,=,ljgudas@med.cornell.edu|3:mail,=,rak2007@med.cornell.edu|3:mail,=,dknowles@med.cornell.edu|3:mail,=,jpleonar@med.cornell.edu|3:mail,=,gml2001@med.cornell.edu|3:mail,=,frmaxfie@med.cornell.edu|3:mail,=,fam2006@med.cornell.edu|3:mail,=,rjm2002@med.cornell.edu|3:mail,=,cnathan@med.cornell.edu|3:mail,=,pnschleg@med.cornell.edu|3:mail,=,mgs2002@med.cornell.edu|3:mail,=,pes2008@med.cornell.edu|3:mail,=,haw2002@med.cornell.edu|3:mail,=,scohen@med.cornell.edu|3:mail,=,spuccin@med.cornell.edu|3:mail,=,dchristi@med.cornell.edu';
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
