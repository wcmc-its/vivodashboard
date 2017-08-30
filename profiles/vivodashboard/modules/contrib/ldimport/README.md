Linked Data Import module
=========================

This module defines plugins for the Feeds module that let you turn remote linked data resources into Drupal entities, such as nodes and taxonomy terms. It can be used for either a one-time import or periodic imports.

Overview
------------

Most of the Drupal functionality comes from the Feeds module itself. All linked data fetching and parsing is handled by the Graphite and ARC2 libraries.

1. You configure a Feeds importer
2. You define a list of resource URIs to import
3. Graphite fetches RDF data for each resource via content negotiation
4. Feeds creates one Drupal entity for each resource
5. Feeds maps RDF properties to Drupal fields for each entity

Requirements
------------

- Drupal 7.x
- Feeds module
- Libraries module
- Graphite library
- ARC2 library

Installation
------------

1. Download and enable the Feeds module and its dependencies.
2. Enable the feeds_ui module.
3. Download and enable the Libraries API module.
4. Download and enable the ldimport module.
5. Download the ARC2 library. Unpack it so the path to ARC2.php is: `sites/<sitename>/libraries/ARC2/arc/ARC2.php`
5. Download the Graphite library. Unpack it so the path to Graphite.php is: `sites/<sitename>/libraries/Graphite/Graphite.php`

or via Drush:
```
drush dl feeds libraries
drush en -y feeds feeds_ui libraries
git clone https://github.com/milesw/ldimport
drush en ldimport
drush ldimport-download
```

Usage
-----

1. Create a new Feeds importer at /admin/structure/feeds. For testing, choose "Use standalone form" for the attached content type, and check "Import on submission".
2. Choose Linked Data Fetcher as the Fetcher plugin.
3. Choose Linked Data Parser as the Parser plugin.
4. Choose any Processor plugin.
5. Add mappings from linked data to Drupal fields under Processor / Mapping. Be sure to include at least one unique mapping (e.g. URI → Feeds URL, or URI → Feeds GUID). There are two special mapping sources: "URI" and "Label". Beyond those, use the full predicate URI as the mapping source. Separate predicate URIs with spaces and empty brackets (" [] ") to map properties from related individuals.
6. Visit /import and click on your importer.
7. Enter a list of URIs for resources you want to import.
8. Run the import.

### Feeds mappings screen:

> ![Feeds UI screenshot](https://github.com/milesw/ldimport/blob/docs/ldimport_mappings.png?raw=true)

Extending the module
--------------------

The module can be extended by [creating a new Feeds fetcher plugin](http://drupal.org/node/622700). The fetcher is responsible for coming up with a list of URIs to be imported. That list could come from a flat file, a SPARQL endpoint, a private web service, etc. The only requirement is that your class extending FeedsFetcherResult includes a getList() method.

### Examples:

- [VIVO plugins for Linked Data Import](https://github.com/milesw/ldimport_vivo)

Credits
-------

This module is the result of work done at Cornell University's Albert R. Mann Library to bring content from Cornell's VIVO database into Drupal.
