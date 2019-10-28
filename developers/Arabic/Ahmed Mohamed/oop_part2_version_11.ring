/*
	Application	: OOP Part 2 Version 10
	Author		: Ahmed Mohamed
	Date		: 2019/10/29
*/


oMyObjects = new myObjects

oMyObjects {
	

	point {x = 10 y = 20} 
	point {x = 100 y = 200} 
	point {x = 300 y = 300}

	? self.aList
}

? oMyObjects.aList

class point x y

class myObjects

	aList = [] point

	func addObject oObject
		aList + oObject

	func first
		return aList[1] # Return By Ref

	func last
		return aList[len(aList)]

	func getPoint
		aList + new point
		return aList[len(aList)]		
