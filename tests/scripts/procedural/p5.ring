aList = ["Mahmoud","Samir","Fayed"]
see aList

see mytest(aList)
see mytest2()
see test4()

v = test4()
see v

see aList

good()
see NL

see test5(aList)

func mytest v1
	return v1

func mytest2
	return aList

func test4
	return aList

func good
	see "good"

func test5 v1
	v2 = v1
	v2[1] = "wow"
	return v2