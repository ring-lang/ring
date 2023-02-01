p1 = new point {x=10  y=20  z=30 }
p2 = new point {x=100 y=200 z=300}
o1 = new myclass 

for t=1 to 10

	o1.myobj = ref(p1)
	? o1.myobj
	? refcount(o1.myobj)
	? refcount(p1)
	? copy("=",20)

	o1.myobj = p2 
	? o1.myobj
	? refcount(o1.myobj)
	? refcount(p1)
	? copy("=",20)

	? p1
	? copy("=",20)
next

class myclass

	myobj 

	func setmyobj v
		? "Using Setter"
		myobj = v

class point x y z