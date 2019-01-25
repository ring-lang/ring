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

p1 = new point { x = 10  y = 20}
p2 = new point { x = 100 y = 200 }

oMyObjects{
	addObject(p1) addObject(p2)
}

? oMyObjects.aList[1]
oMyObjects.first().x = 300
? oMyObjects.aList[1]

oMyObjects.last(){ x = 500 y = 500 }
? oMyObjects.last()

//========================================================

class point x y 

class MyObjects 
	aList = []

func addObject oObject
	aList + oObject 

func first 
	return aList[1]        # Return By Reference

func last
	return aList[len(aList)]  
