aList = [
	test1([1,2,3]),
	test1([4,5,6]),
	test1([7,8,9])
]
? aList

aList = [
	test1([1,2,3]),
	test2([4,5,6]),
	test3([7,8,9])
]
? aList

aList = [
	test3([1,2,3]),
	test3([4,5,6]),
	test3([7,8,9])
]
? aList

func test1 a
	return a

func test2 a
	return a+9999

func test3 a
	for t in a
		t *= 10
	next
	return a