# testing passing list by reference

aList = ["Mahmoud","Samir","Ibrahim","Fayed"]

for x = 1 to 4
	see aList[x] + NL
next

test(aList)
see aList[4] + NL

seelist(aList,4)

func test var1
	see "test " + NL
	see var1[2] + NL
	var1[4] = "programmer"

func seelist var1,var2
	for x = 1 to var2
		see var1[x] + NL
	next