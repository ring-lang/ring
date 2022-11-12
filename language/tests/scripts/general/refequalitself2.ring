for t=1 to 10
	aList = 1:10
	? aList[1]

	aList2 = [ ref(aList) ]
	? aList2[1][10]

	# Copy the reference to itself
	aList2[1] = aList2[1]

	? aList2[1][5]
next