(function ($) {

/**
 * Overides Facet API's behavior to keep facets open when they're
 * specified in the URL fragment.
 *
 * @see facetapi.js
 * @see vivodashboard_core_preprocess_facetapi_link_inactive()
 */
Drupal.facetapi.applyLimit = function(settings) {
  if (settings.limit > 0 && !$('ul#' + settings.id).hasClass('facetapi-processed')) {
    // Only process this code once per page load.
    $('ul#' + settings.id).addClass('facetapi-processed');

    // Ensures our limit is zero-based, hides facets over the limit.
    var limit = settings.limit - 1;

    var open = false;
    if (settings.facetName && window.location.hash && "#" + settings.facetName == window.location.hash) {
      open = true;
    }

    if (!open) {
      $('ul#' + settings.id).find('li:gt(' + limit + ')').hide();
    }

    var linkText = (open) ? Drupal.t('Show less') : Drupal.t('Show more');

    // Adds "Show more" / "Show fewer" links as appropriate.
    $('ul#' + settings.id).filter(function() {
      return $(this).find('li').length > settings.limit;
    }).each(function() {
      $('<a href="#" class="facetapi-limit-link"></a>').text(linkText).click(function() {
        if ($(this).prev().find('li:hidden').length > 0) {
          $(this).prev().find('li:gt(' + limit + ')').slideDown();
          $(this).addClass('open').text(Drupal.t('Show fewer'));
        }
        else {
          $(this).prev().find('li:gt(' + limit + ')').slideUp();
          $(this).removeClass('open').text(Drupal.t('Show more'));
        }
        return false;
      }).insertAfter($(this));
    });
  }
}

})(jQuery);
