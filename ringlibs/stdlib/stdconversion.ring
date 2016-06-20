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
 
	Func number vValue
		return std_number(vValue)

	Func string vValue
		return std_string(vValue)

	Func ascii vValue
		return std_ascii(vValue)

	Func char vValue
		return std_char(vValue)

	Func hex vValue
		return std_hex(vValue)

	Func dec vValue
		return std_dec(vValue)

	Func str2hex vValue
		return std_str2hex(vValue)

	Func hex2str vValue
		return std_hex2str(vValue)
