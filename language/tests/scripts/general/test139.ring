
mymsg = "hello
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
welcomeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeewwwwwwwwwwwwwwwwwwww
eeeeeeeeeeeeeeeeeeeee"

see mymsg + NL

see NL

aList = ["Mahmoud","Samir","Ibrahim","Fayed"]

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
	aArray2[1] = "1"
	aArray2[4] = "4"
	return aArray2

func test2 aArray
	aArray[1] = "Fayed"
	aArray[4] = "Mahmoud"
	return aArray

func seelist alist
	x = 1
	while x <= 4
		see alist[x] + NL
		x++
	end
