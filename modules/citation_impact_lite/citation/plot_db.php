<?php
/************************************************************************************************
 * // Name:    citation/plot_db.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:  Visualizing citation impact for a set of articles that are stored in a database.
 ************************************************************************************************/

include_once(__DIR__ . "/../library/main.php");
include_once(__DIR__ . "/../library/portable_utf8.php");
$mysqli = getDatabaseConnection();
require_file('data.php');
$objData = new Data($mysqli);

$articles = $objData->get_visualization_data();

?>
<script type="text/javascript">
    var chartData = [];
<?php
foreach ($articles as $article){
    $article_data = json_encode($article, JSON_PRETTY_PRINT);
?>
    chartData.push(<?php echo $article_data; ?>);
<?php
}
?>
</script>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <meta http-equiv="cache-control" content="max-age=0" />
    <meta http-equiv="cache-control" content="no-cache" />
    <meta http-equiv="expires" content="0" />
    <meta http-equiv="expires" content="Tue, 01 Jan 1980 1:00:00 GMT" />
    <meta http-equiv="pragma" content="no-cache" />
    <link href="css/citations.css" rel="stylesheet" type="text/css" />
    <link href="css/jquery.qtip.css" rel="stylesheet" type="text/css" />
    <link href="js/lib/jquery.mobile.custom.structure.min.css" rel="stylesheet" type="text/css" />
    <link href="js/lib/jquery.mobile.custom.theme.min.css" rel="stylesheet" type="text/css" />
    <script src="http://d3js.org/d3.v3.min.js"></script>
    <script src="js/lib/jquery.min.js"></script>
    <script src="js/lib/jquery.mobile.custom.min.js"></script>
    <script src="js/lib/underscore.min.js"></script>
    <script src="js/lib/jquery.qtip.js"></script>
</head>
<body>
<div id="header"><h1>Citation Impact Visualization</h1></div>
<div id="svgContainer"></div>
<div id="controls">
    <div id="svgLegendContainer"></div>
</div>
<div id="popupContainer"></div>
<div style="clear:both"><div>
        <script src="js/citation-db.js"></script>
</body>
</html>
