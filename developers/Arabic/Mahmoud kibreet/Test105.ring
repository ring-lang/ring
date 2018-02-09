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
	
oMyobjects {
	point {	
		x=10 
		y=20
	} 
	point {
		x=100 
		y=200
	}
	point {
		x=300 
		y=300
	}
	? self.aList

}

? omyobjects.aList

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
		aList + new point
		return aList[len(aList)]

