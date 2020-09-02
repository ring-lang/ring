/**
 * Application Ring learning
 * Autheur     : Zaghdoudi Chokri
 * Date        : 27/08/2020
*/
# =====================================

/*
	Ring
	   object{
		# atributs
		# methods
	   }
*/

# Composition
# Une classe contient plus qu'un objet

oObjects = new Objets
p1 = new Point{ x=10 y=20 } p2 = new Point{ x=100 y=200 }

oObjects{
	addObject(p1) addObject(p2)
}
? oObjects.aList
? oObjects.aList[1] 
? oObjects.aList[2]

class Point x y

class Objets 

	aList = [] # Conteneur des objets

	func addObject oObj
		aList + oObj
