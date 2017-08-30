(function($){
  Drupal.behaviors.facetapi_multiselect = {
    attach: function (context, settings) {
      $('form[id^="facetapi-multiselect-form"] .form-submit', context).hide();
      $('form[id^="facetapi-multiselect-form"] select', context).change(function () {
        $(this).closest('form').submit();
      });
    }
  };
})(jQuery);
