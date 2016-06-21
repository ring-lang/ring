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
 
 
