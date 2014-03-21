(function($) {

  /**
   * Adds tooltips on hover to flot graphs.
   */
  Drupal.behaviors.VivodashboardCoreChartsGraphsBehavior = {
    attach: function (context, settings) {
      var element = $('<div class="flot-tooltip"></div>').appendTo('body');

      $('.flot', context).each(function () {
        var graph = $(this);
        var bar, offsetX, offsetY = null;

        graph.unbind('plothover').bind('plothover', function (event, pos, item) {
          if (item && bar != item.dataIndex) {
            bar = item.dataIndex;

            // Data might be a small decimal, like 0.01, in order to show a
            // partial bar instead of a no bar. In that case, we want
            // to call it zero.
            var value = Math.floor(item.datapoint[1]);

            // When ticks on the xaxis have been disabled, add the tick label
            // to the tooltip.
            var tick = item.series.xaxis.options.ticks[item.dataIndex];
            if (item.series.xaxis.options.show === false && tick !== undefined) {
              value = tick[1] + ': ' + value;
            }

            element.text(value);

            // Position the element at the exact top center of the bar.
            offsetX = element.outerWidth() / 2;
            offsetY = element.outerHeight() / 2;
            element.css({ top: item.pageY - offsetY, left: item.pageX - offsetX }).show();
          }
          else if (!item) {
            bar = null;
            element.text('').hide();
          }
        })
      })
    }
  }

})(jQuery);
