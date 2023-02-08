? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	aList = list(5)
	refcount(aList)
next
? "Memory: " + ringvm_ismempool()
