obj = new myclass
? "==============="
? obj.test() { ? self x=100 y=200 ? self}
? obj
? obj.mypoint
? "==============="
? obj.test2() { x=70 y=80 ? self }
obj.test3()

class myclass

	mypoint = new point {x=10 y=20 z=30}

	aPoints = [ new point {x=10 y=20 z=30} ]

	func test
		return mypoint

	func test2
		return aPoints[1]

	func test3
		? aPoints[1] { x=50 y=60 ? self }
	
class point x y z