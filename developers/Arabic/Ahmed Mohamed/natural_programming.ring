/*
	Application	: Natural Programming
	Author		: Ahmed Mohamed
	Date		: 2019/10/28
*/


new point { # Call braceStart()
	x = 10
	y = 10
	z = 30
	? self

	dfssdfsdfsdf # Error ----> braceError()
	
} # Call braceEnd()

class point
	x y z

	func braceStart
		? "Start!"

	func braceEnd
		? "End!"

	func braceError
		? "Error :("
