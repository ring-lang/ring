/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.29
*/

Load "odbclib.ring"

# Connect/Disconnect  
# Execute Query (SQL)
# Transaction (Commit)
# Save/Restore binary data (images)

oODBC = odbc_init()
? odbc_drivers(oODBC)
