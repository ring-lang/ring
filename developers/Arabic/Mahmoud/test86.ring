/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.20
*/

load "odbclib.ring"

# Connect/Disconnect 
# Execute Query (SQL)
# Transaction (Commit) 
# Save/Restore binary data (images)

oODBC = odbc_init()
? odbc_drivers(oODBC)
