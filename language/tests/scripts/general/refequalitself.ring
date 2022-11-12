for t=1 to 10
	aList = 1:10
	? aList[1]
	aRef = ref(aList)
	? aRef[10]

	# Copy the reference to itself
	aRef = aRef

	? aRef[5]
next