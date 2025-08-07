? "Memory: " + ringvm_ismempool()
for t=1 to 110000
	RefCount(Ref(list(5)))
	RefCount(Ref(1:5))
	Ref(list(5))
next
? "Memory: " + ringvm_ismempool()

