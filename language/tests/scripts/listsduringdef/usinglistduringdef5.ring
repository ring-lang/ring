# Delete the parent of a protected list

? :start

aList = [  []  ]	# Parent List
aList[1] = [		# Protected List (Still under definition)
	1,2,3,4,5,
	aList[1],
	test(),		# Will delete the parent list (aList)
	:WOW 
]			# Will remove protection & clean memory

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