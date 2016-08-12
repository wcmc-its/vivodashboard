<?php
include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);
$year = '';
if (count($argv) == 4 ) {
    if (isset($argv[1])) {
        $year = (int)$argv[1];
        if( empty($year) || !is_numeric($year)){
            exit;
        }
    }
    if (isset($argv[2])) {
        $pub_cat = (int)$argv[2];
        if( empty($pub_cat) || !is_numeric($pub_cat)){
            exit;
        }
    }
    if (isset($argv[3])) {
        $pub_type = $argv[3];
        if ( !(($pub_type == 'R') || ($pub_type == 'A')) ){
            exit;
        }
    }
}else {
    exit;
}
$limit = 20;

$pub_types = array();

switch($pub_type){
    case 'R': $pub_types[] = 'Review';
        break;
    case 'A': $pub_types[] = 'Academic Article';
        break;
}


// Get custom category
$custom_cat_ids = array($pub_cat);
$categories = $objData->get_custom_categories($custom_cat_ids);

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
            $random_count = ($result_count >= 200) ? 200 : $result_count;

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

