test()

func test

	o1 = new container
	see o1.getitem(2) + nl
	o1.getitem(2) = 20
	o1[3] = 30
	see o1.mylist	

	for r in o1
		see r + nl
		r = "good"
	next

	for r in o1		 
		see r + nl
	next

	return nice()

func nice
	see "nice"  + nl
	return 1

class container

	mylist = [1,2,3]

	func getitem x
		return &mylist[x]

	func operator cOp,cV
		if cOp = "len"
			return len(mylist)
		but cOp = "[]"
			return &mylist[cV]
		ok