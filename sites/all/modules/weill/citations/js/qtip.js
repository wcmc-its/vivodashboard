(function ($) {

    Drupal.behaviors.qtip = { attach: function (select, settings) {

        // Date
        $('#block-facetapi-lkqcrnwhh0w8oreifrey1soxj2amemzn').find('h2').qtip({
            content: {
                text: 'Restrict the result to a year or range of years. If you filter by only the last year, you have the option to filter by a month range.'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 80,
            }
        })

        // Publications Type
        $('#block-facetapi-kqcaslr11zlcnoeq8gpzwtfwixmstwpf').find('h2').qtip({
            content: {
                text: 'Restrict the results to one or more publication types'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Journal Ranking
        $('#block-facetapi-wcrb4ptcvgwsmstin1cruoij2qkzcucd').find('h2').qtip({
            content: {
                text: 'Restrict the results to journals within a given range of <a href="http://www.scimagojr.com/journalrank.php" target="_blank">Scimago Journal Ranks</a>'
            },
            hide: {
                // when: 'mouseout',
                delay: 200,
                fixed: true,
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Journal Name
        $('#block-facetapi-joamqhc51crojdan62s0gscukpgdhsbc').find('h2').qtip({
            content: {
                text: 'Restrict the results to articles appearing in a given journal'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Author Name
        $('#block-facetapi-zgxe3uetec8mcpg5jsk6r1lxiyakxfr9').find('h2').qtip({
            content: {
                text: 'Display data on publications by a given author'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Author Type
        $('#block-facetapi-2qhq5etqbigqyi7v1nktfercdihrjxps').find('h2').qtip({
            content: {
                text: 'Restricts <a href="https://nexus.weill.cornell.edu/display/IdentityManagement/Person+Types">Person Types</a> (login required) of authors. Note that this a person type refers to someone\'s CURRENT status as opposed to the status at the time they authored the article'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 600,
                height: 100,
            }
        })

        // Organization
        $('#block-facetapi-jz4xg8z7tykn8nn8cvrzismzn6thtl9z').find('h2').qtip({
            content: {
                text: 'Authors\' organizational affiliation at the time of publication. For academics, only the primary appointment is included'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 60,
            }
        })


        // First/Last Author Affiliation
        $('#block-facetapi-cz1p15wi0ll07i3k144vjuknf9sayvdc').find('h2').qtip({
            content: {
                text: 'Restrict the results to articles for which the first or last author was affiliated with a given institution'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 60,
            }
        })

        // First/Last Author Position
        $('#block-facetapi-01785nw3yteygf6akiwbdvuurex7ir0v').find('h2').qtip({
            content: {
                text: 'Restrict the results to articles on which the author appeared as first or last author in the author list'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        $('#block-facetapi-xte1a0ewhfa0e3jtjx4jjvcisw0yjrgb').find('h2').qtip({
            content: {
                text: 'Restrict the results to articles appearing in journals in specific fields'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Author Name
        $('#block-facetapi-g86ny0s9ggdbbilbxjijtktci1i1zclx').find('h2').qtip({
            content: {
                text: 'Display data on publications by a given author'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Primary Department
        $('#block-facetapi-ka19ut0wlb7qn28u1z3vzl6ipivve74p').find('h2').qtip({
            content: {
                text: 'Display data on articles written by authors with a given primary departmental affiliation'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Publications Type
        $('#block-facetapi-g2ihwxbjqdazqc9lxg4iuvekabi0aksp').find('h2').qtip({
            content: {
                text: 'Restrict the results to one or more publication types'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // First/Last Author Position
        $('#block-facetapi-01785nw3yteygf6akiwbdvuurex7ir0v').find('h2').qtip({
            content: {
                text: 'Restrict the results to articles on which the author appeared as first or last author in the author list'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Journal Category
        $('#block-facetapi-xte1a0ewhfa0e3jtjx4jjvcisw0yjrgb').find('h2').qtip({
            content: {
                text: 'Restrict the results to articles appearing in journals in specific fields'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 50,
            }
        })

        // Organization for Publication Tab
        $('#block-facetapi-hyunac1sagsoxcjox4olw5ebkm7jgiu4').find('h2').qtip({
            content: {
                text: 'Authors\' organizational affiliation at the time of publication. For academics, only the primary appointment is included'
            },
            position: {
                my: 'bottom center',
                at: 'top center',
            },
            style: {
                classes: 'qtip-light qtip-shadow',
                width: 400,
                height: 60,
            }
        })

        //Publication Tab Text - Open
        $('.notification-open').click(function() {
            $("#notification-text").slideDown(500);
            $(".notification-close").css("display","block");
            $('.notification-open').css("display","none");

        });
        //Publication Tab Text - Close
        $('.notification-close').click(function() {
            $("#notification-text").slideUp(500);
            $(".notification-close").css("display","none");
            $('.notification-open').css("display","block");

        });
        // Publication List citations
        $('.qtip-citation').qtip({
             position: {
                    my: 'left center',
                    at: 'right center'
                },
                style: {
                    classes: 'qtip-light qtip-shadow popupContainer'
                },
                show: {
                    event: 'click',
                },
                hide: {
                    event: 'unfocus'
                }
          })

        // Publication List Author popup
        $('.qtip-author').qtip({
            content: {
                text: function(event, api) {
                    $.ajax({
                        url: '/publication_profile_by_cwid/'+api.elements.target.attr('data-cwid') // Use href attribute as URL
                    })
                    .then(function(content) {
                        // Set the tooltip content upon successful retrieval
                        api.set('content.text', content);
                    }, function(xhr, status, error) {
                        // Upon failure... set the tooltip content to error
                        api.set('content.text', status + ': ' + error);
                    });
        
                    return 'Loading...'; // Set some initial text
                },
                button: true
            },
            position: {
                // my: 'bottom center',at: 'top center',
                // viewport: $(window)
                my: 'center', at: 'center',
                target: $(window)
            },
            style: {
                classes: 'qtip-light qtip-shadow popupContainer popupAuthorContainer'
            },
            show: {
                event: 'click',
                modal: {
                    on: true
                }
            },
            hide: {
                event: 'unfocus'
            }
          })

    } }
})(jQuery);