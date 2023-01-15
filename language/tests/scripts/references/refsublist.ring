aList = [ [1,2] ]
test(ref(aList[1]))		# We pass a reference to sublist
? "Print the Parent list"
? aList
test2(aList[1])			# We pass the sublist itself (Sharing)
? "Print the Parent list"
? aList

func test x
	? "Print the sublist from function"
	? x	
	x = NULL	# We deleted a reference (Not the real sublist)

func test2 x
	? "Update the sublist from function"
	x = [3,4]	# We updated the real sublist 