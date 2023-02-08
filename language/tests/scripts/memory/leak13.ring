func main
	? "Memory: " + ringvm_ismempool()
	for t=1 to 500000
		test()
	next
	? "Memory: " + ringvm_ismempool()

func test
	list1 = list(5)
	list2 = Ref(list(5))
	refcount(ref(list1)) 
	list3 = ref(list1)
