# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	conversion_class_test()
ok

func conversion_class_test
	
	oConversion = new conversion
	See "Test the conversion Class Methods" + nl
	See oConversion.number("3") + 5  + nl
	See oConversion.string(3) + "5" + nl
	See oConversion.Ascii("m") + nl	
	See oConversion.char(77) + nl	
	see oConversion.hex(162) + nl
	see oConversion.dec("a2") + nl
	cHex = oConversion.str2hex("Hello")
	see cHex + nl
	see oConversion.hex2str(cHex) + nl

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
