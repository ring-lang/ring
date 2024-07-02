# Using (for-in) variable with a similar name to function argument

test("one")
test(1)
test([1])

func test x

	aList = 1:10
	for x in aList
		? x
	next 