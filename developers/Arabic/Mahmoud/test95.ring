/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.20
*/

new point { 
	x=10 y=20 
	print() 
	? x
}


class Point 

	x y			# public 

	func print 
		? "X : " + x +
		" Y : " + y

	func getx
		? "Message from GetX()"
		return x

	func setx value 
		x = value + 10
		? "Message from SetX()"
