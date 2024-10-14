/*
	Application	: Database (ODBC) Version 1
	Author		: Ahmed Mohamed
	Date		: 2019/10/25
*/

# Database

# ODBC (Connect - Database - ODBC Driver)
# MySQL
# SQLite
# GUI Framework (Qt) - Database Classes
#================================================

load "odbclib.ring"

# Connect/Disconnect
# Execute
# Transaction (Commit)
# Save/Restore Binary Data (Images)

oODBC = odbc_init()

? odbc_drivers(oODBC)
