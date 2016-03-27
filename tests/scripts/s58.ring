see "Hello" + NL
see "see list using function " + NL
aList = [["mahmoud","samir","fayed"],[1,2,3]]

test(aList[1])
test(aList[2])

see "see list using the see command " + NL

see aList
see aList[2]
see aList[1]

see "Copy List" + NL

aList2 = aList
aList2[1][1] = "Ahmed"
see aList2[1]
see aList[1]

aList3 = aList2[1]

aList3[1] = "Ibrahim"
see aList3
see aList2[1]
see aList[1]

func test var
	for x = 1 to 3
		see var[x] 
		see NL
	next

