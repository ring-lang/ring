# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
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


Class String

	cValue 

	Func Init x
		cValue = x

	Func Lower
		return new string( std_lower(cValue) )

	Func Upper
		return new string( std_upper(cValue) )
	
	Func Left x
		return new string( left(cValue,x) )
	
