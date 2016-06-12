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
	oString.println()
	oString.upper().println()
	oString.lower().println()
	oString.left(5).println()
	oString.right(6).println()
	oString = new string("Hi" + nl + "Hello" )
	See oString.lines() + nl
	oString = new string("    Welcome    ")
	oString.println()
	oString.trim().println()
	oString = new string("Hello! ")
	oString.copy(3).println()
	see oString.strcmp("Hello! ") + nl
	see oString.strcmp("Hello ") + nl
	see oString.strcmp("Hello!! ") + nl
	oString = new string(["one","two","three"])
	oString.print()
	see oString.lines() + nl
	oString = new String(1234)
	oString.println()
	oString = new String("one"+nl+"two"+nl+"three")
	aList = oString.tolist()
	see "List Items" + nl See aList
	oString = new String( "Welcome to the Ring programming language")
	See "the - position : " + oString.pos("the") + nl
	oString = oString.getfrom(oString.pos("Ring"))
	oString.println()
	oString.get(1,4).println()
	oString = oString.replace("Ring","***Ring***",true)
	oString.println()
	oString = oString.replace("ring","***Ring***",false)
	oString.println()
	oString1 = new string("First")
	oString2 = new string("Second")
	oString = oString1 + oString2
	oString.println()
	oString = oString1 * 3
	oString.println()
	for t in ostring see t next
	oString.tofile("test.txt")
	oString = new string("one two three")
	see nl
	see ostring.split()

Class String From StdBase

	Func Init x
		if isstring(x)
			super.init(x)
		but isnumber(x)
			super.init(""+x)
		but islist(x)
			super.init(list2str(x))
		else
			raise("Error: String Class - Init Method - Bad Parameter")
		ok

	Func Lower
		return new string( std_lower(cValue) )

	Func Upper
		return new string( std_upper(cValue) )

	Func Left x
		return new string( std_left(cValue,x) )

	Func Right x
		return new string( std_right(cValue,x) )

	Func Lines
		return std_lines(cValue)

	Func Trim
		return new string( std_trim(cValue) )

	Func Copy x
		return new string( std_copy(cValue,x) )

	Func strcmp cStr
		return std_strcmp(cValue,cStr)

	Func tolist
		return std_str2list(cValue)

	Func tofile cFile
		write (cFile,cValue)

	Func get nPos1,nPos2
		return new string( std_getsubstr(cValue,nPos1,nPos2) )

	Func getfrom nPos1
		return new string( std_getsubstrfrom(cValue,nPos1) )

	Func pos cStr
		return std_substrpos(cValue,cStr)

	Func replace cStr1,cStr2,lCase
		if lCase
			return new string( std_substrreplace(cValue,cStr1,cStr2) )
		else
			return new string(std_substrreplace_notcasesensitive(cValue,cStr1,cStr2))
		ok

	Func Split
		return str2list( substr(cValue," ",nl) )

	Func operator cOperator,Para
		result = new string
		switch cOperator
			on "+"
		  		result.cValue = cValue + Para.cValue
			on "*"
				result.cvalue = std_copy(cValue,Para)
			on "len"
				return len( cValue )
			on "[]"
				return cValue[para]
		off
		return result
