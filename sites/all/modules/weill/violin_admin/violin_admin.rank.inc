<?php

function violin_admin_populate() {

     //truncate violin_percentile_rank table
    /*$truncate_result = db_truncate('violin_wcmc_author')->execute();
    $truncate_result = db_truncate('violin_wcmc_article')->execute();
    $truncate_result = db_truncate('violin_wcmc_author_article')->execute();

    $truncate_result = db_truncate('field_data_field_article_type')->execute();
    $truncate_result = db_truncate('field_revision_field_article_type')->execute();

    $truncate_result = db_truncate('field_data_field_category')->execute();
    $truncate_result = db_truncate('field_revision_field_category')->execute();

    $truncate_result = db_truncate('field_data_field_percentile_rank')->execute();
    $truncate_result = db_truncate('field_revision_field_percentile_rank')->execute();*/

    // flag to check for re-index
    $citations_reindex = false;
    $reindex_items = array();
    $reindex_new_items = array();
    $reindex_update_items = array();


    // get new publications and populate
    $new_pub_ids = array();
    $new_pub_ids = violin_admin_get_new_pubs();

    if(count($new_pub_ids) > 0){
        $reindex_new_items = violin_admin_populate_percentile_rank($new_pub_ids);
        $citations_reindex = true;
    }

    //get updated publications and populate
    $updated_pub_ids = array();
    $updated_pub_ids = violin_admin_get_updated_pubs();
    if(count($updated_pub_ids) > 0){
        $reindex_update_items = violin_admin_populate_percentile_rank($updated_pub_ids);
        $citations_reindex = true;
    }

    /*$pubs = violin_admin_get_new_update_pubs();
    if(count($pubs) > 0) {
        $items = violin_admin_populate_percentile_rank($pubs);
        $citations_reindex = true;
    }



    foreach($items as $id => $status) {
        $reindex_items[] = $id;
    }
    */
    // reindex citations search api server

    if($citations_reindex === true ){
        $reindex_items = array_unique(array_merge($reindex_new_items, $reindex_update_items ));
        // Load Search API Index.
        $citations_index = search_api_index_load('citations');
        search_api_index_specific_items($citations_index, $reindex_items);
    }

    return "Program completed successfully.";

}

function violin_admin_get_new_update_pubs(){
    $pub_ids = array();

    $query = "select nid, 'INSERT' as status from node where  node.type = 'publication' and node.nid not in ( select entity_id from violin_wcmc_article )
union
select a.entity_id as nid, 'UPDATE' as status from (select entity_id, field_citations_value from field_data_field_citations) a
join (select entity_id, citation_count from violin_wcmc_article where unix_timestamp(now()) - unix_timestamp(updated) > 604800) b on a.entity_id = b.entity_id 
where a.field_citations_value != b.citation_count LIMIT 0,500";


    // $query = "select nid from node where  node.type = 'publication' and node.nid in ('32372', '144414', '145208' )";

    $record = db_query($query)->fetchAll();
    $return_array = array();
    foreach ($record as $row) {
        $return_array[$row->nid] = $row->status;
    }
    return $return_array;
}

function violin_admin_get_new_pubs(){
    $pub_ids = array();
    $query = "select nid, taxonomy_term_data.name as type from node
join field_data_field_date
on
node.nid = field_data_field_date.entity_id
join 
field_data_field_rdf_type
on
node.nid = field_data_field_rdf_type.entity_id
left join
taxonomy_term_data
on
field_data_field_rdf_type.field_rdf_type_tid = taxonomy_term_data.tid
where  node.type = 'publication' and node.nid not in ( select entity_id from violin_wcmc_article ) 
and date_format(field_data_field_date.field_date_value,'%Y') between DATE_FORMAT(CURDATE(),'%Y') - 12 and DATE_FORMAT(CURDATE(),'%Y') - 3
and taxonomy_term_data.name in ('Academic Article', 'Review')
limit 0, 1500";

    // $query = "select nid from node where  node.type = 'publication' and node.nid in ('32372', '144414', '145208' )";

    $record = db_query($query)->fetchAll();

    foreach ($record as $row) {
        $pubs[] = array(
            'id' => $row->nid,
            'type' => $row->type,
        );
    }
    return $pubs;
}

function violin_admin_get_updated_pubs(){

    $pub_ids = array();

    // get unix timestamp for 7 days ago
    $prev_week_ts = time() - (7 * 24 * 60 * 60);
    // $query = "select nid from node where  node.type = 'publication' and node.created != node.changed and node.changed > $prev_week_ts";

    // Select all rows in field_data_field_citations where field_citations_value differ from citation_count in violin_wcmc_article
    $query = "select a.entity_id as entity_id, b.article_type as type from (select entity_id, field_citations_value from field_data_field_citations) a join (select entity_id, citation_count, article_type from violin_wcmc_article ) b on a.entity_id = b.entity_id where a.field_citations_value != b.citation_count limit 0, 1500";

    $record = db_query($query)->fetchAll();

    foreach ($record as $row) {
        $pubs[] = array(
            'id' => $row->entity_id,
            'type' => $row->type,
        );
    }
    return $pubs;
}

function violin_admin_populate_percentile_rank($pub_ids)
{

    $percentile_items = array();

    $items_to_index = array();

    if (count($pub_ids) > 0) {

        //foreach ($pub_ids as $id => $update_status) {

            foreach ($pub_ids as $pub) {
            $id = $pub['id'];
            $type = $pub['type'];
            $items_to_index[] = $id;

            // all author field values
            $pub_node = node_load($id);
            $pub_wrapper = entity_metadata_wrapper('node', $pub_node);

            // populate all publication fields
            $citation_count = $pub_wrapper->field_citations->value();

            // check if this article already exist with same citation count, if yes skip to the next record
            $update_status = check_article_update_status($id, $citation_count);

            switch ($update_status) {
                case 'not_exist':
                    $data = array();

                    $data['entity_id'] = $id;

                    $data['pmid'] = trim(strip_tags($pub_wrapper->field_pmid->value()));

                    $data['doi'] = $pub_wrapper->field_doi->value();

                    $data['scopus_id'] = $pub_wrapper->field_scopus_id->value();

                    $data['cover_date'] = date("Y-m-d H:i:s", $pub_wrapper->field_date->value());

                    $data['citation_count'] = $pub_wrapper->field_citations->value();

                    $article_title = $pub_wrapper->field_full_title->value();
                    $data['title'] = $article_title;

                    $article_issue = $pub_wrapper->field_issue->value();
                    $data['issue'] = $article_issue;

                    $article_volume = $pub_wrapper->field_volume->value();
                    $data['volume'] = $article_volume;

                    $article_page_start = $pub_wrapper->field_page_start->value();
                    $article_page_end = $pub_wrapper->field_page_end->value();
                    $article_pages = $article_page_start . " - " . $article_page_end;

                    $data['pages'] = $article_pages;

                    $article_sid = $pub_wrapper->field_scopus_id->value();
                    $data['scopus_doc_id'] = $article_sid;

                    $article_authors = get_article_authors($id);
                    $data['authors'] = $article_authors;

                    $journal_issn = get_journal_issn($id);
                    $data['journal_issn'] = $journal_issn;

                    $journal_eissn = get_journal_eissn($id);
                    $data['journal_eissn'] = $journal_eissn;

                    $journal_lissn = get_journal_lissn($id);
                    $data['journal_lissn'] = $journal_lissn;

                    // get journal title and category from violin using either issn, eissn or lissn
                    $journal_title = "";
                    $journal_categories = array();

                    $journal_record = get_journal_record($journal_issn, $journal_eissn, $journal_lissn);

                    if (isset($journal_record->journal_id)) {
                        $journal_id = $journal_record->journal_id;
                        $journal_title = $journal_record->journal_title;
                        $journal_categories = get_journal_category($journal_id);
                    }

                    // if still no title found, then use the one from vivo import
                    if (empty($journal_title)) {
                        $journal_title = get_journal_name($id);
                        // get category, if empty, using this title
                        if (empty($journal_categories) && !empty($journal_title)) {
                            // try picking the category using a title match
                            $journal_categories = get_journal_category_by_title($journal_title);
                        }
                    }

                    $data['journal'] = $journal_title;

                    if (isset($journal_categories['ids'])) {
                        $data['category'] = implode("|", $journal_categories['ids']);
                    } else {
                        $data['category'] = "";
                    }

                    // populate journal category field using category names
                    if (isset($journal_categories['names'])) {
                        populate_category_field($id, $journal_categories['names']);
                    }

                    // Get article type.
                    //$article_type = get_article_type($id);
                    $article_type = $type;

                    // populate article type field
                    if (!empty($article_type)) {
                        $data['article_type'] = $article_type;
                        populate_article_type_field($id, $article_type);
                    } else {
                        $data['article_type'] = "";
                    }

                    // get percentile ranking
                    $percentile_rank = NULL;
                    //if (!empty($data['citation_count'])) { Commented out to include publications with citation count as 0
                        $percentile_rank = calculate_percentile_rank($data['citation_count'], $data['pmid'], $data['article_type'], $data['category'], $data['cover_date']);
                    //}
                    $data['percentile_rank'] = $percentile_rank;
                    // populate percentile rank field
                    populate_percentile_rank_field($id, $percentile_rank , 'INSERT');

                    // populate article table
                    // insert into violin_article table
                    $article_id = populate_violin_article($data);

                    // get authors
                    // get all endpoint nodes for authors for this node
                    $endpoints_query = "
                        select distinct node.nid
                        from node
                        left join field_data_endpoints on field_data_endpoints.endpoints_entity_id = node.nid
                        where node.type = 'author'
                        and field_data_endpoints.entity_id in (
                          select e.entity_id
                          from field_data_endpoints e
                          join node n on n.nid = e.endpoints_entity_id
                          where e.endpoints_entity_id = $id
                        )
                        ";
                    $endpoints_records = db_query($endpoints_query)
                        ->fetchAll();

                    foreach ($endpoints_records as $auth_row) {

                        $auth_node = node_load($auth_row->nid);
                        $pub_wrapper = entity_metadata_wrapper('node', $auth_node);

                        //get all author fields
                        $data['author_entity_id'] = $auth_row->nid;
                        $data['cwid'] = $pub_wrapper->field_id->value();
                        $data['first_name'] = $pub_wrapper->field_first_name->value();
                        $data['last_name'] = $pub_wrapper->field_last_name->value();

                        // Get author position. Use 1 for testing
                        $is_first_or_last_author = get_first_or_last_author($auth_row->nid, $id);
                        $data['is_first_or_last_author'] = ($is_first_or_last_author == true) ? 1 : 0;

                        // finally insert into db
                        if (!empty($auth_row->nid)) {
                            // insert into violin_author table
                            $author_id = populate_violin_author($data);
                            if (!empty($author_id) && !empty($article_id)) {
                                $author_article_id = populate_violin_author_article($data, $author_id, $article_id);
                            }

                            // take item to be indexed
                            $items_to_index[] = $auth_row->nid;
                        }

                    }
                    unset($data);
                    unset($article_id);
                    unset($author_id);
                    unset($author_article_id);

                    break;
                case 'exist_differ_count':
                    $data = array();

                    $data['entity_id'] = $id;

                    $data['pmid'] = $pub_wrapper->field_pmid->value();

                    $data['doi'] = $pub_wrapper->field_doi->value();

                    $data['scopus_id'] = $pub_wrapper->field_scopus_id->value();

                    $data['cover_date'] = date("Y-m-d H:i:s", $pub_wrapper->field_date->value());

                    $data['citation_count'] = $pub_wrapper->field_citations->value();

                    $article_title = $pub_wrapper->field_full_title->value();
                    $data['title'] = $article_title;

                    $article_issue = $pub_wrapper->field_issue->value();
                    $data['issue'] = $article_issue;

                    $article_volume = $pub_wrapper->field_volume->value();
                    $data['volume'] = $article_volume;

                    $article_page_start = $pub_wrapper->field_page_start->value();
                    $article_page_end = $pub_wrapper->field_page_end->value();
                    $article_pages = $article_page_start . " - " . $article_page_end;

                    $data['pages'] = $article_pages;

                    $article_sid = $pub_wrapper->field_scopus_id->value();
                    $data['scopus_doc_id'] = $article_sid;

                    $article_authors = get_article_authors($id);
                    $data['authors'] = $article_authors;

                    $journal_issn = get_journal_issn($id);
                    $data['journal_issn'] = $journal_issn;

                    $journal_eissn = get_journal_eissn($id);
                    $data['journal_eissn'] = $journal_eissn;

                    $journal_lissn = get_journal_lissn($id);
                    $data['journal_lissn'] = $journal_lissn;

                    // get journal title and category from violin using either issn, eissn or lissn
                    $journal_title = "";
                    $journal_categories = array();

                    $journal_record = get_journal_record($journal_issn, $journal_eissn, $journal_lissn);

                    if (isset($journal_record->journal_id)) {
                        $journal_id = $journal_record->journal_id;
                        $journal_title = $journal_record->journal_title;
                        $journal_categories = get_journal_category($journal_id);
                    }

                    // if still no title found, then use the one from vivo import
                    if (empty($journal_title)) {
                        $journal_title = get_journal_name($id);
                        // get category, if empty, using this title
                        if (empty($journal_categories) && !empty($journal_title)) {
                            // try picking the category using a title match
                            $journal_categories = get_journal_category_by_title($journal_title);
                        }
                    }

                    $data['journal'] = $journal_title;

                    if (isset($journal_categories['ids'])) {
                        $data['category'] = implode("|", $journal_categories['ids']);
                    } else {
                        $data['category'] = "";
                    }

                    // Get article type.
                    //$article_type = get_article_type($id);

                    $article_type = $type;
                    // populate article type field
                    if (!empty($article_type)) {
                        $data['article_type'] = $article_type;
                    } else {
                        $data['article_type'] = "";
                    }

                    // get percentile ranking
                    $percentile_rank = NULL;
                    //if (!empty($data['citation_count'])) { Commented out to include publications with citation count as 0
                        $percentile_rank = calculate_percentile_rank($data['citation_count'], $data['pmid'], $data['article_type'], $data['category'], $data['cover_date']);
                    //}
                    $data['percentile_rank'] = $percentile_rank;
                    // populate percentile rank field
                    populate_percentile_rank_field($id, $percentile_rank, 'UPDATE');

                    // populate article table
                    // update violin_article table
                    $article_id = update_violin_article($data);

                    // get authors. This is only for reindexing author ids corresponding to this pub
                    // get all endpoint nodes for authors for this node
                    $endpoints_query = "
                        select distinct node.nid
                        from node
                        left join field_data_endpoints on field_data_endpoints.endpoints_entity_id = node.nid
                        where node.type = 'author'
                        and field_data_endpoints.entity_id in (
                          select e.entity_id
                          from field_data_endpoints e
                          join node n on n.nid = e.endpoints_entity_id
                          where e.endpoints_entity_id = $id
                        )
                        ";
                    $endpoints_records = db_query($endpoints_query)
                        ->fetchAll();

                    foreach ($endpoints_records as $auth_row) {
                        // take item to be indexed
                        if (!empty($auth_row->nid)) {
                            $items_to_index[] = $auth_row->nid;
                        }
                    }

                    unset($data);
                    unset($article_id);

                    break;
                default:
                    break;
            }

            node_save($pub_node);

            // clear cache
            entity_get_controller("node")->resetCache(array($id));

            // Clear field cache for the node.
            cache_clear_all('field:node:' . $id, 'cache_field');

        }

    }

    return $items_to_index;

}

function last_updated_node()
{
    $last_node_id = 0;
    $last_query = "select entity_id from violin_wcmc_article ORDER BY entity_id DESC LIMIT 1";
    $last_record = db_query($last_query)->fetchObject();
    if (!empty($last_record->entity_id)) {
        $last_node_id = $last_record->entity_id;
    }
    return $last_node_id;
}

function check_article_update_status($id, $count)
{
    $update_status = 'not_exist';
    // check if this article exist with same citation count
    $chk_query = "
      select entity_id, citation_count, category, updated
      from violin_wcmc_article a
      where a.entity_id = $id";
    $chk_record = db_query($chk_query)->fetchObject();
    if (!empty($chk_record->entity_id)) {
        $update_status = 'exist';
        $citation_count = $chk_record->citation_count;
        $category = $chk_record->category;
        $update_date = $chk_record->updated;
        if(strtotime($update_date) < (time() - 60 * 60 * 24)) {
            if ($citation_count != $count || $category == '') {
                $update_status = 'exist_differ_count';
            }
        }
    }
    return $update_status;
}

function populate_violin_author($data)
{
    $author_id = "";
    // check if this author exist already
    $chk_query = "
      select *
      from violin_wcmc_author a
      where a.entity_id = " . (int)$data['author_entity_id'];
    $chk_record = db_query($chk_query)->fetchObject();
    if (!empty($chk_record->author_id)) {
        $author_id = $chk_record->author_id;
    } else {
        $timestamp = date("Y-m-d H:i:s");
        $author_id = db_insert('violin_wcmc_author')
            ->fields(array(
                'entity_id' => $data['author_entity_id'],
                'cwid' => $data['cwid'],
                'first_name' => $data['first_name'],
                'last_name' => $data['last_name'],
                'created' => $timestamp,
                'updated' => $timestamp
            ))
            ->execute();
    }
    return $author_id;
}

function populate_violin_article($data)
{
    $article_id = "";

    // check if this article exist already
    $chk_query = "
      select *
      from violin_wcmc_article a
      where a.entity_id = " . (int)$data['entity_id'];
    $chk_record = db_query($chk_query)->fetchObject();
    if (!empty($chk_record->article_id)) {
        $article_id = $chk_record->article_id;
    } else {
        $timestamp = date("Y-m-d H:i:s");
        $article_id = db_insert('violin_wcmc_article')
            ->fields(array(
                'entity_id' => $data['entity_id'],
                'pmid' => $data['pmid'],
                'scopus_id' => $data['scopus_id'],
                'article_type' => $data['article_type'],
                'journal' => $data['journal'],
                'journal_issn' => $data['journal_issn'],
                'journal_eissn' => $data['journal_eissn'],
                'journal_lissn' => $data['journal_lissn'],
                'citation_count' => (int)$data['citation_count'],
                'percentile_rank' => $data['percentile_rank'],
                'cover_date' => $data['cover_date'],
                'category' => $data['category'],
                'title' => $data['title'],
                'pages' => $data['pages'],
                'volume' => $data['volume'],
                'issue' => $data['issue'],
                'scopus_doc_id' => $data['scopus_doc_id'],
                'authors' => $data['authors'],
                'created' => $timestamp,
                'updated' => $timestamp
            ))
            ->execute();
    }
    return $article_id;
}

function update_violin_article($data)
{
    $num_updated = "";
    // check if this article exist already
    $chk_query = "
      select *
      from violin_wcmc_article a
      where a.entity_id = " . (int)$data['entity_id'];
    $chk_record = db_query($chk_query)->fetchObject();
    if (!empty($chk_record->article_id)) {
        $article_id = $chk_record->article_id;
        $timestamp = date("Y-m-d H:i:s");
        $num_updated = db_update('violin_wcmc_article') // Table name no longer needs {}
        ->fields(array(
            'entity_id' => $data['entity_id'],
            'pmid' => $data['pmid'],
            'scopus_id' => $data['scopus_id'],
            'article_type' => $data['article_type'],
            'journal' => $data['journal'],
            'journal_issn' => $data['journal_issn'],
            'journal_eissn' => $data['journal_eissn'],
            'journal_lissn' => $data['journal_lissn'],
            'citation_count' => $data['citation_count'],
            'percentile_rank' => $data['percentile_rank'],
            'cover_date' => $data['cover_date'],
            'category' => $data['category'],
            'title' => $data['title'],
            'pages' => $data['pages'],
            'volume' => $data['volume'],
            'issue' => $data['issue'],
            'scopus_doc_id' => $data['scopus_doc_id'],
            'authors' => $data['authors'],
            'updated' => $timestamp
        ))
            ->condition('article_id', $article_id, '=')
            ->execute();
    }
    return $num_updated;
}

function populate_violin_author_article($data, $auth_id, $art_id)
{
    $auth_id = (int)($auth_id);
    $art_id = (int)($art_id);
    $is_first_or_last = (int)$data['is_first_or_last_author'];

    $author_article_id = "";

    // check if this relation exist already
    $chk_query = "
      select *
      from violin_wcmc_author_article a
      where a.author_id = $auth_id and a.article_id = $art_id ";

    $chk_record = db_query($chk_query)->fetchObject();
    if (!empty($chk_record->id)) {
        $author_article_id = $chk_record->id;
    } else {
        $timestamp = date("Y-m-d H:i:s");
        $author_article_id = db_insert('violin_wcmc_author_article')
            ->fields(array(
                'author_id' => $auth_id,
                'article_id' => $art_id,
                'is_first_or_last_author' => $is_first_or_last,
                'created' => $timestamp,
                'updated' => $timestamp
            ))
            ->execute();
    }
    return $author_article_id;
}

function populate_percentile_rank_field($node_id, $rank ,$op)
{

    $node = node_load($node_id); // 1 is node id we want to load

    // Change field value
    $node->field_percentile_rank[$node->language][0]['value'] = $rank;

    // Get the numeric id of your field by passing field name
    $info = field_info_field('field_percentile_rank');

    $fields = array($info['id']);

    // Execute the storage function
    if($op == "INSERT")
        field_sql_storage_field_storage_write('node', $node, 'insert', $fields);
    else
        field_sql_storage_field_storage_write('node', $node, 'update', $fields);

    // Clear field cache
    cache_clear_all("field:node:$node->nid", 'cache_field');

    return;
}

function populate_article_type_field($node_id, $type)
{

    $node = node_load($node_id); // 1 is node id we want to load

    // Change field value
    $node->field_article_type[$node->language][0]['value'] = $type;

    // Get the numeric id of your field by passing field name
    $info = field_info_field('field_article_type');

    $fields = array($info['id']);

    // Execute the storage function
    field_sql_storage_field_storage_write('node', $node, 'insert', $fields);

    // Clear field cache
    cache_clear_all("field:node:$node->nid", 'cache_field');

    return;
}

function populate_category_field($node_id, $categories)
{

    if (count($categories) > 0) {

        $node = node_load($node_id);

        // Get the numeric id of your field by passing field name
        $info = field_info_field('field_category');

        $fields = array($info['id']);

        $count = 0;
        foreach ($categories as $item) {
            // Change field value
            $node->field_category[$node->language][$count]['value'] = $item;
            $count++;
        }

        // Execute the storage function
        field_sql_storage_field_storage_write('node', $node, 'insert', $fields);

        // Clear field cache
        cache_clear_all("field:node:$node->nid", 'cache_field');
    }
    return;
}

// get article authors
function get_article_authors($node_id)
{
    $node_id = (int)$node_id;
    $article_authors = "";
    return $article_authors;
}

// get the journal issn for this publication
function get_journal_issn($node_id)
{
    $node_id = (int)$node_id;
    $issn_query = "
        select i.field_issn_value
        from field_data_field_journal j
        left join field_data_field_issn i on i.entity_id =  j.field_journal_tid
        left join taxonomy_index t on t.tid =  j.field_journal_tid
        where t.nid = $node_id
    ";

    $issn_record = db_query($issn_query);
    $journal_issn = $issn_record->fetchField();
    return $journal_issn;
}

// get the journal eissn for this publication
function get_journal_eissn($node_id)
{
    $node_id = (int)$node_id;
    $eissn_query = "
        select i.field_eissn_value
        from field_data_field_journal j
        left join field_data_field_eissn i on i.entity_id =  j.field_journal_tid
        left join taxonomy_index t on t.tid =  j.field_journal_tid
        where t.nid = $node_id
    ";

    $eissn_record = db_query($eissn_query);
    $journal_eissn = $eissn_record->fetchField();
    return $journal_eissn;
}

// get the journal lissn for this publication
function get_journal_lissn($node_id)
{
    $node_id = (int)$node_id;
    $lissn_query = "
        select i.field_lissn_value
        from field_data_field_journal j
        left join field_data_field_lissn i on i.entity_id =  j.field_journal_tid
        left join taxonomy_index t on t.tid =  j.field_journal_tid
        where t.nid = $node_id
    ";

    $lissn_record = db_query($lissn_query);
    $journal_lissn = $lissn_record->fetchField();
    return $journal_lissn;
}

// get the journal for this publication
function get_journal_name($node_id)
{
    $node_id = (int)$node_id;

    $journal_query = "
        select t.name
        from field_data_field_journal j
        left join taxonomy_term_data t on t.tid =  j.field_journal_tid
        where j.entity_id = $node_id and t.vid = 4
    ";

    $journal_record = db_query($journal_query);
    $journal_name = $journal_record->fetchField();

    return $journal_name;
}

function get_article_type($node_id)
{
    //RDF types
    $academic_article_types = array(
        'Academic Article'
    );
    $review_types = array(
        'Review'
    );

    $node_id = (int)$node_id;

    $type_query = "
        select t.name
        from field_data_field_rdf_type r
        left join taxonomy_term_data t on t.tid =  r.field_rdf_type_tid
        where r.entity_id = $node_id and r.bundle = 'publication'
        and t.vid = 6
    ";

    // var_dump($type_query);

    $type_record = db_query($type_query)->fetchAll();

    $type_name = "";
    foreach ($type_record as $row) {
        if (in_array($row->name, $academic_article_types)){
            $type_name = "Academic Article";
            break;
        }else if (in_array($row->name, $review_types)) {
            $type_name = "Review";
            break;
        }
    }

    $article_type = "";
    switch ($type_name) {
        case 'Academic Article':
            $article_type = "Academic Article";
            break;
        case 'Review':
            $article_type = "Review";
            break;
        default:
            break;
    }
    return $article_type;
}

//get issn for the journal
function get_journal_record($journal_issn = '', $journal_eissn = '', $journal_lissn = '')
{

    $journal_issn = addslashes($journal_issn);
    $journal_eissn = addslashes($journal_eissn);
    $journal_lissn = addslashes($journal_lissn);

    // get journal record using issn
    if (!empty($journal_issn)) {
        $journal_query = "select * from violin_journal v  where v.issn = '$journal_issn' ";
        $journal_record = db_query($journal_query)->fetchObject();
        if (!empty($journal_record->journal_id)) {
            return $journal_record;
        }
    }

    // get journal record using eissn
    if (!empty($journal_eissn)) {
        $journal_query = "select * from violin_journal v  where v.issn = '$journal_eissn' ";
        $journal_record = db_query($journal_query)->fetchObject();
        if (!empty($journal_record->journal_id)) {
            return $journal_record;
        }
    }

    // Look for journal record using violin_NLM tables
    // First, use $journal_issn to get nlmeissn and use that value to get journal reocord
    if (!empty($journal_issn)) {
        $nlm_eissn = "";
        $nlm_eissn_query = "select nlmeissn from violin_NLM n  where n.nlmissn = '$journal_issn' ";
        $nlm_eissn = db_query($nlm_eissn_query)->fetchField();
        if (!empty($nlm_eissn)) {
            $journal_query = "select * from violin_journal v  where v.issn = '$nlm_eissn' ";
            $journal_record = db_query($journal_query)->fetchObject();
            if (!empty($journal_record->journal_id)) {
                return $journal_record;
            }
        }
    }

    // Next, use $journal_eissn to get nlmissn and use that value to get journal reocord
    if (!empty($journal_eissn)) {
        $nlm_issn = "";
        $nlm_issn_query = "select nlmissn from violin_NLM n  where n.nlmeissn = '$journal_eissn' ";
        $nlm_issn = db_query($nlm_issn_query)->fetchField();
        if (!empty($nlm_issn)) {
            $journal_query = "select * from violin_journal v  where v.issn = '$nlm_issn' ";
            $journal_record = db_query($journal_query)->fetchObject();
            if (!empty($journal_record->journal_id)) {
                return $journal_record;
            }
        }
    }

    // get journal reccord using lissn. Since there are no lissn in vivo, this normally doesn't yield any result.
    // Keeping it here for completness.
    if (!empty($journal_lissn)) {
        $journal_query = "select * from violin_journal v  where v.issn = '$journal_lissn' ";
        $journal_record = db_query($journal_query)->fetchObject();
        if (!empty($journal_record->journal_id)) {
            return $journal_record;
        }
    }


}

// get issn for the journal
function get_journal_record_by_type($type, $journal_id)
{
    $type = addslashes($type);
    $journal_id = addslashes($journal_id);
    switch ($type) {
        case 'issn':
            $journal_query = "select * from violin_journal v  where v.issn = '$journal_id' ";
            break;
        case 'eissn':
            $journal_query = "select * from violin_journal v  where v.issn = '$journal_id' ";
            break;
        case 'lissn':
            $journal_query = "select * from violin_journal v  where v.issn = '$journal_id' ";
            break;
    }
    $journal_record = db_query($journal_query)->fetchObject();
    return $journal_record;
}

function get_journal_category($journal_id)
{
    $categories = array();
    $journal_id = (int)$journal_id;
    $cat_query = "
      select c.*
      from violin_category c
      left join violin_journal_category jc on jc.category_id =  c.category_id
      where jc.journal_id = $journal_id ";

    $category_record = db_query($cat_query)->fetchAll();

    $ids = array();
    $names = array();

    foreach ($category_record as $row) {
        $ids[] = $row->category_id;
        $names[] = $row->category;
    }

    $categories['ids'] = $ids;
    $categories['names'] = $names;

    return $categories;
}

function get_journal_category_by_title($journal_title)
{
    $categories = array();
    $journal_title = addslashes($journal_title);
    $cat_query = "
      select c.*
      from violin_category c
      left join violin_journal_category jc on jc.category_id =  c.category_id
      left join violin_journal j on j.journal_id = jc.journal_id
      where j.journal_title = '" . $journal_title . "'";

    $category_record = db_query($cat_query)->fetchAll();

    $ids = array();
    $names = array();

    foreach ($category_record as $row) {
        $ids[] = $row->category_id;
        $names[] = $row->category;
    }

    $categories['ids'] = $ids;
    $categories['names'] = $names;

    return $categories;
}

function get_first_or_last_author($author_id, $pub_id)
{
    $author_id = (int)$author_id;
    $pub_id = (int)$pub_id;

    $first_or_last = false;
    $ckh_query = "
        select p.field_author_position_value
        from field_data_field_author_position p
        where p.entity_id = (
            select e.entity_id
            from field_data_endpoints e
            left join node n on n.nid =  e.endpoints_entity_id
            where e.endpoints_entity_id = $pub_id and e.entity_id = $author_id
        )
    ";
    $chk_record = db_query($ckh_query)->fetchObject();

    if (isset($chk_record->field_author_position_value)) {
        if (($chk_record->field_author_position_value == 'first') or ($chk_record->field_author_position_value == 'first')) {
            $first_or_last = true;
        }
    }

    return $first_or_last;
}

function calculate_percentile_rank($cites, $pmid = "", $type = "", $cat = "", $date="")
{

    $rank = 0;
    $type = addslashes($type);
    $cat = addslashes($cat);
    $date = addslashes($date);
    $year = '';
    if(!empty($date)) {
        // extract year from date
        $parts = explode('-', $date);
        $year = $parts[0];

        $to_year = date('Y', strtotime('-3 years'));
        $from_year = date('Y', strtotime('-12 years'));


        if($year < $from_year || $year > $to_year) {
            return null;
        }
    }

    // check if the article exist in reference set with the same pmid, then return the percentile rank.
    if (!empty($pmid)) {
        $query = "";
        $query .= " select * from violin_baseline where pmid = $pmid";
        $query .= " limit 1";
        $record = db_query($query)->fetchObject();
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
                $record = db_query($query)->fetchObject();
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

    $record = db_query($query)->fetchObject();
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

    $record = db_query($query)->fetchObject();
    if (isset($record->percentile_rank)) {
        $rank = $record->percentile_rank;
        return $rank;
    }

    return $rank;
}