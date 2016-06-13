# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	list_class_test()
ok

func list_class_test
	oList = new list ( [1,2,3] )
	oList.Add(4)
	oList.print()

Class List From StdBase

	Func Init x
		if isstring(x) or isnumber(x)
			super.init([x])
		but islist(x)
			super.init(x)
		else
			raise("Error: List Class - Init Method - Bad Parameter")
		ok

	Func Add x
		std_add( vValue , x)

	Func Delete x
		std_del( vValue , x)
			
	Func Item x
		return vValue[x]

