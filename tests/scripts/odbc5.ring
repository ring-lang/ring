func main

See "ODBC test 5" + nl
pODBC = odbc_init()
pODBC2 = odbc_init()
See "Connect to database" + nl
see odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
odbc_connect(pODBC2,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
See "Select data" + nl
see odbc_execute(pODBC,"select top 3 * from person") + nl
odbc_execute(pODBC2,"select top 1 * from person") + nl

printdata(pODBC)

see "
==========
more data 
==========
" + nl

printdata(pODBC2)


See "Close database..." + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)
See "Close database 2..." + nl
odbc_disconnect(pODBC2)
odbc_close(pODBC2)

func printdata pObj

nMax = odbc_colcount(pObj)
See "Columns Count : " + nMax + nl
while odbc_fetch(pObj)
	See "Row data:" + nl
	for x = 1 to nMax
		see odbc_getdata(pObj,x) + " - "
	next
	see nl
end
