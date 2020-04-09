/*
**	Application	: Ring lessons - Object Oriented Programming ( OOP )- Class Composition .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 16 .
*/

oMyObjects = new myObjects

oMyObjects{
		point {
			x =1
			y = 2
			}
		point {
			x =11
			y = 22
			}
		point {
			x =111
			y = 222
			}
		? self.aList
		}
? oMyObjects.aList
class point x y

class myobjects
		aList =[] point
		func addObject oObject
			aList + oobject
		func first()		
			return aList[1]			# Return By Ref
		func last
			return aList[len(aList)]
		func getpoint
			aList + new point
			return aList[len(aList)]
