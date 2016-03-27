gvar = " wow "
stest1()

name = "Ahmed"
see name + NL
testscope()
see name + NL

pSum(3,4)
pLoop(10)
aList = ["Mahmoud","Mohamed","Ahmed","Ibrahim"]
pItem(1)

see "i am here1 "
see pGetItem(1) + pGetItem(2) + pGetItem(3) + NL

see "i am here "
see pSq(4)
see NL
see pSq(4) + pSq(3)

#see pListTest(aList)

return

func stest1
	for x = 1 to 10
	next

	stest2()
	see " x value : " 
	see x
	see NL

	return

func stest2
	for x = 1 to 100
	next
	see " x value : " 
	see x
	see NL
	see gvar + NL
	return


func testscope
	name = "Mahmoud"
	see name + NL
	return

func pSum n1,n2
	see "Number (1) : " + n1 + NL
	see "Number (2) : " + n2 + NL
	see "Sum : " + (n1+n2) + NL
	return

func pLoop n1
	for x = 1 to n1
		see x
		see NL
	next
	return

func pItem x
	see "Item number : " + x + NL
	see aList[x] + NL
	return

func pGetItem x
	return aList[x]

func pSq x
	return x*x

#func pListTest aListName
	#see aListName[1]
	#return