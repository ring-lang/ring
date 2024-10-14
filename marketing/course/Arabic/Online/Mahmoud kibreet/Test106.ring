/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.31
*/

new point 
{ 				# call bracestart()
	x = 10 y = 10 z = 30
	? self
	jkjhhgggf 	        # error braceend()
}				# call braceend()


class point 
	x y z

	func bracestart
	? "Start!"

	func braceend
	? "End!"

	func braceerror
	? "Error!"
