myobj = test() { ? self test() }
? myobj { ? self test() }

func test
        return new point { ? self test() }

class point 
	x=10 y=20 z=30
	func test 
		? "Hello from test() method"