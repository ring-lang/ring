# We expect a runtime error 

aList = [  []  ]

aList[1] = [
	1,2,3,4,5,
	aList[1],
	test(),
	:WOW,
	aList = NULL 
]

? aList

func test
	try
		aList[1] = NULL	
	catch
		? "Pass the first error"
	done
	try
		aList[1] = 1000
	catch
		? "Pass the second error"
	done
	try
		aList[1] = []
	catch
		? "Pass the third error"
	done
	try
		aList[1] = new point	
	catch
		? "Pass the forth error"
	done
	return "good"

class point x y z