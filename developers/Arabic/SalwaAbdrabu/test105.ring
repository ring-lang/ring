/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/


/*
	Object {
		Attributes
 		Methods   
} 

*/



oMyObjects = new MyObjects  

 oMyObjects { 
	
	point { x = 10 y = 20   }
	point { x = 100 y = 200 }
	point { x = 300 y = 400 }
	? self.aList
}

? oMyObjects
? oMyObjects.aList

//========================================================

class point x y 

class MyObjects 
	aList = []	point

func addObject oObject
	aList + oObject 

//func first 
//	return aList[1]        # Return By Reference

//func last
//	return aList[len(aList)] 

func GetPoint
	aList + new point 
	return aList[len(aList)]
