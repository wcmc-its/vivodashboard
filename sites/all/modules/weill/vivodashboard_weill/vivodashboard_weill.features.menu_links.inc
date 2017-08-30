<?php
/**
 * @file
 * vivodashboard_weill.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function vivodashboard_weill_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_citation-impact:citations/main.
  $menu_links['main-menu_citation-impact:citations/main'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'citations/main',
    'router_path' => 'citations/main',
    'link_title' => 'Citation Impact',
    'options' => array(
      'attributes' => array(
        'title' => 'Citation impact as a pictograph',
      ),
      'identifier' => 'main-menu_citation-impact:citations/main',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: main-menu_citation-lookup-tool:citation_lookup.
  $menu_links['main-menu_citation-lookup-tool:citation_lookup'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'citation_lookup',
    'router_path' => 'citation_lookup',
    'link_title' => 'Citation Lookup Tool',
    'options' => array(
      'identifier' => 'main-menu_citation-lookup-tool:citation_lookup',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 0,
  );
  // Exported menu link: main-menu_export:publications/export.
  $menu_links['main-menu_export:publications/export'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications/export',
    'router_path' => 'publications/export',
    'link_title' => 'Export',
    'options' => array(
      'identifier' => 'main-menu_export:publications/export',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_publications:publications',
  );
  // Exported menu link: main-menu_faq:citations/faq.
  $menu_links['main-menu_faq:citations/faq'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'citations/faq',
    'router_path' => 'citations/faq',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => 'Frequently asked questions for citations impact',
      ),
      'identifier' => 'main-menu_faq:citations/faq',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_citation-impact:citations/main',
  );
  // Exported menu link: main-menu_faq:publications/faq.
  $menu_links['main-menu_faq:publications/faq'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications/faq',
    'router_path' => 'publications/faq',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => 'Publications - Frequently Asked Questions',
      ),
      'identifier' => 'main-menu_faq:publications/faq',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_publications:publications',
  );
  // Exported menu link: main-menu_graph:publications.
  $menu_links['main-menu_graph:publications'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications',
    'router_path' => 'publications',
    'link_title' => 'Graph',
    'options' => array(
      'identifier' => 'main-menu_graph:publications',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_publications:publications',
  );
  // Exported menu link: main-menu_list:publications/list.
  $menu_links['main-menu_list:publications/list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications/list',
    'router_path' => 'publications/list',
    'link_title' => 'List',
    'options' => array(
      'identifier' => 'main-menu_list:publications/list',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_publications:publications',
  );
  // Exported menu link: main-menu_pictograph:citations/pictograph.
  $menu_links['main-menu_pictograph:citations/pictograph'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'citations/pictograph',
    'router_path' => 'citations/pictograph',
    'link_title' => 'Pictograph',
    'options' => array(
      'attributes' => array(
        'title' => 'Citation Impact as a pictograph',
      ),
      'identifier' => 'main-menu_pictograph:citations/pictograph',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_citation-impact:citations/main',
  );
  // Exported menu link: main-menu_publications:publications.
  $menu_links['main-menu_publications:publications'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications',
    'router_path' => 'publications',
    'link_title' => 'Publications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_publications:publications',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_violin-plot:citations/violinplot.
  $menu_links['main-menu_violin-plot:citations/violinplot'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'citations/violinplot',
    'router_path' => 'citations/violinplot',
    'link_title' => 'Violin Plot',
    'options' => array(
      'attributes' => array(
        'title' => 'Citation impact as a violin plot',
      ),
      'identifier' => 'main-menu_violin-plot:citations/violinplot',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_citation-impact:citations/main',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Citation Impact');
  t('Citation Lookup Tool');
  t('Export');
  t('FAQ');
  t('Graph');
  t('List');
  t('Pictograph');
  t('Publications');
  t('Violin Plot');

  return $menu_links;
}
