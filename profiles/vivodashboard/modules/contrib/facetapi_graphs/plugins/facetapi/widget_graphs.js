(function ($) {
  Drupal.behaviors.facetapi_graphs_form = {
    attach: function(context) {

      $('#edit-engine', context).change(function() {

        var engine    = this.value,
          className = 'facetapi_graphs_' + engine + '_chart_types',
          hidden    = 'facetapi_graphs_chart_types_hidden';

        $('div.facetapi_graphs_chart_types', context).each(function() {

          $this = $(this);

          if ($this.hasClass(className)) {
            $this.removeClass(hidden);
          } else {
            $this.addClass(hidden);
          };
        });
      });
    }
  };
})(jQuery);
