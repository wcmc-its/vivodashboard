; This will build a VIVO Dashboard codebase compatible with VIVO 1.6 and above.

core = 7.x
api = 2

;-------------------------------------------------------------------------------
; Drupal core
;-------------------------------------------------------------------------------

projects[drupal][version] = 7.x

;-------------------------------------------------------------------------------
; Installation profile
;-------------------------------------------------------------------------------

projects[vivodashboard][type] = "profile"
projects[vivodashboard][download][type] = "git"
projects[vivodashboard][download][url] = "https://github.com/wcmc-its/vivodashboard.git"
projects[vivodashboard][download][branch] = "master"
