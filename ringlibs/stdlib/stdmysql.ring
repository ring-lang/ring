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
	}

Class MySQL
 

	Func info
		return std_mysql_info()

	Func init
		return std_mysql_init()

	Func error oMySQL
		return std_mysql_error(oMySQL)

	Func connect oMySQL,cServer,cUser,cPass
		return std_mysql_connect(oMySQL,cServer,cUser,cPass)

	Func close oMySQL	
		return std_mysql_close(oMySQL)

	Func query oMySQL,cQuery
		return std_mysql_query(oMySQL,cQuery)

	Func insert_id
		return std_mysql_insert_id()

	Func result oMySQL
		return std_mysql_result(oMySQL)

	Func next_result oMySQL
		return std_mysql_next_result(oMySQL)

	Func columns oMySQL
		return std_mysql_columns(oMySQL)

	Func result2 oMySQL
		return std_mysql_result2(oMySQL)

	Func escape_string oMySQL,cStr
		return std_mysql_escapse_string(oMySQL,cStr)

	Func autocommit oMySQL,lStatus
		return std_mysql_autocommit(oMySQL,lStatus)

	Func commit oMySQL
		return std_mysql_commit(oMySQL)

	Func rollback oMySQL
		return std_mysql_rollback(oMySQL)


