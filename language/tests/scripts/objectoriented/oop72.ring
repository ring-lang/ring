o1 = new point 
? o1
o2 = new point2

func test
	? o1

func test2
	try
		o2 = NULL
	catch
		? "Can't kill the object"
		? "It's still under construction"
	done

class point 

	x=10 
	y=20
	mytest()
	z=30

	func mytest
		test()

class point2

	x=10 
	y=20
	mytest()
	z=30

	func mytest
		test2()