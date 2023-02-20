? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	try
		test2()
	catch
	done
end
? "Memory: " + ringvm_ismempool()

func test2
	new point {
		mmmm
	}

class point x y z