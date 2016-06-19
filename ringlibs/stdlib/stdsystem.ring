# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	system_class_test()
ok

func System_class_test
	
	ofile = new file

	See "Test the System Class Methods" + nl
 

Class System
 
