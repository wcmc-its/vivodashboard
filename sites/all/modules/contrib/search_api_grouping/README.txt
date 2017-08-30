== BACKGROUND ==

This module has following version specific dependencies:
- Search API version >= 7.x-1.6  
- Search API Solr >=7.x-1.0

This module creates a meta index for entities so that proper searching and
sorting multi-valued fields becomes possible. Solr does not allow sorting on
multi-value fields, further it can't handle the relations between two properties
of the same multi-value field.
As such this module does the necessary de-normalization by computing the
cartesian product of entity values for each possible combination of the selected
multi-valued fields. For instance let us say you have the following node content
type:

nid: 1
type: product
multifield1:
    item1,
    item2
multivaluemultifield2:
    featureX1 featureX2,
    featureY1 featureY2
singlefielda:
    widget

This module de-normalizes this node into the following search entries if you
choose to de-normalize on both multivalue fields:
  nid: 1
  type: product
  multifield1: item1
  multivaluemultifield2-value1: featureX1
  multivaluemultifield2-value2: featureX2
  singlefielda: widget

  nid: 1
  type: product
  multifield1: item1
  multivaluemultifield2-value1: featureY1
  multivaluemultifield2-value2: featureY2
  singlefielda: widget

  nid: 1
  type: product
  multifield1: item2
  multivaluemultifield2-value1: featureX1
  multivaluemultifield2-value2: featureX2
  singlefielda: widget

  nid: 1
  type: product
  multifield1: item2
  multivaluemultifield2-value1: featureY1
  multivaluemultifield2-value2: featureY2
  singlefielda: widget

Due to this denormalization we will now be able to sort on the previously multi-
valued columns. Further the connection between the both values of the
multivaluemultifield2 is maintained, enabling us to filter properly by those
values.

This module also provides the possibility to group the results returned from
solr on configured fields. To do so enabled the processor "Grouping" and
configured the fields to group on.

Related Links:
Solr sorting on multi-value field: https://issues.apache.org/jira/browse/SOLR-2339

"Grouping" feature
------------------------
This module defines the "Grouping" feature (feature key: "search_api_grouping")
that search service classes can implement. With a server supporting this, you
can use the „Grouping“ processor to group the search result based on fields.

For developers:
A service class that wants to support this feature has to check for a
"search_api_grouping" option in the search() method. When present, it will be an
array containing following keys:
- use_grouping:  If set to TRUE the grouping is used.
- fields: An array of fields to use for grouping.
- group_sort: An associative array of fields that define how to sort documents
              within a group. Direction can be "asc" or "desc".
              group_sort = array(
                field_foo => direction,
                field_bar => direction,
              )
- truncate: If true, facet counts are based on the most relevant result of each
            group matching the query.

The options are based on the Solr FieldCollapsing:
http://wiki.apache.org/solr/FieldCollapsing

== CONFIGURATION ==

After enabling the module visit 'admin/config/search/search_api' and add a new
index. This module creates an index type for each entity type covered by search
API. These are identified by the prefix 'Denormalized' so to use this index for
nodes create a new index of item type 'Denormalized Node'.
The fields to use de-normalization and / or grouping can be configured in the
"Workflow" tab of the index.

== KNOWN ISSUES ==

Creating or Enabling / Disabling an index leads to a full rebuild of the
denormalized item ids. This can take quite some time.
