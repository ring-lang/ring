/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 09/04/2018
*/


/*
	object {
		# attributes
		# methods
	}

*/

oMyObjects = new myobjects

oMyObjects {
	point {
		x=10
		y=20
	} 
}

oMyObjects {
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

? oMyObjects
? oMyObjects.aList

? oMyObjects.first()

class point x y 

class myobjects 

	aList = [] point

	func AddObject oObject
		aList  + oObject

	func first 
		return aList[1]		# return by reference

	func last 
		return aList[len(aList)]	

	func GetPoint
		aList + new point
		return aList[len(aList)]
