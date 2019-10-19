# lesson 10  , Ring Practices with Dr.Mahmoud Fayed
# Date  : 18/10/2019
# title : DATABESE (Connect ODBC Driver)-(MYSQL) -(SQLIte) 
# Author: S.BOURROU

#==========================================================#
# ODBC
# We can use ODBC to Connect or Disconnect
# And Execute Queries (sql)
# Transactions (Commit) ..
# Store / restore binary data ( like images) ..

load "odbclib.ring"
objODBC = odbc_init()
? odbc_drivers(objODBC)
