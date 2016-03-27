See "ODBC test 3" + nl
pODBC = odbc_init()

see pODBC

See "Connect to database" + nl
see odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl

pODBC2 = pODBC

See "after copy" + nl
see pODBC
see pODBC2

See "disconnect" + nl
odbc_disconnect(pODBC)

See "Close database..." + nl
odbc_close(pODBC)

See "After Close..." + nl
see pODBC
see pODBC2


See "Crash" + nl
odbc_close(pODBC2)

see pODBC
see pODBC2
