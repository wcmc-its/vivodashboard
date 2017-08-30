
Format CSV is a module targetted at Drupal developers, allowing to
format standard table array as CSV, mimicking Drupal's built-in
theme_table() function behavior.

It accepts both simple arrays of cell values and associative
arrays with "data" keys, strips all HTML tags and ignores all
HTML attributes, returning full content of CSV file with default
or user-defined CSV field delimiters and enclosures.


Install
-------

1) Copy the csv folder to the modules folder in your installation.

2) Enable the module using Administer -> Site building -> Modules
   (/admin/build/modules).


Usage
-----

Call theme('format_csv', ...) function the same way as you call theme('table', ...).

  theme_format_csv($header, $variables)

$variables = array($header, $rows, $attributes, $caption, $delimiter, $enclosure)

$header, $rows, $attributes, $caption
  Same parameters as used by theme_table(). For full description see:
  http://api.drupal.org/api/drupal/includes--theme.inc/function/theme_table/6
  Note that for associative arrays, only "data" keys are processed
  and returned as CSV values, all other keys are ignored.

$delimiter
  Sets the field delimiter (one character only). Optional.
  By default set to , (comma).

$enclosure
  Sets the field enclosure (one character only). Optional.
  By default set to " (double quote).


Author
------

Maciej Zgadzaj
maciej.zgadzaj@gmail.com
