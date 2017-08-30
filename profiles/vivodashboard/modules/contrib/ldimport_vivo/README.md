VIVO plugins for Linked Data Import
===================================

This module contains VIVO-specific plugins for the [Linked Data Import](http://github.com/milesw/ldimport) Drupal module.

Requirements
------------

- Drupal 7.x
- Linked Data Import module

Installation
------------

1. Download and install the ldimport module and its dependencies.
2. Download and enable ldimport_vivo.

Usage
-----

New fetcher plugins will be available on the Feeds importer configuration.

Included plugins
----------------

### VIVO Class Fetcher
Retrieves all resources of a particular class from a VIVO instance.

![Screenshot](https://raw.github.com/milesw/ldimport_vivo/docs/ldimport_vivo_class_fetcher.png)

Included examples
-----------------

The following example modules are included to demonstrate usage. They include content types, fields, and pre-configured Feeds importers. You'll need the Features module, and you'll want to enable feeds_ui as well.

### VIVO Libraries
Imports all [individuals of type http://vivoweb.org/ontology/core#Library](http://vivo.cornell.edu/individuallist?vclassId=http%3A%2F%2Fvivoweb.org%2Fontology%2Fcore%23Library) from Cornell University's VIVO instance as nodes. A few properties are mapped to Drupal text fields.
