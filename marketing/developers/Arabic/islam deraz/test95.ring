/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.16
*/
new point {

	x = 10  y = 20
     	print()
	? x
	
}

class point 
	
	x y			# public
	
	func print 
		? " x: " + x +
		  " y: " + y 

	func getx
		? "Message from getx()"
			return x

	func setx value
			x = value + 20
			? "Message from setx()"
