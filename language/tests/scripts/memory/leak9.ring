? "Memory: " + ringvm_ismempool()
for t=1 to 110000
	aList = list(5)
	aList2 = ref(aList)
	aList2 = NULL

next
? "Memory: " + ringvm_ismempool()
