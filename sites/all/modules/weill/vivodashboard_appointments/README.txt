--------------------------------------------------------------------------------
VIVO Dashboard Appointments module
--------------------------------------------------------------------------------

This module incorporates WCMC faculty appointment data into VIVO Dashboard. It
does this by linking the CWID of publication authors with appointment data and
organizations in violin_appointments and violin_org_units.


Updating appointment data
-------------------------

After updating data in violin_appointments or violin_org_units, all search
indexes must be re-indexed. Run the following commands:

  $ drush cc all
  $ drush search-api-reindex

This will mark all indexes for re-indexing and they will be slowly re-indexed
during cron runs. To re-index immediately, you can run:

  $ drush search-api-index
  