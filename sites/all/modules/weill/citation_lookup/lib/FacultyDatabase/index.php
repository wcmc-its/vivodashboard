<!DOCTYPE html>
<html>
<head>
      <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Faculty Journal Management System - WCMC</title>
        <meta name="description" content="">
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <!-- Place favicon.ico and apple-touch-icon.png in the root directory -->

        <link rel="stylesheet" href="css/style.css">
        <link href="css/tipr.css" rel="stylesheet">
        <script src="js/vendor/modernizr-2.6.2.min.js"></script>
        <script src="js/tipr.js"></script>
        <link rel="stylesheet" href="css/jquery.treetable.css" />
	    <link rel="stylesheet" href="css/jquery.treetable.theme.default.css" />
	    <script src="js/jquery.js"></script>
	    <script src="js/jquery.treetable.js"></script>
	
</head>
<body>
<script type="text/javascript" language="javascript">
var body = document.body, html = document.documentElement;
var height = Math.max( body.scrollHeight, body.offsetHeight, 
        html.clientHeight, html.scrollHeight, html.offsetHeight );
        
function checkfile(sender) {
    var validExts = new Array(".xlsx", ".xls", ".csv");
    var fileExt = sender.value;
    fileExt = fileExt.substring(fileExt.lastIndexOf('.'));
    if (validExts.indexOf(fileExt) < 0) {
      alert("Invalid file selected, valid files are of " +
               validExts.toString() + " types.");
      sender.value="";
      return false;
    }
    else return true;
}

function validateForm(){
	var excl=document.getElementById('excelfile');
	return checkfile(excl);
}
</script>
<?php 
	$uploadOk = 0;
	if(isset($_POST["submit"])) {
		if (isset($_FILES["excelfile"])) {
			if ($_FILES["excelfile"]["error"] > 0) {
				echo "<span style='color:red'>Error Return Code: " . $_FILES["excelfile"]["error"] . "</span><br />";
			}else {
				if(file_exists($_FILES["excelfile"]["name"])){
					unlink($_FILES["excelfile"]["name"]);
				}
				$target_dir = "feeds/";				
				$fileinfo = pathinfo($_FILES["excelfile"]["name"]);
				$ext = $fileinfo['extension'];
				//$tstmp=date('Y_M_d_H_i_s');
				//$target_file = $target_dir.'FACULTY_DATABASE_'.$tstmp.'.'.$ext;				
				//move_uploaded_file( $_FILES['excelfile']['tmp_name'], $target_file);
				$target_file=$_FILES['excelfile']['tmp_name'];
				$uploadOk = 1;
				
				require_once 'Classes/PHPExcel/IOFactory.php';
				require_once 'Classes/dto/UserDTO.php';
				require_once 'Classes/dto/Citation.php';
				require_once 'PubMedAPI.php';
				require_once 'util/util.php';
				
				
				try {					
					$objTpl= PHPExcel_IOFactory::load($target_file);
					$objTpl->setActiveSheetIndex(0);
					$allDataInSheet = $objTpl->getActiveSheet()->toArray(null,true,true,true);
					$arrayCount = count($allDataInSheet);

					$userArr=array();
					
					$url = 'http://anystyle.io/parse/references';
					$ch = curl_init($url);
					if($arrayCount>2){
						//$i=2;
						for($i=2;$i<=20 && $i<=$arrayCount;$i++){
							$user=getUserDataObject($allDataInSheet[$i],$ch);
							array_push($userArr, $user);
						}
					}
					curl_close($ch);
					//echo var_dump($userArr);
				} catch(Exception $e) {	
					die('Error loading file "'.pathinfo($target_file,PATHINFO_BASENAME).'": '.$e->getMessage());
				}
				/*$allDataInSheet = $objPHPExcel->getActiveSheet()->toArray(null,true,true,true);
				$arrayCount = count($allDataInSheet);  // Here get total count of row in that Excel sheet
				echo "Total Number of RowsL ".$arrayCount;*/
			}
		}
	}
?>
	<header role="banner">
        <div id="logo-container"><a href="http://weill.cornell.edu"><img src="images/logo.png"></a></div> 
	</header>
	 
	
<?php 
if($uploadOk == 0){
?>
	<div id="wrap">
		<center><h1><b>AnyStyle.IO Citations Parser</b></h1> </p></center>
	</div>
	<center> <p>Enter Citations to parse and return the results from AnyStyle.IO parser, Citations can be uploaded as a file.</p></center>
	
	<form action="<?php echo $_SERVER["PHP_SELF"]; ?>" method="post" enctype="multipart/form-data">
		<table width="600" style="margin:70px auto; background:#f8f8f8; border:1px solid #eee; padding:20px 0 25px 0;">
			<tr><td colspan="2" style="font:bold 21px arial; text-align:center; border-bottom:1px solid #eee; padding:5px 0 10px 0;">
			<a href="http://www.discussdesk.com" target="_blank">Upload Citation Data </a></td></tr>
			<tr><td colspan="2" style="font:bold 15px arial; text-align:center; padding:0 0 5px 0;">Browse and Upload Your File </td></tr>
			<tr>
			<td width="50%" style="font:bold 12px tahoma, arial, sans-serif; text-align:right; border-bottom:1px solid #eee; padding:5px 10px 5px 0px; border-right:1px solid #eee;"></td>
			<td width="50%" style="border-bottom:1px solid #eee; padding:5px;"><input type="file" name="excelfile" id="excelfile" onchange="checkfile(this);" /></td>
			</tr>
		</table>
		<center>
			<td style="font:bold 12px tahoma, arial, sans-serif; text-align:right; padding:5px 10px 5px 0px; border-right:1px solid #eee;"></td>
			<td width="50%" style=" padding:5px;"><input class="buttonSubmit" value="Upload" type="submit" name="submit" onclick="return validateForm()"/></td>
		</center>
	</form>
	<br></br><br></br> <br></br><br></br>
<?php 
}else{
?>
<div style="overflow:auto" id="reportId">
<table border="1" class="treetable" id="citationTblId"><tr><th>CWID</th><th>User Name</th><th>Title</th><th>Anystyle IO Query</th><th>Anystyle IO output</th><th>PubMed Query</th><th>PubMed Result</th></tr>
<?php 
$kk=1;
foreach($userArr as $user){
	$out="<tr class='branch collapsed' data-tt-id='".$kk."'><td>".$user->getCWID()."</td><td>".$user->getUserName()."</td><td>".$user->getTitle()."</td><td>";
	$carr=$user->getCitationArray();
	$pout="";
	$jj=1;
	foreach($carr as $cr){
		if($jj>1)$out="<tr class='branch expanded' data-tt-id='".$kk.".".($jj-1)."' data-tt-parent-id='".$kk."'><td>&nbsp;</td><td>&nbsp;</td><td>&nbsp;</td><td>";
		$jobj=$cr->getJsonObject();
		$jout="";
		if(isset($jobj->author))$jout=getFormattedOutput($jobj->author,$jout,"Author");
		else if(isset($jobj->editor))$jout=getFormattedOutput($jobj->editor,$jout,"Author");
		if(isset($jobj->title))$jout=getFormattedOutput($jobj->title,$jout,"Title");
		if(isset($jobj->location))$jout=getFormattedOutput($jobj->location,$jout,"Location");
		if(isset($jobj->publisher))$jout=getFormattedOutput($jobj->publisher,$jout,"Publisher");
		if(isset($jobj->type))$jout=getFormattedOutput($jobj->type,$jout,"Type");
		if(isset($jobj->language))$jout=getFormattedOutput($jobj->language,$jout,"Language");
		
		//$jout="Author: ".$jobj->author."<br />Title: ".$jobj->title."<br />Location: ".$jobj->location."<br />Publisher: ".$jobj->publisher." <br />Type: ".$jobj->type."<br />Language: ".$jobj->language;
		$pobj=$cr->getPubMedResultArray();
		$pobjcnt=count($pobj);
		if($pobjcnt>0){
			foreach($pobj as $pr){
				$pout=$pout."PMID: ".$pr["pmid"]."<br />";
			}
		}
		$out=$out.$cr->getFilteredCitation()."</td><td>".$jout."</td><td>".$cr->getPubMedQry()."</td><td>".$pout."</td></tr>";
		echo $out;
		++$jj;
	}
	
	++$kk;
}
?>

</table>
</div>
<script type="text/javascript">
	var reportId=document.getElementById('reportId');
	reportId.style.height=(height-150)+"px";
	$("#citationTblId").treetable({ expandable: true });
</script>
<?php }?>

<footer>
    <p class="footer">&copy; Copyright @2015 by Weill Cornell Medical College</p>
</footer>
</body>
</html>