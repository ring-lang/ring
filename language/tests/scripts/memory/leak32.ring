? "Memory: " + ringvm_ismempool()
for t=1 to 110000
	test()
end
? "Memory: " + ringvm_ismempool()



func test
	aList = 1:10
	for x in aList
		for t=1 to 100
			for t2= 1 to 100
				return 
				exit		# Added to force pVM->pExitMark usage
			next
			loop			# Added to force pVM->pLoopMark usage
		next
	next
	