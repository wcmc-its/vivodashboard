VIVO Dashboard CSV Import module
================================

This module implements migrations for the Migrate module to import VIVO data
prepared in CSV format by WCMC.


CSV files
---------

The migrations look for CSV files in Drupal's private files directory. To change
this without changing the migration code, you can add the following to
settings.php to override CSV file paths individually:

$conf['vivodashboard_csv_import_files'] = array(
  'Authors' => 'private://somewhere-else/authors.csv',
  'Authorships' => 'private://somewhere-else/authorships.csv',
  'Departments' => 'private://somewhere-else/departments.csv',
  'Institutions' => 'private://somewhere-else/institutions.csv',
  'Journals' => 'private://somewhere-else/journals.csv',
  'Publications' => 'private://somewhere-else/publications.csv',
  'RdfTypes' => 'private://another-folder/rdf_types.csv',
  'JournalRankings' => 'private://another-folder/journal_rankings.tsv',
);


Checking import status
----------------------

via Drush:

$ drush ms

via UI:

/admin/content/migrate/groups/vivodashboard


Additional Migrate features
---------------------------

The following features have been implemented on top of Migrate and the CSV
handling it comes with out of the box.

1. Skipping imports

When a CSV file has not changed at all since it was last imported, we skip it
entirely since iterating large CSVs and checking rows can take a long time.

See VivoDashboardCsvMigrationBase::import()

2. Resumable imports

Normally the Migrate module expects to import data in a single shot when run via
Drush. Since some of the migrations here can take more than 1 hour (more than
Pantheon's time limit), the base VivoDashboardCsvSource class has been developed
to pick up where it left of with CSV iteration.

See VivoDashboardCsvSource::performRewind()

3. Cleaning stale data

The base migration class for this module implements a "cleaning" feature that
Migrate does not come with out of the box. Upon reaching the end of a CSV, it
will compare the rows with the CSV to those imported into Drupal. If there are
imported rows that are no longer in the CSV, it will consider those orphaned and
remove those items from Drupal.

See VivoDashboardCsvMigrationBase::cleanOrphanedItems()

There is unfinished work on the same feature here:
https://www.drupal.org/node/1416672