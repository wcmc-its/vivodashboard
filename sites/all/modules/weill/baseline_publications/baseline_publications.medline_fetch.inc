<?php
ini_set('max_execution_time', 0);
set_time_limit(12000);
function baseline_publications_medline_fetch()
{
    include_once(__DIR__ . "/library/portable_utf8.php");
    require_once(__DIR__ . "/library/data.php");

    // check scopus cron status. if status = run, then do not run
    $scopus_status = get_update_status('scopus');
    if ($scopus_status == 'run') {
        return;
    }

    // check medline cron status. if status = stop, then do not run
    $medline_status = get_update_status('medline');
    if($medline_status == 'stop'){
        return;
    }

    $limit = 200;

    $pub_types = get_all_types();

    $categories = get_all_categories();
    $years = get_all_years();

    // get next run parameters
    //$parms = get_next_update_parms('medline');

    /*$year = $parms['year'];
    $type_id = $parms['type'];
    $type = $pub_types[$type_id];
    $cat_id = $parms['category'];
    $flag = $parms['flag'];*/

    //if (!empty($year) && !empty($type) && !empty($cat_id)) {

    require_once(__DIR__ . "/library/MedlineAPI.php");
    $objAPI = new MedlineAPI();
    $count = 1;
    foreach($years as $yearKey => $yearVal) {
    $term = "";
    foreach ($pub_types as $type) {
        $start = microtime();
        if (count($categories) > 0) {
            foreach ($categories as $key => $val) {
                // construct queries
                $ids = array();
                $ids = get_category_journal_ids($key);

                if (!empty($ids)) {
                    $term = construct_query($yearVal, $type, $ids);
                }

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
                // populate_data( $year, $type, $key, $pubmed_efetch_results );
                populate_multi_data($yearVal, $type, $key, $pubmed_efetch_results);

                echo "Processed, Year:" . $yearVal . ", Type:" . $type . ", Category:" . $key . "\n";

                // update update history
                //Set update_history to stop when reaches the end year
                if($yearVal == (int)(date('Y') - 3)) {
                    $curr_parms = array(
                        'year' => $yearVal,
                        'type' => $type,
                        'category' => $key,
                        'flag' => 'stop'
                    );
                }
                else {
                    $curr_parms = array(
                        'year' => $yearVal,
                        'type' => $type,
                        'category' => $key,
                        'flag' => 'run'
                    );
                }
                set_curr_update('medline', $curr_parms);

                $end = microtime();

                if (($end - $start) < 333000) {
                    usleep(333000);
                }
            }
        }
    }
}

    //}

    return;
}