<?php
ini_set('max_execution_time', 0);
set_time_limit(12000);

function baseline_publications_populate_journal_category()
{

    include_once(__DIR__ . "/library/portable_utf8.php");
    require_once(__DIR__ . "/library/data.php");

    truncate_table('violin_journal');
    truncate_table('violin_category');
    truncate_table('violin_journal_category');

    // $query = "select * from violin_excel where category = 'WOMEN\'S STUDIES'";
    $query = "select * from violin_excel";
    $result = db_query($query)->fetchAll();

    foreach ($result as $row) {
        $record[] = $row;
    }

    foreach ($record as $obj) {
        $data = array();
        $data['title'] = $obj->title;
        $data['issn'] = $obj->issn;
        $data['impact_factor'] = $obj->col4;
        $data['category'] = $obj->category;

        $jid = populate_journal($data);

        $cid = populate_category($data);

        if (!empty($jid) && !empty($cid)) {
            populate_journal_category($jid, $cid);
        }

    }

    echo "Program completed \n";

    return;
}


?>