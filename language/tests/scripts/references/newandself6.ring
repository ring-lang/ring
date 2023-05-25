myobj = new point { x=10 y=20 z=30 }
myobj2 = ref(myobj)

myobj {
	? self
	myobj = null
	test()
	? self
}


class point  x y z
	func test 
		? :Test