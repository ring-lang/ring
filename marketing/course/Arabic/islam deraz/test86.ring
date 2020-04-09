/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.16
*/

load "odbclib.ring"

# connect/Disconnect()
# Execute Query (SQL)
# Transaction (commit)
# save/restore binary data (images)

oODBC=odbc_init()
? odbc_drivers(oODBC)




