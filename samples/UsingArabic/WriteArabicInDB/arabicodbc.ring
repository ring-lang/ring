load "odbclib.ring"
See "ODBC test 4" + nl
pODBC = odbc_init()
See "Connect to database" + nl
see odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
See "Select data" + nl
odbc_execute(pODBC,"insert into tel values (44,'محمود','')  ")
see odbc_execute(pODBC,"select * from tel where name = 'محمود' ") + nl
nMax = odbc_colcount(pODBC)
See "Columns Count : " + nMax + nl
while odbc_fetch(pODBC)
        See "Row data:" + nl
        for x = 1 to nMax
                see odbc_getdata(pODBC,x) + " - "
        next
end
See "Close database..." + nl
see "محمود" + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)
