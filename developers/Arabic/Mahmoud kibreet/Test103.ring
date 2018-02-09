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

oMyobjects.first().x=300

? oMyobjects.aList[1]

omyobjects.last() {
	x=500 y=500
}

? omyobjects.last()

class point x y

class myobjects

	aList = []

	func Addobject oObject 
		aList + oObject

	func first 
		return aList[1]  # Return By Reference

	func last
		return aList[len(aList)]
