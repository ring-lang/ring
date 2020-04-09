/*
**	Application Name : OOP 14;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-23;		
*/
oMyobj = new myObj

oMyobj {
	point {
		x = 30
		y = 60
	}
	point {
		x = 78
		y = 89
	} 
	? self.aList
}

class point x y
class myObj
	aList = []   point
	func test oObj
		alist + oObj
	func first 
		return aList[1]
	func last 
		return aList[len(aList)]
	func getPoint 
		aList + new point 
		return last()
