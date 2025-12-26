fCheck = func {
	aList = attributes(self)
	for cAttr in aList
		See cAttr + " = " eval("? " + cAttr)
	next
}

new point { x=10 y=20 z=30 call {fCheck()} }

class Point

	x y z

	func print
	
		? self