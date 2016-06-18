# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	datetime_class_test()
ok

func datetime_class_test
	
	odatetime = new datetime

	See "Test the datetime Class Methods" + nl

Class datetime 
