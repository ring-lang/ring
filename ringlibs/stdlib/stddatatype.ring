# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	datatype_class_test()
ok

func datatype_class_test
	
	oDataType = new DataType
	See "Test the DataType Class Methods" + nl
	see oDataType.isstring("test") + nl
	see oDataType.isnumber(1) + nl
	see oDataType.islist(1:3) + nl
	see oDataType.type("test") + nl
	see oDataType.isnull(null) + nl
	see oDataType.isalnum("Hello") + nl +     # print 1
	oDataType.isalnum("123456") + nl +    # print 1
	oDataType.isalnum("ABCabc123") + nl + # print 1
	oDataType.isalnum("How are you")  + nl     # print 0 because of spaces
 	see oDataType.isalpha("Hello") + nl +     # print 1
    	oDataType.isalpha("123456") + nl +    # print 0
   	oDataType.isalpha("ABCabc123") + nl + # print 0
   	oDataType.isalpha("How are you")  + nl    # print 0
	See oDataType.iscntrl("hello") + nl +     # print 0
	oDataType.iscntrl(nl)                 # print 1
	see oDataType.isdigit("0123456789") + nl +        # print 1
	oDataType.isdigit("0123a") + nl
	see oDataType.isgraph("abcdef") + nl +    # print 1
	oDataType.isgraph("abc def")   + nl        # print 0
	see oDataType.islower("abcDEF") + nl +    # print 0
	oDataType.islower("ghi") + nl          # print 1
	see oDataType.isprint("Hello") + nl +             # print 1
	oDataType.isprint("Nice to see you") + nl +   # print 1
	oDataType.isprint(nl)    + nl                      # print 0
	see oDataType.isprint("Hello") + nl              # print 1
	see oDataType.isupper("welcome") + nl +    # print 0
	oDataType.isupper("WELCOME")  + nl         # print 1
	see oDataType.isxdigit("0123456789abcdef") + nl +  # print 1
	oDataType.isxdigit("123z")                     # print 0

Class DataType
 
	Func isstring vValue
		return std_isstring(vValue)

	Func isnumber vValue
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
