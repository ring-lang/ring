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
	
	p1 = new point {x=10 y=20} 
	p2 = new point {x=100 y=200}

oMyobjects {
	Addobject(p1) 
	Addobject(p2)
	point point point 
}


class point x y

class myobjects

	aList = [] point

	func Addobject oObject 
		aList + oObject

	func first 
		return aList[1]  # Return By Reference

	func last
		return aList[len(aList)]

	func GetPoint
		? "Hello from GetPoint()"

