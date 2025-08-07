? "Memory: " + ringvm_ismempool()
for t=1 to 110000
	test()
end
? "Memory: " + ringvm_ismempool()

func test
	eval("return")