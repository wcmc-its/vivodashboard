<?php
/************************************************************************************************
 * // Name:    medline_fetch.php
 * // Author:    Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Fetch publications from medline using delayed query.
 ************************************************************************************************/

include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);

$limit = 20;

$pub_years = array(
    '2003',
);

$pub_types = array(
    'Academic Article',
    'Review'
);

$categories = $objData->get_all_categories();

// include pubmed api
require_file('MedlineAPI.php');
$objAPI = new MedlineAPI();
$count = 1;
foreach ($pub_years as $year) {
    $term = "";
    foreach ($pub_types as $type) {
        if (count($categories) > 0) {
            foreach ($categories as $key => $val) {

                $start = microtime();

                // construct queries
                $ids = array();
                $ids = $objData->get_category_journal_ids($key);

                if(!empty($ids)){
                    $term = $objData->construct_query($year, $type, $ids);
                }

                // $term = $objData->construct_query(2008, "Review", $ids);

                // Get Medline XML with PMID list for this search term
                $pmids = array();
                $pmids = $objAPI->query($term);

                $result_count = count($pmids);

                // Get return count
                $random_count = ($result_count >= $limit)? $limit : $result_count;

                // get xml for all articles with  a random 200 pmids from this list
                $pubmed_efetch_results = array();
                $pubmed_efetch_results = $objAPI->pubmed_random_efetch($pmids, $random_count);

                // populate local database with the result
                // $objData->populate_data( $year, $type, $key, $pubmed_efetch_results );
                $objData->populate_multi_data( $year, $type, $key, $pubmed_efetch_results );

                echo "Processed, Year:".$year. ", Type:". $type. ", Category:". $key . "\n";

                $end = microtime();

                if(($end - $start) < 333000 ) {
                    usleep(333000);
                }
            }
        }
    }

    $count++;


}

?>

