# Delete the parent of a protected list

? :start
? ringvm_ismempool()
for t=1 to 110000
aList = [  []  ]
aList[1] = [
	1,2,3,4,5,
	aList[1],
	test(),
	:WOW 
]
next
? ringvm_ismempool()
? :done

func test
	try
		aList = NULL	
	catch
		? "Pass the first error"
	done
	try
		aList = 1000
	catch
		? "Pass the second error"
	done
	try
		aList = []
	catch
		? "Pass the third error"
	done
	try
		aList = new point	
	catch
		? "Pass the forth error"
	done
	return "good"

class point x y z