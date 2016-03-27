See "ODBC test - Save image in the database" + nl
pODBC = odbc_init()
See "Connect to database" + nl
see odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
see "insert data..." + nl
cFile = read("tests\mahmoud.jpg")
cFile = str2hex(cFile)
see "size " + len(CFile)+nl
stmt = "insert into tel values (20000,'mahmoud','" + cFile + "');"
odbc_execute(pODBC,stmt)

See "Close database..." + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)

