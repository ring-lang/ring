/*
	name	:	Darsh Adam
	Lesson	:	Ring Lessons.ring
	Date 	:	30/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================
new point { 
	x = 10 y = 20 
	print()
	? x
}


class point x y 
	func print
		? " x : " + x +" " + "Y : " + y 

	func getx
		? "message from getx()"
		return x
	func setx value 
		x = value + 10
		?"message from setx()" 
		
