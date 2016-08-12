<?php
/************************************************************************************************
 * // Name:    scopus.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Fetch citation count from scopus to be used in scopus_fetch_parallel.php
 ************************************************************************************************/
include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);

$year = '';
if (count($argv) == 2) {
    if (isset($argv[1])) {
        $year = (int)$argv[1];
        if (empty($year) || !is_numeric($year)) {
            exit;
        }
    }
} else {
    exit;
}

// include scopus api
require_file('ScopusAPI.php');
$objAPI = new ScopusAPI();

$limit = 1;
$start = 0;

if (empty($last_offset)) {
    $last_offset = 0;
}

$total_records = $objData->get_pmid_count();

$pmids = $objData->get_all_pmids_by_year($year);

if (count($pmids) > 0) {
    $count = 0;

    $chunks = array_chunk($pmids, 100, true);

    foreach ($chunks as $chunk) {

        $term = '';
        $count = count($chunk);
        if ($count > 0) {
            $term .= "pmid(";
            foreach ($chunk as $key => $val) {
                $count--;
                $term .= $val;
                if ($count) {
                    $term .= ' OR ';
                }
            }
            $term .= ")";
        }

        if (!empty($term)) {

            // Get Scopus XML
            $scopus_search_xml = $objAPI->query($term);

            $scopus_search_data = $objAPI->parse($scopus_search_xml);

            if (!empty($scopus_search_data)) {
                foreach ($chunk as $key => $val) {
                    if (array_key_exists($val, $scopus_search_data)) {
                        // populate local database with the result
                        $cite_data = $scopus_search_data[$val];
                        $up_data['pmid_id'] = (int)$key;
                        $up_data['citation_count'] = $cite_data['citedby-count'];
                        $objData->update_citation_count($up_data);
                    } else {
                        $up_data['pmid_id'] = (int)$key;
                        $up_data['scopus_article_exist'] = 'No';
                        $objData->update_empty_result($up_data);
                    }

                }
            }

        }

        $count++;

    }

}

?>

