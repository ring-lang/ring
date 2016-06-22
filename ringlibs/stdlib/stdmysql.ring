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
	See "Test the mysql Class Methods" + nl
	omysql { 
	}

Class mysql
 
 
