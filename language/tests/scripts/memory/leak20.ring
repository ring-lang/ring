? "Memory: " + ringvm_ismempool()
for t=1 to 110000
	try
		test4()
	catch
	done
end
? "Memory: " + ringvm_ismempool()

func test4
	new point2

class point2
	1/0