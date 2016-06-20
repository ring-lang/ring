# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	datatype_class_test()
ok

func datatype_class_test
	
	oDataType = new DataType
	See "Test the DataType Class Methods" + nl
 	 
Class DataType
 
	Func isstring vValue
		return std_isstring(vValue)

	Func strd_isnumber vValue
		return std_isnumber(vValue)

	Func islist vValue
		return std_islist(vValue)

	Func type vValue
		return std_type(vValue)

	Func isnull vValue
		return std_isnull(vValue)

	Func isalnum vValue
		return std_isalnum(vValue)

	Func isalpha vValue
		return std_isalpha(vValue)

	Func iscntrl vValue
		return std_iscntrl(vValue)

	Func isdigit vValue
		return std_isdigit(vValue)

	Func isgraph vValue
		return std_isgraph(vValue)

	Func islower vValue
		return std_islower(vValue)

	Func isprint vValue
		return std_isprint(vValue)

	Func ispunct vValue
		return std_ispunct(vValue)

	Func isspace vValue
		return std_isspace(vValue)

	Func isupper vValue
		return std_isupper(vValue)

	Func isxdigit vValue
		return std_isxdigit(vValue)
