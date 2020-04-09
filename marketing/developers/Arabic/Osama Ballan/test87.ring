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

pODBC = odbc_init()
? "Connect to database"
? odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}")
? "Select data"
? odbc_execute(pODBC,"select * from person")
nMax = odbc_colcount(pODBC)
See "Columns Count : " + nMax + nl
while odbc_fetch(pODBC)
        See "Row data:" + nl
        for x = 1 to nMax
                see odbc_getdata(pODBC,x) + " - "
        next
end
See "Close database..." + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)

