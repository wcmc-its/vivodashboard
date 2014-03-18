(function($) {

  /**
   * Loads the Chosen plugin for FacetAPI Multiselect elements.
   */
  Drupal.behaviors.VivodashboardCoreFacetApiMultiselectWidget = {
    attach: function (context, settings) {
      $('.facetapi-multiselect', context).each(function () {
        $(this).chosen({
          width: "100%"
        })
      })
    }
  }

})(jQuery);
