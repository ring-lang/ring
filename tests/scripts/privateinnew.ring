o = new myclass
o.test()
o {
	see new point(x,"")
	see "we must get runtime error (using private attribute)!" + nl
	see new point(number)
}
class myclass

	x = 20

	func test
		new point(x,"")	
		new point(number,new point2(number))		

	private

		number = 10

class point
	func init p1,p2
		see "point class" + nl
		see p1 + nl

class point2
	func init p1