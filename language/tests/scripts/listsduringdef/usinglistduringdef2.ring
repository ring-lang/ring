# We expect a runtime error 

aList = [
	1,2,3,4,5,
	aList[1],
	test(),
	:WOW,
	aList = NULL 
]

? aList

func test
	aList = NULL	# Runtime error

class point x y z