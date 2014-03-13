core = 7.x
api = 2

; Drupal core
projects[drupal][version] = 7.x

; Patch core to fix poor EntityFieldQuery performance with Relation
projects[drupal][patch][1859084] = "https://drupal.org/files/issues/multicolumn-1859084-30.patch"

; Install profile
projects[vivodashboard][type] = "profile"
projects[vivodashboard][download][type] = "git"
projects[vivodashboard][download][url] = "https://github.com/milesw/vivodashboard.git"
projects[vivodashboard][download][branch] = "master"
