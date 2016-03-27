mymsg = "hello
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
eeeeeeeeeeeeeeeeeeeee"

see mymsg + NL

see NL

aList = [3,3,3,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]

see aList
see NL

see test(aList) 
see NL

seelist(test(aList))
see NL

see NL+"action"+NL
see aList
seelist(aList)
see NL
see test2(aList)
see aList

func test aArray
	aArray2 = aArray
	aArray2[1] = 1
	aArray2[4] = 4
	return aArray2

func test2 aArray
	aArray[1] = 5
	aArray[4] = 6
	return aArray

func seelist alist
	for x = 1 to 20
		see alist[x] + NL
	next
