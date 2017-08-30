(function ($) {

    Drupal.behaviors.citations = { attach: function (select, settings) {

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

        // Primary Department - Check
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
                height: 70,
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
                width: 450,
                height: 90,
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
                height: 60,
            }
        })

    } }
})(jQuery);