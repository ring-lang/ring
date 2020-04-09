/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 04/04/2018
*/

load "ODBClib.ring"

# Connect/Disconnect
# Execute Query (SQL)
# Transaction (Comit)
# Save/Restore binary data (images)

oODBC = odbc_init()
? odbc_drivers(oODBC)
