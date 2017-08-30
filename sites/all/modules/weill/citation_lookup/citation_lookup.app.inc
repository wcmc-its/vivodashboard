<?php

require_once 'lib/FacultyDatabase/Classes/PHPExcel/IOFactory.php';
require_once 'lib/FacultyDatabase/Classes/dto/UserDTO.php';
require_once 'lib/FacultyDatabase/Classes/dto/Citation.php';
require_once 'lib/FacultyDatabase/PubMedAPI.php';
require_once 'lib/FacultyDatabase/util/util.php';

define('VIVO_ANYSTYLE_IO_API_URL', 'https://anystyle.io/parse/references');


function citation_lookup_form($form, &$form_state, $fid = null) {

    $html = '';

  $css_dir = drupal_get_path('module', 'citation_lookup').'/lib/FacultyDatabase/css';
  $form['#attached']['css'] = array(
    //$css_dir.'/style.css' => array('basename' => 'citation-style.css'),
    $css_dir.'/tipr.css',
    $css_dir.'/jquery.treetable.css',
    $css_dir.'/jquery.treetable.theme.default.css',
    '#excelfile-ul-upload .form-submit {display: none}' => array('type' => 'inline'),
  );

  $js_dir = drupal_get_path('module', 'citation_lookup').'/lib/FacultyDatabase/js';
  $form['#attached']['js'] = array(
    $js_dir.'/vendor/modernizr-2.6.2.min.js',
    $js_dir.'/tipr.js',
    $js_dir.'/jquery.js',
    $js_dir.'/jquery.treetable.js',
    drupal_get_path('module', 'citation_lookup').'/citation_lookup.app.js',
  );

  $table = '';
  if(isset($form_state['table'])) {
    $table = $form_state['table'];
  }
  else if($fid) {
    $file = file_load($fid);
    $table = citation_lookup_table_from_xlsx($file);
  }

  if(empty($table)) {
    $file_link = l('this format', drupal_get_path('module', 'citation_lookup') . '/CitationLookupDemo.xlsx');
    $pubmed_link = l('PubMed identifiers', 'http://www.ncbi.nlm.nih.gov/pubmed/');
    $github_link = l('here', 'https://github.com/wcmc-its/citationlookup');
    // $text = t('This service converts citations exactly as manually entered on a CV and returns !pubmed_link (PMIDs). If your citations are for a single user, paste them into the form below. Alternatively, you can upload a spreadsheet following !file_link as a guide. Learn more !github_link.', array('!pubmed_link' => $pubmed_link, '!github_link' => $github_link, '!file_link' => $file_link));
    //$text = t('This service converts citations exactly as manually entered on a CV and returns !pubmed_link (PMIDs). It is designed to identify citations from free-text data, and will accommodate citations represented in a variety of formats. If your citations are for a single author or you don\'t need to distinguish between citations by more than one specific author, paste them into the form below. Alternatively, you can upload a spreadsheet following !file_link as a guide. Learn more !github_link.', array('!pubmed_link' => $pubmed_link, '!github_link' => $github_link, '!file_link' => $file_link));
    $html .= '<div class="notification">
      <b>About the Citation Lookup Tool</b>
      <div style="position:absolute; right: 5px; top: 10px; width: 20px; height: 20px; text-align:center; cursor:pointer; border: 1px solid; border-radius: 50%; line-height: 18px;" class="notification-open">+</div>
      <div style="position:absolute; right: 5px; top: 10px; width: 20px; height: 20px; text-align:center; cursor:pointer; border: 1px solid; border-radius: 50%; line-height: 18px; display:none;" class="notification-close">-</div>
      <p id = "notification-text" style="display:none;">This service converts citations exactly as manually entered on a CV and returns <a href="http://www.ncbi.nlm.nih.gov/pubmed/" class="notification-text">PubMed identifiers</a> (PMIDs). It is designed to identify citations from free-text data, and will accommodate citations represented in a variety of formats. If your citations are for a single author or you don\'t need to distinguish between citations by more than one specific author, paste them into the form below. Alternatively, you can upload a spreadsheet following '.$file_link.' as a guide. Learn more <a href="https://github.com/wcmc-its/citationlookup" class="notification-text"> here</a>.</p></div>';


      $form['head']['#markup'] = '<p>' . $html . '</p>';
    $form['upload'] = array(
      '#type' => 'fieldset',
      '#title' => t('Upload Citation Data'),
      'pasted' => array(
        '#type' => 'textarea',
        '#id' => 'pasted-data',
        '#title' => t('Paste citations here'),
        '#description' => t('One citation per line')
      ),
      'process' => array(
        '#type' => 'submit',
        '#name' => 'pasted-button',
        '#value' => 'Convert pasted citations',
      ),
      'or' => array(
        '#type' => 'container',
        array('#markup' => '<h3>Or</h3>'),
      ),
      'excelfile' => array(
        '#type' => 'managed_file',
        '#id' => 'excelfile-ul',
        '#title' => t('Browse and Upload Your File'),
        '#upload_location' => "temporary://citation_lookup/",
        "#upload_validators" => array("file_validate_extensions" => array("xlsx xls csv")),
      ),
      'upload' => array(
        '#type' => 'submit',
        '#value' => 'Convert uploaded file',
        '#name' => 'upload',
        '#attributes' => array(
          'onclick' => "return Drupal.behaviors.citation_lookup.validateForm()",
        ),
      ),
    );
  }
  else {
    $form['download_csv'] = array(
      '#type' => 'submit',
      '#name' => 'download_csv',
      '#value' => t('Download CSV'),
    );
    
    $form['reset'] = array(
      '#type' => 'submit',
      '#name' => 'reset',
      '#value' => t('Reset'),
    );
    
    $form['table'] = $table;
  }

	return $form;
}


function citation_lookup_form_submit($form, &$form_state) {
  
  if($form_state['triggering_element']['#name'] == 'reset') {
    unset($form_state);
    return;
  }
  
  if ($form_state['triggering_element']['#name'] == 'download_csv' 
  && !empty($form_state['anystyle'])) {   
    
    $table_data = citation_lookup_table_from_data($form_state['anystyle']);
    $table_data['#theme'] = 'format_csv';
    
    $data = render($table_data);
         
    $temp_name = drupal_tempnam('temporary://', 'file').'.csv';
    if (file_put_contents($temp_name, $data)) {
      $headers = array(
        'Content-Type' =>  file_get_mimetype( $temp_name ),
        'Content-Length' => filesize($temp_name),
        'Cache-Control' => 'private',
        'Content-Disposition' => 'attachment; filename="' . 'citations.csv' . '"',
      );
      file_transfer($temp_name, $headers);  
      drupal_exit();
    }    
  }
  
  $anystyle = '';
  
  if($form_state['triggering_element']['#name'] == 'upload') {
    if($form_state['values']['excelfile']) {
      $file = file_load($form_state['values']['excelfile']);
      $anystyle = citation_lookup_anystyle_from_xlsx($file);
    }
  }
  
  if($form_state['triggering_element']['#name'] == 'pasted-button') {
    if(!empty($form_state['values']['pasted'])) {
      $anystyle = citation_lookup_anystyle_from_text($form_state['values']['pasted']);    
    }
  }
  
  if(!empty($anystyle)) {      
    $form_state['anystyle'] = $anystyle;
    $form_state['table'] = citation_lookup_table_from_data($anystyle);
    $form_state['rebuild'] = TRUE;
  }
  
}

function citation_lookup_anystyle_from_text($text) {

  $text = preg_split('/\r\n|[\r\n]/', $text);
  $text = array_values(array_filter($text));
  
  //If there are short lines, make them part of the previous line.
  //Line 0 should never be considered "short" though.
  $cut_line_threshold = 90;
  
  for($i = 0; ($i < sizeof($text)) ; $i++) {    
    if(isset($text[$i - 1]) && strlen($text[$i]) < $cut_line_threshold) {
      $text[$i - 1] .= " ".$text[$i];
      unset($text[$i]);
      
      //Reset the array and continue the process from the start
      $text = array_values($text);
      $i=0;
    }    
  }
  
  $userArr = array();
  $ch = curl_init(VIVO_ANYSTYLE_IO_API_URL);
  foreach($text as $line) {  
    $fake_row = array(
      'A' => null,
      'B' => $line,
    );    
    $userArr[] = getUserDataObject($fake_row,$ch);
  }  
  curl_close($ch);
  
  return $userArr;
}

function citation_lookup_anystyle_from_xlsx($file) {

  $out = '';

	$userArr = array();
	try {
  	$filepath = drupal_realpath($file->uri);
		$objTpl= PHPExcel_IOFactory::load($filepath);
		$objTpl->setActiveSheetIndex(0);
		$allDataInSheet = $objTpl->getActiveSheet()->toArray(null,true,true,true);
		$arrayCount = count($allDataInSheet);

		$ch = curl_init(VIVO_ANYSTYLE_IO_API_URL);
		if($arrayCount>2){
			//$i=2;
			for($i=2;$i<=20 && $i<=$arrayCount;$i++){
				$user = getUserDataObject($allDataInSheet[$i],$ch);
				array_push($userArr, $user);
			}
		}
		curl_close($ch);

	}
	catch(Exception $e) {
		die('Error loading file "'.pathinfo($filepath,PATHINFO_BASENAME).'": '.$e->getMessage());
	}
	
	return $userArr;
}

/**
 * Helper function with logic pulled from old code
**/
function _citation_lookup_format_anystyle_data($jobj) {
  $jout="";
	if(isset($jobj->author))$jout=getFormattedOutput($jobj->author,$jout,"Author");
	else if(isset($jobj->editor))$jout=getFormattedOutput($jobj->editor,$jout,"Author");
	if(isset($jobj->title))$jout=getFormattedOutput($jobj->title,$jout,"Title");
	if(isset($jobj->location))$jout=getFormattedOutput($jobj->location,$jout,"Location");
	if(isset($jobj->publisher))$jout=getFormattedOutput($jobj->publisher,$jout,"Publisher");
	if(isset($jobj->type))$jout=getFormattedOutput($jobj->type,$jout,"Type");
	if(isset($jobj->language))$jout=getFormattedOutput($jobj->language,$jout,"Language");
	
	return $jout;  
}


function citation_lookup_table_from_data($userArr) {
  
  $rows = array();
  foreach($userArr as $user) {
    $carr=$user->getCitationArray();
    foreach($carr as $cr) {
      
      $jobj=$cr->getJsonObject();
      
      
      $pobj=$cr->getPubMedResultArray();

      $pout = '';
  		if(count($pobj)){
            $arr_pmid = array();
  			foreach($pobj as $pr){

                $pubmed_link = '' ;
                $pubmed_link .= '<a href="http://www.ncbi.nlm.nih.gov/pubmed/?term=';
                $pubmed_link .= $pr["pmid"];
                $pubmed_link .= '"  ';
                $pubmed_link .= 'target="_blank">'.$pr["pmid"].'</a>';

                // $pout=$pout.$pr["pmid"]."<br />";
                $pout = $pout.$pubmed_link."<br />";
  			}
  		}
      
      $rows[] = array(
        'CWID' => $user->getCWID(),
        'Anystyle IO Query' => $cr->getFilteredCitation(),
        'Anystyle IO output' => _citation_lookup_format_anystyle_data($jobj),
        'PubMed Query' => $cr->getPubMedQry(),
        'PubMed Result' => $pout,
      );
      
    }    
  }
  
  return array(
    '#theme' => 'table',
    '#header' => array_keys(reset($rows)),
    '#rows' => $rows,
  );
}
