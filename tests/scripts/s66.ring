alist = ["mahmoud","samir","fayed"]
for x = 1 to 100000
	test(alist)
next

see "done..."

func test pList
	pList[1] = "1"
	pList[2] = "2"
	pList[3] = "3"
	return pList