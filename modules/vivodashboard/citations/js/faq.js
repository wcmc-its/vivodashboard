(function ($) {

    Drupal.behaviors.violin = { attach: function (select, settings) {

        var linksToMain = jQuery('a[href="/citations/main"]');
        linksToMain.addClass("active");

    } }
})(jQuery);