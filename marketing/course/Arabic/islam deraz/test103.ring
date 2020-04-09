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
p1 = new point { x=10 y=20 }  p2 = new point { x=100 y=200 }

omyobjects {
	Addobject(p1) Addobject(p2)
}

? omyobjects.alist[1]

omyobjects.first().x = 300

? omyobjects.alist[1]

omyobjects.last(){
	x = 500 y = 500 
}

? omyobjects.last()

class point x y

class myobjects	
	alist = []
	func Addobject oobject
		alist + oobject

	func first 
		return alist[1]	# return by reference

	func last 
		return alist[len(alist)]

	
