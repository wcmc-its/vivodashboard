(function($) {

  /**
   * Initializes the Select2 plugin for FacetAPI Autocomplete elements.
   */
  Drupal.behaviors.FacetapiAutocompleteWidget = {
    attach: function (context, settings) {
      $('.facetapi-autocomplete', context).each(function () {
        var element = $(this);
        var url = element.attr('data-url');
        var path = element.attr('data-path');
        var facet = element.attr('data-facet');
        var params = JSON.parse(element.attr('data-params'));

        element.select2({
          multiple: element.attr('data-multiple'),
          width: '100%',
          minimumInputLength: 2,
          formatInputTooShort: function() {
              if (path.toLowerCase().indexOf("citations") >= 0){
                  return 'Enter an author name.';
              }else {
                  return 'Enter some keywords.';
              }
          },
          ajax: {
            url: url,
            dataType: 'json',
            data: function (term, page) {
              params.keywords = term;
              params.facet = facet;
              params.path = path;
              return params;
            },
            results: function (data, page) {
              return { results: data };
            },
            quietMillis: 1500
          },
        });

        element.on('change', function(event) {
          element.parents('form').submit();
        })
      })
    }
  }

})(jQuery);
