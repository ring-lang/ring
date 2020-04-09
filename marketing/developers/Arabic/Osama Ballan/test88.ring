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
odbc_connect(pODBC,"DBQ=myDB.mdb;Driver={Microsoft Access Driver (*.mdb)}")
? "Select data"
odbc_execute(pODBC,"select * from myTable")
nMax = odbc_colcount(pODBC)
See "Columns Count : " + nMax + nl

while odbc_fetch(pODBC)
        ? ""
        for x = 1 to nMax
                see odbc_getdata(pODBC,x)
		if x != nMax see " - " ok
        next
end
? ""
? "Close database..."
odbc_disconnect(pODBC)
odbc_close(pODBC)

