/*
	Application	: OOP Version 7
	Author		: Ahmed Mohamed
	Date		: 2019/10/26
*/

new point { 
	x = 10 
	y = 20 
	print() 

}


class point 
	
	x y	# public 
	
	func print
		? "x : " + x + " Y : " + y

	func getx
		? "Message From getx()"
		return x
	
	func setx value
		x = value + 10
		? "Message From setx()"
	
