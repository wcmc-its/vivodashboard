<?php
/************************************************************************************************
 * // Name:    scopus_fetch.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Fetch citation count from scopus
 ************************************************************************************************/
include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);

// include scopus api
require_file('ScopusAPI.php');
$objAPI = new ScopusAPI();

$limit = 1;
$start = 0;

if (empty($last_offset)) {
    $last_offset = 0;
}

$total_records = $objData->get_pmid_count();

$pmids = $objData->get_all_pmids();

$count = 0;

if (count($pmids) > 0) {

    foreach ($pmids as $key => $val) {

        if (!empty($key) && !empty($val)) {
            $term = "pmid(" . $val . ")";

            // Get Scopus XML
            $scopus_search_xml = $objAPI->query($term);

            // check if result empty in Scopus
            $is_result_empty = $objAPI->parse_empty_result($scopus_search_xml);

            if ($is_result_empty) {
                $up_data['pmid_id'] = (int)$key;
                $up_data['scopus_article_exist'] = 'No';
                $objData->update_empty_result($up_data);
            } else {
                $citation_count = $objAPI->parse_citation_count($scopus_search_xml);
                // populate local database with the result
                $up_data['pmid_id'] = (int)$key;
                $up_data['citation_count'] = $citation_count;
                $objData->update_citation_count($up_data);
                echo "Updated, pmid:" . $key . "count:" . $citation_count . "\n";
            }

        }

        echo "Counter:" . $count . "\n";

        $count++;
    }

}

?>

