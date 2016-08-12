<?php

/***********************************************************************************************
 * // Name:    data.php
 * // Author:    Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Data abstraction class
 ************************************************************************************************/
class Data
{
    var $mysqli;
    var $violin_baseline;
    var $violin_category;
    var $violin_journal;
    var $violin_journal_category;
    var $violin_pmids;


    // Methods
    function Data($conn)
    {
        global $tables;
        $this->mysqli = $conn;
        $this->violin_baseline = $tables->violin_baseline;
        $this->violin_category = $tables->violin_category;
        $this->violin_journal = $tables->violin_journal;
        $this->violin_journal_category = $tables->violin_journal_category;
        $this->violin_pmids = $tables->violin_pmids;
    }

    function get_query_count($countQuery)
    {
        $total = 0;
        $result = $this->mysqli->query($countQuery);
        if ($row = mysqli_fetch_object($result)) {
            $total = $row->total;
        }
        return $total;
    }

    function get_all_categories()
    {
        $categories = array();
        $sql = "select violin_category.category_id, violin_category.category from violin_category ";
        // $sql = "select violin_category.category_id, violin_category.category from violin_category where category_id = 2 ";
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
            $categories[$row->category_id] = $row->category;
        }
        return $categories;
    }

    function get_custom_categories($ids)
    {
        $str_ids = "(" . implode(',', $ids) . ")";
        $categories = array();
        $sql = "select violin_category.category_id, violin_category.category from violin_category where category_id in $str_ids ";
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
            $categories[$row->category_id] = $row->category;
        }
        return $categories;
    }

    function get_pmid_count()
    {
        $total = 0;
        $sql = "select count(*) as total from violin_pmid where citation_count = 0";
        $result = $this->mysqli->query($sql);
        if ($row = mysqli_fetch_object($result)) {
            $total = $row->total;
        }
        return $total;
    }

    function get_all_pmids()
    {
        $pmids = array();
        $sql = "select pmid_id, pmid from violin_pmid where citation_count = 0";
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
            $pmids[$row->pmid_id] = $row->pmid;
        }
        return $pmids;
    }

    function get_all_pmids_by_year($year)
    {
        $year = (int)$year;
        $pmids = array();
        $sql = "select pmid_id, pmid from violin_pmid where publication_year = " . $year;
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
            $pmids[$row->pmid_id] = $row->pmid;
        }
        return $pmids;
    }

    function get_pmids($limit = 100, $offset = 0)
    {
        $pmids = array();
        $sql = "select pmid_id, pmid from violin_pmid where citation_count = 0 limit $offset, $limit  ";
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
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

        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
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
                $this->insert_data($insert_record);
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
                $this->insert_data($insert_record);
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
        $chk_result = $this->mysqli->query($chk_query);
        if ($row = mysqli_fetch_object($chk_result)) {
            $chk_pmid = $row->pmid;
        }
        if (empty($chk_pmid)) {
            $in_query = "insert into violin_pmid
                (pmid, issn, category_id, publication_year, article_type, pubmed_article_type, title)
                values
                ($curr_pmid, '$curr_issn', $curr_category_id, $curr_year, '$curr_article_type','$curr_pubmed_article_type', '$curr_title')
            ";
            // echo $in_query;
            $this->mysqli->query($in_query) or die ("Error inserting record:" . $this->mysqli->error);

        }
    }

    function update_citation_count($data)
    {

        if (!empty($data['pmid_id'])) {
            $this->update_citation_count_data($data);
        }

    }

    function update_citation_count_data($data)
    {
        $pmid_id = (int)$data['pmid_id'];
        $citation_count = (int)$data['citation_count'];
        $chk_id = '';
        $chk_query = "select pmid_id from violin_pmid where pmid_id = $pmid_id ";

        // echo $chk_query . "\n";

        $chk_result = $this->mysqli->query($chk_query);
        if ($row = mysqli_fetch_object($chk_result)) {
            $chk_id = $row->pmid_id;
        }
        if (!empty($chk_id)) {
            $up_query = "
                update violin_pmid
                set citation_count = $citation_count, date_of_citation_count = NOW(), scopus_article_exist = NULL
                where pmid_id = $pmid_id
            ";
            // echo $in_query;
            $this->mysqli->query($up_query) or die ("Error inserting record:" . $this->mysqli->error);
        }
    }

    function update_empty_result($data)
    {

        if (!empty($data['pmid_id']) && !empty($data['scopus_article_exist'])) {
            $this->update_article_exist_data($data);
        }

    }

    function update_article_exist_data($data)
    {
        $pmid_id = (int)$data['pmid_id'];
        $scopus_article_exist = addslashes($data['scopus_article_exist']);

        $chk_id = '';
        $chk_query = "select pmid_id from violin_pmid where pmid_id = $pmid_id ";

        // echo $chk_query . "\n";

        $chk_result = $this->mysqli->query($chk_query);
        if ($row = mysqli_fetch_object($chk_result)) {
            $chk_id = $row->pmid_id;
        }
        if (!empty($chk_id)) {
            $up_query = "
                update violin_pmid
                set scopus_article_exist = '$scopus_article_exist' , date_of_citation_count = NOW()
                where pmid_id = $pmid_id
            ";
            // echo $in_query;
            $this->mysqli->query($up_query) or die ("Error updating record:" . $this->mysqli->error);
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
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
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
            $median_rank = $this->get_median_rank($val, $sortPubs);
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
            $median = $this->get_stat($ranks, 'median');
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

                $this->insert_baseline_data($insert_record);
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
        $chk_result = $this->mysqli->query($chk_query);
        if ($row = mysqli_fetch_object($chk_result)) {
            $chk_pmid = $row->pmid;
        }
        if (empty($chk_pmid)) {
            $in_query = "insert into violin_baseline
                (pmid, category_id, publication_year, times_cited, rank, median_rank, percentile_rank, article_type)
                values
                ($curr_pmid, $curr_category_id, $curr_year, $curr_times_cited, $curr_rank, $curr_median_rank, $curr_percentile_rank, '$curr_article_type')
            ";
            // echo $in_query;
            $this->mysqli->query($in_query) or die ("Error inserting record:" . $this->mysqli->error);

        }
    }

    function get_all_excel_data()
    {
        $results = array();
        $sql = "select * from violin_excel";
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
            $results[] = $row;
        }
        return $results;
    }

    function populate_journal($data)
    {
        if (!empty($data)) {
            $issn = addslashes($data['issn']);
            $journal_id = $this->get_journal_id($issn);
            if (!empty($journal_id)) {
                return $journal_id;
            } else {
                $title = addslashes($data['title']);
                $impact_factor = (double)$data['impact_factor'];
                $in_query = "insert into violin_journal (journal_title, issn, impact_factor) values ('$title', '$issn', $impact_factor)";
                $this->mysqli->query($in_query) or die ("Error inserting record:" . $this->mysqli->error);
                $journal_id = $this->mysqli->insert_id;
                return $journal_id;
            }
        }
    }

    function populate_category($data)
    {
        if (!empty($data)) {
            $category = addslashes(ucwords(strtolower($data['category'])));
            $cat_id = $this->get_category_id($category);
            if (!empty($cat_id)) {
                return $cat_id;
            } else {
                $in_query = "insert into violin_category (category) values ('$category' )";
                $this->mysqli->query($in_query) or die ("Error inserting record:" . $this->mysqli->error);
                $cat_id = $this->mysqli->insert_id;
                return $cat_id;
            }
        }
    }

    function populate_journal_category($jid, $cid)
    {
        $jid = (int)$jid;
        $cid = (int)$cid;
        if (!$this->journal_category_exist($jid, $cid)) {
            $in_query = "insert into violin_journal_category (journal_id, category_id) values ($jid, $cid )";
            $this->mysqli->query($in_query) or die ("Error inserting record:" . $this->mysqli->error);
        }
    }

    function journal_exist($issn)
    {
        $issn = addslashes($issn);
        if (!empty($issn)) {
            $sql = "SELECT count(*) as total from violin_journal where issn = '" . $issn . "'";
            $total = 0;
            $result = $this->mysqli->query($sql);
            if ($row = mysqli_fetch_object($result)) {
                $total = $row->total;
            }
            return ($total != 0) ? true : false;
        }
    }

    function category_exist($category)
    {
        $category = addslashes(ucwords(strtolower($category)));
        if (!empty($category)) {
            $sql = "SELECT count(*) as total from violin_category where category = '" . $category . "'";
            $total = 0;
            $result = $this->mysqli->query($sql);
            if ($row = mysqli_fetch_object($result)) {
                $total = $row->total;
            }
            return ($total != 0) ? true : false;
        }
    }

    function journal_category_exist($journal_id, $cat_id)
    {
        $journal_id = (int)$journal_id;
        $cat_id = (int)$cat_id;
        if (!empty($journal_id) && !empty($cat_id)) {
            $sql = "SELECT count(*) as total from violin_journal_category where journal_id = " . $journal_id . " and category_id = " . $cat_id;
            $total = 0;
            $result = $this->mysqli->query($sql);
            if ($row = mysqli_fetch_object($result)) {
                $total = $row->total;
            }
            return ($total != 0) ? true : false;
        }
    }

    function get_journal_id($issn)
    {
        if (!empty($issn)) {
            $journal_id = 0;
            $sql = " SELECT journal_id from violin_journal where issn = '" . $issn . "'";
            $result = $this->mysqli->query($sql);
            while ($row = mysqli_fetch_object($result)) {
                $journal_id = $row->journal_id;
            }
            return $journal_id;
        }
    }

    function get_category_id($category)
    {
        if (!empty($category)) {
            $cat_id = 0;
            $sql = " SELECT category_id from violin_category where category = '" . $category . "'";
            $result = $this->mysqli->query($sql);
            while ($row = mysqli_fetch_object($result)) {
                $cat_id = $row->category_id;
            }
            return $cat_id;
        }
    }

    function truncate_table($name)
    {
        //truncate table
        $query = "truncate table $name";
        $this->mysqli->query($query) or die ("Error truncation table:" . $this->mysqli->error);
    }


    function get_all_articles()
    {
        $results = array();
        $sql = "select * from article";
        $result = $this->mysqli->query($sql);
        while ($row = mysqli_fetch_object($result)) {
            $results[] = $row;
        }
        return $results;
    }

    // calculate percentile rank
    function calculate_percentile_rank($pub){

        $rank = 0;
        $pmid = addslashes($pub->pmid);
        $type = addslashes($pub->article_type);
        $cat = addslashes($pub->category);
        $date = addslashes($pub->cover_date);
        $cites = addslashes($pub->citation_count);
        $year = '';
        if(!empty($date)) {
            // extract year from date
            $parts = explode('-', $date);
            $year = $parts[0];

            if($year < 2003 || $year > 2014) {
                return null;
            }
        }

        // check if the article exist in reference set with the same pmid, then return the percentile rank.
        if (!empty($pmid)) {
            $query = "";
            $query .= " select * from violin_baseline where pmid = $pmid";
            $query .= " limit 1";
            $record = $this->mysqli->query($query);
            if (isset($record->percentile_rank)) {
                $rank = $record->percentile_rank;
                return $rank;
            }
        }

        // else return the percentile_rank calculated over all categories of that publication.
        if (!empty($cat)) {
            $cat_ids = explode("|", $cat);
            // calculate cumulative citation count for all categories.
            $id_count = count($cat_ids);
            if ($id_count > 0) {
                $total_rank = 0;
                $count = 0;
                foreach ($cat_ids as $item) {

                    $query = "";
                    $query .= " select * from violin_baseline where ";

                    if (!empty($type) && !empty($year)) {
                        $query .= " article_type = '$type' and publication_year = $year ";
                        $query .= " and ";
                    }else if(!empty($type) && empty($year)){
                        $query .= " article_type = '$type' ";
                        $query .= " and ";
                    }else if(empty($type) && !empty($year)){
                        $query .= " publication_year = $year ";
                        $query .= " and ";
                    }

                    $query .= " category_id = $item";

                    $query .= " order by ABS(times_cited - " . $cites . ")";
                    $query .= " limit 1";
                    $record = $this->mysqli->query($query);
                    if (isset($record->percentile_rank)) {
                        $total_rank += $record->percentile_rank;
                        $count++;
                    }

                }
                if ($count > 0) {
                    $rank = $total_rank / $count;
                }

            }
            if (!empty($rank)) {
                return $rank;
            }
        }

        // If there still no match, then get the percentile ranking of the closest pmid for type and year.
        $query = "";
        $query .= " select * from violin_baseline where ";
        if (!empty($type) && !empty($year)) {
            $query .= " article_type = '$type' and publication_year = $year ";
        }else if(!empty($type) && empty($year)){
            $query .= " article_type = '$type' ";
        }else if(empty($type) && !empty($year)){
            $query .= " publication_year = $year ";
        }

        $query .= " order by ABS(times_cited - " . $cites . ")";
        $query .= " limit 1";

        $record = $this->mysqli->query($query);
        if (isset($record->percentile_rank)) {
            $rank = $record->percentile_rank;
            return $rank;
        }

        // If there still no match, look for closest pmid in that year then get the percentile ranking of the closest pmid.
        $query = "";
        $query .= " select * from violin_baseline ";
        if(!empty($year)) {
            $query .= " where publication_year = $year ";
        }
        $query .= " order by ABS(times_cited - " . $cites . ")";
        $query .= " limit 1";

        $record = $this->mysqli->query($query);
        if (isset($record->percentile_rank)) {
            $rank = $record->percentile_rank;
            return $rank;
        }

        return $rank;
    }

    function update_article_percentile_rank($id, $rank='') {
        $id = (int)$id;
        $rank = (double)$rank;
        $chk_id = '';
        $chk_query = "select id from article where article_id = $id ";

        $chk_result = $this->mysqli->query($chk_query);
        if ($row = mysqli_fetch_object($chk_result)) {
            $chk_id = $row->id;
        }
        if (!empty($chk_id)) {
            $up_query = "
                update article
                set percentile_rank = $rank
                where article_id = $id
            ";
            // echo $in_query;
            $this->mysqli->query($up_query) or die ("Error updating percentile rank in citation article:" . $this->mysqli->error);
        }
    }

    function get_visualization_data()
    {
        $records = array();
        $query = "select * from article where article.percentile_rank is not null limit 100";

        $result = $this->mysqli->query($query);
        while ($row = mysqli_fetch_object($result)) {
            if (!empty($row->pmid)) {
                $data = array();
                // get all authors
                $authors = $this->get_article_authors($row->article_id);
                // get categories
                $categories = $this->get_article_categories($row->category);
                $data['pmid'] = $row->pmid;
                $data['pubtype'] = $row->article_type;
                $data['citation_count'] = $row->citation_count;
                $data['percentile_rank'] = $row->percentile_rank;
                $data['cover_date'] = $row->cover_date;
                $data['category'] = $categories;
                $data['first_or_last_author'] = '';
                $data['title'] = $row->title;
                $data['publication_name'] = $row->journal;
                $data['pages'] = $row->pages;
                $data['volume'] = $row->volume;
                $data['issue'] = $row->issue;
                $data['nlmabbreviation'] = $row->nlmabbreviation;
                $data['scopus_doc_id'] = $row->scopus_doc_id;
                $data['authors'] = $authors;
                $records[] = $data;
            }
        }
        return $records;
    }

    function get_article_authors($pub_id = '')
    {
        $authors_str = '';
        $authors = array();
        $pub_id = addslashes($pub_id);

        if (!empty($pub_id)) {
            $sql = "select author.* from author, author_article where author_article.author_id = author.author_id and author_article.article_id = $pub_id";
            $result = $this->mysqli->query($sql);
            while ($row = mysqli_fetch_object($result)) {
                $authors[] = $row->first_name . " " . $row->last_name;
            }
        }
        if(count($authors) > 0){
            $authors_str = implode('|', $authors);
        }
        return $authors_str;
    }

    function get_article_categories($cat_ids) {
        $category_str = '';
        $categories = array();
        $cat_ids = addslashes($cat_ids);

        if (!empty($cat_ids)) {
            $ids = explode("|", $cat_ids);
            foreach ($ids as $id) {
                $sql = " select category from violin_category where category_id = $id";
                $record = $this->mysqli->query($sql);
                if (isset($record->category)) {
                    $categories[] = $record->category;
                }
            }
        }

        if(count($categories) > 0){
            $category_str = implode('|', $categories);
        }

        return $category_str;
    }

}


?>