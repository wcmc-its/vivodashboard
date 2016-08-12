<?php
/************************************************************************************************
 * // Name:    citation/plot_csv.php
 * // Author:  Prakash Adekkanattu
 * // Date:    08/05/16
 * // Description:  Visualizing citation impact for a set of articles that are stored locally in a CSV file.
 ************************************************************************************************/
?>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <meta http-equiv="cache-control" content="max-age=0" />
    <meta http-equiv="cache-control" content="no-cache" />
    <meta http-equiv="expires" content="0" />
    <meta http-equiv="expires" content="Tue, 01 Jan 1980 1:00:00 GMT" />
    <meta http-equiv="pragma" content="no-cache" />
    <link href="css/style.css" rel="stylesheet" type="text/css" />
    <link href="js/lib/jquery.mobile.custom.structure.min.css" rel="stylesheet" type="text/css" />
    <link href="js/lib/jquery.mobile.custom.theme.min.css" rel="stylesheet" type="text/css" />
    <script src="http://d3js.org/d3.v3.min.js"></script>
    <script src="js/lib/jquery.min.js"></script>
    <script src="js/lib/jquery.mobile.custom.min.js"></script>
    <script src="js/lib/underscore.min.js"></script>
</head>
<body>
<div id="header"><h1>Citation Impact Visualization</h1></div>
<div id="svgContainer"></div>
<div id="controls">
    <span class="label">Data Set:</span><br />
    <select id="selectDataSet" class="selectBox" onchange="refreshGraph();">
        <option value="sample_times_cited_data_1_with_authors.csv">Sample #1</option>
        <option value="sample_times_cited_data_2_with_authors.csv">Sample #2</option>
    </select><br />
    <div id="svgLegendContainer"></div>
</div>
<div id="popupContainer"></div>
<div style="clear:both"><div>
        <script src="js/citation-csv.js"></script>
        <script>
            $("#popupContainer").popup();
            refreshGraph();
        </script>
</body>
</html>
