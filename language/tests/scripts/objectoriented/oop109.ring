o1 = new A	o1.test()
o2 = new B	o2.test()
o3 = new C	o3.test()

class A
	x
	func test
		? "hello from A"

class B from A
	y
	func test
		super.test()
		? "hello from B"

class C from B
	z
	func test
		super.test() 
		? "hello from C"