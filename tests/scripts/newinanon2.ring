test = func {

	new mybase {
		point {
			x = 10
		}	
	}

}

see "test" + nl
see test+nl

call test()

class mybase
	point
	func getpoint
		return new point

class point 
	x y z
	func setx t
		see "wow" + nl
		x = t