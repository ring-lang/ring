for t=1 to 100
	aList = [1,2]
	aListRef = ref(aList)
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
	# Delete the list (Note: We still have aListRef)
		aList = []
	# Using aListRef
		? "Size: " + len(aListRef)
		? type(aListRef[1])
		? type(aListRef[2])
		aListRef[2] { 		
			test(t)
		}
next

class myclass
	func test t
		? "Test " + t