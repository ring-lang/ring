/*
**	Application	: Ring lessons - Object Oriented Programming ( OOP ) .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 15 .
*/

new point {
	x=10 y=20 
	print()
	? x
}

class point
	x y 			# public 
	func print 
			? copy("-",10)
			? "X : " + x +
			  "  Y : " + y
			? copy("-",10)
	func getx
		? "Message From Getx()"
		return x + 5
	func setx value
		x = value + 2
		? "Message From Setx()"


