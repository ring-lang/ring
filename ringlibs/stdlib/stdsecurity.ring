# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	secuirty_class_test()
ok

func secuirty_class_test
	
	osecuirty = new secuirty
	See "Test the secuirty Class Methods" + nl
	osecuirty { 
	}

Class secuirty
 
