(function($) {

  /**
   * Watches ranges sliders for changes and updates a display.
   *
   * @see search_api_ranges.js
   */
  Drupal.behaviors.VivodashboardCoreRangeSliderDisplay = {
    attach: function (context, settings) {
      var yearFacet = 'search-api-ranges-publication_year';
      var monthFacet = 'search-api-ranges-publication_month';
      var months = ['', 'Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sept', 'Oct', 'Nov', 'Dec'];

      $('.search-api-ranges-widget', context).each(function () {
        var widget = $(this);
        var id = widget.attr('id');
        var slider = widget.find('.range-slider');
        var display = widget.find('.text-range').empty();
        var loading = $('<span class="loader"></span>').hide();

        var from = widget.find('input[name="range-from"]');
        var to = widget.find('input[name="range-to"]')
        var thisYear = new Date().getFullYear();

        var updateDisplay = function(start, end) {
          // Custom formatting for year values.
          if (id == yearFacet && end == thisYear) {
            end = 'Present';
          }

          // Custom formatting for month values.
          if (id == monthFacet && months[start] !== undefined) {
            start = months[start];
          }
          if (id == monthFacet && months[end] !== undefined) {
            end = months[end];
          }

          display.text(start + ' - ' + end);
        }

        updateDisplay(from.val(), to.val());
        loading.insertAfter(display);

        slider.on('slide change', function(event, ui) {
          updateDisplay(ui.values[0], ui.values[1]);
        });

        widget.find('form').submit(function() {
          display.empty();
          loading.show();
        });
      });
    }
  }

})(jQuery);
