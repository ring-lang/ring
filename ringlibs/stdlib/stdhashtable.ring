# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	hashtable_class_test()
ok

func hashtable_class_test
	
	ohashtable = new hashtable
	See "Test the hashtable Class Methods" + nl
	ohashtable { 
		
	}

Class hashtable
 
