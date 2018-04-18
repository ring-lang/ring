/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 18/04/2018
*/

new point 
{ 				# call BraceStart()
	x=10 y=20 z=30
	? self

	ofsjgfjgmsijg		# Error ----> BraceError()
}				# call BraceEnd()



class point
	x y z 

	func bracestart
		? "Start!"

	func braceend
		? "End!"

	func braceerror
		? "Error!"
