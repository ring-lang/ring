/*
	Application	: Database (ODBC) Version 2
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

pODBC = odbc_init()
? "Connect to database"
? odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}")
? "Select data"
? odbc_execute(pODBC,"select * from person")
nMax = odbc_colcount(pODBC)
? "Columns Count : " + nMax
while odbc_fetch(pODBC)
        ? "Row data:"
        for x = 1 to nMax
                see odbc_getdata(pODBC,x) + " - "
        next
end
? "Close database..."
odbc_disconnect(pODBC)
odbc_close(pODBC)


