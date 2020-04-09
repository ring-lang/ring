/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.28
*/


/*

	object {
			# Attributes
			# Methods
		}

*/

omyobjects = new myobjects


omyobjects {
	
	point {
		x =10
		y =20
		}

	point {
		x =100
		y =200
	}

	point {
		x =300
		y =300
		}

	? self.alist

	}

? omyobjects.alist


class point x y

class myobjects	

	alist = []  point

	func Addobject oobject
		alist + oobject

	func first 
		return alist[1]	# return by reference

	func last 
		return alist[len(alist)]

	
	func getpoint
		alist + new point 
		return alist[len(alist)]
