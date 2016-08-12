var width = 800;
var height = 640;
var legendWidth = 250 ;
var legendHeight = 250;

var tileWidth;
var tileHeight;
var tileMargin;

/**
 * Refreshes the impact graph.
 */
function refreshGraph() {

    // Read user input for the data-set.
    var selectDataSet = document.getElementById("selectDataSet");
    var dataFile = selectDataSet.options[selectDataSet.selectedIndex].value;

    // Load data-set and refresh the graph
    d3.csv('data/' + dataFile, function(rows) {

        var timePeriods = generateTimePeriods();
        var dataSet = [
            [[],[],[],[],[],[],[],[],[],[]],
            [[],[],[],[],[],[],[],[],[],[]],
            [[],[],[],[],[],[],[],[],[],[]]];

        var articles = _.sortBy(deduplicate(rows), function(d) { return isReview(d); });

        for (var i = 0; i < articles.length; i++) {
            var article = articles[i];
            var dateString = article.cover_date;
            var year = parseInt(dateString.split("/")[2]);
            for (var j = 0; j < timePeriods.length; j++) {
                if (timePeriods[j][0] <= year && timePeriods[j][1] >= year) {
                    var percentileRank = parseInt(article.percentile_rank_dummy_data);
                    var percentileIndex = Math.floor((percentileRank / 10) - 0.1);
                    dataSet[j][percentileIndex].push(article);;
                    break;
                }
            }
        }
        drawGraph(dataSet);
    });
}

/**
 * Draws a new graph by using the provided data-set.
 */
function drawGraph(dataSet) {
    d3.select("#svgContainer").selectAll("*").remove();
    var svg =
        d3.select("#svgContainer")
            .append("svg")
            .attr("width", width)
            .attr("height", height);

    var blockWidth = 220;
    var blockHeight = 50;
    var blockBottomMargin = 3;
    var graphLeftMargin = 40;
    var graphTopMargin = 50;

    svg.append("text")
        .attr("class", "label percentileLabel")
        .attr("transform", "translate(15," + (10 * (blockHeight + blockBottomMargin)) / 2 + ") rotate(-90)")
        .style("text-anchor", "middle")
        .text("Percentile rank of times cited");

    var timePeriodLimits = generateTimePeriods();
    dataSet.forEach(function (timePeriod, i) {

        var labelStartX = (i * (blockWidth + 10) + graphLeftMargin + 52);
        var articleCount = 0;
        timePeriod.forEach(function (d) { articleCount += d.length; });
        var percentileMedian =
            Math.round(
                d3.median(
                    _.map(
                        _.flatten(timePeriod),
                        function(d) { return d.percentile_rank_dummy_data; }
                    )
                )
            );

        // Show label for the time-frame
        svg.append("text")
            .attr("class", "label timeFrameLabel")
            .attr("transform", "translate(" + labelStartX + ",20)")
            .text(timePeriodLimits[i][0] + "-" + timePeriodLimits[i][1]);

        svg.append("text")
            .attr("class", "label articleCount")
            .attr("transform", "translate(" + labelStartX + ",40)")
            .text(articleCount + " total articles");

        // Draw percentiles for this time-frame
        timePeriod.forEach(function (block, j) {
            var blockGroup = svg.append("g").attr("transform", "translate(" + (i * (blockWidth + 10) + graphLeftMargin) + "," + (j * (blockHeight + blockBottomMargin) + graphTopMargin) + ")");
            var upperBound = ((j + 1) * 10);
            var lowerBound = upperBound - 9;
            drawBlock(blockGroup, block, lowerBound, upperBound, percentileMedian, blockWidth, blockHeight);
        });
    });

    drawLegend();
}

/**
 * Draws a new decile block based on provided the data and dimensions.
 */
function drawBlock(svg, articles, lowerBound, upperBound, percentileMedian, width, height) {

    var blockMargin = 2;
    var axisStart = 39;
    var axisWidth = 7;
    svg.append("path")
        .attr("class", "axis")
        .attr("d", "M " + axisStart + " " + blockMargin + " " +
            "L " + (axisStart + axisWidth) + " " + blockMargin + " " +
            "L " + (axisStart + axisWidth) + " " + (height - blockMargin) + " " +
            "L " + axisStart + " " + (height - blockMargin));

    // Show a median marker if the percentile median falls into this decile;
    // otherwise show axis label for the decile (there's not enough space for both)
    if (lowerBound <= percentileMedian && upperBound >= percentileMedian) {
        drawPercentileMarker(svg, percentileMedian, (((percentileMedian - lowerBound) / 10) * height) + 3);
    } else {
        svg.append("text")
            .attr("class", "label axisLabel")
            .attr("x", 2)
            .attr("y", height / 2)
            .text(lowerBound + "-" + upperBound);
    }

    // We have 10x3 tiles, calculate the dimensions based on available space
    var tileStart = axisStart + axisWidth + 7;
    tileMargin = 2;
    tileWidth = (width - tileStart) / 10;
    tileHeight = (height - 2 * blockMargin - tileMargin) / 3;

    var tiles = svg.selectAll(".tile")
        .data(articles)
        .enter()
        .append("rect")
        .attr("class", function (d) { return isReview(d) ? "tile reviewTile" : "tile researchArticleTile";})
        .attr("x", function(d,i) { return tileStart + (Math.ceil((i + 1) / 3) - 1) * (tileWidth + tileMargin);})
        .attr("y", function(d,i) { return blockMargin + (((i + 1) % 3 == 0) ? 2 : (((i + 1) % 3) - 1)) * (tileHeight + tileMargin);})
        .attr("width", tileWidth - tileMargin)
        .attr("height", tileHeight - tileMargin)
        .on("click", function(d) {
            $("#popupContainer").html(createMetadata(d));
            $("#popupContainer").popup('open', {x: d3.event.pageX + 28, y: d3.event.pageY - 28});
        });
}

function drawPercentileMarker(svg, percentile, position) {

    var pointX = 40;
    var pointY = position;
    var markerHeight = 20;
    var markerGroup = svg.append("g");

    markerGroup.append("path")
        .attr("class", "medianMarker")
        .attr("d", "M " + pointX + " " + pointY + " " +
            "L " + (pointX - markerHeight * 0.66) + " " + (pointY - markerHeight / 2) + " " +
            "L " + (pointX - markerHeight * 1.66) + " " + (pointY - markerHeight / 2) + " " +
            "L " + (pointX - markerHeight * 1.66) + " " + (pointY + markerHeight / 2) + " " +
            "L " + (pointX - markerHeight * 0.66) + " " + (pointY + markerHeight / 2) + " " +
            "L " + pointX + " " + pointY);

    markerGroup.append("text")
        .attr("class", "label medianMarkerLabel")
        .attr("x", pointX - markerHeight * 1.16)
        .attr("y", pointY)
        .text(percentile);

    return markerGroup;
}

function drawLegend() {
    d3.select("#svgLegendContainer").selectAll("*").remove();
    var svg =
        d3.select("#svgLegendContainer")
            .append("svg")
            .attr("width", legendWidth)
            .attr("height", legendHeight);

    var yLevel = 20;
    var marker = drawPercentileMarker(svg, "X", yLevel);
    marker.attr("transform", "scale(0.6,0.6)");

    svg.append("text")
        .attr("class", "label legendLabel")
        .attr("x", 35)
        .attr("y", yLevel * 0.7)
        .text("Median percentile rank");

    svg.append("rect")
        .attr("class", "researchArticleTile")
        .attr("x", 4)
        .attr("y", yLevel + (tileHeight + tileMargin) / 2)
        .attr("width", tileWidth - tileMargin)
        .attr("height", tileHeight - tileMargin);

    svg.append("text")
        .attr("class", "label legendLabel")
        .attr("x", 35)
        .attr("y", yLevel + tileHeight + 2)
        .text("Research article");

    svg.append("rect")
        .attr("class", "reviewTile")
        .attr("x", 4)
        .attr("y", 52)
        .attr("width", tileWidth - tileMargin)
        .attr("height", tileHeight - tileMargin);

    svg.append("text")
        .attr("class", "label legendLabel")
        .attr("x", 35)
        .attr("y", 60)
        .text("Review");
}

/**
 * Creates a summary of an article (shown on the popup).
 */
function createMetadata(article) {
    // Authors. Title. Journal. Year Month;Volume(Issue):Pages. Times cited: n. Percentile rank in Field: n.
    var year = parseInt(article.cover_date.split(".")[2]);
    var month = parseInt(article.cover_date.split(".")[1]);
    return article.authors.replace(new RegExp('\\|', 'g'), ', ') + ". " +
        article.title + ". " +
        article.publication_name + ". " +
        year + " " + month + ";" +
        article.volume + "(" + article.issue + "):" + article.pages + ". " +
        "Times cited: " + article.citation_count + ". " +
        "Percentile rank in field: " + article.percentile_rank_dummy_data + ".<br /><br />" +
        "<a href='http://vivo.med.cornell.edu/display/pubid" + article.scopus_doc_id + "'>View details &#9654;</a>";
}

/**
 * Generates the time periods to use. In the literature it is recommended that
 * the two most recent years are excluded from the analysis.
 */
function generateTimePeriods() {
    var currentYear = new Date().getFullYear();
    return [[currentYear - 12, currentYear - 9],
        [currentYear - 8, currentYear - 6],
        [currentYear - 5, currentYear - 3]];
}

/**
 * Checks if the given article is a review.
 *
 * @param article The article to check
 */
function isReview(article) {
    var isReview = false;
    article.pubtype.split('|').forEach(function(d) {
        if (d == "Review") isReview = true;
    });
    return isReview;
}

/**
 * In the data-set, one article will have one row per category. To avoid double
 * counting, here we deduplicate the list and ensure that we always choose the
 * category with highest percentile rank and ignore the other categories.
 *
 * @param articles a list of articles to deduplicate
 */
function deduplicate(articles) {
    var deduplicated = [];
    articles.forEach(function(d) {
        var i = _.findIndex(deduplicated, function(e) { return e.pmid == d.pmid; }); // O(n^2)
        if (i > -1) {
            var existingRank = parseInt(deduplicated[i].percentile_rank_dummy_data);
            var currentRank = parseInt(d.percentile_rank_dummy_data);
            if (currentRank > existingRank) {
                deduplicated[i] = d;
            }
        } else {
            deduplicated.push(d);
        }
    });
    return deduplicated;
}