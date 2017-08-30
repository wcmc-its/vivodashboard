<?php

/**
 * @file
 * Drush integration for the ldimport module.
 *
 * @todo Remove all this once Libraries has its own download capability.
 */

/**
 * Implements hook_drush_command().
 */
// function ldimport_drush_command() {
//   $items['ldimport-download'] = array(
//     'callback' => 'ldimport_drush_libraries_download',
//     'description' => dt('Downloads the required ARC2 library from http://github.com/semsol/arc2'),
//   );
//   return $items;
// }

/**
 * Implementation of hook_drush_help().
 */
// function ldimport_drush_help($section) {
//   switch ($section) {
//     case 'drush:ldimport-download':
//       return dt('Downloads the required ARC2 library from http://github.com/semsol/arc2');
//   }
// }

/**
 * Drush command callback for 'ldimport-install'.
 */
function ldimport_drush_libraries_download() {
  $library = libraries_detect('ARC2');

  if (!module_exists('libraries')) {
    drush_log('The Libraries module is not enabled.', 'error');
    return;
  }
  elseif ($library && $library['installed']) {
    drush_log('ARC2 already installed.', 'ok');
    return;
  }

  // @todo Support different destinations.
  $destination = drush_get_context('DRUSH_DRUPAL_ROOT') . '/sites/all/libraries/' . $library['machine name'];

  if (!is_dir($destination)) {
    drush_mkdir($destination);
  }

  if (drush_op('chdir', $destination) &&
      drush_shell_exec('wget --no-check-certificate -O arc.tar.gz http://github.com/semsol/arc2/tarball/master') &&
      drush_shell_exec('tar zxvf arc.tar.gz') &&
      drush_shell_exec('mv semsol-arc2-* arc') &&
      drush_shell_exec('rm arc.tar.gz')) {
    drush_log(dt('The latest ARC2 library has been downloaded to @path', array('@path' => $destination)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the ARC2 library to @path', array('@path' => $destination)), 'error');
  }
}
