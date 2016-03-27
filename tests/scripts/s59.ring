mymsg = "hello
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
eeeeeeeeeeeeeeeeeeeee"

see mymsg

aList = ["Mahmoud","Ahmed","Ibrahim","Mohammed"]
see mymsg
see aList
test(aList)
see aList
test2(aList)
see aList

see "test function return list" + NL
see test3(aList)

see "new test" + NL
#v = test4()
#see v
see test4()

see "test index of array returned from function" + NL
see test4()[1] + " " + test4()[2]

mysee(test4()[1])

see "test array square " + NL
nList = [1,2,3,4,5]
see " Array (2) " + NL
see arraysquare(nList,5)
see " Array (1) " + NL
see nList

see "WOWOOW"



func test array
	array[1] = "Mohammed"
	array[4] = "Mahmoud"

func test2 array
	array2 = array
	array2[1] = "1"
	array2[4] = "2"

func test3 array
	array2 = array
	array2[1] = "1"
	array2[4] = "2"	
	return array2

func test4 
	return aList

func mysee x
	see NL see x see NL

func arraysquare aArray1,nSize
	aArray = aArray1
	for x = 1 to nSize
		aArray[x] = aArray[x] * aArray[x]
	next
	return aArray