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
<?php //print $output; 
print '<strong>Author(s):</strong> ';

$authors = explode(', ', $output);
$author_name_info = array();
$count = 0;
foreach ($authors as $author) {
	preg_match('/href=(["\'])([^\1]*)\1/i', $author, $m);
	if(count($m) > 0) {
		$cwid = explode('-', $m[2]);
		$author_link = str_replace('-'.$cwid[1].'"', '-'.$cwid[1].'" onclick="return false;" class="qtip-author" data-cwid="'.$cwid[1].'"', $author);

		//*
		$author_name = explode('">', $author_link);
			
		$author_name_string = explode(' ', str_replace('</a>', '', $author_name[1]));

		$author_search_name = html_entity_decode(str_replace('</a>', '', $author_name[1]), ENT_QUOTES);

		$res = db_query('SELECT n.title as title, i.field_id_value as cwid, f.field_first_name_value as first_name, l.field_last_name_value as last_name FROM {node} n LEFT JOIN {field_data_field_first_name} f ON n.nid = f.entity_id LEFT JOIN {field_data_field_last_name} l ON n.nid = l.entity_id LEFT JOIN {field_data_field_id} i ON n.nid = i.entity_id WHERE n.title = :author_name', array(':author_name'=> $author_search_name ))->fetchObject();

		if(!empty($res->title)) {
			print '<a href="#'.$res->cwid.'" onclick="return false;" class="qtip-author" data-cwid="'.$res->cwid.'">' . $res->first_name . ' ' . $res->last_name .'</a>';
		}

	} else {
		$author_name = explode(' ', $author);

		if(count($author_name) > 2) {
			print $author_name[1] . ' ' . $author_name[2] . ' ' . $author_name[0];
		} else {
			print $author_name[1] . ' ' . $author_name[0];
		}
	}

	if($count < count($authors) - 1) {
		print ', ';
	}

	$count++;
}

print '<br>';
?>