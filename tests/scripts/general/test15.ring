oLetters = new letters

new rect {
	top = 100
	test(new point(oLetters.print(printtop())))
}

class point x y z
	func init v1

class rect top left width height
	func test v1
	func printtop
		see isattribute(self,"top") + nl
		see attributes(self)
		see top + nl

class letters
	a b c
	func print rr
		see "print" + nl



/*
o2 = new rect {top=10 left=10 width=200 height=200}
o1 = new point {x=10 y=20 z=30}

o2 { o1.check( print() ) }

new rect { 
	top=10 left=10 width=200 height=200
	new point {x=10 y=20 z=30} . check(print())
}

mylist = []
mylist + new rect
mylist[1] { 
	top=10 left=10 width=200 height=200
	new point {x=10 y=20 z=30} . check(print())
}

oLetters = new letters

mylist[1] {
	test(new point(oLetters.print(printtop())))
}


class point x y z
	func check t
		see self
	func init v1

class rect top left width height
	func print
		see self
	func test v1
	func printtop
		see top + nl

class letters
	a b c
	func print rr
		see a + b + c + nl
*/
