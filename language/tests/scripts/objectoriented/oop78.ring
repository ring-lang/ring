obj = new myclass
? obj.test() { ? self x=100 y=200 ? self}
? obj
? obj.mypoint

class myclass

	mypoint = new point {x=10 y=20 z=30}

	func test
		return mypoint { ? self }

	
class point x y z