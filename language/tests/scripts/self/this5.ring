? type(this)
myobj = new myclass { mytest() }
? myobj.name
? myobj.point.x
? myobj.point.y
? myobj.point.z
? type(this)

class myclass 
	name = "myclass"
	point 
	func mytest
		this.name = "myclass2"
		point = new point {
			x=10 y=20 z=30
			test()
		}
		this.name = "myclass3"
		? type(this)
		? classname(this)

class point x y z
	func test
		this.x = 100
		? type(this)
		? classname(this)