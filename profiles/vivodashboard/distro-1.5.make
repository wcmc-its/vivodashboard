; This will build a VIVO Dashboard codebase compatible with VIVO 1.5 and below.

core = 7.x
api = 2

;-------------------------------------------------------------------------------
; Drupal core
;-------------------------------------------------------------------------------

projects[drupal][version] = 7.34

;-------------------------------------------------------------------------------
; Installation profile
;-------------------------------------------------------------------------------

projects[vivodashboard][type] = "profile"
projects[vivodashboard][download][type] = "git"
projects[vivodashboard][download][url] = "https://github.com/paulalbert1/vivodashboard.git"
projects[vivodashboard][download][branch] = "master"
projects[vivodashboard][download][revision] = "bd4e92761c9f974ed5281fa6e4f2b46fb015dcc5"
