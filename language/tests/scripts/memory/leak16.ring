# Try return from class region while we are inside braces
# Also, Use assignment with the output

test()

func test

	? "Memory: " + ringvm_ismempool()
	for t=1 to 100000
		o = new point
	end
	? "Memory: " + ringvm_ismempool()

class point x y z
	new point2 {
		x=10
		y=20
		z=30
		return
	}
	
class point2 x y z
	