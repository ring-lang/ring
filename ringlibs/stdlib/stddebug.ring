# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	debug_class_test()
ok

func Debug_class_test
	
	oDebug = new Debug
	See "Test the Debug Class Methods" + nl
	oDebug.eval("see 'Hello'+nl")
	try
		x = 10
		oDebug.assert(x=11)
	catch see "assert" + nl done
	raise("Error!")
 	 
Class Debug
 
	Func eval cCode
		return std_eval(cCode)

	Func raise cError
		std_raise(cError)

	Func assert cCondition
		std_assert(cCondition)
