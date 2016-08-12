<?php
/***********************************************************************************************
 * // Name:    load_journal_category.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description: Populate violin_journal, violin_category and violin_journal_category tables
 * // from excel data
 ************************************************************************************************/

include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);

// truncate tables
$objData->truncate_table('violin_journal');
$objData->truncate_table('violin_category');
$objData->truncate_table('violin_journal_category');

$record = array();
$record = $objData->get_all_excel_data();

foreach ($record as $obj) {
    global $conn;
    $data = array();
    $data['title'] = $obj->title;
    $data['issn'] = $obj->issn;
    $data['impact_factor'] = $obj->col4;
    $data['category'] = $obj->category;

    $jid = $objData->populate_journal($data);

    $cid = $objData->populate_category($data);

    if(!empty($jid) && !empty($cid)){
        $objData->populate_journal_category($jid, $cid);
    }
 }

echo "Program completed \n";

exit;

?>