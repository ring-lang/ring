? "ONE"
myobj = new Obj { 
	self.data = new point
}
? myobj
? myobj.data

? "TWO"
myobj = new Obj { 
	self.data = new point {x=10 y=20 z=30}
}
? myobj
? myobj.data

? "THREE"
myobj = new Obj2 { 
	self.data = new point
}
? myobj
? myobj.data

? "FOUR"
myobj = new Obj2 { 
	self.data = new point {x=10 y=20 z=30}
}
? myobj
? myobj.data

? :done

class Obj

	data 

	func setdata value
		? "Using Setter"
		data = value

class Obj2

	data 

class point x y z