<?php
/************************************************************************************************
 * // Name:    main.php
 * // Author:    Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Main settings file
 ************************************************************************************************/

//	PHP Settings
//error_reporting(E_NONE);
error_reporting(E_ERROR | E_PARSE);
ini_set("display_errors", 1);

// Application Settings and Variables
$settings->basePath = "/root/directory/to/citation_impact_lite";
$settings->cnsaPath = $settings->basePath."/citation_impact_lite";
$settings->libPath = $settings->cnsaPath."/library";
$settings->dataPath = $settings->cnsaPath."/data";

$settings->test = false;

// db connection account
if (($_SERVER['HOSTNAME'] == 'web_server_hostname')){
    $mysql->host = 'database_hostname';
    $mysql->user = 'database_user';
    $mysql->pass = 'database_password';
    $mysql->db = 'database_name';
    $mysql->conn = '';
}else {
    // localhost
    $mysql->host = 'p:localhost';
    $mysql->user = 'db_user';
    $mysql->pass = 'db_password';
    $mysql->db = 'db_name';
    $mysql->conn = '';
}


$mysqli = null;

$tables->violin_baseline = 'violin_baseline';
$tables->violin_category = 'violin_category';
$tables->violin_journal = 'violin_journal';
$tables->violin_journal_category = 'violin_journal_category';
$tables->violin_pmids = 'violin_pmids';
$tables->article = 'article';
$tables->author = 'author';
$tables->author_article = 'author_article';

$messageObjects = array();


// open connection
function getDatabaseConnection() {
	global $mysql, $mysqli;
    if(!isset($mysqli)){
        // $mysqli = mysqli_connect($mysql->host, $mysql->user, $mysql->pass, $mysql->db);
        $mysqli = new mysqli($mysql->host, $mysql->user, $mysql->pass, $mysql->db);
        // Check connection
        if ($mysqli->connect_errno) {
            die('Connections Error, '. $mysqli->connect_errno . ': ' . $mysqli->connect_error);
        }else {
            return $mysqli;
        }
    }
}

// close connection
function closeDatabaseConnection() {
    global $mysqli;
    if(isset($mysqli)){
        $mysqli->close();
    }

}

function printVar($var) {
	print "<pre>\n";
	print_r($var);
	print "</pre>\n";
}

function require_file($strName) {
	global $settings;
	require_once($settings->libPath."/".$strName);
}

function addMessageObject($strName) {
	global $messageObjects;
	$messageObjects[] = $strName;
}

function nl2br2($string){
	$string = preg_replace("(<BR>\r|<br>\r)","\r", $string);
	$string = preg_replace("(<BR>|<br>)","\n", $string);
	return nl2br($string);
}

function web_text($string){
	return nl2br($string);
}


?>
