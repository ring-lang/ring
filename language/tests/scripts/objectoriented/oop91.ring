new point {

	width = 100   height = 100
	aList = list(width,height)

	// Instead of using a for loop that define x & y as local variables
	// We will use x and y directly ---> Which means x & y from the point object
	// This will call the getter method (FOUR TIMES) once it's defined using addMethod()

	for m=1 to 2

		? "Before using aList"
		aList[x][y] = [x,x+y,x*y]
		? "Counter: " + counter
		? "After using aList"

		if ! ismethod(self, :getx) addmethod(self, :getx, func { ? :getter counter++ return x }) ok

	next

}

class point 
	x=1 y=1 counter=0
	