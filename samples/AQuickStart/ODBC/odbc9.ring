load "odbclib.ring"

See "ODBC Test - Restore image from the database" + nl
pODBC = odbc_init()
See "Connect to database" + nl
see odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
See "Select data" + nl
see odbc_execute(pODBC,"select * from tel") + nl
nMax = odbc_colcount(pODBC)
See "Columns Count : " + nMax + nl
while odbc_fetch(pODBC)
        See "Write image file" + nl
        write("great.jpg",hex2str( odbc_getdata(pODBC,3) ) )
end
See "Close database..." + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)
