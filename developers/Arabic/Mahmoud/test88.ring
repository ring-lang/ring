/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.20
*/

load "odbclib.ring"

pODBC = odbc_init()
? "Connect to database"
odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
? "Select data" 
odbc_execute(pODBC,"select * from mytable") 
nMax = odbc_colcount(pODBC)
? "Columns Count : " + nMax 
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

