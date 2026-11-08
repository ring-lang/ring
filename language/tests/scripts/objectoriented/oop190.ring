new point().test()

? (new point)

? (new point())

? (new point()).test()

class point 

	x=10 y=20 z=30
	
	func init

		o = new point { x=100 y=200 z=300 }
		return o

	func test

		? "inside test()"
		? self