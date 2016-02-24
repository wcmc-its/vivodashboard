<?php

function citations_views_query_alter(&$view, &$query) {
    if ($view->name == 'citations_chart') {
        // drupal_set_message($view->build_info['query']);
        $alias = $query->add_table('field_data_field_id');
        $query->add_where_expression(0, $alias . '.field_id_value', NULL,  'not empty');

    }
}
