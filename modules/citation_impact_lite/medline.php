<?php
/************************************************************************************************
 * // Name:    medline.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Fetch pmid's from medline to be used in medline_fetch_parallel.php
 ************************************************************************************************/

include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);
$year = '';
if (count($argv) == 2 ) {
    if (isset($argv[1])) {
        $year = (int)$argv[1];
        if( empty($year) || !is_numeric($year)){
            exit;
        }
    }
}else {
    exit;
}
$limit = 20;

$pub_types = array(
    'Academic Article',
    'Review'
);

$categories = $objData->get_all_categories();

// $custom_cat_ids = array(7, 19, 49, 134, 127, 206); // Microbiology and Medical Informatics
// $categories = $objData->get_custom_categories($custom_cat_ids);

// include pubmed api
require_file('MedlineAPI.php');
$objAPI = new MedlineAPI();
$count = 1;

$term = "";
foreach ($pub_types as $type) {
    if (count($categories) > 0) {
        foreach ($categories as $key => $val) {
            // construct queries
            $ids = array();
            $ids = $objData->get_category_journal_ids($key);

            if (!empty($ids)) {
                $term = $objData->construct_query($year, $type, $ids);
            }

            // $term = $objData->construct_query(2008, "Review", $ids);

            // Get Medline XML with PMID list for this search term
            $pmids = array();
            $pmids = $objAPI->query($term);

            $result_count = count($pmids);

            // Get return count
            $random_count = ($result_count >= $limit) ? $limit : $result_count;

            // get xml for all articles with  a random 200 pmids from this list
            $pubmed_efetch_results = array();
            $pubmed_efetch_results = $objAPI->pubmed_random_efetch($pmids, $random_count);

            // populate local database with the result
            // $objData->populate_data( $year, $type, $key, $pubmed_efetch_results );
            $objData->populate_multi_data($year, $type, $key, $pubmed_efetch_results);

            echo "Processed, Year:" . $year . ", Type:" . $type . ", Category:" . $key . "\n";

        }
    }
}

$count++;


?>

