(function($, Drupal) {

  /**
   * Drupal behaviors for D3 module.
   */
  Drupal.behaviors.citation_lookup = {
    
    validateForm: function() {
      var excl=$('input#excelfile-ul');
    	return this.checkfile(excl);
    },
    
    checkfile: function (sender) {
        var validExts = new Array(".xlsx", ".xls", ".csv");
        var fileExt = sender.val();
        fileExt = fileExt.substring(fileExt.lastIndexOf('.'));
        if (validExts.indexOf(fileExt) < 0) {
          alert("Invalid file selected, valid files are of " +
                   validExts.toString() + " types.");
          sender.val("");
          return false;
        }
        else return true;
    },
    
    attach: function(context, settings) {
      
      var body = document.body, html = document.documentElement;
      var height = Math.max( body.scrollHeight, body.offsetHeight, 
              html.clientHeight, html.scrollHeight, html.offsetHeight );

      var reportId = document.getElementById('reportId') || false;
      if(reportId) {
        reportId.style.height=(height-150)+"px";
        $('#main').css('width', '100%');
        $("#citationTblId").treetable({ expandable: true });
      }
    }
  };

})(jQuery, Drupal);