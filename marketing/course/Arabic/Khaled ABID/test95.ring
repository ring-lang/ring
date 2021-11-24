/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 05/04/2018
*/

new point { 
	x=10 y=20 
	print() 
	? x
}

Class Point 
	
	x y	# Public

	func print 
		? "X : " + x +
		  " Y : " + y

	func getx
		? "Message from GetX()"
		return x

	func setx value
		x = value + 10
		? "Message from SetX()"
