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
$output = explode('|', $output);

$authors = explode(', ', $output[0]);

$has_params = isset($_GET['f']) ? $_GET['f'] : '';
$has_authors = array();
foreach ($has_params as $param) {
	if(strpos($param, 'publication_author_names') !== false){
		$author_name = str_replace('publication_author_names:', '', $param);
		$wcmc_author = explode(' - ', $author_name);
		$wcm_author = explode(' ', $wcmc_author[0]);

		$full_name = '';
		$full_name .= $wcm_author[count($wcm_author)-1] . ' ' . substr($wcm_author[0], 0 , 1);
		/*
		for ($i=count($wcm_author) - 1; $i >= 0; $i--) {
			$full_name .= $wcm_author[$i];
			if($i > 0) {
				$full_name .= ' ';
			}

		}
		//*/
		$has_authors[] = $full_name;
		// $has_authors[] = $author_name;
		/*if(in_array($author_name, $authors)){
			print '<strong>'.$author_name.'</strong>, ';
		} else {
			print $param . ', ';
		}*/
	}
}

$count = 0;
foreach ($authors as $author) {
	$res = db_query('SELECT n.title as title, i.field_id_value as cwid, f.field_first_name_value as first_name, l.field_last_name_value as last_name FROM {node} n LEFT JOIN {field_data_field_first_name} f ON n.nid = f.entity_id LEFT JOIN {field_data_field_last_name} l ON n.nid = l.entity_id LEFT JOIN {field_data_field_id} i ON n.nid = i.entity_id WHERE n.title = :author_name', array(':author_name'=> $author ))->fetchObject();

	$author_query_name = $res->last_name . ' ' . substr($res->first_name, 0, 1);

	if(in_array($author_query_name, $has_authors)) {
		print '<strong>' . $author_query_name . '</strong>';
	} else {
		print $author_query_name;
	}

	/*if(in_array($author, $has_authors)) {
		$author_info = explode(' ', $author);
		if(count($author_info) > 2) {
			print '<strong>'.$author_info[0] . ' ' . substr($author_info[1], 0 , 1) .'</strong>';
		} else {
			print '<strong>'.$author_info[0] . ' ' . substr($author_info[1], 0 , 1) .'</strong>';
		}
		// print '<strong>'.$author.'</strong>';
	} else {
		$author_info = explode(' ', $author);
		if(count($author_info) > 2) {
			print $author_info[0] . ' ' . substr($author_info[1], 0 , 1);
		} else {
			print $author_info[0] . ' ' . substr($author_info[1], 0 , 1);
		}
		// print $author;
	}*/

	if($count < count($authors) - 1) {
		print ', ';
	}

	$count++;
}
print '.'; 
print $output[1];

?>