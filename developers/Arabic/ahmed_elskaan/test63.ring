/*
**	Application Name : ODBC;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-22;		
*/
load "odbclib.ring"
pODBC = odbc_init()
? "Connect to database"
odbc_connect(pODBC,"DBQ=Database2.accdb;Driver={Microsoft Access Driver (*.mdb)}")
? "Select data"
odbc_execute(pODBC,"select * from test")
nMax = odbc_colcount(pODBC)
? "Columns Count : " + nMax
while odbc_fetch(pODBC)
        ? "Row data:"
        for x = 1 to nMax
                see odbc_getdata(pODBC,x) 
		if x != nMax see " - " ok
        next
end
see ""
? "Close database..."
odbc_disconnect(pODBC)
odbc_close(pODBC)
