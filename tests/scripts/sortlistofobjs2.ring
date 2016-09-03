Func main
	myList = [
		new Company {position=3 name="Mahmoud" symbol="MHD"},
		new Company {position=2 name="Bert" symbol="BRT"},
		new Company {position=1 name="Ring" symbol="RNG"}
          	]
	see sortlistofobjs(mylist,"position")
	see copy("*",70) + nl
	see sortlistofobjs(mylist,"name")
	see copy("*",70) + nl
	see sortlistofobjs(mylist,"symbol")

Func sortlistofobjs aList,cAttribute
	if len(aList) <= 1 return aList ok
	aAttributes = attributes(aList[1]) 
	if not  find(aAttributes,cAttribute)  raise ("Error in attribute name") ok		
	aTempList = []
	for x=1 to len(aList)		
		aTempList + [x,getattribute(aList[x],cAttribute)] 
	next
	aTempList = sort(aTempList,2)
	aTemp2 = []
	for x=1 to len(aTempList)
		aTemp2 + aList[aTempList[x][1]]
	next
	return aTemp2
	
Class company position name symbol
