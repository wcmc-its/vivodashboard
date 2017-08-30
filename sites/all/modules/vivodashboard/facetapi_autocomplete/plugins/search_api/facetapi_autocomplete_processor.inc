<?php

/**
 * Search API processor plugin.
 *
 * This plugin alters the query results for autocomplete facets before
 * FacetAPI gets a chance to build facets. Since there is no limit on the
 * query the quantity of results can get very large, and Facet API will slow
 * things down by running FacetapiProcessor::initializeBuild() on tens of
 * thousands of results. So we do our keyword matching as early as possible
 * to keep things relatively fast.
 *
 * @see facetapi_autocomplete_search_api_query_alter()
 */
class FacetapiAutocompleteSearchApiProcessor extends SearchApiAbstractProcessor
{

    public function postprocessSearchResults(array &$response, SearchApiQuery $query)
    {
        $autocomplete_facet = drupal_static('facetapi_autocomplete_active_facet');

        if ($autocomplete_facet && isset($response['search_api_facets'][$autocomplete_facet])) {
            $new_results = array();
            $results = $response['search_api_facets'][$autocomplete_facet];

            $keywords = explode(' ', strtoupper(trim($_GET['keywords'])));

            // Filter by those names in wcmc_authors
//            $wcmc_authors = $this->get_wcmc_authors();
//            $wcmc_results = array();
//            foreach ($results as $k => $item) {
//                $value = strtoupper($item['filter']);
//                foreach ($wcmc_authors as $author) {
//                    if (strpos($value, $author) === FALSE) {
//                        continue(2);
//                    }
//                }
//                $wcmc_results[] = $item;
//            }

            foreach ($results as $k => $item) {
                $value = strtoupper($item['filter']);
                // Perform a very basic string match on the indexed and rendered values.
                foreach ($keywords as $keyword) {
                    // If any of the keywords don't match, move on to next facet item.
                    if (strpos($value, $keyword) === FALSE) {
                        continue(2);
                    }
                }
                $new_results[] = $item;
            }

            // @todo - Make configureable?
            $response['search_api_facets'][$autocomplete_facet] = array_slice($new_results, 0, 100);

        }
    }

    public function configurationForm()
    {
        return FALSE;
    }

    public function get_wcmc_authors(){
        $authors = array();
        $name_query = "
                select distinct a.field_last_name_value as author
                from field_data_field_last_name a
                where a.entity_id in (
                select e.entity_id
                from field_data_endpoints e
                join node n on n.nid = e.endpoints_entity_id
                join field_data_field_id i on i.entity_id = n.nid
                where n.type = 'author'
            )
            ";
        $name_result = db_query($name_query);
        $name_record = $name_result->fetchAll;
        foreach ($name_record as $row) {
            $authors[] = strtoupper($row->author);
        }
        return $authors;
    }

}
