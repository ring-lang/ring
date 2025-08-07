test()

func test

	aList = 1:1000
	aList2 = ref(aList)

	? "Memory: " + ringvm_ismempool()
	for t=1 to 110000
		ref(aList)
		refcount(aList)
	end
	? "Memory: " + ringvm_ismempool()