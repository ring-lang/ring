/*
	Application	: OOP Part 2 Version 8
	Author		: Ahmed Mohamed
	Date		: 2019/10/28
*/

oMyObjects = new myObjects

p1 = new point { x = 10 y = 20 } p2 = new point { x = 100 y = 200 } 

oMyObjects {
	
	AddObject(p1) AddObject(p2)
}


? oMyObjects.aList[1]

oMyObjects.first().x = 300

? oMyObjects.aList[1]

oMyObjects.last() {
	x = 500
	y = 500
}

? oMyObjects.last()

class point x y

class myObjects

	aList = []

	func addObject oObject
		aList + oObject

	func first
		return aList[1] # Return By Ref

	func last
		return aList[len(aList)]
