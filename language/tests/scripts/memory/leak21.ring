? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	try
		test4()
	catch
	done
end
? "Memory: " + ringvm_ismempool()

func test4
	new point2

class point2
	new point3

class point3
	new point4

class point4
	1/0