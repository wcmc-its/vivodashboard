<?php

/**
 * Implements hook_views_pre_render().
 */
function vivodashboard_publications_views_pre_render($view) {

  // Hides the result of the publications_graphs view. The actual display
  // of graphs is done with Facet API Graphs.
  if ($view->name == 'publications_graph') {
    $view->result = array();
  }

  // Attach Download buttons to data export views.
  $data_views = array('publications_export_csv', 'publications_export_doc');
  if (in_array($view->name, $data_views) && $view->display_handler->plugin_name == 'page') {

    $query = drupal_get_query_parameters();

    $max = $view->display_handler->options['items_per_page'];
    if (!empty($_GET['items_per_page'])) {
      $max = (int) $_GET['items_per_page'];
    }

    $single_page = FALSE;
    $total = !empty($view->total_rows) ? $view->total_rows : NULL;
    if ($total && $total < $max) {
      $max = $total;
      $single_page = TRUE;
    }

    // Can't depend on current_path() because it might be shortened to
    // something like /publications/export (no format) by the menu system.
    $path = !empty($view->display_handler->options['path']) ? $view->display_handler->options['path'] : current_path();

    // Build up a query parameter that will contain the final destination URL,
    // which gets carried through the batch process.
    // Again, can't use current_path() so pull the path from the options.
    $query['return'] = $view->display['download_all']->display_options['return_path'] . '?' . drupal_http_build_query($query);

    $link1 = l("Download $max items", "$path/download", array('query' => $query, 'attributes' => array('class' => array('button', 'button-download'))));
    $link2 = l("Download all items", "$path/download/all", array('query' => $query, 'attributes' => array('class' => array('button', 'button-download'))));
    $view->attachment_before = ($single_page) ? $link1 : $link1 . ' ' . $link2;
  }
}

/**
 * Implements hook_views_pre_view().
 */
function vivodashboard_publications_views_pre_view(&$view, $display_id, $args) {
  $data_views = array('publications_export_csv', 'publications_export_doc');

  // Override the items per page for the data export based on what the user
  // had selected in the page display.
  if (in_array($view->name, $data_views) && $display_id == 'download' && !empty($_GET['items_per_page']) && is_numeric($_GET['items_per_page'])) {
    $view->display_handler->options['pager']['options']['items_per_page'] = (int) $_GET['items_per_page'];
  }

  // If we're doing a batch export set the return URL. To actually parse this
  // URL properly we have to override the default theme function.
  // @see vivodashboard_publications_views_data_export_complete_page()
  if (in_array($view->name, $data_views) && $display_id == 'download_all' && !empty($_GET['return'])) {
    $view->display_handler->options['return_path'] = $_GET['return'];
  }
}

/**
 * Implements hook_views_data_alter().
 *
 * Use our special views field handlers for certain properties of publications.
 */
function vivodashboard_publications_views_data_alter(&$data) {
  $data['search_api_index_publications']['authorships']['field']['handler'] = 'vivodashboard_publications_field_handler_authorship';
  $data['search_api_index_publications']['authors']['field']['handler'] = 'vivodashboard_publications_field_handler_authorship';
  $data['search_api_index_publications']['title']['field']['handler'] = 'vivodashboard_publications_field_handler_title';
  $data['search_api_index_publications']['author_labels']['field']['handler'] = 'vivodashboard_publications_field_handler_title';
}
