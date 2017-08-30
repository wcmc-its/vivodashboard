<?php
/**
 * @file
 * vivodashboard_weill.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function vivodashboard_weill_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: facetapi
  // $overrides["facetapi.search_api@authorships:block:publication_author_firstlast_affiliations.settings|filters|include_items|status"] = 1;
  // $overrides["facetapi.search_api@authorships:block:publication_author_firstlast_affiliations.settings|include"] = 'Weill Cornell Medical College, Cornell University';
  // $overrides["facetapi.search_api@publications:block:publication_author_firstlast_affiliations.settings|include"] = 'Weill Cornell Medical College, Cornell University';
  $overrides["facetapi.search_api@publications:block:publication_types.settings|filters"] = array();

  // Exported overrides for: variable
  $overrides["variable.configurable_timezones.value"] = 1;
  $overrides["variable.elysia_cron_stuck_time.value"] = 360;
  $overrides["variable.elysia_cron_time_limit.value"] = 180;

  // Exported overrides for: views_view
  $overrides["views_view.publications_export_csv.display|default|display_options|filters"] = array(
    'publication_author_types' => array(
      'id' => 'publication_author_types',
      'table' => 'search_api_index_authorships',
      'field' => 'publication_author_types',
      'operator' => 'not empty',
      'value' => array(),
    ),
  );
  $overrides["views_view.publications_list.display|default|display_options|fields|authorships|vivo_namespace"] = 'http://vivo.med.cornell.edu/individual/cwid-';

 return $overrides;
}
