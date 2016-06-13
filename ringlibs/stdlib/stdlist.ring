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
	see oList.item(1) + nl
	oList.delete(4)
	oList.print()
	see oList.first() + nl
	see oList.last() + nl
	oList { set(1,"one") set(2,"two") set(3,"three") print() }
	see oList.find("two") + nl
	oList.sort().print()
	oList.reverse().print()
	oList.insert(2,"nice")
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

	Func First		
		return vValue[1]

	Func Last
		return vValue[len(vValue)]

	Func Set nIndex,Value
		vValue[nIndex] = value

	Func Find value
		return std_find(vValue,value)

	Func Sort
		return new list ( std_sort(vValue) )
	
	Func Reverse
		return new list ( std_reverse(vValue) )

	Func Insert nIndex,Item
		std_insert(vValue,nIndex,Item)	
