core = 7.x
api = 2

;-------------------------------------------------------------------------------
; Contrib modules
;-------------------------------------------------------------------------------

defaults[projects][subdir] = contrib

projects[admin_menu][version] = "3.0-rc4"
projects[ctools][version] = "1.4"
projects[charts_graphs][version] = "2.0"
projects[charts_graphs_flot][version] = "1.0"
projects[context][version] = "3.3"
projects[date][version] = "2.9"
projects[devel][version] = "1.5"
projects[diff][version] = "3.2"
projects[disable_messages][version] = "1.1"
projects[entity][version] = "1.5"
projects[entitycache][version] = "1.2"
projects[facetapi][version] = "1.5"
projects[facetapi_bonus][version] = "1.1"
projects[facetapi_multiselect][version] = "1.0-beta1"
projects[features][version] = "2.7"
projects[feeds][version] = "2.0-beta1"
projects[jquery_update][version] = "2.4"
projects[libraries][version] = "2.1"
projects[link][version] = "1.2"
projects[search_api][version] = "1.13"
projects[search_api_db][version] = "1.4"
projects[search_api_solr][version] = "1.6"
projects[strongarm][version] = "2.0"
projects[ultimate_cron][version] = "2.0-rc1"
projects[uuid][version] = "1.0-alpha6"
projects[views][version] = "3.8"
projects[views_bulk_operations][version] = "3.2"
projects[views_data_export][version] = "3.0-beta7"

; Newer versions introduce bug with display settings form similar to...
; https://www.drupal.org/node/2156193
projects[date_facets][type] = "module"
projects[date_facets][download][type] = "git"
projects[date_facets][download][url] = "http://git.drupal.org/project/date_facets.git"
projects[date_facets][download][branch] = "7.x-1.x"
projects[date_facets][download][revision] = "9037608bc2736096b9e30d94e843958aab27e584"

projects[facetapi_graphs][type] = "module"
projects[facetapi_graphs][download][type] = "git"
projects[facetapi_graphs][download][url] = "http://git.drupal.org/project/facetapi_graphs.git"
projects[facetapi_graphs][download][branch] = "7.x-1.x"
projects[facetapi_graphs][download][revision] = "1f87addaa99fa1a941fa9cfa101fd49925b6e49d"

projects[flot][type] = "module"
projects[flot][download][type] = "git"
projects[flot][download][url] = "http://git.drupal.org/project/flot.git"
projects[flot][download][branch] = "7.x-1.x"
projects[flot][download][revision] = "516ecd418878d3a10abd38342862a4fafdf12179"

projects[job_scheduler][type] = "module"
projects[job_scheduler][download][type] = "git"
projects[job_scheduler][download][url] = "http://git.drupal.org/project/job_scheduler.git"
projects[job_scheduler][download][branch] = "7.x-2.x"
projects[job_scheduler][download][revision] = "c51661e94e6d23c9e494cd86377782d010070da4"

projects[relation][type] = "module"
projects[relation][download][type] = "git"
projects[relation][download][url] = "http://git.drupal.org/project/relation.git"
projects[relation][download][branch] = "7.x-1.x"
projects[relation][download][revision] = "2ca9fe24c12c24c6f9fc7dab631ae5a24999b84c"

projects[search_api_ranges][type] = "module"
projects[search_api_ranges][download][type] = "git"
projects[search_api_ranges][download][url] = "http://git.drupal.org/project/search_api_ranges.git"
projects[search_api_ranges][download][branch] = "7.x-1.x"
projects[search_api_ranges][download][revision] = "05a372d7d216765cdb49b789602cfb0041ae92e9"

projects[ldimport][type] = "module"
projects[ldimport][download][type] = "git"
projects[ldimport][download][url] = "https://github.com/milesw/ldimport.git"
projects[ldimport][download][branch] = "master"
projects[ldimport][download][revision] = "88be6fb818de54d72355a60079630bd00567ea38"

projects[ldimport_vivo][type] = "module"
projects[ldimport_vivo][download][type] = "git"
projects[ldimport_vivo][download][url] = "https://github.com/milesw/ldimport_vivo.git"
projects[ldimport_vivo][download][branch] = "graphite"
projects[ldimport_vivo][download][revision] = "5ee8582a42a8e59e726a67d2eeddd6fa2e6748e1"

;-------------------------------------------------------------------------------
; Patches
;-------------------------------------------------------------------------------

projects[facetapi_multiselect][patch][180634] = "https://drupal.org/files/issues/1806344.13.count_autosubmit_removeSelected_0.patch"
projects[relation][patch][2354019] = "https://www.drupal.org/files/issues/relation-2354019-1-custom-feeds-mappers.patch"
projects[relation][patch][2349385] = "https://www.drupal.org/files/issues/chasing_feeds_head-2349385-1.patch"
projects[search_api_ranges][patch][2217717] = "https://drupal.org/files/issues/search_api_ranges-2217717-1-cancel-autosubmit.patch"
projects[search_api_ranges][patch][2051163] = "https://drupal.org/files/issues/search_api_ranges-2051163-9-decimal-support.patch"
projects[search_api_ranges][patch][2130349] = "https://drupal.org/files/issues/search_api_ranges-error_locale_module_disabled-2130349-4.patch"
projects[views_data_export][patch][1258390] = "https://drupal.org/files/views_data_export-solr_export-1258390-13.patch"
projects[feeds][patch][2147341] = "https://www.drupal.org/files/issues/feeds-2147341-missing_taxonomy_bundle-8-latest_dev.patch"

;-------------------------------------------------------------------------------
; Libraries
;-------------------------------------------------------------------------------

libraries[ARC2][download][type] = "git"
libraries[ARC2][download][url] = "https://github.com/semsol/arc2.git"
libraries[ARC2][download][revision] = "bc67abee322edb0a38b304cc4695543c43ae735b"
libraries[ARC2][directory_name] = "arc"
libraries[ARC2][subdir] = "ARC2"
libraries[ARC2][type] = "library"

libraries[Graphite][download][type] = "git"
libraries[Graphite][download][url] = "https://github.com/cgutteridge/Graphite.git"
libraries[Graphite][download][revision] = "c3442ca9f3ca46e1f037aef8cbc89cb415186f01"
libraries[Graphite][directory_name] = "Graphite"
libraries[Graphite][type] = "library"

libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/1.0.0/chosen_v1.0.0.zip"
libraries[chosen][directory_name] = "chosen"
libraries[chosen][type] = "library"

libraries[select2][download][type] = "get"
libraries[select2][download][url] = "https://github.com/ivaynberg/select2/archive/3.4.5.zip"
libraries[select2][directory_name] = "select2"
libraries[select2][type] = "library"

libraries[flot][download][type] = "git"
libraries[flot][download][url] = "https://github.com/flot/flot.git"
libraries[flot][download][revision] = "e2147c078e669365b70427c28dce363031ecc7ed"
libraries[flot][directory_name] = "flot"
libraries[flot][type] = "library"

libraries[flot-tickrotor][download][type] = "git"
libraries[flot-tickrotor][download][url] = "https://github.com/markrcote/flot-tickrotor"
libraries[flot-tickrotor][download][revision] = "c658595830c3e17cac4090f0b6b90c7246666b17"
libraries[flot-tickrotor][directory_name] = "flot-tickrotor"
libraries[flot-tickrotor][type] = "library"
