? "Memory: " + ringvm_ismempool()
for t=1 to 110000
	aList = list(5)
	refcount(aList)
next
? "Memory: " + ringvm_ismempool()
