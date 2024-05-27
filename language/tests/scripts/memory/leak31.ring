? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	test()
end
? "Memory: " + ringvm_ismempool()

func test
	aList = list(100)
	aList[1] = 1
	for x in aList
		aList = NULL
	next


