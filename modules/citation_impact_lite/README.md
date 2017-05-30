Citation Impact Tool
================

Overview
----------------

Many measures of scholarly impact, including the journal impact factor, use parametric approaches that assume citation data to be normally distributed. However, because citation data are highly skewed (i.e., not normally distributed), these parametric approaches are often unreliable. For proper measurement of citation impact, leading bibliometrics researchers support the use of nonparametric approaches. In accordance with this recommendation we developed the Citation Impact Tool, a system that calculates the percentile rank of times cited for individual articles, measured against a baseline of 200 articles of the same type, in the same discipline, and published the same year. The system presents this information visually as an iconographic box plot, portraying a researcher or department’s profile of articles as a collection, with each article displayed in a bin corresponding to its normalized percentile rank.

#### How to generate a citation impact plot using your own data:

The Citation Impact Tool Lite requires PHP, a general-purpose programming language, to be installed (note that knowledge of how to code in PHP is *not* required). If you are using a Mac you likely already have PHP on your machine. If you are using Windows you will need to install PHP if it is not already installed: http://php.net/manual/en/install.windows.php

To use these instructions, you need to know how to use a terminal or command prompt to navigate between directories. A tutorial on using the command prompt is here: http://www.digitalcitizen.life/command-prompt-how-use-basic-commands

* In a terminal or command prompt, navigate to the directory where you would like to install the Citation Impact Tool
* To download the code to your local machine, enter the command:
git clone https://github.com/wcmc-its/vivodashboard.git
* Navigate to the directory /vivodashboard/modules/citation_impact_lite/citation
* To generate an html file with the plot, enter the command:
php plot_csv.php > citation_impact.html<br>
(Note that the above command tells the operating system to use php to run the code in plot_csv.php and to save the output as citation_impact.html)
* In Finder (on Mac) or File Explorer (on Windows), navigate to the directory /vivodashboard/modules/citation_impact_lite/citation
* To display the plot in your browser, double-click on citation_impact.html
* To change the data displayed in the plot, modify the data in /vivodashboard/modules/citation_impact_lite/citation/data/sample_times_cited_data_1_with_authors.csv.
* To modify the data, open it in Microsoft Excel or a text editor. At a minimum, you need to include data in the following fields:
  * pubtype
  * citation_count
  * percentile_rank_dummy_data
  * cover_date

####  Here's how we calculate percentile ranks:

For a given article, we determine the Web of Science subject categories for its journal.

We take the first category, identify all the journals in Medline that are assigned to that category, and randomly select a sample of 200 articles matching the year and article type (academic article or review).

These 200 articles form our baseline for comparison. To determine how many times each of these articles has each been cited we use the Scopus API.
Once we know how many times these articles have been cited we assign each one a rank. The one that’s been cited the fewest number of times is given a rank of 1; the one that’s been cited the most is given a rank of 200. Sometimes there are ties (when more than one article has been cited the same number of times); in that case we assign the median rank of the articles that are tied.
Once we have a rank for each article, we can calculate the percentile rank of the number of times it’s been cited, against the articles in the baseline, using a formula proposed by Hazen (1914):

((i-0.5)/n*100)
where i is the article rank (adjusted for ties)
and n is the number of documents in the reference set.

Finally, we use the reference set to calculate the percentile rank of the article we’re interested in. A given article will have a percentile rank for each category that its journal is in.

####  Building a fully functional citation impact visualization application involves the following steps:

####  I) Database
**Note: The below table definitions can be replicated using the create_db.sql file under the folder sql.**
* Create a database using your preferred database client.
* Create a database user account and provide access permission to this new database.
* Create the following tables necessary for the base application.
 * violin_excel
 * violin_category
 * violin_journal
 * violin_journal_category
 * violin_pmid
 * violin_baseline
 * violin_update_history

In addition to the above tables, the following three tables are also needed if institutional articles are to be stored in a database.
* article
* author
* author_article

#### II) Application settings
Copy the entire code base of citation_impact_lite to your web server home directory.
Modify the library/main.php file with base path and database information.

To test the application, open the file test.php on a browser to see if the phpinfo() page is loading properly.

#### III) Load the sql/violin_excel.sql data containing journals and category to the table violin_excel in your database.
On most database clients this can be accomplished by using the import feature.

#### IV) Populate violin_journal, violin_category and violin_journal_category tables using the data from violin_excel table.
To populate these tables run load_journal_category.php script from a command line:
```
php -f load_journal_category.php
```

#### V) If applicable, import baseline articles from Medline/Scopus
Note: Please ensure that your use of these scripts is consistent with your institution's publication data licensing agreement.
There are two scripts that handle the whole import process:
1. **medline_fetch.php** - This script first fetches a list of PMIDs from PubMed based on the search criteria specified. Then the script will randomly select 200 of these PMIDs and fetch details of each articles from PubMed. Except in cases where the number of candidate articles is small (e.g., review articles in acoustics for the Year 2004), there will be approximately 200 articles in each reference set.
The returned XML is then parsed and populate the table violin_pmid.
2. **scopus_fetch.php** - This script access Scopus API for citation count for each article in violin_pmid and update the citation_count field.

Running these scripts on command line is straightforward. Go to the citation-impact root directory where medline_fetch.php and scopus_fetch.php are located.

First run the Medline fetch script:
```
php -f medline_fetch.php
```

Once Medline fetch is complete,  run the Scopus fetch script:
```
php -f scopus_fetch.php
```

To run these scripts on Cron, set up a crontab as follows:

**Run Medline fetch script:**
```
CITATION_DIR=/dir/location/of/citation_impact_lite
cd $CITATION_DIR; php -f ./medline_fetch.php > /dev/null 2>&1
```
**Run Scopus fetch script**
```
cd $CITATION_DIR; php -f ./scopus_fetch.php > /dev/null 2>&1
```

***Note: Before every run, all entries from previous runs should be removed from violin_pmid table.

#### VI) Custom scripts to import publications for a given year, category ID and article type:

1. **custom_medline_fetch.php** - This script fetches a list of PMIDs from PubMed for a given year, category_id and article type. The program will randomly select 200 of these PMIDs and fetch details of each article from PubMed. The returned XML is then parsed to populate the table violin_pmid.
2. **custom_scopus_fetch.php** - This script accesses the Scopus API to retrieve citation counts for each article in violin_pmid for a given year and updates the citation_count field.

**To run these scripts on the command line, first run the Medline fetch script:**
```
	php -f medline_fetch.php [year] [category id] [type]
```  
```
	Example: php -f medline_fetch.php 2005 114 R
```

**Once Medline fetch is complete, run the Scopus fetch script:**
```php -f scopus_fetch.php 2005```

Note: Article type is "R" for Review and "A" for Academic article.

Note: Custom scripts may be used to import a given set of articles without going through the whole process of importing an entire set. This step is described for testing and experimental purposes only.

#### VII) Import articles through parallel implementation: 

The main scripts that handle the whole import process:

1. fetch_medline.php and medline.php
This script will initiate 11 processes to fetch publications for each year 2005 thru 2015. The script will then randomly select 200 of these PMIDs and will fetch details for each article from PubMed.
The returned XML is then parsed to populate the table violin_pmid.
2. fetch_scopus.php and scopus.php
These scripts will initiate 11 processes for year 2005 thru 2015 to access Scopus API to retrieve the citation count for each article in violin_pmid and will update the citation_count field.

**Running these scripts on command line:**

**First run the medline fetch script:**
```php -f medline_fetch_parallel.php```

**Once Medline fetch is complete, then run the Scopus fetch script:**  
```php -f scopus_fetch_parallel.php```

Note. Parallel implementation significantly reduces the overall time required for the import process, and is only an alternative to step V.

#### VIII) Calculating rank, median rank, and percentile rank for baseline articles:

Running the script **baseline_rank.php** will access the violin_pmid table and then calculate the rank, median rank, and percentile rank for the set of 200 articles corresponding to a given year, category id, and article type:  
```php -f baseline_rank.php```

#### IX) Calculating percentile rank of institutional articles:
Before running this script, excluding the percentile_rank field in the article table, the tables article, author, and author_article need to be properly populated with appropriate data.

The specific source of these data may vary between institutions. At Weill Cornell Medicine, these data come from our VIVO instance through a separate import process.

Running the script calculate_percentile_rank.php will calculate the percentile rank of the given articles by comparing against the percentile rank of baseline articles.
This script will then update the percentile_rank field the article table.
php -f calculate_percentile_rank.php

#### X) Visualizing citation impact of institutional articles:
The folder citation contains all the code necessary for visualizing the citation impact plot for a given set of articles.
Two sample scripts are provided: **plot_csv.php** and **plot_db.csv**.
The script **plot_csv.php** gets publication data from a local CSV file and shows the corresponding visualization chart.
The script **plot_db.php** gets publication data from a database and shows the corresponding visualization chart. For this script to work three tables (article, author, and author_article) should contain appropriate article data with percentile rank calculated through step IX.
