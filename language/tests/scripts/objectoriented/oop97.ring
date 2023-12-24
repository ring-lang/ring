p1 = new point()
p1.test(p1)
? type(p1)

class point

	func init
		? type(this)
		? type(self)
		test(this)
		return this

	func test o
		? (o=self)