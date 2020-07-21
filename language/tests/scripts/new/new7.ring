
o1 = new myclass
o1.print("hello")
o1.printobj(new point {x=10 y=20 z=30} )
o1.printobj(new point(100,200,300))


new myclass { printobj(new point(1000,2000,3000)) }

o1 { printobj(new point(1000,2000,3000)) }

Class point x y z
	func init a,b,c
		x=a y=b z=c


class myclass
	func print r
		see r + nl
	func printobj r
		see r