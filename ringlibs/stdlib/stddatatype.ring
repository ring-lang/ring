# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	datatype_class_test()
ok

func datatype_class_test
	
	oDataType = new DataType
	See "Test the DataType Class Methods" + nl
 	 
Class DataType
 
