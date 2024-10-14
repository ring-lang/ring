/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.20
*/


/*
	object {
			# attributes 
			# methods 
	}

*/

oMyObjects = new myObjects 

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
		x= 300		
		y= 300
	}
 	? self.aList
}

? oMyObjects
? oMyObjects.aList 

class point x y

class myobjects 

	aList = []   point

	func AddObject oObject 
		aList + oobject

	func first 
		return aList[1]		# RETURN BY REF 
	
	func last 
		return aList[len(aList)]

	func GetPoint 
		aList + new point
		return aList[len(aList)]
