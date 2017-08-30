--------------------------------------------------------------------------------
Customizations to VIVO Dashboard
--------------------------------------------------------------------------------

This folder contains WCMC's extensions to VIVO Dashboard.

Generally the code inside DRUPAL_ROOT/profiles/vivodashboard should not be changed unless the change applies to all VIVO Dashboard instances. Instead, the modules, libraries, and themes inside the profile may be overridden by adding a version to DRUPAL_ROOT/sites/all.

Custom code used for WCMC:

- DRUPAL_ROOT/sites/all/modules/vivodashboard/*
  Modules in this directory take precedence over those included with the base VIVO Dashboard profile. These have been customized for WCMC. Generally this should be avoided and new modules should be created as additions.

- DRUPAL_ROOT/sites/all/modules/contrib/*
  Contributed modules from drupal.org not used by the base install profile.

- DRUPAL_ROOT/sites/all/modules/weill/*
  (This directory) Custom code written for WCMC's VIVO Dashboard.


Reinstalling WCMC VIVO Dashboard
--------------------------------

The vivodashboard_weill feature has been created to capture WCMC-specific config. It is also used to install/enable necessary modules when installing a fresh copy of VIVO Dashboard.

1. Install the standard "VIVO Dashboard" Drupal profile.
2. Enable the vivodashboard_weill module.
3. Run the command: drush features-revert-all -y
4. Clear caches for good measure: drush cc all

Step #3 is necessary to forcefully apply any overrides introduced by the WCMC-specific modules. The overrides can also be manually reviewed at /admin/structure/features.




