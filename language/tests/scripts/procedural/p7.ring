start()
see "use general temp memory" + NL
see [1,2.12]
start()

func start
	see "hello world" + NL
	myloop()
	list()
	math()
	string()
	getpara("Hello","How are you?","Are you fine ?")
	see fact(5)
	see NL
	whilemyloop()
	x = 5
	y = 7
	scope()
	see "after scope" + NL
	see x 
	see NL
	see y
	see NL
	aList = [1,2,3,4,5]
	see "reverse list" + NL
	see reverselist(aList,5)
	see "see list by reference" + NL
	see square(aList,5)
	see "see List" + NL
	see aList
	see "Get item of array returned from function" + NL
	for x = 1 to 3
		see getlist(aList)[x]
		see NL
	next
	see "using seelist" + NL
	aArray1 = ["Mahmoud","Samir","Fayed"]
	seelist(aArray1,3)
	see "passing array by value to seelist" + NL
	seelist(["Hello","How are you ?","Are you fine"],3)
	see "see list directly without using variables " + NL
	see ["Mahmoud","Samir","Fayed",[1,2,3,4,5]]
	see "test function return list directly by value" + NL
	see funcretlistbyvalue()
	see "reverse two items " + NL
	see revtwoitems([1,2])
	see revtwoitems(["Mahmoud","Fayed"])
	for x = 1 to 3
		see revtwoitems2(["Fayed","Samir","Mahmoud"],["","",""])[x] + " " 
	next
	see NL + "send function return list to function take list" + NL
	see revtwoitems(revtwoitems([1,2]))[1] 
	see NL
	see revtwoitems(revtwoitems([1,2]))[2] 
	see NL

func myloop
	for x = 1 to 10
		see x
		see NL
		if x = 3
			see "Number three" + NL
		ok
	next

func list
	aList = ["Mahmoud","Samir","Fayed"]
	for x = 1 to 3
		see aList[x] + NL
	next

func math
	x = 1
	y = 2
	see "" + (x+y) + NL
	see "" + (y-x) + NL
	see "" + (x*y) + NL
	see "" + (x/y) + NL
	see "" + (x%y) + NL
	
func string
	cName = "Mahmoud"
	cAddress= "Egypt"
	cAge = "28"
	see cName + "-" + cAddress + "-" + cAge + NL

func getpara x,y,z
	see x + NL
	see y + NL
	see z + NL

func fact x
	if x = 1
		return 1
	else
		return x * fact(x-1)
	ok

func whilemyloop
	x = 10
	while x > 0
		see x
		x = x - 1
	end
	see NL

func scope
	x = 10
	y = 20
	see "inside scope" + NL
	see x 
	see NL
	see y
	see NL

func square aList,nSize
	for x = 1 to nSize
		aList[x] = aList[x] * aList[x]
	next
	return aList

func reverselist aList,nSize
	aList2 = aList # copy the array
	for x = 1 to nSize
		aList2[nSize-x+1] = aList[x]
	next
	return aList2

func getlist aList
	return aList

func seelist aList,nSize
	for x = 1 to nSize
		see aList[x] + NL
	next
	return

func funcretlistbyvalue
	return ["Wow","How are you ?","I hope that you are fine !"]

func revtwoitems aList
	return [aList[2],aList[1]]

func revtwoitems2 aList1,aList2
	for x = 1 to 3
		aList2[x] = aList1[3-x+1]
	next
	return aList2
