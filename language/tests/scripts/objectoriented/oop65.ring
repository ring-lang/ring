o1 = new myclass
o1.myobj = test()
? o1.myobj

o1.myobj = new myclass
? o1.myobj

func test
	return new point { x=10 y=20 z=30 }

class myclass 

	myobj="ok"
	pp = new point {x=10 y=20 z=30}

	func setmyobj value
		? "Setter"
		myobj=value

class point x y z 
