# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	conversion_class_test()
ok

func conversion_class_test
	
	oconversion = new conversion
	See "Test the conversion Class Methods" + nl

Class conversion
 
