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
p1 = new point { x=10 y=20} p2 = new point { x=100 y=200}
oMyObjects {
	AddObject(p1) AddObject(p2)
}

? oMyObjects.aList[1]

class point x y 

class myobjects 

	aList = []

	func AddObject oObject
		aList  + oObject
