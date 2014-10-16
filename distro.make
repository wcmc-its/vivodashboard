core = 7.x
api = 2

;-------------------------------------------------------------------------------
; Drupal core
;-------------------------------------------------------------------------------

projects[drupal][version] = 7.32

;-------------------------------------------------------------------------------
; Installation profile
;-------------------------------------------------------------------------------

projects[vivodashboard][type] = "profile"
projects[vivodashboard][download][type] = "git"
projects[vivodashboard][download][url] = "https://github.com/milesw/vivodashboard.git"
projects[vivodashboard][download][branch] = "master"
