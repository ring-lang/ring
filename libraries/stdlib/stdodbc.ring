# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	odbc_class_test()
ok

func odbc_class_test
	
	oodbc = new odbc
	See "Test the odbc Class Methods" + nl
	oODBC { 
 		see drivers()
		see datasources()
		See "Connect to database" + nl
		see connect("DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") + nl
		See "Select data" + nl
		see execute("select * from person") + nl
		nMax = colcount()
		See "Columns Count : " + nMax + nl
		while fetch()
		        See "Row data:" + nl
		        for x = 1 to nMax
		                see getdata(x) + " - "
		        next
		end
		See "Close database..." + nl
		disconnect()
		close()
	}

Class odbc
 
	oODBC = init()
	 
	Func init
		return std_odbc_init()

	Func drivers  
		return std_odbc_drivers(oODBC)

	Func datasources  
		return std_odbc_datasources(oODBC)

	Func close  
		return std_odbc_close(oODBC)

	Func connect cConString
		return std_odbc_connect(oODBC,cConString)

	Func disconnect  
		return std_odbc_disconnect(oODBC)

	Func execute cSQL
		return std_odbc_execute(oODBC,cSQL)

	Func colcount 
		return std_odbc_colcount(oODBC)

	Func fetch
		return std_odbc_fetch(oODBC)

	Func getdata nCol
		return std_odbc_getdata(oODBC,nCol)

	Func tables
		return std_odbc_tables(oODBC)

	Func columns cTableName
		return std_odbc_columns(oODBC,cTableName)

	Func autocommit lStatus
		return std_odbc_autocommit(oODBC,lStatus)

	Func commit 
		return std_odbc_commit(oODBC)

	Func rollback
		return std_odbc_rollback(oODBC)
