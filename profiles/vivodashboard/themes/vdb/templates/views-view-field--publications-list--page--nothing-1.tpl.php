<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php 

$output = explode('</div>', $output);

$authors = strip_tags($output[0]);

$auth_names = explode(', ', html_entity_decode($authors,ENT_QUOTES) );
$author_names = array();

$author_search = implode(',', $auth_names);

foreach ($auth_names as $value) {
	$query = db_query('SELECT n.title as title, i.field_id_value as cwid, f.field_first_name_value as first_name, l.field_last_name_value as last_name FROM {node} n LEFT JOIN {field_data_field_first_name} f ON n.nid = f.entity_id LEFT JOIN {field_data_field_last_name} l ON n.nid = l.entity_id LEFT JOIN {field_data_field_id} i ON n.nid = i.entity_id WHERE n.title = :author_names GROUP BY n.title', array(':author_names'=> $value ))->fetchObject();

	if(!empty($query->title)) {
		if($query->cwid != '') {
			$first_name_split = explode(' ', $query->first_name);

			$full_name = $query->last_name . ' ';
			// print_r($first_name_split);
			foreach ($first_name_split as $fname_initial) {
				$full_name .= substr($fname_initial, 0, 1);
			}
			$author_names[] = $full_name;
		} else {
			$auth_name = explode(' ', $value);
			if(count($auth_name) > 2) {
				$author_names[] = $auth_name[0] . ' ' . substr($auth_name[1], 0, 1) . '' . substr($auth_name[2], 0, 1);

			} else {
				$author_names[] = $auth_name[0] . ' ' . substr($auth_name[1], 0, 1);
			}
		}
	}
}

$article_title = strip_tags(str_replace('<div>', '', $output[1]));
$journal = strip_tags($output[2]);
$year = strip_tags($output[3]);
$volume = trim(strip_tags($output[4]));
$issue = trim(strip_tags($output[5]));
$page_start = trim(strip_tags($output[6]));
$page_end = trim(strip_tags($output[7]));

$pages = '';
if($page_start != '') {
	$pages = ':'.$page_start; // . "-" . $page_end .'.';
}

$pmid = trim(strip_tags($output[8]));
if($pmid != '') {
	$pmid = '. ' . str_replace('PMID', 'PMID: ', $pmid) . '.';
}

$pmcid = trim(strip_tags($output[10]));
if($pmcid != '') {
	$pmcid = str_replace('; ', '', $pmcid) . '.';
}

$qtip_output = '<div class="field-citations-qtip"><div class="qtip-citation" title="'.implode(', ', $author_names) .'. <span class=\'field-pub-title\'>' . $article_title .'</span>' . $journal . $year . $volume . $issue . $pages . $pmid . $pmcid.'">Citation <span>+</span></div></div>';

print $qtip_output;

?>