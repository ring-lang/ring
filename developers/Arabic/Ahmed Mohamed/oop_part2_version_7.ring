/*
	Application	: OOP Part 2 Version 7
	Author		: Ahmed Mohamed
	Date		: 2019/10/28
*/

oMyObjects = new myObjects

p1 = new point { x = 10 y = 20 } p2 = new point { x = 100 y = 200 } 

oMyObjects {
	
	AddObject(p1) AddObject(p2)
}

? oMyObjects.aList[1]

class point x y

class myObjects

	aList = []

	func addObject oObject
		aList + oObject
