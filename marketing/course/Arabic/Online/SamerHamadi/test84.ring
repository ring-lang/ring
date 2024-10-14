/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 22/12/2017
*/
#================================================================

load "odbclib.ring"

# Connect/Disconnect 
# Excute Query (SQL)
# Transaction (commit)
# Save/Restore binary data (images)

oODBC = odbc_init()
? odbc_drivers(oODBC)
