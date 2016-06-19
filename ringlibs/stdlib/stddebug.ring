# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	debug_class_test()
ok

func Debug_class_test
	
	oDebug = new Debug

	See "Test the Debug Class Methods" + nl
 	 

Class Debug
 
