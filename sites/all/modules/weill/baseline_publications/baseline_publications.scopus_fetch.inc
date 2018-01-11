<?php
ini_set('max_execution_time', 0);
set_time_limit(12000);
function baseline_publications_scopus_fetch()
{
    include_once(__DIR__ . "/library/portable_utf8.php");
    require_once(__DIR__ . "/library/data.php");

    // check medline cron staus. If it's running then do not run
    $medline_status = get_update_status('medline');
    if ($medline_status == 'run') {
        return;
    }

    // check scopus cron status. if status = stop, then do not run
    $scopus_status = get_update_status('scopus');
    if ($scopus_status == 'stop') {
        return;
    }

    // include scopus api
    require_once(__DIR__ . "/library/ScopusAPI.php");
    $objAPI = new ScopusAPI();

    $pub_types = get_all_types();

    $categories = get_all_categories();
    $years = get_all_years();

    $limit = 1;
    $start = 0;

    if (empty($last_offset)) {
        $last_offset = 0;
    }

    $total_records = get_pmid_count();




    /* // get previous run parameters
     $parms = get_next_update_parms('scopus');

     $year = $parms['year'];
     $type_id = $parms['type'];
     $type = $pub_types[$type_id];
     $category = $parms['category'];
     $flag = $parms['flag'];*/

    $pmids = get_all_pmids();

    $count = 0;

        if (count($pmids) > 0) {

            foreach ($pmids as $key => $val) {

                if (!empty($key) && !empty($val)) {
                    $term = "pmid(" . $val . ")"; //Commented out as using FULL View of Scopus API

                    //$term = $val;

                    // Get Scopus XML
                    $scopus_search_xml = $objAPI->query($term);

                    // check if result empty in Scopus
                    $is_result_empty = $objAPI->parse_empty_result($scopus_search_xml);

                    if ($is_result_empty) {
                        $up_data['pmid_id'] = (int)$key;
                        $up_data['scopus_article_exist'] = 'No';
                        update_empty_result($up_data);
                    } else {
                        $citation_count = $objAPI->parse_citation_count($scopus_search_xml);
                        // populate local database with the result
                        $up_data['pmid_id'] = (int)$key;
                        $up_data['citation_count'] = $citation_count;
                        update_citation_count($up_data);
                         echo "Updated, pmid:".$key. " with citation count:".$citation_count ."\n" ;
                    }

                }

                // echo "Counter:". $count. "\n";
                $count++;
            }

        }

        /*$curr_parms = array(
            'year' => $year,
            'type' => $type_id,
            'category' => $category,
            'flag' => $flag
        );

        // update cron history
        set_curr_update('scopus', $curr_parms);*/


    return;
}

