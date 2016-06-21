# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	odbc_class_test()
ok

func odbc_class_test
	
	oodbc = new odbc
	See "Test the odbc Class Methods" + nl
 

Class odbc
 
	 
	Func init
		return std_odbc_init()

	Func drivers oODBC
		return std_odbc_drivers(oODBC)

	Func datasources oODBC
		return std_odbc_datasources(oODBC)

	Func close oODBC
		return std_odbc_close(oODBC)

	Func connect oODBC,cConString
		return std_odbc_connect(oODBC,cConString)

	Func disconnect oODBC
		return std_odbc_disconnect(oODBC)

	Func execute oODBC,cSQL
		return std_odbc_execute(oODBC)

	Func colcount oODBC
		return std_odbc_colcount(oODBC)

	Func fetch oODBC
		return std_odbc_fetch(oODBC)

	Func getdata oODBC,nCol
		return std_odbc_getdata(oODBC,nCol)

	Func tables oODBC
		return std_odbc_tables(oODBC)

	Func columns oODBC,cTableName
		return std_odbc_columns(oODBC,cTableName)

	Func autocommit oODBC,lStatus
		return std_odbc_autocommit(oODBC,lStatus)

	Func commit oODBC
		return std_odbc_commit(oODBC)

	Func rollback oODBC
		return std_odbc_rollback(oODBC)
