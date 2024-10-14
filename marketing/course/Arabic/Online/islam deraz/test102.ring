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

class point x y

class myobjects	
	alist = []
	func Addobject oobject
		alist + oobject

	
