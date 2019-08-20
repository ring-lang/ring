/*
**	Application Name : OOP 5;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-22;		
*/

new firstClass  {
	x = 10 y = 20 
	print()
	? x
}

class firstClass
	x y 		 # public
	func print 
		? "x: " + x + " y: " + y
	func getx
		? "Message from getx()"
		return x
	func setx value
		x = value + 10
		? "Message from setx()"
