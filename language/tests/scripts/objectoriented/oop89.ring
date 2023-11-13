new point {

	width = 100   height = 100
	aList = list(width,height)

	// Instead of using a for loop that define x & y as local variables
	// We will use x and y directly ---> Which means x & y from the point object
	// This will call the getter method (FOUR TIMES)

	aList[x][y] = [x,x+y,x*y]

	? "Counter: " + counter

}

class point 
	x=1 y=1 counter=0
	func getx 
		? :getter
		counter++
		return x