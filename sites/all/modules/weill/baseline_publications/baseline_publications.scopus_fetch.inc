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
    if(count($pmids) >0 ) {
        $count = 0;

        $chunks = array_chunk($pmids, 25, true);


        //  if (count($pmids) > 0) {

        //   foreach ($pmids as $key => $val) {

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
                            update_citation_count($up_data);
                            echo 'Updated pmid : ' . $up_data['pmid_id'] . ' with citation count of : ' . $up_data['citation_count'] . "<br>";
                        } else {
                            $up_data['pmid_id'] = (int)$key;
                            $up_data['scopus_article_exist'] = 'No';
                            update_empty_result($up_data);
                        }

                    }
                }

            }
            $count++;

        }
    }



        //}

        //}

        $curr_parms = array(
            'year' => (int)date('Y') - 3,
            'type' => 'Academic Article',
            'category' => 200,
            'flag' => 'stop'
        );

        // update cron history
        set_curr_update('scopus', $curr_parms);


    return;
}

