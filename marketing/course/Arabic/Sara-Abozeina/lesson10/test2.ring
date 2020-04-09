/*
**	Application:ODBC
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/

load "odbclib.ring"
odbc_init()

pODBC = odbc_init()
see odbc_connect(pODBC,"DBQ=test2.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl


see odbc_execute(pODBC,"select * from persons") + nl
nMax = odbc_colcount(pODBC)

while odbc_fetch(pODBC)
	?" "
        for x = 1 to nMax
                see odbc_getdata(pODBC,x)
		if x!=nMax see "-" ok
        next
end

odbc_disconnect(pODBC)
odbc_close(pODBC)
