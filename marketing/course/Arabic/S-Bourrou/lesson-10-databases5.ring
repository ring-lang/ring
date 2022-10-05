# Lesson 10  , Ring Practices with Dr.Mahmoud Fayed
# Date  : 18/10/2019
# Title : Database (Connect ODBC Driver)-(MySQL) -(SQLite)
# Author: S.BOURROU

#==========================================================#
# ODBC
# We can use ODBC to Connect or Disconnect
# And Execute Queries (sql)
# Transactions (Commit) ..
# Store / restore binary data ( like images) ..

load "odbclib.ring"

See "ODBC test " + nl

pODBC = odbc_init()
See "Connect to database" + nl
see odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
See "Select data" + nl

see odbc_execute(pODBC,"select * from Mytable") + nl
nMax = odbc_colcount(pODBC)

See "Columns Count : " + nMax + nl

while odbc_fetch(pODBC)
        See "" + nl
        for x = 1 to nMax
                see odbc_getdata(pODBC,x) 
         if x != nMax see " - " ok
        next
end
?""
See "Close database..." + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)
