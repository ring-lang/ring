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
	oList = new list ( [ [1,"one"],[2,"two"],[3,"three"] ] )
	see copy("*",10) + nl
	oList.print()
	see "Search two : " + oList.findincolumn(2,"two") + nl
	see "Search 1 : " + oList.findincolumn(1,1) + nl
	oList = new list ( [ "Egypt" , "USA" , "KSA" ] )
	for x in oList
		see x + nl
	next
	oList =  new list ( [1,2,3,4] )
	oList + [5,6,7] 
	oList.print()
	oList = new list ( ["one","two"] )
	oList2 = new list ( ["three","four"] )
	oList + oList2
	oList.print()

Class List From StdBase

	vValue  = []

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

	Func FindinColumn nCol,value
		return std_findincolumn(vValue,value,nCol)

	Func Sort
		return new list ( std_sort(vValue) )
	
	Func Reverse
		return new list ( std_reverse(vValue) )

	Func Insert nIndex,Item
		std_insert(vValue,nIndex,Item)	

	Func operator cOperator,Para
		result = new list
		switch cOperator
			on "+"
				if isobject(para)
					for t in Para.vValue
						vValue + t
					next
				but islist(para)
					for t in Para
						vValue + t
					next
				ok
			on "len"
				return len( vValue )
			on "[]"
				return vValue[para]
		off
		return result
