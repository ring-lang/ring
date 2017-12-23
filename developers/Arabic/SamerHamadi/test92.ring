/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 22/12/2017
*/
#================================================================

new point { 
	x=10 y=20 
	print()
	? x
}


class point 

	x y		# Public

	func print()	
		? "X :"+ x + 
		  " Y :" + y
	
	func getx 
		? "Message From getx()"
		return x

	func setx value 
		x = value + 10
		? "Message From setx()"
