? "Loading Library"
loadlib("mylib.dll")

? "Test passing global variables as integer pointer"
nNum1 = 100
changevalue(:nNum1)
? nNum1

changevalue(:nNum1)
? nNum1

test()

new point { x=10 y=20 z=30 ? self test() }

func test

	? "Using test() function - Pass local variables"
	y = 1516
	changevalue(:y)
	? y
	changevalue(:y)
	? y

class point 

	x y z

	func test

		? "Using test() method - pass object attributes"

		changevalue(:x)
		? x

		changevalue(:y)
		? y

		changevalue(:z)
		? z