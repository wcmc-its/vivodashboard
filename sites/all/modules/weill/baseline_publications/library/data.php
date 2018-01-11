<?php

function truncate_table($name)
{
    //truncate table
    $transaction = db_transaction();
    try {
        $query = "truncate table $name";
        db_query($query);
    } catch (Exception $e) {
        $transaction->rollback();
        var_dump($e->getMessage());
    }
}

function populate_journal($data)
{
    if (!empty($data)) {
        $issn = addslashes($data['issn']);
        $journal_id = get_journal_id($issn);
        if (!empty($journal_id)) {
            return $journal_id;
        } else {
            $title = addslashes($data['title']);
            $impact_factor = (double)$data['impact_factor'];

            $transaction = db_transaction();
            try {
                $insert_id = db_insert('violin_journal')
                    ->fields(array(
                        'journal_title' => $title,
                        'issn' => $issn,
                        'impact_factor' => $impact_factor
                    ))
                    ->execute();

            } catch (Exception $e) {
                $transaction->rollback();
                var_dump($e->getMessage());
            }

            return $insert_id;
        }
    }
}

function populate_category($data)
{
    if (!empty($data)) {
        $category = addslashes(ucwords(strtolower($data['category'])));
        $cat_id = get_category_id($category);
        if (!empty($cat_id)) {
            return $cat_id;
        } else {
            $transaction = db_transaction();
            try {
                $cat_id = db_insert('violin_category')
                    ->fields(array(
                        'category' => $category
                    ))
                    ->execute();
                return $cat_id;
            } catch (Exception $e) {
                $transaction->rollback();
                var_dump($e->getMessage());
            }
        }
    }
}

function populate_journal_category($jid, $cid)
{
    global $conn;
    $jid = (int)$jid;
    $cid = (int)$cid;
    if (!journal_category_exist($jid, $cid)) {
        $transaction = db_transaction();
        try {
            $cat_id = db_insert('violin_journal_category')
                ->fields(array(
                    'journal_id' => $jid,
                    'category_id' => $cid
                ))
                ->execute();

        } catch (Exception $e) {
            $transaction->rollback();
            var_dump($e->getMessage());
        }

    }
}

function journal_exist($issn)
{
    $issn = addslashes($issn);
    if (!empty($issn)) {
        $total = 0;
        $sql = "SELECT count(*) as total from violin_journal where issn = '" . $issn . "'";
        $result = db_query($sql)->fetchObject();
        if (!empty($result->total)) {
            $total = $result->total;
        }
        return ($total != 0) ? true : false;
    }
}

function category_exist($category)
{
    $category = addslashes(ucwords(strtolower($category)));
    if (!empty($category)) {
        $total = 0;
        $sql = "SELECT count(*) as total from violin_category where category = '" . $category . "'";
        $result = db_query($sql)->fetchObject();
        if (!empty($result->total)) {
            $total = $result->total;
        }
        return ($total != 0) ? true : false;
    }
}

function journal_category_exist($journal_id, $cat_id)
{
    $journal_id = (int)$journal_id;
    $cat_id = (int)$cat_id;
    if (!empty($journal_id) && !empty($cat_id)) {
        $total = 0;
        $sql = "SELECT count(*) as total from violin_journal_category where journal_id = " . $journal_id . " and category_id = " . $cat_id;
        $result = db_query($sql)->fetchObject();
        if (!empty($result->total)) {
            $total = $result->total;
        }
        return ($total != 0) ? true : false;
    }
}

function get_journal_id($issn)
{
    if (!empty($issn)) {
        $journal_id = 0;
        $sql = " SELECT journal_id from violin_journal where issn = '" . $issn . "'";
        $result = db_query($sql)->fetchObject();
        if (!empty($result->journal_id)) {
            $journal_id = $result->journal_id;
        }
        return $journal_id;
    }
}

function get_category_id($category)
{
    $category = addslashes($category);
    if (!empty($category)) {
        $cat_id = 0;
        $sql = " SELECT category_id from violin_category where category = '" . $category . "'";
        $result = db_query($sql)->fetchObject();
        if (!empty($result->category_id)) {
            $cat_id = $result->category_id;
        }
        return $cat_id;
    }
}

function get_query_count($countQuery)
{
    $total = 0;
    $sql = "select count(*) as total from violin_pmid";
    $result = db_query($sql)->fetchObject();
    if (!empty($result->total)) {
        $total = $result->total;
    }
    return $total;
}

function get_all_years()
{
    $start_year = (int)date('Y') - 13;
    for($i =0; $i<10; $i++)  {
        $start_year++;
         $years[$start_year] = $start_year;
    }
    /*$years = array(
        '2003' => '2003',
        '2004' => '2004',
        '2005' => '2005',
        '2006' => '2006',
        '2007' => '2007',
        '2008' => '2008',
        '2009' => '2009',
        '2010' => '2010',
        '2011' => '2011',
        '2012' => '2012',
        '2013' => '2013',
        '2014' => '2014',
        '2015' => '2015'

    );*/
    return $years;
}

function get_all_types()
{
    $types = array(
        '1' => 'Academic Article',
        '2' => 'Review'
    );
    return $types;
}

function get_all_categories()
{
    $categories = array();
    $sql = "select violin_category.category_id, violin_category.category from violin_category ";
    $result = db_query($sql)->fetchAll();
    foreach ($result as $row) {
        $categories[$row->category_id] = $row->category;
    }
    return $categories;
}

function get_custom_categories($ids)
{
    $str_ids = "(" . implode(',', $ids) . ")";
    $categories = array();
    $sql = "select violin_category.category_id, violin_category.category from violin_category where category_id in $str_ids ";
    $result = db_query($sql)->fetchAll();
    foreach ($result as $row) {
        $categories[$row->category_id] = $row->category;
    }
    return $categories;
}

function get_pmid_count()
{
    $total = 0;
    $sql = "select count(*) as total from violin_pmid";
    $result = db_query($sql)->fetchObject();
    if (!empty($result->total)) {
        $total = $result->total;
    }
    return $total;
}

function get_all_pmids()
{
    $pmids = array();
    $sql = "select pmid_id, pmid from violin_pmid where citation_count = 0";
    $result = db_query($sql)->fetchAll();
    foreach ($result as $row) {
        $pmids[$row->pmid_id] = $row->pmid;
    }
    return $pmids;
}

function get_pmids_by_offset($limit, $offset = 0)
{
    $pmids = array();
    $limit = (int)$limit;
    $offset = (int)$offset;
    if (!empty($limit)) {
        $sql = "select pmid_id, pmid from violin_pmid limit $limit offset $offset";

        // var_dump($sql);
        $result = db_query($sql)->fetchAll();
        foreach ($result as $row) {
            $pmids[$row->pmid_id] = $row->pmid;
        }
    }
    return $pmids;
}

function get_update_pmids($year, $type, $category)
{
    $pmids = array();
    $year = (int)$year;
    $type = addslashes($type);
    $category = (int)$category;
    if (!empty($year) && !empty($type) && !empty($category)) {

        $sql = "select pmid_id, pmid from violin_pmid where publication_year = " . $year . " and article_type = '" . $type . "' and  category_id = " . $category;

        $result = db_query($sql)->fetchAll();
        foreach ($result as $row) {
            $pmids[$row->pmid_id] = $row->pmid;
        }
    }
    return $pmids;
}

function get_last_update($item)
{
    $last_update_id = "";
    $sql = "select pmid_id from violin_update_history where item = '$item' limit 1";
    $result = db_query($sql)->fetchObject();
    if (!empty($result->pmid_id)) {
        $last_update_id = $result->pmid_id;
    }
    return $last_update_id;
}

function get_update_status($item)
{
    $item = addslashes($item);
    $update_status = "";
    $sql = "select flag from violin_update_history where item = '$item'";
    $result = db_query($sql)->fetchObject();
    if (!empty($result->flag)) {
        $update_status = $result->flag;
    }
    return $update_status;
}

function get_next_update_parms($item)
{
    $parms = array();

    $item = addslashes($item);

    $years = array_keys(get_all_years());
    $begin_year = reset($years);
    $end_year = end($years);

    $types = array_keys(get_all_types());
    $begin_type = reset($types);
    $end_type = end($types);

    $categories = array_keys(get_all_categories());
    $begin_category = reset($categories);
    $end_category = end($categories);

    $last_year = '';
    $last_type = '';
    $last_category = '';

    $next_year = '';
    $next_type = '';
    $next_category = '';

    $query = "select * from violin_update_history where item = '" . $item . "' ";
    $result = db_query($query)->fetchObject();

    if (!empty($result->id)) {

        $last_year = $result->year;
        $last_type = $result->type;
        $last_category = $result->category;

        if ($last_category == $end_category) {
            $next_category = $begin_category;
            if ($last_type == $end_type) {
                $next_type = $begin_type;
                if ($last_year == $end_year) {
                    $next_year = $begin_year;
                } else {
                    $next_year = $last_year + 1;
                }
            } else {
                $next_type = $last_type + 1;
                $next_year = $last_year;
            }
        } else {
            $next_category = $last_category + 1;
            $next_type = $last_type;
            $next_year = $last_year;
        }

    } else {
        $next_year = $begin_year;
        $next_type = $begin_type;
        $next_category = $begin_category;
    }

    if($next_year == $end_year && $next_type == $end_type && $next_category == $end_category) {
        $flag = "stop";
    }else {
        $flag = "run";
    }

    $parms['year'] = $next_year;
    $parms['type'] = $next_type;
    $parms['category'] = $next_category;
    $parms['flag'] = $flag;

    return $parms;
}

function set_curr_update($item, $parms)
{
    $item = addslashes($item);
    $year = (int)$parms['year'];
    $type = $parms['type'];
    $category = (int)$parms['category'];
    $flag = addslashes($parms['flag']);

    $chk_id = '';
    $chk_query = "select id from violin_update_history where item = '" . $item . "' ";
    $chk_result = db_query($chk_query)->fetchObject();
    if (!empty($chk_result->id)) {
        $chk_id = $chk_result->id;
    }
    $transaction = db_transaction();
    try {
        if (empty($chk_id)) {
            $insert_id = db_insert('violin_update_history')
                ->fields(array(
                    'item' => $item,
                    'year' => $year,
                    'type' => $type,
                    'category' => $category,
                    'flag' => 'run',
                    'update_date' => date("Y-m-d H:i:s", time()),
                ))
                ->execute();
        } else {

            $update_id = db_update('violin_update_history')
                ->fields(array(
                    'year' => $year,
                    'type' => $type,
                    'category' => $category,
                    'flag' => $flag,
                    'update_date' => date("Y-m-d H:i:s", time()),
                ))
                ->condition('item', $item, '=')
                ->execute();
        }
    } catch (Exception $e) {
        $transaction->rollback();
        var_dump($e->getMessage());
    }
}

function get_all_pmids_by_year($year)
{
    $year = (int)$year;
    $pmids = array();
    $sql = "select pmid_id, pmid from violin_pmid where publication_year = " . $year;
    $result = db_query($sql)->fetchAll();
    foreach ($result as $row) {
        $pmids[$row->pmid_id] = $row->pmid;
    }
    return $pmids;
}

function get_pmids($limit = 100, $offset = 0)
{
    $pmids = array();
    $sql = "select pmid_id, pmid from violin_pmid where citation_count = 0 limit $offset, $limit  ";
    $result = db_query($sql)->fetchAll();
    foreach ($result as $row) {
        $pmids[$row->pmid_id] = $row->pmid;
    }
    return $pmids;
}

function get_category_journal_ids($cat_id)
{
    $records = array();
    $sql = "
          select distinct violin_journal.issn
          from violin_journal
          left join violin_journal_category on violin_journal.journal_id = violin_journal_category.journal_id
          where violin_journal_category.category_id =  " . $cat_id;

    // echo $sql;

    $result = db_query($sql)->fetchAll();
    foreach ($result as $row) {
        $records[] = $row->issn;
    }
    return $records;
}

function construct_query($year, $type, $ids)
{

    $search_term = "";
    $str_review_annex = "";
    // $search_term .= "English[LA] AND ";

    if (!empty($year)) {
        $search_term .= $year . "[DP] AND ";
    }

    if (!empty($type)) {
        $str_type = "";
        switch ($type) {
            case 'Academic Article':
                $str_type .= "(Clinical Trial, Phase I[PT] OR Clinical Trial, Phase II[PT] OR Clinical Trial, Phase III[PT] OR Clinical Trial, Phase IV[PT] OR Randomized Controlled Trial[PT] OR Multicenter Study[PT] OR Twin Study[PT] OR Case Reports[PT] OR Comparative Study[PT] OR Technical Report[PT])";
                break;
            case 'Review':
                $str_type .= "(Review[PT] OR Meta-Analysis[PT])";
                $str_review_annex = " NOT Clinical Trial, Phase I[PT] NOT Clinical Trial, Phase II[PT] NOT Clinical Trial, Phase III[PT] NOT Clinical Trial, Phase IV[PT] NOT Randomized Controlled Trial[PT] NOT Multicenter Study[PT] NOT Twin Study[PT] NOT Case Reports[PT] NOT Comparative Study[PT] NOT Technical Report[PT] ";
                break;
        }
        $search_term .= $str_type . " AND ";
    }

    if (count($ids) > 0) {
        $mod_ids = array();
        foreach ($ids as $k) {
            $mod_val = $k . "[TA]";
            $mod_ids[] = $mod_val;
        }
        $search_term .= "(";
        $search_term .= implode(" OR ", $mod_ids);
        $search_term .= ")";
    }

    if (!empty($str_review_annex)) {
        $search_term .= $str_review_annex;
    }

    // echo $search_term . "\n";

    return $search_term;
}

function construct_scopus_term($ids)
{
    $search_term = "";
    if (count($ids) > 0) {
        $search_term .= "pmid(";
        $search_term .= implode(", ", $ids);
        $search_term .= ")";
    }
    return $search_term;
}

function populate_data($year, $type, $category_id, $data)
{
    foreach ($data as $key => $val) {
        if (!empty($key)) {
            $fetch_data = $val[0];
            $insert_record = array();
            $insert_record['pmid'] = $key;
            $insert_record['issn'] = $fetch_data['issn'];
            $insert_record['category_id'] = $category_id;
            $insert_record['publication_year'] = $year;
            $insert_record['article_type'] = $type;
            $insert_record['pubmed_article_type'] = $fetch_data['articletype'];
            $insert_record['title'] = $fetch_data['title'];
            insert_data($insert_record);
        }
    }
}

function populate_multi_data($year, $type, $category_id, $data)
{
    foreach ($data as $val) {
        if (!empty($val)) {
            $fetch_data = $val;
            $insert_record = array();
            $insert_record['pmid'] = $fetch_data['pmid'];
            $insert_record['issn'] = $fetch_data['issn'];
            $insert_record['category_id'] = $category_id;
            $insert_record['publication_year'] = $year;
            $insert_record['article_type'] = $type;
            $insert_record['pubmed_article_type'] = $fetch_data['articletype'];
            $insert_record['title'] = $fetch_data['title'];
            insert_data($insert_record);
        }
    }
}

function insert_data($data)
{
    $curr_pmid = (int)$data['pmid'];
    $curr_issn = addslashes($data['issn']);
    $curr_category_id = (int)$data['category_id'];
    $curr_year = (int)$data['publication_year'];
    $curr_article_type = addslashes($data['article_type']);
    $curr_pubmed_article_type = addslashes($data['pubmed_article_type']);
    $curr_title = addslashes($data['title']);

    $chk_pmid = '';
    $chk_query = "select pmid from violin_pmid where pmid = $curr_pmid ";
    $chk_result = db_query($chk_query)->fetchObject();
    if (!empty($chk_result->pmid)) {
        $chk_pmid = $chk_result->pmid;
    }
    $transaction = db_transaction();
    try {
        if (empty($chk_pmid)) {
            $insert_id = db_insert('violin_pmid')
                ->fields(array(
                    'pmid' => $curr_pmid,
                    'issn' => $curr_issn,
                    'category_id' => $curr_category_id,
                    'publication_year' => $curr_year,
                    'article_type' => $curr_article_type,
                    'pubmed_article_type' => $curr_pubmed_article_type,
                    'title' => $curr_title
                ))
                ->execute();
        }
    } catch (Exception $e) {
        $transaction->rollback();
        var_dump($e->getMessage());
    }
}

function update_citation_count($data)
{
    if (!empty($data['pmid_id'])) {
        update_citation_count_data($data);
    }
}

function update_citation_count_data($data)
{
    $pmid_id = (int)$data['pmid_id'];
    $citation_count = (int)$data['citation_count'];
    $chk_id = '';
    $chk_query = "select pmid_id from violin_pmid where pmid_id = $pmid_id ";

    $chk_result = db_query($chk_query)->fetchObject();
    if (!empty($chk_result->pmid_id)) {
        $chk_id = $chk_result->pmid_id;
    }

    $transaction = db_transaction();
    try {
        if (!empty($chk_id)) {
            $num_updated = db_update('violin_pmid')
                ->fields(array(
                    'citation_count' => $citation_count,
                    'date_of_citation_count' => date("Y-m-d H:i:s", time()),
                    'scopus_article_exist' => NULL,
                ))
                ->condition('pmid_id', $pmid_id, '=')
                ->execute();
        }

    } catch (Exception $e) {
        $transaction->rollback();
        var_dump($e->getMessage());
    }

}

function update_empty_result($data)
{
    if (!empty($data['pmid_id']) && !empty($data['scopus_article_exist'])) {
        update_article_exist_data($data);
    }
}

function update_article_exist_data($data)
{
    $pmid_id = (int)$data['pmid_id'];
    $scopus_article_exist = addslashes($data['scopus_article_exist']);

    $chk_id = '';
    $chk_query = "select pmid_id from violin_pmid where pmid_id = $pmid_id ";

    $chk_result = db_query($chk_query)->fetchObject();
    if (!empty($chk_result->pmid_id)) {
        $chk_id = $chk_result->pmid_id;
    }
    $transaction = db_transaction();
    try {
        if (!empty($chk_id)) {
            $num_updated = db_update('violin_pmid')
                ->fields(array(
                    'scopus_article_exist' => $scopus_article_exist,
                    'date_of_citation_count' => date("Y-m-d H:i:s", time())
                ))
                ->condition('pmid_id', $pmid_id, '=')
                ->execute();
        }

    } catch (Exception $e) {
        $transaction->rollback();
        var_dump($e->getMessage());
    }
}

function get_baseline_pubs($pubYear, $catId, $artType)
{
    $pubYear = (int)$pubYear;
    $catId = (int)$catId;
    $artType = addslashes($artType);
    $pubs = array();
    $sql = "select pmid_id, pmid, citation_count from violin_pmid where publication_year = " . $pubYear . " and category_id = " . $catId . " and article_type = '" . $artType . "'";
    // echo $sql;
    $result = db_query($sql)->fetchAll();
    foreach ($result as $row) {
        $pubs[$row->pmid] = $row->citation_count;
    }
    return $pubs;
}

function rank_pubs($sortPubs)
{
    $rankPubs = array();
    $count = count($sortPubs);
    foreach ($sortPubs as $key => $val) {
        $rank = array_search($key, array_keys($sortPubs)) + 1;
        $median_rank = get_median_rank($val, $sortPubs);
        $percentile_rank = (($median_rank - 0.5) / $count) * 100;
        $rankPubs[] = array('pmid' => $key, 'count' => $val, 'rank' => $rank, 'median_rank' => $median_rank, 'percentile_rank' => $percentile_rank);
    }
    return $rankPubs;
}

function get_median_rank($value, $arrPubs)
{
    $ranks = array();
    $median = 0;
    $count = 0;
    foreach ($arrPubs as $k => $v) {
        if ($value == $v) {
            $count++;
            $ranks[] = array_search($k, array_keys($arrPubs)) + 1;
        }
    }
    if ($count > 0) {
        $median = get_stat($ranks, 'median');
    }
    return $median;
}

function get_stat($array, $output = 'mean')
{
    if (!is_array($array)) {
        return FALSE;
    } else {
        switch ($output) {
            case 'mean':
                $count = count($array);
                $sum = array_sum($array);
                $total = $sum / $count;
                break;
            case 'median':
                rsort($array);
                $count = count($array);
                $middle = floor($count / 2);
                if (($count % 2) == 0) {
                    $total = ($array[$middle--] + $array[$middle]) / 2;
                } else {
                    $total = $array[$middle];;
                }
                break;
            case 'mode':
                $v = array_count_values($array);
                arsort($v);
                foreach ($v as $k => $v) {
                    $total = $k;
                    break;
                }
                break;
            case 'range':
                sort($array);
                $sml = $array[0];
                rsort($array);
                $lrg = $array[0];
                $total = $lrg - $sml;
                break;
        }
        return $total;
    }
}

function populate_baseline_data($year, $type, $category_id, $data)
{
    foreach ($data as $val) {
        if (!empty($val)) {
            $fetch_data = $val;
            $insert_record = array();
            $insert_record['pmid'] = $fetch_data['pmid'];
            $insert_record['category_id'] = $category_id;
            $insert_record['year'] = $year;
            $insert_record['times_cited'] = $fetch_data['count'];
            $insert_record['rank'] = $fetch_data['rank'];
            $insert_record['median_rank'] = $fetch_data['median_rank'];
            $insert_record['percentile_rank'] = $fetch_data['percentile_rank'];
            $insert_record['article_type'] = $type;

            insert_baseline_data($insert_record);
        }
    }
}

function insert_baseline_data($data)
{

    $curr_pmid = (int)$data['pmid'];
    $curr_year = (int)$data['year'];
    $curr_category_id = (int)$data['category_id'];
    $curr_times_cited = (int)($data['times_cited']);
    $curr_rank = (int)($data['rank']);
    $curr_median_rank = (double)($data['median_rank']);
    $curr_percentile_rank = (double)($data['percentile_rank']);
    $curr_article_type = addslashes($data['article_type']);

    $chk_pmid = '';
    $chk_query = "select pmid from violin_baseline where pmid = $curr_pmid ";

    $chk_result = db_query($chk_query)->fetchObject();
    if (!empty($chk_result->pmid)) {
        $chk_pmid = $chk_result->pmid;
    }

    $transaction = db_transaction();
    try {
        if (empty($chk_pmid)) {
            $insert_id = db_insert('violin_baseline')
                ->fields(array(
                    'pmid' => $curr_pmid,
                    'category_id' => $curr_category_id,
                    'category_id' => $curr_category_id,
                    'publication_year' => $curr_year,
                    'times_cited' => $curr_times_cited,
                    'rank' => $curr_rank,
                    'median_rank' => $curr_median_rank,
                    'percentile_rank' => $curr_percentile_rank,
                    'article_type' => $curr_article_type
                ))
                ->execute();
        }

    } catch (Exception $e) {
        $transaction->rollback();
        var_dump($e->getMessage());
    }

}


?>