/*
	Application	: Database (ODBC) Version 1
	Author		: Ahmed Mohamed
	Date		: 2019/10/25
*/

# Database

# ODBC (Connect - Database - ODBC Driver)
# MYSql
# SQLite
# GUI Framework (QT) - Database Classes
#================================================

load "odbclib.ring"

# Connect/Dicconnect
# Execute
# Transaction (Commit)
# Save/Restore Binary Data (Images)

oODBC = odbc_init()

? odbc_drivers(oODBC)
