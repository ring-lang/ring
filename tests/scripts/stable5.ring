# Return of Function Call don't track anything!

for x = 1 to 1000000
	see "nice" + nl
	test()
next


func test
	
	for t = 1 to 10
		return
	next
	