# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
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
	oString.mid(1,4).println()
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
	oString {
		set("Hello") println()
		set("How are you?") println()
		see startswith("How") + nl
		see endswith("you?") + nl
	}


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
		return new string( std_lower(vValue) )

	Func Upper
		return new string( std_upper(vValue) )

	Func Left x
		return new string( std_left(vValue,x) )

	Func Right x
		return new string( std_right(vValue,x) )

	Func Lines
		return std_lines(vValue)

	Func Trim
		return new string( std_trim(vValue) )

	Func Copy x
		return new string( std_copy(vValue,x) )

	Func strcmp cStr
		return std_strcmp(vValue,cStr)

	Func tolist
		return std_str2list(vValue)

	Func tofile cFile
		write (cFile,vValue)

	Func mid nPos1,nPos2
		return new string( std_getsubstr(vValue,nPos1,nPos2) )

	Func getfrom nPos1
		return new string( std_getsubstrfrom(vValue,nPos1) )

	Func pos cStr
		return std_substrpos(vValue,cStr)

	Func replace cStr1,cStr2,lCase
		if lCase
			return new string( std_substrreplace(vValue,cStr1,cStr2) )
		else
			return new string(std_substrreplace_notcasesensitive(vValue,cStr1,cStr2))
		ok

	Func Split
		return str2list( substr(vValue," ",nl) )

	Func startswith substr
		if std_left(std_trim(vValue) , len(substr)) = substr return 1 else return 0 ok   

	Func endswith substr
		if std_right(std_trim(vValue), len(substr)) = substr return 1 else return 0 ok 

	Func operator cOperator,Para
		result = new string
		switch cOperator
			on "+"
		  		result.vValue = vValue + Para.vValue
			on "*"
				result.vValue = std_copy(vValue,Para)
			on "len"
				return len( vValue )
			on "[]"
				return vValue[para]
		off
		return result
