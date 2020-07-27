load "odbclib.ring"

See "ODBC test - Get Database Tables" + nl
pODBC = odbc_init()
See "Connect to database" + nl
odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
See "Select data" + nl
odbc_tables(pODBC) + nl
nMax = odbc_colcount(pODBC)
See "Columns Count : " + nMax + nl
while odbc_fetch(pODBC)
        for x = 1 to nMax
                see odbc_getdata(pODBC,x)
                if x != nMax see " - " ok
        next
        See nl
end
See "Close database..."
odbc_disconnect(pODBC)
odbc_close(pODBC)
