# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	string_class_test()
ok

func string_class_test

	See "Testing the String Class" + nl
	oString = new string("Hello, World!")
	see oString
	oString2 = oString.upper()
	see oString2
	oString2 = oString.lower()
	see oString2
	oString2 = oString.left(5)
	see oString2


Class String From StdBase

	Func Lower
		return new string( std_lower(cValue) )

	Func Upper
		return new string( std_upper(cValue) )
	
	Func Left x
		return new string( std_left(cValue,x) )
	
