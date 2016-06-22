# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	mysql_class_test()
ok

func mysql_class_test
	
	omysql = new mysql
	See "Test the MySQL Class Methods" + nl
	omysql { 
		see info() + nl
		connect("localhost", "root", "root","mahdb")
		see "Execute Query" + nl
		query("SELECT * FROM Employee")
		see "Print Result" + nl
		see result2()
		see "Close database" + nl
		close()
	}

Class MySQL
 
	oMySQL = init()

	Func info
		return std_mysql_info()

	Func init
		return std_mysql_init()

	Func error 
		return std_mysql_error(oMySQL)

	Func connect cServer,cUser,cPass,cDatabase
		return std_mysql_connect(oMySQL,cServer,cUser,cPass,cDatabase)

	Func close 	
		return std_mysql_close(oMySQL)

	Func query cQuery
		return std_mysql_query(oMySQL,cQuery)

	Func insert_id
		return std_mysql_insert_id()

	Func result 
		return std_mysql_result(oMySQL)

	Func next_result 
		return std_mysql_next_result(oMySQL)

	Func columns 
		return std_mysql_columns(oMySQL)

	Func result2 
		return std_mysql_result2(oMySQL)

	Func escape_string cStr
		return std_mysql_escapse_string(oMySQL,cStr)

	Func autocommit lStatus
		return std_mysql_autocommit(oMySQL,lStatus)

	Func commit 
		return std_mysql_commit(oMySQL)

	Func rollback
		return std_mysql_rollback(oMySQL)


