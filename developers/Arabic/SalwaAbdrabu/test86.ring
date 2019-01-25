/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

load "odbclib.ring"

# Connect - Disconnect 
# Execute Query(Sql)
# Transaction (Commit)
# Save / Restore Binary Data (Images)

oODBC = odbc_init()
? odbc_drivers(oODBC)

