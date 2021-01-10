o1 = new point {x=10 y=20 z=30}
o2 = new point {x=100 y=200 z=300}

? o1.x
? o1.y
? o1.z
? (o1).x
? (o1).y
? (o1).z
? (o2).x
? (o2).y
# Test '(' Expression ')' '.' Attribute|Method

? (o2).z
? (o1+o2).x
? (o1+o2).test()

class point x y z
	func operator cOp,oVal
		mypoint = new point	
		if cOp = "+"
			mypoint.x = x+ oVal.x
		ok
		return mypoint
	func test
		? "Inside the Test() Method"
		? "X = " + x