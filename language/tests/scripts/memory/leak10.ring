? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	test()
next
? "Memory: " + ringvm_ismempool()

func test
	aList = list(5)
