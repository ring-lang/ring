x = 10
? x		# Print 10
test1()
? x		# Print 10
test2()
? x		# Print 10

func test1
	for x = 1 to 5
	next
	? x	# Print 6

func test2
	list = 1:5
	for x in list
	next
	? x		# Empty String