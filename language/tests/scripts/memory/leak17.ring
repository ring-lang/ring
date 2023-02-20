? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	try
		test()
	catch
	done
end
? "Memory: " + ringvm_ismempool()


func test
	[
		"hi",
		nice
	]