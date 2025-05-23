me = NULL

p1 = new point { x=10 y=20 z=30 }

p1.event = func {
	? "x = " + me.x
}

p1.go()

class point 

	x y z
	
	event

	func go

		me = ref(this)
		call event()
		me = NULL
	