(function ($) {

    Drupal.behaviors.violin = { attach: function (select, settings) {

        // javascript code
        var margin = {top: 10, bottom: 50, left: 70, right: 10};
        var width = 690;
        var height = 450;
        var domain = [0, 100];
        var violinWidth = 150;
        var violinSpacing = 30;
        var ticks = 5;
        var resolution = 25;
        var interpolation = 'monotone'; // 'monotone', 'basis', 'step-before'

        // 0 = violin color
        // 1 = median marker stroke
        // 2 = median marker gradient begin
        // 3 = median marker gradient end

        var colorThemes = [
            ['#ccc', '#ffb400', '#ffc600', '#fff800'],
            ['#8faac0', '#006699', '#3399cc', '#99cccc'],
            ['#95a63c', '#4e4900', '#c9cb8c', '#c9cb8c', '#fffceb']
        ];
        var colorTheme = 0;

        var linksToMain = jQuery('a[href="/citations/main"]');

        linksToMain.addClass("active");

        updateViolinChart("#violinPlot")

        /**
         * Refreshes the violin chart in the specified container using the provided data.
         *
         * @param {string} container A selector for the container to draw to
         * @param {string} dataFile the name of the file that contains the data
         */
        function updateViolinChart(container) {

            var chartData = Drupal.settings.violin.violinData;

            var timePeriods = generateTimePeriods();
            var dataSet = [
                [],
                [],
                []
            ];
            for (var i = 0; i < chartData.length; i++) {
                var dateString = chartData[i].cover_date;
                var year = parseInt(dateString.split("-")[0]);
                for (var j = 0; j < timePeriods.length; j++) {
                    if (timePeriods[j][0] <= year && timePeriods[j][1] >= year) {
                        dataSet[j].push(parseInt(chartData[i].percentile_rank));
                        break;
                    }
                }
            }
            refreshViolinChart(container, dataSet);
        }

        /**
         * Generates the time periods to use. In the literature it is recommended that
         * the two most recent years are excluded from the analysis.
         */
        function generateTimePeriods() {
            var currentYear = new Date().getFullYear();
            return [
                [currentYear - 12, currentYear - 9],
                [currentYear - 8, currentYear - 6],
                [currentYear - 5, currentYear - 3]
            ];
        }

        /**
         * Appends a violin plot to the specified container.
         *
         * @param {string} container A selector for the container to draw to
         * @param dataSet the data set to use
         */
        function refreshViolinChart(container, dataSet) {

            var timePeriods = generateTimePeriods();

            var y =
                d3.scale.linear()
                    .range([height - margin.bottom, margin.top])
                    .domain(domain);

            var yAxis =
                d3.svg.axis()
                    .scale(y)
                    .ticks(ticks)
                    .orient("left")
                    .tickSize(5, 0);

            d3.select(container).select("svg").remove();

            // Add a warning about too few articles if needed
            var lessThanTen = false;
            for (var i = 0; i < dataSet.length; i++) {

                if (dataSet[i].length < 10) {
                    lessThanTen = true;
                }
            }
            if (lessThanTen) {
                d3.select("#tooltipArticleCount").style("display", "block");
            } else {
                d3.select("#tooltipArticleCount").style("display", "none");
            }

            var svg =
                d3.select(container)
                    .append("svg")
                    .attr("width", width)
                    .attr("height", height);

            // Append a definition for the gradient to use for the median markers
            var gradient = svg.append("defs").append("radialGradient").attr("id", "gradient");
            gradient.append("stop").attr("offset", "60%").attr("stop-color", colorThemes[colorTheme][3]);
            gradient.append("stop").attr("offset", "100%").attr("stop-color", colorThemes[colorTheme][2]);

            // Draw the grid lines
            for (var i = 0; i <= ticks; i++) {
                svg.append("line")
                    .attr("class", "grid")
                    .attr("x1", margin.left)
                    .attr("x2", width - margin.right)
                    .attr("y1", y(i * (domain[1] / ticks)))
                    .attr("y2", y(i * (domain[1] / ticks)))
                    .style("stroke-dasharray", ("3, 3"));
            }

            // Draw a violin for each time period
            for (var i = 0; i < dataSet.length; i++) {
                dataSet[i] = dataSet[i].sort(d3.ascending)
                var g = svg.append("g").attr("transform", "translate(" + (i * (violinWidth + violinSpacing) + margin.left + 50) + ",0)");
                appendViolin(g, dataSet[i], violinWidth, y(domain[0]) - y(domain[1]), domain);
            }

            // Append a median marker for each violin period. We have to do this in a separate
            // step to ensure correct "z-index" for the markers.
            for (var i = 0; i < dataSet.length; i++) {
                var g = svg.append("g").attr("transform", "translate(" + (i * (violinWidth + violinSpacing) + margin.left + 50) + ",0)");
                appendMedianMarker(g, dataSet[i], violinWidth, y(domain[0]) - y(domain[1]), domain);
            }

            // Draw the y-axis
            svg.append("g")
                .attr('class', 'axis')
                .attr("transform", "translate(" + margin.left + ",0)")
                .call(yAxis);

            // Draw the y-axis label
            svg.append("text")
                .attr('class', 'axis-label')
                .attr("transform", "rotate(-90)")
                .attr("y", 10)
                .attr("x", 0 - (height / 2))
                .attr("dy", "1em")
                .style("text-anchor", "middle")
                .text("PERCENTILE RANK");

            // Draw the x-axis labels
            for (var i = 0; i < dataSet.length; i++) {
                var x = (i * (violinWidth + violinSpacing) + margin.left + 50 + violinWidth / 2);
                svg.append("text")
                    .attr('class', 'axis-label')
                    .attr("transform", "translate(" + x + "," + (height - 20) + ")")
                    .style("text-anchor", "middle")
                    .text("N=" + dataSet[i].length);
                svg.append("text")
                    .attr('class', 'axis-label-bold')
                    .attr("transform", "translate(" + x + "," + (height) + ")")
                    .style("text-anchor", "middle")
                    .text(timePeriods[i][0] + "-" + timePeriods[i][1]);
            }
        }

        /**
         * Appends a violin to the specified chart.
         *
         * @param chart The chart to append to
         * @param data The data to use
         * @param width The width of the violin to draw
         * @param height The height of the violin to draw
         * @param domain The domain
         */
        function appendViolin(chart, data, width, height, domain) {

            var histogramData =
                d3.layout.histogram()
                    .bins(resolution)
                    .frequency(0)(data);

            // If we are drawing a smooth curve, append additional 0-levels at both ends
            // of histogram to close the paths more nicely.
            if (interpolation == "basis" || interpolation == "monotone") {
                var start = [];
                start.x = histogramData[0].x - histogramData[0].dx;
                start.y = 0;
                histogramData.unshift(start);
                var end = [];
                end.x = histogramData[histogramData.length - 1].x + histogramData[histogramData.length - 1].dx;
                end.y = 0;
                histogramData.push(end);
            }

            var y =
                d3.scale.linear()
                    .range([width / 2, 0])
                    .domain([0, d3.max(histogramData, function (d) {
                        return d.y;
                    })]);

            var x =
                d3.scale.linear()
                    .range([height, 0])
                    .domain([0, 100])
                    .nice();

            var area =
                d3.svg.area()
                    .interpolate(interpolation)
                    .x(function (d) {
                        if (interpolation == "step-before") {
                            return x(d.x + d.dx);
                        } else {
                            return x(d.x);
                        }
                    })
                    .y0(width / 2)
                    .y1(function (d) {
                        return y(d.y);
                    });

            var line =
                d3.svg.line()
                    .interpolate(interpolation)
                    .x(function (d) {
                        if (interpolation == "step-before") {
                            return x(d.x + d.dx);
                        } else {
                            return x(d.x);
                        }
                    })
                    .y(function (d) {
                        return y(d.y);
                    });

            var gBoth = chart.append("g");
            var gPlus = gBoth.append("g");
            var gMinus = gBoth.append("g");

            gPlus.append("path")
                .datum(histogramData)
                .attr("class", "area")
                .attr("d", area)
                .style("fill", colorThemes[colorTheme][0]);

            gPlus.append("path")
                .datum(histogramData)
                .attr("class", "violin")
                .attr("d", line)
                .style("stroke", colorThemes[colorTheme][0]);

            gMinus.append("path")
                .datum(histogramData)
                .attr("class", "area")
                .attr("d", area)
                .style("fill", colorThemes[colorTheme][0])


            gMinus.append("path")
                .datum(histogramData)
                .attr("class", "violin")
                .attr("d", line)
                .style("stroke", colorThemes[colorTheme][0]);

            gPlus.attr("transform", "rotate(90,0,0) translate(" + margin.top + ",-" + width + ")");
            gMinus.attr("transform", "rotate(90,0,0) scale(1,-1) translate(" + margin.top + ",0)");
            gBoth.on('mousemove', function () {
                displayTooltip("#tooltipViolin");
            })
                .on('mouseout', function () {
                    hideTooltip("#tooltipViolin");
                });

        }

        /**
         * Appends a median marker to the specified violin.
         *
         * @param chart The chart to append to
         * @param data The data to use
         * @param width The width of the violin to draw
         * @param height The height of the violin to draw
         * @param domain The domain
         */
        function appendMedianMarker(chart, data, width, height, domain) {

            var x =
                d3.scale.linear()
                    .range([height, 0])
                    .domain([0, 100])
                    .nice();

            // Draw a yellow circle for the median percentile rank
            var medianPercentileRank = Math.round(d3.median(data));
            var medianMarker =
                chart.append("g")
                    .attr("transform", "rotate(90,0,0) translate(" + margin.top + ",-" + width / 2 + ")");

            var circle =
                medianMarker
                    .append("circle")
                    .attr("class", "medianMarker")
                    .attr("cx", x(medianPercentileRank))
                    .attr("cy", 0)
                    .attr("r", 10)
                    .attr("stroke", colorThemes[colorTheme][1])
                    .attr("fill", "url(#gradient)")
                    .on('mousemove', function () {
                        hideTooltip("#tooltipViolin");
                        displayTooltip("#tooltipMedian");
                    })
                    .on('mouseout', function () {
                        hideTooltip("#tooltipMedian")
                    });

            // Draw a label for the median indicator. I admit, this is not the nicest way
            // to position an element.
            var medianLabel =
                medianMarker
                    .append("text")
                    .attr("transform", "translate(-" + margin.top + "," + width / 2 + ") rotate(-90, 0, 0) translate(" + ((width / 2) + 17) + "," + (x(medianPercentileRank) + margin.top + 5) + ")");

            medianLabel
                .append("tspan")
                .attr("class", "medianLabel")
                .text(medianPercentileRank);

            medianLabel
                .append("tspan")
                .attr("class", "medianLabelOrdinalIndicator")
                .attr("dy", -5)
                .text(ordinalIndicator(medianPercentileRank));

            medianLabel
                .append("tspan")
                .attr("class", "medianLabel")
                .attr("dy", 5)
                .text(" percentile");
        }

        /**
         * Displays the median tooltip.
         */
        function displayTooltip(element) {
            var div = d3.select(element);
            div.style("display", "block")
                .style("opacity", .85)
                .style("left", (d3.event.pageX + 28) + "px")
                .style("top", (d3.event.pageY - 28) + "px");
        }

        /**
         * Hides the median tooltip.
         */
        function hideTooltip(element) {
            d3.select(element).style("display", "none")
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


    } }
})(jQuery);