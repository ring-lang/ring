/*
	Application	: OOP Part 2 Version 10
	Author		: Ahmed Mohamed
	Date		: 2019/10/29
*/


oMyObjects = new myObjects

p1 = new point { x = 10 y = 20 } p2 = new point { x = 100 y = 200 } 

oMyObjects {
	
	AddObject(p1) 
	AddObject(p2)
	point point point
}


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
		? "Hello From getPoint() "
