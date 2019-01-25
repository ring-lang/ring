/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

new point {			# Call bracestart
		x=10 y=20 z=30 
		? self
		hhkgjlgsdj	# Error --> Call braceerror 
}

class point
	x y z

func bracestart
	? "Hello From Func BraceStart"

func braceend
	? "Hello From Func Braceend"

func braceerror
	? "Hello From Func Braceerror"
