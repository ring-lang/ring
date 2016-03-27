Func Main
	See "Hello World" + nl
	for x = 1 to 10
		see x + nl
	next
	test()

func test
	see "welcome" + nl
	o1 = new point { x=10 y=20 z=30 }
	see o1

class point x y z