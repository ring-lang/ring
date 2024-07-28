new class3 { test() ? "****" test2() }


class class1
	x1=10
	func test
		? x1

class class2 from class1

	x2=100

	func test
		super.test()
		? x2

	func test2
		? x2
		super.test()


class class3 from class2

	x3=1000

	func test
		super.test()
		? x3

	func test2
		? x3
		super.test2()


