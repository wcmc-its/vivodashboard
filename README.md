VIVO Dashboard
==============

VIVO Dashboard is a Drupal-based application for analyzing publication metadata coming from VIVO, a semantic researcher profile system. VIVO Dashboard allows end users (primarily administrators) to easily generate reports in one of the three way: bar graphs, HTML lists, and spreadsheets. End users can facet publication records in a variety of ways including:

- year
- publication type
- journal ranking
- journal name
- author name
- author type
- organizational affiliation
- first-last author affiliation


What it looks like
-----------

- Weill Cornell Medical College: http://live-vivo-dashboard.gotpantheon.com


How it works
------------

### Import process

All VIVO sites expose their data as RDF. VIVO Dashboard routinely retrieves batches of RDF data from VIVO and turns it into Drupal content using Drupal's "Feeds" module.

VIVO's index pages contain links to RDF files listing all individuals in a particular class. VIVO Dashboard uses these RDF lists as feeds, similar to RSS feeds, periodically checking the lists to see if publications have been added or removed. Individuals linked to publications, such as authors and journals, are imported on demand.

**Note**: VIVO may limit these RDF lists to 30,000 items.

The import process is quite slow. Tens of thousands of publications will typically take between a few days and a week to import, depending on the performance of the VIVO site.

### Drupal interface

VIVO Dashboard saves imported data as Drupal content.

- Publications -> nodes
- Authorships -> relations
- Authors -> nodes
- Journals -> taxonomy terms
- Departments -> taxonomy terms

By storing imported data as Drupal content it becomes possible to leverage the thousands of available Drupal modules. VIVO Dashboard uses a number of popular modules to power its faceted search interface, including:

- Views
- Search API
- Facet API

The main interface included with the application is highly customizable. These modules allow for great flexibility, and administrators can adjust the interface to suit their institution's needs.

VIVO version compatibility
--------------------------

VIVO Dashboard has been updated to work with the new VIVO-ISF ontology structure introduced in VIVO 1.6. The import system has been upgraded with better caching and more configurability. The Ultimate Cron module has been added as a more reliable replacement to Elysia Cron.

To install a version of VIVO Dashboard compatible with VIVO 1.5 and below, simply use the distro-1.5.make file when building the codebase, as described the "Installation" section. Note that, after building the codebase, the README for that particular version of VIVO Dashboard can be found in DRUPAL_ROOT/profiles/vivodashboard.

Installation
------------

VIVO Dashboard is made available as a Drupal install profile and does not actually include all the required packages. Before installing, the codebase must be "built" using Drush.

### Building with Drush

Install Drush by following the instructions at: https://github.com/drush-ops/drush

For VIVO 1.6+ run:

    drush make https://raw.githubusercontent.com/paulalbert1/vivodashboard/master/distro.make vivodashboard

For VIVO 1.5 and below run:

    drush make https://raw.githubusercontent.com/paulalbert1/vivodashboard/master/distro-1.5.make vivodashboard

If no errors were reported, you should should have a complete VIVO Dashboard codebase inside the "vivodashboard" directory.

### Drupal hosting

If you have your own hosting, or want to install VIVO Dashboard in your own local development environment, review the documentation on installing Drupal here : https://drupal.org/documentation/install (Step 1 is already done).

If you have don't have a preference for hosting, Pantheon is an excellent option. Development sites are free.

If you want to get up and running quickly on your local machine, Acquia Dev Desktop is a great self-contained LAMP environment for Windows and Mac, designed for Drupal.

### Installing on Pantheon

1. Create a new site on Pantheon and proceed through the Drupal installation. Info you enter does not matter at this point.
2. Put the Pantheon site in SFTP mode.
3. Inside the "vivo-dashboard" directory you built using Drush, locate the "profiles/vivodashboard" directory.
4. Connect to the Pantheon FTP server and upload your "profiles/vivodashboard" to the corresponding "profiles" directory on Pantheon. This may be inside a "code" directory.
5. In the Pantheon dashboard go to "Workflow" and then "Wipe". Confirm and wipe the environment.
6. Click on "Visit Development Site".
7. You should see a Drupal installation page again, with an option to install VIVO Dashboard. Choose that option and proceed through the installation. If there is no such option, you probably did not upload "profiles/vivodashboard" to the correct location.
8. When the installation is finished you will be taken to VIVO Dashboard's main page.

Note: If you're comfortable using Git, steps 2-4 can be done with Pantheon's Git repository for the site. You'll need to add an SSH key in the Pantheon dashboard.

### Installing with Acquia Dev Desktop

1. Install the Acquia Dev Desktop application
2. Open the Acquia Dev Desktop Control Panel, go to Settings, then Sites, then Import.
3. For the "Site path" locate the "vivo-dashboard" directory you built using Drush.
4. For the database select "Create new database".
5. Enter anything you want for the domain.
6. After clicking "Import" you should be brought to a Drupal installation page.
7. Choose the "VIVO Dashboard" option and proceed through the installation.
8. When the installation is finished you will be taken to VIVO Dashboard's main page.


Setup
-----

### Starting an Import

Once installed, the first thing to do is start the import.

1. Visit the /import page, then choose the "VIVO Publications" importer.
2. Enter your VIVO site's URL in the form.
3. Enter the URI for the class you'd like to import (e.g. http://purl.org/ontology/bibo/AcademicArticle).
4. Click "Import".
5. In a new browser tab visit /import/log to confirm data is being retrieved.

Note: VIVO importers other than "VIVO Publications" can be ignored. These get triggered automatically.

If you see a status message reporting "There are no new nodes" your class URI is likely incorrect.

If you see an error message, your VIVO site URL might be incorrect or VIVO could be failing to produce the RDF list for the specified class. Some VIVO sites seem to have trouble with RDF lists containing a large number of individuals. You can test this by instead trying a class that contains a smaller number of individuals (hundreds instead of thousands). See the Troubleshooting section for more information.

If the form spends a minute or two loading after clicking "Import", and you get an error without any details, it's likely that PHP hit its time limit. That's fine, the import will pick up where it left off.

### Configuring cron

Most VIVO sites contain thousands of publications, and a complete publication import may take anywhere from a few days to over a week. Because PHP has limits on the execution time for a request, Drupal must import one small chunk of data at a time via cron runs.

Review the documentation on setting up cron for Drupal: https://drupal.org/cron

For VIVO Dashboard, the optimal cron frequency is 1 minute.

The ideal way to run cron is via Drush + Ultimate Cron. The Ultimate Cron module has a special drush command "cron-run" that will be the most efficient way to keep your import running.

Example crontab entry:

    */1 * * * * drush --root=/path/to/your/drupalroot --quiet cron-run

Note: If you need to install your crontab entry on a separate server (i.e. when using Pantheon for hosting), you will need to install SSH keys and Drush aliases on that server.

Example crontab entry on a separate server:

    */1 * * * * drush @pantheon.username.vivo-dashboard.dev --quiet cron-run

If unable to use Drush, a more typical crontab entry should still work:

    */1 * * * * wget -O - -q -t 1 http://mysite.gotpantheon.com/cron.php?cron_key=rUncI0PLGq7_56SrZzNCrnerLoHZOHb7pCoFSFhBwdE

Note: The cron_key is unique for each site. You can find this URL on the Status Report (Reports -> Status report).


### More cron

Cron runs are used to keep Drupal working. The two main jobs that VIVO Dashboard performs during a cron run are:

1. Importing data from VIVO
2. Indexing imported content for search

VIVO Dashboard comes with a module called Ultimate Cron. This module acts as a manager responsible for delegating work. Ultimate Cron knows how frequently jobs should be performed and will trigger them accordingly.

Ultimate Cron can be configured at: Configuration -> System -> Cron Settings (/admin/config/system/cron)

### Resting the publication import process on VIVODashboard

Following are the procedures to reset the import on VIVODashboard.
1. Login with admin privilege.
2. Unlock the import by first killing/unlocking the running cron jobs on feeds: (https://vivodashboard.weill.cornell.edu/admin/config/system/cron)
Default cron handler
Queue: feeds_push_unsubscribe
Queue: feeds_source_clear
Queue: feeds_source_expire
Queue: feeds_source_import
3. Go to import module and unlock the import process: (https://vivodashboard.weill.cornell.edu/import/vivo_publications)
Click on the UNLOCK tab to open a confirmation page.
Confirm unlock by clicking on Unlock button.


Customization
-------------

### Journal rankings

SCImago journal ranking data can be imported using the Journal Rankings importer (/import/journal_rankings), which expects a TSV file. Column 1 should contain the journal name, column 2 should contain the rank, and column 3 should contain the ISSN.

Once these are imported you'll need to do a bulk update to add ranking data to previously-imported journals (/admin/structure/taxonomy/journal_rankings/update), and run a search reindex (/admin/config/search/search_api/index/authorships and /admin/config/search/search_api/index/publications). Journals added after ranking data has been imported will automatically pick up rankings based on ISSN.

### Institution-specific data

Chances are you will want to adjust the existing data mappings or add new data specific to your institution. All the mapping from VIVO to Drupal happens in the Feeds importer configurations under Structure -> Feeds importers, then under Processor -> Mapping.

- VIVO Publications: /admin/structure/feeds/vivo_publications/mapping
- VIVO Authors: /admin/structure/feeds/vivo_authors/mapping
- VIVO Journals: /admin/structure/feeds/vivo_journals/mapping

It should be fairly easy to add new data properties and map them to Drupal fields. Object properties (relationships), however, are a bit more complex and mapping for these has yet to be streamlined.

### Hiding rdf:type items

You will often get not-so-useful superclasses, such as "Thing" or "Agent", appearing in facets and lists. To hide those, edit the corresponding taxonomy term (/admin/structure/taxonomy/rdf_types) and click the "Hidden" option at the bottom. You will need to reindex before the change takes effect.

**Note**: It's a good idea to clear caches after hiding/unhiding an rdf:type term. Do this before reindexing.

### Including/excluding facet items

When logged in you can edit configuration for facets by hovering over them and clicking the gear icon. Select "Configure facet filters", where you can enable either "Include" or "Exclude" filters.


Troubleshooting
---------------

The first thing to try when troubleshooting Drupal is clearing caches. You can find "Flush all caches" under the Home icon in the toolbar.

### Database log

Drupal maintains a comprehensive system log at: Reports -> Recent log messages (/admin/reports/dblog)

### Feeds log

There is aggregated view of the Feeds import log at: /import/log

By default, feed importers are configured to add lots of debug information to the log. These entries have a severity of "debug". This can be turned off per-importer in the parser plugin settings.

Problems during a VIVO import, such as failed linked data requests, are usually logged with a severity of "warning" or "error".

### Failed linked data requests

If you see warnings in the Feeds log indicating that certain VIVO URIs returned no data, the requests are likely timing out. This typically happens with VIVO individuals containing very large amounts of data. You can try increasing the timeout for the importer in the parser settings (e.g. /admin/structure/feeds/vivo_publications/settings/LdImportParser).

### VIVO RDF list errors workaround

If you get error messages such as "500 Internal Server Error" after submitting the Import form, the VIVO site is likely failing to produce the RDF list for the class you specified. You can verify this by visiting the index page on the VIVO site, choosing the respective class, and trying the RDF link at the top.

One way to work around this is by manually creating a text file containing all the publication URIs to be imported, with one URI per line. This can be done using VIVO's internal SPARQL endpoint. You'll then need to change the Fetcher plugin for the importer (/admin/structure/feeds/vivo_publications/fetcher) to either "File upload" or "HTTP Fetcher". Then you can specify this text file on the import form (/import/vivo_publications).

**Note**: VIVO's SPARQL form produces a CSV with URIs wrapped in quotes. The quotes need to be removed for VIVO Dashboard.

### Cron jobs not running

If the jobs at /admin/config/system/cron are not running and you are certain that a crontab entry has been correctly configured, it may be that Ultimate Cron has gotten stuck. Unfortunately, the best way to unstick it seems to be to manually truncating the following database tables: cache_ultimate_cron, ultimate_cron_lock


Performance
-----------

Drupal's great flexibility often comes at the expense of performance. As the amount of data increases, VIVO Dashboard will become slower. There are some things you can do to give Drupal a boost.

### Linked data caching (enabled by default)

The Graphite library is now used for all RDF handling during imports. Graphite will optionally cache all linked data responses to the filesystem. This saves a tremendous number of HTTP requests while importing VIVO data, so this caching is enabled by default. The cache location is inside Drupal's configured temporary directory, in a "graphite-HASH" directory. Be aware this directory can grow quite large.

### Entity Cache

VIVO Dashboard comes with a module called Entity Cache that is intended to reduce the load on the database. This module is disabled by default only because it has not had enough testing. Enabling it is perfectly safe and should lead to noticeable performance gains. However, it should be suspect if pieces of data start disappearing.

### Apache Solr

The primary module behind VIVO Dashboard's faceted search is Search API. Search API relies on a "backend" module and clever indexing to do its magic. Out of the box the database backend (search_api_db) is used for VIVO Dashboard in order to minimize hosting requirements. While this is the most convenient backend, it's not the most performant.

Using Apache Solr as the backend for Search API will yield substantially better performance. Although it hasn't been fully tested, it should simply be a matter of changing the Search API indexes to use the Solr backend already included with VIVO Dashboard (/admin/config/search/search_api).

You also, of course, must set up the Apache Solr server itself. Once you do so, you'll need to copy configuration files from the search_api_solr Drupal module to Apache Solr's "conf" directory. Instructions and be found on the search_api_solr module page: https://drupal.org/project/search_api_solr


Developer notes
----------------------

VIVO Dashboard is set up as a Drupal install profile, with custom functionality handled by the Features module.

The custom features bundled with VIVO dashboard can be found in: DRUPAL_ROOT/profiles/vivodashboard/modules/vivodashboard

Most files in these directories are generated by features and can be ignored.

Custom code can be found in:

- The .module file for the feature (e.g. vivodashboard_publications.module)
- Module-specific includes, autoloaded by other modules (e.g. vivodashboard_import.feeds.inc)
- The plugins directory for each feature (e.g. vivodashboard_core/plugins)

### Capturing local changes

As a general rule, don't touch the code inside DRUPAL_ROOT/profiles/vivodashboard. If you need to add or upgrade a contrib module, place it in sites/all.

After overriding the VIVO Dashboard defaults, when customizing things for your institution, you may want to capture your changes in code for version control. Overwriting the VIVO Dashboard features directly would make future updates difficult. A more sustainable approach extract new features modules and include them in sites/all/modules.

Sometimes it may be necessary to duplicate the entire VIVO Dashboard feature to sites/all/modules in order to make your modifications. Unfortunately Drupal 7 doesn't offer a better option for managing configuration.

### Search API publications and authorships

You will find there are two Search API indexes: publications and authorships. They have the same fields indexed and the same facets enabled. The authorships index exists to work around an unfortunate limitation in Search API's Views integration.

VIVO Dashboard's publication export pages are views listing individual authorships (as opposed to publications). Normally Views would be able to accomplish this using relationships, but Search API relies on Entity API for Views integration, which has very limited support for relationships. This drupal.org issue has comments from the Entity API and Search API maintainers regarding this limitation: https://drupal.org/node/1378656

For now, maintaining two separate, almost identical, Search API indexes is the only way to accomplish both the List and Export views. Consolidated indexing code can be found in search_api_alter_callback_publications.inc

Citation Impact Tool
----------------------

### Overview

The Citation Impact Tool is a module in VIVO Dashboard designed to allow credentialed users to view data on the scholarly impact of full-time WCM faculty (numbering approximately 1,600 as of October 2015). The data are presented in the form of interactive information graphics, iconographic box plots depicting the distribution in percentile ranks of the number of times each of the researcher's scholarly works have been cited, against a baseline of articles in the same field, published the same year, and of the same article type.

As of June 2016, access to the system is limited to VIVO Dashboard evaluators in the library and ITS. Following the beta release system access will be limited to selected library and ITS staff and individuals in the WCMC Executive Faculty Council.

A Frequently Asked Questions (FAQ) page for users is available at http://dev-vivo-dashboard.gotpantheon.com/citations/faq

### Roles

- Librarian: Designed Citation Impact plot. Worked with developer to design data systems and processes. Provides customer service to users. 
- Developer: Developed data systems and processes to produce the plots and keep them updated. Maintains integrity of data. Resolves technical problems if needed.

### Data sources

- Publications data in the PubAdmin tool are ingested into VIVO, which are in turn ingested into VIVO Dashboard.
- Times cited data, both for WCM-authored publications and the publications in the baselines, are from Scopus.
- Journal categories are from the Thomson Reuters Web of Science database.

### Key processes

Publications authored by WCM full-time faculty are maintained in the PubAdmin database maintained by Paul Albert, Eliza Chan, and Prakash Adekkanattu. Upstream from the Citation Impact Tool, metadata about these publications are ingested into VIVO on a regular basis.

1. Ingesting publication data from VIVO
  1. A combination of multiple modules is used to import WCM faculty-authored publications from VIVO by retrieving and parsing associated RDF data. The parsed data for each publication are then used to create various nodes, terms, and data fields in VIVO Dashboard, which is built on a Drupal platform.
  2. The import process runs on a regular basis through jobs scheduled using Cron.
  3. Details on Cron jobs used in the Citation Impact Tool are in the "Cron jobs" section below.
2. Updating citation counts
  1. The import process brings in updated citation counts for WCM articles as and when this value gets updated in VIVO. 
3. Compiling articles for the baseline reference sets
  1. Using the baseline set of articles imported from Pubmed and updated with citation counts from Scopus (violin_pmid), a custom PHP tool populates violin_baseline with sets of articles matching the year, field, and article type. These reference sets serve as the baselines against which percentile rank values are calculated.
  2. Except in cases where the number of candidate articles is small (e.g., review articles in acoustics for the Year 2004), there are approximately 200 articles in each reference set.
4. Calculating percentile ranks
  1. A PHP script calculates percentile rank for each article in VIVO Dashboard and populate tables violin_wcmc_article, violin_wcmc_author and violin_wcmc_author_article with various fields.
  2. To calculate the percentile rank, this script first calculates a percentile rank for each category assigned to the journal in which the article is published.
  3. To identify the categories for a given journal, the journal's ISSN (or EISSN) is used to determine the journal_id in the violin_journal table.
  4. This journal_id is used to look up the journal's categories in the violin_journal_category table.
  5. The categories themselves are in the violin_category table.
  6. To determine an article's percentile rank in a given category, the script sorts the articles in the selected baseline by times cited and assigns each article a raw rank. The article cited the highest number of times is assigned a raw rank of 1; the article cited the fewest number of times is assigned 200. The script then determines whether, among the articles in the baseline, there is an article with a matching number of times cited.
    1. If there is an article with a matching number of times cited, the article is assigned a percentile rank (for the given category) based on the rank of the article in the baseline.
    2. If there is no article with a matching number of times cited, the article is assigned a percentile rank (for the given category) based on the average of the ranks of the articles immediately above and below the value corresponding to the article's times cited.
  7. When an article's journal is assigned to more than one category, the percentile ranks for each of an article's journal's categories are averaged together to compute the rank. 

### Percentile ranking for WCM Publications

A Drupal module called violin_admin handles percentile ranking calculations for WCM publications. For each article, percentile ranking is calculated through an algorithm that determines the percentile rank of a given article in comparison to the baseline reference set corresponding to the article's year, categories, and article type.

The violin_admin module runs on a Cron to handles new and updated articles coming to VIVODashboard from VIVO through the import process.

### Citation Visualization on VIVO Dashboard

The visualization of citation impact for WCM publications are done through a custom module called Citations. This module queries the citations search index, and presents the results in the form of interactive iconographic box plots depicting the distribution in percentile ranks. The search API indexes on publications. authorships and citations are handled by a module called search API . Search results can be filtered based on various publication and author related fields through facet filters. The facet filters are implemented by another module called facet API. 

### Cron Jobs

Cron jobs are used to run processes that populate VIVO Dashboard with data from VIVO. Elements of data are parsed from publications and used to create nodes, terms, and data fields in the VIVO Dashboard Drupal instance. Cron jobs are configured and run from the corresponding modules on Drupal. They are managed on Drupal by a module called ultimate_cron. They may also be run manually as needed.

To run them manually:

1. Login to VIVO Dashboard as an administrator
2. Click Configuration, System, Cron. (Link is http://dev-vivo-dashboard.gotpantheon.com/admin/config/system/cron).
3. Run any desired Cron job manually.

### Notes on d3.js code

The iconographic box plots are generated using code written with the d3.js javascript library. The d3.js code takes one parameter, articlesPerSquare. This indicates the number of articles represented visually by each square in the iconographic plot.

### Instructions and timetable for manual and automatic updates

#### Updating the Web of Science categories

Purpose: Thomson Reuters periodically updates the Web of Science journal categories. These changes are manually integrated into the Citation Lookup Tool.

Persons responsible: Michael Bales and Prakash Adekkanattu

Dates run: March 1st of each year, starting March 1st, 2016.

How to get the Web of Science subject categories for all journals (Michael):

1. Point a web browser to Web of Science
2. Navigate to Journal Citation Reports
3. Click Categories by Rank
4. Find the numbers in the Journals column
5. Click the number for a WoS category
6. Download the records.
7. Repeat for all subject categories (232 as of February 2016)
8. Put all the downloaded files into a new folder "mycsv" in a directory of your choice on your local machine.
9. To concatenate the CSV files, in command line, navigate to the directory and type:

files=*
cat $files > combined.csv

Michael sends the combined.csv file to Prakash, who updates the violin_journal, violin_category, and violin_journal_category tables on VIVO Dashboard Dev and VIVO Dashboard Live.

#### Updating the baseline reference sets

Purpose: Percentile ranks are measured against baseline sets of articles published the same year, in the same filed, and of the same article type. These baselines must be updated periodically to maintain the accuracy of the data in the citation impact plots.

Person responsible: Prakash Adekkanattu

Dates run: Quarterly, on March 1st, June 1st, September 1st, and December 1st of each year, starting March 1st, 2016.

Process: Prakash runs medline_fetch.php, scopus_fetch.php, and percentile_ranking.php, in sequence. Details below.

#### PHP tools to manage baseline article sets

The tables relevant to management of the baseline article sets are: violin_category, violin_journal, and violin_journal_category, violin_pmid, and violin_baseline.

medline_fetch.php: Imports a baseline set of articles from Pubmed. 200 articles for each category, article type, and publication year for ten-year period starting 13 years prior to the current year and ending two years prior to the current year. For example, for the calendar year 2016, the time range covered is 2003–2014. Along with scopus_fetch.php, this script populates violin_pmid.

scopus_fetch.php: Retrieves citation count from Scopus for all the articles in baseline set that are imported from Pubmed. Along with medline_fetch.php, this script populates violin_pmid.

percentile_ranking.php: Calculates percentile ranking for each article in baseline set. This script populates violin_baseline, which is used to calculate percentile ranking for WCM publications.

Baseline tables are manually copied by Prakash to the VIVO Dashboard database for use in calculating percentile ranks for WCMC publications.
