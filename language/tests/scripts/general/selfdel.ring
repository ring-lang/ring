for t=1 to 100
	o1 = new myclass
	o1.test(t)
	o2 = ref(o1)
	# Delete the Original Object 
		o1 = NULL
	# Access the Object using another reference
		o2.test(t)
	# Braces uses the Self attribute to access the Object
	o2 { 		
		test(t)
	}
next

class myclass
	func test t
		? "Test " + t