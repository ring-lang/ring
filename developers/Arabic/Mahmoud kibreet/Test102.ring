/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.30
*/


/*
object {
	# attributes 
	# methods
}

*/

oMyobjects = new myobjects
p1 = new point {x=10 y=20} p2 = new point {x=100 y=200}
oMyobjects {
	Addobject(p1) Addobject(p2)
}

? oMyobjects.aList[1]

class point x y

class myobjects

	aList = []

	func Addobject oObject 
		aList + oObject
