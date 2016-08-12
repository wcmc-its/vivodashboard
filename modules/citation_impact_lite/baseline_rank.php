<?php
/************************************************************************************************
 * // Name:    baseline_rank.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Rank baseline publications
 ************************************************************************************************/
include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);
$year = '';

$pub_years = array(
    '2003',
    '2004',
    '2005',
    '2006',
    '2007',
    '2008',
    '2009',
    '2010',
    '2011',
    '2012',
    '2013',
    '2014'
);

$pub_types = array(
    'Academic Article',
    'Review'
);

$categories = $objData->get_all_categories();

// $custom_cat_ids = array(134, 127); // Microbiology and Medical Informatics
// $categories = $objData->get_custom_categories($custom_cat_ids);


foreach ($pub_years as $year) {

    foreach ($pub_types as $type) {
        if (count($categories) > 0) {
            foreach ($categories as $key => $val) {
                // get all pubs
                $raw_ref_pubs =  $objData->get_baseline_pubs($year, $key, $type);

                if(count($raw_ref_pubs) > 0){

                    asort($raw_ref_pubs);

                    $rank_ref_pubs = $objData->rank_pubs($raw_ref_pubs);

                    // populate baseline table with the result
                    $objData->populate_baseline_data($year, $type, $key, $rank_ref_pubs);

                    echo "Processed, Year:" . $year . ", Type:" . $type . ", Category:" . $key . "\n";
                }
            }
        }
    }

}

$count++;


?>

