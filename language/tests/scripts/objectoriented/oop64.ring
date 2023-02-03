o1 = new myclass
? :one
o1.myobj = new point {x=10 y=20 z=30}
? o1.myobj

? :two
o1.myobj = [1,2,3]
? o1.myobj

? :three
o1.myobj = 10
? o1.myobj + nl

? :four
o1.myobj = "test"
? o1.myobj + nl

? :five
o1.setmyobj(new point {x=10 y=20 z=30})
? o1.myobj

class myclass 
	myobj
	func setmyobj value
		? "Setter"
		myobj=value

class point x y z 