for t=1 to 100
	aList = [1,2]
	aList[1] = new myclass
	aList[1].test(t)
	aList[2] = ref(aList[1])
	# Delete the Original Object 
		aList[1] = NULL
	# Access the Object using another reference
		aList[2].test(t)
	# Braces uses the Self attribute to access the Object
	aList[2] { 		
		test(t)
	}
next

class myclass
	func test t
		? "Test " + t