<?php
/************************************************************************************************
 * // Name:    calculate_percentile_rank.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Calculate percentile rank for institutional articles
 ************************************************************************************************/

include_once(__DIR__ . "/library/main.php");
include_once(__DIR__ . "/library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);

//get all publications from citation_article
$articles = $objData->get_all_articles();

if (count($articles) > 0) {

    foreach ($articles as $item) {

        // calculate percentile rank
        $percentile_rank = $objData->calculate_percentile_rank($item);

        //update percentile rank
        $objData->update_article_percentile_rank($item->article_id, $percentile_rank);
    }
}

echo "Program completed\n\n";