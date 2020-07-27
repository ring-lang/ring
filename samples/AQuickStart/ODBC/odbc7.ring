load "odbclib.ring"

See "ODBC Test - Transactions and using Commit and Rollback" + nl
pODBC = odbc_init()
See "Connect to database" + nl
see odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
see "insert data..." + nl
odbc_autocommit(pODBC,0)
for x = 1 to 10000
        odbc_execute(pODBC,"insert into tel values (" + x + ",'mahmoud')")
next
for x = 10001 to 15000
        odbc_execute(pODBC,"insert into tel values (" + x + ",'samir')")
next
odbc_commit(pODBC)

for x = 15001 to 20000
        odbc_execute(pODBC,"insert into tel values (" + x + ",'fayed')")
next

ODBC_ROLLBACK(pODBC)
odbc_execute(pODBC,"insert into tel values (" + x + ",'fayed')")
odbc_commit(pODBC)

See "Close database..." + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)
