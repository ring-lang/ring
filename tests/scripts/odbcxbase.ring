See "Using DBF Files using ODBC" + nl
pODBC = odbc_init()
See "Connect to database" + nl
odbc_connect(pODBC,"Driver={Microsoft dBase Driver (*.dbf)};datasource=dBase Files;DriverID=277")
See "Select data" + nl
odbc_execute(pODBC,"select * from tel.dbf") + nl
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
