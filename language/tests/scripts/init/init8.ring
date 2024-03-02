load "stdlibclasses.ring"
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