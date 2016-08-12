var width = 700;
var height = 640;
var graphLeftMargin = 50;
var graphTopMargin = 50;
var legendWidth = 670;
var legendHeight = 250;

var blockWidth = 200;
var blockHeight = 50;
var blockTopMargin = 2;
var blockBottomMargin = 3;
var axisStart = 39;
var axisWidth = 7;

/**
 * Preferred tile dimensions. These will be scaled down if it turns out that
 * there's not enough space available (see below).
 */
var tileMargin = 2;
var tileWidth = 16;
var tileHeight = 14;

/**
 * The 'blockWidth' includes the space for the axis and label. When we substract
 * the space required for those, we get the space available for the tiles. If
 * this space is not wide enough for the largest decile in our data, we need to
 * scale down the tiles from their preferred dimensions.
 */
var tileScale = 1;

/* The entire unprocessed data-set */
var unprocessedData;

var articlesPerSquare = 1;

/* A global variable to check if articles less than 10 in any time frame. */
var showMsg = 0;


$("#popupContainer").click(function() {
    $("#popupContainer").popup();
});

refreshGraph();

/**
 * Refreshes the impact graph.
 */
function refreshGraph() {

    unprocessedData = chartData;

    var timePeriods = generateTimePeriods();
    var dataSet = [
        [
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            []
        ],
        [
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            []
        ],
        [
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            [],
            []
        ]
    ];

    var articles = _.sortBy(deduplicate(chartData), function (d) {
        return isReview(d);
    });

    for (var i = 0; i < articles.length; i++) {
        var article = articles[i];
        if (typeof article !== 'undefined') {
            var dateString = article.cover_date;
            var year = parseInt(dateString.split("-")[0]);
            for (var j = 0; j < timePeriods.length; j++) {
                if (timePeriods[j][0] <= year && timePeriods[j][1] >= year) {
                    var percentileRank = parseInt(article.percentile_rank);
                    var percentileIndex = Math.floor((percentileRank / 10) - 0.1);
                    dataSet[j][percentileIndex].push(article);
                    break;
                }
            }
        }
    }

    // Determine if we need to scale down the tiles to fit the available space.
    // See declaration of 'tileScale' for more details.

    var maxBlockWidth =
        _.reduce(
            _.flatten(dataSet, true),
            function (memo, value) {
                return Math.max(memo, calculateBlockWidth(value));
            },
            0
        );

    var availableSpace = blockWidth - axisStart - axisWidth;
    if (maxBlockWidth > availableSpace) {
        tileScale = availableSpace / maxBlockWidth;
    } else {
        tileScale = 1;
    }

    drawGraph(dataSet);
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

    svg.append("text")
        .attr("class", "label percentileLabel")
        .attr("transform", "translate(15," + (10 * (blockHeight + blockBottomMargin)) / 2 + ") rotate(-90)")
        .style("text-anchor", "middle")
        .text("Percentile rank of times cited");

    svg.append("text")
        .attr("class", "label percentileLabel")
        .attr("transform", "translate(35," + (10 * (blockHeight + blockBottomMargin)) / 2 + ") rotate(-90)")
        .style("text-anchor", "middle")
        .text("better \u2192");

    var timePeriodLimits = generateTimePeriods();
    dataSet.forEach(function (timePeriodData, i) {

        var startX = i * (blockWidth + 10) + graphLeftMargin;
        var articleCount = 0;
        timePeriodData.forEach(function (d) {
            articleCount += d.length;
        });

        if (articleCount > 0 && articleCount < 10) {
            showMsg = 1;
        }


        var percentileMedian =
            Math.round(
                d3.median(
                    _.map(
                        _.flatten(timePeriodData),
                        function (d) {
                            return d.percentile_rank;
                        }
                    )
                )
            );

        // Show label for the time-frame
        var timePeriodLabel = timePeriodLimits[i][0] + "-" + timePeriodLimits[i][1];
        svg.append("text")
            .attr("class", "label timeFrameLabel")
            .attr("transform", "translate(" + (startX + 52) + ",20)")
            .text(timePeriodLabel);

        svg.append("text")
            .attr("class", "label articleCount")
            .attr("transform", "translate(" + (startX + 52) + ",40)")
            .text(articleCount + " total articles");

        // Draw percentiles for this time-frame
        timePeriodData.forEach(function (block, j) {
            var startY = (j * (blockHeight + blockBottomMargin) + graphTopMargin);
            var axisGroup = svg.append("g").attr("transform", "translate(" + startX + "," + startY + ")");
            var blockGroup = svg.append("g").attr("transform", "translate(" + startX + "," + startY + ")");
            var upperBound = ((j + 1) * 10);
            var lowerBound = upperBound - 9;
            drawBlock(axisGroup, blockGroup, block, lowerBound, upperBound, percentileMedian, i, blockWidth, blockHeight);
        });
    });

    drawLegend();
}

/**
 * Draws a new decile block based on provided the data and dimensions.
 */
function drawBlock(axisGroup, blockGroup, articles, lowerBound, upperBound, percentileMedian, timePeriodIndex, width, height) {

    axisGroup.append("path")
        .attr("class", "axis")
        .attr("d", "M " + axisStart + " " + blockTopMargin + " " +
            "L " + (axisStart + axisWidth) + " " + blockTopMargin + " " +
            "L " + (axisStart + axisWidth) + " " + (height - blockTopMargin) + " " +
            "L " + axisStart + " " + (height - blockTopMargin));

    // Show a median marker if the percentile median falls into this decile;
    // otherwise show axis label for the decile (there's not enough space for both)
    if (lowerBound <= percentileMedian && upperBound >= percentileMedian) {
        drawPercentileMarker(axisGroup, percentileMedian, (((percentileMedian - lowerBound) / 10) * height) + 3, timePeriodIndex);
    } else {
        axisGroup.append("text")
            .attr("class", "label axisLabel")
            .attr("x", 2)
            .attr("y", height / 2)
            .text(lowerBound + "-" + upperBound);
    }

    // Split articles into chunks based on the articlesPerSquare parameter. If
    // the value is higher than 1, each tile will represent multiple articles.

    // Note that reviews will still always go to separate chunks. Therefore, we
    // first partition the articles and then chunk the two partitions independently.
    // As a final step, we then merge the two partitions back into a singe array.

    // var partitionedArticles = articles.partition(function(article) { return !isReview(article); });
    // var partitionedArticles = partition(articles, function(article) { return !isReview(article); });
    // var partitionedAndChunkedArticles = [partitionedArticles[0].chunk(articlesPerSquare), partitionedArticles[1].chunk(articlesPerSquare)];
    // var partitionedAndChunkedArticles = [chunk(partitionedArticles[0], articlesPerSquare), chunk(partitionedArticles[1], articlesPerSquare)];


    var partitionedArticles = partition(articles, function (article) {
        return !isReview(article);
    });
    var researchArticles = _.sortBy(partitionedArticles[0], function (article) {
        return Number(article.percentile_rank);
    })
    var reviews = _.sortBy(partitionedArticles[1], function (article) {
        return Number(article.percentile_rank);
    })
    var partitionedAndChunkedArticles = [chunk(researchArticles, articlesPerSquare), chunk(reviews, articlesPerSquare)];

    var chunkedArticles = _.flatten(partitionedAndChunkedArticles, true);

    // Calculate the X-coordinate for the first tile
    var tileStart = axisStart + axisWidth + 7;

    // Create a group for the tiles so that they can be scaled if necessary
    var tileGroup =
        blockGroup.append("g")
            .attr("class", "tileGroup")
            .attr("transform", "translate(" + tileStart + " 0)");

    // Finally, draw the tiles.
    var tiles = tileGroup.selectAll(".tile")
        .data(chunkedArticles)
        .enter()
        .append("rect")
        .attr("id", function (d) {
            return "article_" + d[0].pmid;
        })
        .attr("class", function (d) {
            return isReviewArray(d) ? "tile reviewTile" : "tile researchArticleTile";
        })
        .attr("x", function (d, i) {
            return (Math.ceil((i + 1) / 3) - 1) * (tileWidth + tileMargin);
        })
        .attr("y", function (d, i) {
            return blockTopMargin + (((i + 1) % 3 == 0) ? 2 : (((i + 1) % 3) - 1)) * (tileHeight + tileMargin);
        })
        .attr("width", function (d) {
            return calculateTileWidth(d);
        })
        .attr("height", tileHeight - tileMargin)
        .on("mouseover", function (d) {
            d3.select(this).style("opacity", 0.7);
        })
        .on("mouseout", function (d) {
            d3.select(this).style("opacity", 1);
        })
        .on("click", function (d) {
            showArticleCallout('#article_' + d[0].pmid, d, articles);
        })

    tileGroup.attr("transform", "translate(" + tileStart + " 0) scale(" + tileScale + " 1)");
}

/**
 * Calculates the tile width. If the article count is less than the value of
 * articlesPerSquare, we need to scale the tile size accordingly.
 */
function calculateTileWidth(chunkedArticles) {
    if (chunkedArticles.length < articlesPerSquare) {
        // -1 in the end accounts for the fact that current SVG implementations offer
        // very little control over the stroke location. Width of the stoke is always
        // fixed and partially outside the shape (thus increasing the outer dimensions).
        return (chunkedArticles.length / articlesPerSquare) * (tileWidth - tileMargin) - 1;
    } else {
        return tileWidth - tileMargin;
    }
}

/**
 * Calculates the block width when using preferred tile dimensions.
 */
function calculateBlockWidth(articles) {
    return Math.ceil(Math.ceil(articles.length / articlesPerSquare) / 3) * (tileWidth + tileMargin);
}

/**
 * Draws the percentile marker.
 */
function drawPercentileMarker(svg, percentile, position, timePeriodIndex) {

    var pointX = 40;
    var pointY = position;
    var markerHeight = 20;
    var markerGroup =
        svg.append("g")
            .attr("id", function (d) {
                return "median_" + timePeriodIndex;
            })
            .on("mouseover", function (d) {
                showMedianCallout(percentile, timePeriodIndex);
            });

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
        .style("pointer-events", "none")
        .append("tspan")
        .attr("dy", "3pt") /* An ugly hack because IE does not respect alignment-baseline: middle */
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
        .text("Academic article");

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

    svg.append("text")
        .attr("class", "label legendLabel")
        .attr("x", 4)
        .attr("y", 85)
        .text("This chart shows ONLY those articles with citation count data available.");

    if (showMsg == 1) {
        svg.append("text")
            .attr("class", "label legendLabel")
            .attr("x", 4)
            .attr("y", 105)
            .text("Note that there are fewer than 10 articles in at least one time period. Please use caution when");
        svg.append("text")
            .attr("class", "label legendLabel")
            .attr("x", 4)
            .attr("y", 125)
            .text("drawing conclusions about the percentile rank of times cited for this researcher\'s articles.");

    }

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
    if (article.pubtype !== undefined && article.pubtype !== null) {
        article.pubtype.split('|').forEach(function (d) {
            if (d == "Review") isReview = true;
        });
    }
    return isReview;
}

/**
 * Checks if the given article array consists of reviews.
 *
 * @param articles The articles
 */
function isReviewArray(articles) {
    return articles.length > 0 ? isReview(articles[0]) : false;
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
    articles.forEach(function (d) {
        var i = _.findIndex(deduplicated, function (e) {
            return e.pmid == d.pmid;
        }); // O(n^2)
        if (i > -1) {
            var existingRank = parseInt(deduplicated[i].percentile_rank);
            var currentRank = parseInt(d.percentile_rank);
            if (currentRank > existingRank) {
                deduplicated[i] = d;
            }
        } else {
            deduplicated.push(d);
        }
    });
    return deduplicated;
}


/**
 * Splits the array into chunks of specified size.
 *
 * @param chunkSize the size of the chunks
 */
function chunk(data, chunkSize) {
    var array = data;
    return [].concat.apply([],
        array.map(function (elem, i) {
            return i % chunkSize ? [] : [array.slice(i, i + chunkSize)];
        })
    );
}

/**
 * Partitions the array based on a discriminator function.
 *
 * @param discriminator the discriminator function to use
 */
function partition(data, discriminator) {
    var matched = [],
        unmatched = [],
        i = 0,
        j = data.length;

    for (; i < j; i++) {
        (discriminator.call(data, data[i], i) ? matched : unmatched).push(data[i]);
    }
    return [matched, unmatched];
}

/**
 * Shows a callout next to the specified median marker.
 *
 * @param marker the median marker
 */
function showMedianCallout(percentile, timePeriodIndex) {
    $('div.qtip:visible').qtip('hide');
    $("#median_" + timePeriodIndex).qtip({
        content: {
            text: function () {
                var timePeriodLimits = generateTimePeriods();
                var timePeriodLabel = timePeriodLimits[timePeriodIndex][0] + "-" + timePeriodLimits[timePeriodIndex][1];

                return "For " + timePeriodLabel + " the median percentile rank of citations received " +
                    "for each article, adjusted for year, article type, and field of publication.";
            }
        },
        position: {
            my: 'left center',
            at: 'right center'
        },
        style: {
            classes: 'qtip-light qtip-shadow popupContainer'
        },
        show: {
            event: 'click',
            ready: true
        }
    });
}

/**
 * Shows a callout next to the specified tile containing metadata
 * about the specified articles (there can be many if articlesPerSquare > 1).
 *
 * @param tile the tile representing the articles
 * @param articles the articles
 */
function showArticleCallout(tile, articles) {
    $(tile).qtip({
        content: {
            text: function () {
                return createMetadata(articles);
            }
        },
        position: {
            my: 'left center',
            at: 'right center'
        },
        style: {
            classes: 'qtip-light qtip-shadow popupContainer'
        },
        show: {
            event: 'click',
            ready: true
        },
        hide: {
            event: 'unfocus'
        }
    });
}

/**
 * Creates a summary of a chunk of articles (shown on the popup).
 *
 * @param articles the articles
 */
function createMetadata(articles) {

    $('.metadataContainer').remove(); // Needed to avoid flickering.

    var result = "";
    articles.forEach(function (article, i) {

        // The title of the article is formatted as follows:
        // Authors. Title. Journal. Year Month;Volume(Issue):Pages.

        var year = parseInt(article.cover_date.split("-")[0]);
        var month = parseInt(article.cover_date.split("-")[1]);

        if (i == 0) {
            result += '<div class="metadataContainer" id="article_metadata_' + i + '">';
        } else {
            result += '<div class="metadataContainer" id="article_metadata_' + i + '" style="display: none;">';
        }

        // The inner container has a fixed minimum height. This way the navigation
        // links below will stay in fixed position when the users clicks through
        // the articles. Otherwise they would jump around depending on the height
        // of the content.

        result += '<div class="innerMetadataContainer">';

        var authors = "";
        if (article.authors !== "" && article.authors !== null) {
            authors = createAuthorMetadata(article);
        }
        if (authors !== "" && authors !== null) {
            result += "<strong>" + authors + "</strong>. ";
        }

        if (article.title !== "" && article.title !== null) {
            result += article.title + ". ";
        }

        if (article.publication_name !== "" && article.publication_name !== null) {
            result += "<i>" + article.publication_name + "</i>. ";
        }

        if (year !== "" && year !== null && year !== NaN) {
            result += year + " ";
        }

        if (month !== "" && month !== null && month !== NaN) {
            result += month + "; ";
        }

        if (article.volume !== "" && article.volume !== null) {
            result += article.volume;
        }

        if (article.issue !== "" && article.issue !== null) {
            result += "(" + article.issue + ")";
        }

        if (article.pages !== "" && article.pages !== null) {
            result += ":" + article.pages + ".<br/><br />";
        } else {
            result += ".<br/><br />";
        }

        var summary = createCitationSummary(article);
        if (summary !== "" && summary !== null) {
            result += summary + "<br /><br />";
        }
        result += "</div>"; // innerMetaDataContainer

        if (article.scopus_doc_id !== "" && article.scopus_doc_id !== null) {
            result += "<a href='http://vivo.med.cornell.edu/display/pubid" + article.scopus_doc_id + "'>View details</a>";
        }

        if (articlesPerSquare != 1) {
            result += createPagination(article, i, articles.length);
        }

        result += "</div>";
    });

    return result;
}

/**
 * Creates the author segment of the article summary. If there are more than five
 * authors, we want to format the segment as follows:
 *
 * North BJ, Rosenberg MA, Jeganathan KB, (...), Rosenzweig A, Sinclair DA
 *
 * @param article the article
 */
function createAuthorMetadata(article) {
    var authors = article.authors.split('|');
    var separator = ', ';
    return authors.join(separator);
}

/**
 * Creates the citation summary segment of the article summary. We want to
 * format the segment as follows;
 *
 * Times cited: 22
 * Category/rank
 * Cancer (8th), Cell Biology (14th), Biochemistry (18th)
 *
 * @param article the article
 */
function createCitationSummary(article) {
    var articles =
        _.map(
            // Sorts categories by the percentile rank
            _.sortBy(
                // Retrieves all the categories the article appears in
                _.filter(unprocessedData, function (d) {
                    return d.pmid == article.pmid;
                }),
                'percentile_rank'
            ),
            function (d) {

                if (d.category !== undefined && d.category !== "" && d.category !== null) {
                    return d.percentile_rank +
                        ordinalIndicator(d.percentile_rank) + " percentile for "
                        + sanitizeCategory(d.category);
                } else {
                    return d.percentile_rank +
                        ordinalIndicator(d.percentile_rank);
                }

            }
        );

    var citeString = "Times cited - " + article.citation_count + "<br />";

    citeString += "Rank - " + articles.join(',');

    // return "Times cited - " + article.citation_count + "<br />" + "Rank - " + articles.join(', ');

    return citeString;
}

/**
 * Creates a pagination links for the article.
 *
 * @param article the article
 * @param index the index of the article
 * @param count the total number of articles shown in this callout
 */
function createPagination(article, index, count) {

    var result = '<span class="paginationContainer">';

    if (index == 0) {
        result += '<i class="fa fa-arrow-left paginationDisabled"></i>';
    } else {
        result += '<a onclick="calloutPreviousPage(' + index + ');"><i class="fa fa-arrow-left paginationEnabled"></i></a>';
    }

    result += '&nbsp;';
    result += isReview(article) ? 'Review' : 'Article';
    result += '&nbsp;' + (index + 1) + ' of ' + count + '&nbsp;';

    if (index == count - 1) {
        result += '<i class="fa fa-arrow-right paginationDisabled"></i>';
    } else {
        result += '<a onclick="calloutNextPage(' + index + ');"><i class="fa fa-arrow-right paginationEnabled"></i></a>';
    }

    result += '</span>';
    return result;
}


/**
 * Capitalizes the specified value. For example:
 *
 * BIOCHEMISTRY & MOLECULAR BIOLOGY
 *
 * becomes:
 *
 * Biochemistry & Molecular Biology
 *
 * @param value the value to capitalize
 */
function sanitizeCategory(value) {

    return _.map(
        value.split(' '),
        /*function(d) { return d.charAt(0).toUpperCase() + d.slice(1).toLowerCase(); }).join(' '); */
        function (d) {
            return d.charAt(0).toUpperCase() + d.slice(1);
        }).join(' ').replace(/,/g, '; ');
}

/**
 * Determines the ordinal indicator to use for the value.
 *
 * @param {int} value The value
 */
function ordinalIndicator(value) {
    var indicator;
    var modulo = value % 10;
    switch (modulo) {
        case 1:
            indicator = (value != 11 ? "st" : "th");
            break;
        case 2:
            indicator = (value != 12 ? "nd" : "th");
            break;
        case 3:
            indicator = (value != 13 ? "rd" : "th")
            break;
        default:
            indicator = "th";
    }
    return indicator;
}