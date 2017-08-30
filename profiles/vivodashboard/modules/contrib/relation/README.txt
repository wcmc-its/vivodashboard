SUMMARY
=======

Describes relations between entities (comment, node, user etc).

Here's how every relation looks:

  Relation
       |
       +----+ entity 1
       |
       +----+ entity 2
       |
      ...
       |
       +----+ entity N


Every relation looks like this. N is called the arity of the relation.
For directional relations, entity 1 is called the source, the rest are called
targets.

An example of a non-directional, n-ary relation:

  siblings(john, jen, jack, jess)

A binary, directional relation:

  child(bruno, Boglarka)

Relations can be directional, ie:
  parent(boglarka, bruno, sara)

Where Bruno and Sara are siblings http://www.flickr.com/photos/pnegyesi/6041665852
and Boglarka are their mother. Once again, the first entity has a special
role, in this case, it's the parent.

Relations are entities, so they can relate relations to other entities, for
example:
  CompanyA -> donation123 -> PartyB
  donations123 -> transaction456 -> BankC
  that is, "Company A made a donation to Political Pary B, via Bank C".

The entities in the relation can be thought of as the subject and object(s)
of the relation.

  Entity relation type    = SUBJECT   + PREDICATE      + OBJECT
  Node author relation    = node      + creator        + user
  Taxonomy field relation = blog post + is tagged with + some term

Relation bundles are fieldable, so you can add any relevant fields. For
example, with the donation example above, you could add a text field denoting
"amount ($)", or a date field specifying when the donation was made.

ROADMAP
=======
See the Live, Self-Organising RoadMap (LSORM™) at:
http://drupal.org/project/issues/search/relation?status[]=Open&categories[]=task&categories[]=feature

USAGE
=====

* Go to admin/structure/relation, and create a new relation type. Add fields if
  neccesary.
* Enable the relation_entity_collector block if it is not enabled on install -
  it tries to insert itself after the system management block if that one is
  enabled.
* To use the relation_entity_collector block, go to any page that loads
  entities, and the entity selector will appear.
* "Pick" as many entities as you need for your relation type (between min_ and
  max_arity in the appropriate relation bundle). Picks remain until cleared
  or the relation is created.
* Click "Create Relation", your relation will be created, and you will be given
  a link to the relation page.
* Here you can view the relation, and edit it to add or change field data.
* To see the relation later, the relation_dummy_field shows it on the entities
  belonging to the relation.

For more detailed instructions see https://www.drupal.org/node/1274796

UNINSTALLING RELATION
=====================

1. If you are using the relation dummy field, delete every field of 'relation'
   type then run cron. This is the same as deleting any other field.
2. You also need to disable and uninstall every other module depending on the
   Relation Endpoints module in the order allowed.
3. Once relation module itself is disabled and uninstalled it marks the
   endpoints field for deletion. You need to run cron to remove the contents
   of the endpoints table. This might require several cron runs. You will see
   on the modules page how relation endpoints can not be uninstalled because
   there are fields using it.
4. Now you can disable and uninstall relation endpoints itself.


CONTACT
=======

Current maintainers:
* Mikko Rantanen (mikran) - https://www.drupal.org/u/mikran

Former maintainers:
* Daniel F. Kudwien (sun) - http://drupal.org/user/54136
* Ned Haughton (naught101) - http://drupal.org/user/44216
* Karoly Negesi (chx) - http://drupal.org/user/9446
