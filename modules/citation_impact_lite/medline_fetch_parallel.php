<?php
/************************************************************************************************
 * // Name:    medline_fetch_parallel.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:    Fetch publications from medline run in parallel
 ************************************************************************************************/
error_reporting(E_STRICT);
ini_set("display_errors", 1);

include_once(__DIR__ . "/library/ProcessManager.php"); //load the class file
$manager              = new ProcessManager();	//create the manager object
$manager->executable  = "php";					//the Linux executable
$manager->path        = "";						//path to the scripts to run
$manager->show_output = false;					//show the output of the manager
$manager->processes   = 14;						//max concurrent processes
$manager->sleep_time  = 1;						//time between checking if the processes are complete

$pub_years = array(
    '2002',
    '2003',
    '2004',
    '2005',
    '2006',
    '2007',
    '2008',
    '2009',
    '2010',
    '2011',
    '2012',
    '2013',
    '2014',
    '2015'
);
//add a script, argument, and it max execution time in seconds
foreach ($pub_years as $year) {
    $manager->addScript("medline.php", $year);
}

$manager->exec();								//start processing through the code
echo 'Completed all tasks';

?>