<?php
ini_set('max_execution_time', 0);
set_time_limit(12000);
function baseline_publications_percentile_rank()
{
    include_once(__DIR__ . "/library/portable_utf8.php");
    require_once(__DIR__ . "/library/data.php");

    // check medline cron staus. If it's running then do not run
    $medline_status = get_update_status('medline');
    $scopus_status = get_update_status('scopus');
    if ($medline_status == 'stop' && $scopus_status == 'stop') {

        truncate_table('violin_baseline');

        $pub_years = array_keys(get_all_years());
        $pub_types = array_values(get_all_types());
        $categories = get_all_categories();

        //    $custom_cat_ids = array(1); // Microbiology and Medical Informatics
        //    $categories = get_custom_categories($custom_cat_ids);

        foreach ($pub_years as $year) {
            foreach ($pub_types as $type) {
                if (count($categories) > 0) {
                    foreach ($categories as $key => $val) {
                        // get all pubs
                        $raw_ref_pubs = get_baseline_pubs($year, $key, $type);

                        if (count($raw_ref_pubs) > 0) {

                            asort($raw_ref_pubs);

                            $rank_ref_pubs = rank_pubs($raw_ref_pubs);

                            // populate baseline table with the result
                            populate_baseline_data($year, $type, $key, $rank_ref_pubs);

                            // echo "Processed, Year:" . $year . ", Type:" . $type . ", Category:" . $key . "\n";
                        }
                    }
                }
            }

        }

        echo "Program completed. \n";
    } else {
        echo "Scopus or medline is in run status. Program exited without performing ranking \n";
    }

}

?>

