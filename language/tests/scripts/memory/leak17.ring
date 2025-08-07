? "Memory: " + ringvm_ismempool()
for t=1 to 110000
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