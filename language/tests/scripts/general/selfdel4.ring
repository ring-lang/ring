	aList = []
	# A reference to an empty list - Worth Nothing!!!
		aListRef = Ref(aList)	

	# The Assignment will delete the old empty list
	# The previous reference will not be useful!
	aList = [ 
		1,2, 
		new myclass {x=10 y=20 z=30} , 
		Ref(aList[3]) {x=100 y=200 z=300} ,
		aList[3] ,
		Ref(aList[5]) {x=1000 y=2000 z=3000} 
	]
	# We can create another reference now 
		aListRef2 = Ref(aList)
		? aList[3]	? aList[4]
		? aList[5]	? aList[6]
	# Delete the list again
		aList = NULL
	# The first reference give us the empty list!
		nSize = len(aListRef)
		? "Size: " + nSize
	# The second reference give us 6 items
		nSize = len(aListRef2)
		? "Size: " + nSize
		for t=1 to nSize
			? Type(aListRef2[t])
		next

class myclass
	x y z
	func test t
		? "Test " + t