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
 
	Func mysql_info
		return std_mysql_info()

	Func mysql_init
		return std_mysql_init()

	Func mysql_error oMySQL
		return std_mysql_error(oMySQL)

	Func mysql_connect oMySQL,cServer,cUser,cPass
		return std_mysql_connect(oMySQL,cServer,cUser,cPass)

	Func mysql_cose oMySQL	
		return std_mysql_close(oMySQL)

	Func mysql_query oMySQL,cQuery
		return std_mysql_query(oMySQL,cQuery)

	Func mysql_insert_id
		return std_mysql_insert_id()

	Func mysql_result oMySQL
		return std_mysql_result(oMySQL)

	Func mysql_next_result oMySQL
		return std_mysql_next_result(oMySQL)

	Func mysql_columns oMySQL
		return std_mysql_columns(oMySQL)

	Func mysql_result2 oMySQL
		return std_mysql_result2(oMySQL)

	Func mysql_escape_string oMySQL,cStr
		return std_mysql_escapse_string(oMySQL,cStr)

	Func mysql_autocommit oMySQL,lStatus
		return std_mysql_autocommit(oMySQL,lStatus)

	Func mysql_commit oMySQL
		return std_mysql_commit(oMySQL)

	Func mysql_rollback oMySQL
		return std_mysql_rollback(oMySQL)


