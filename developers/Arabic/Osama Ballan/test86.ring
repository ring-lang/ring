/*
**	Application	: Ring lessons - DataBase(ODBC) .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 14 .
*/

# DataBase

# ODBC ( Connect - DataBase - ODBC Driver )
# MySQL
# SQLite
# GUI Framework (QT) - DataBase Classes
# ==============================
load "odbclib.ring"

# Connect / Disconnect
# Execute Query (SQL)
# Transaction(Commit)
# Save / Restore Binary Data (Images)

oODBC = odbc_init()
? odbc_drivers(oODBC)
? copy("*",20)
? odbc_datasources(oODBC)

odbc_close(oODBC)
