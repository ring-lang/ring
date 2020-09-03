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
# Une classe contient plus qu'un objet - management

oObjects = new Objets

oObjects{
# modification de l'objet retourné par getPoint()
	point{
		x=10 y=20
	}
	point{ x=100 y=200 }
	point{ x=300 y=300 }
	//? self.aList
}
? oObjects.aList
//? oObjects.last()

class Point x y

class Objets 

	aList = [] # Conteneur des objets
	point

	func addObject oObj
		aList + oObj
	# Ring - retour de valeur depui un tableau 
	# sera par référence
	func first
		? "Longueur du tableau " + len(aList)
		if len(aList) <= 0 return ok
		return aList[1] # Par référence
	func last
		? "Longueur du tableau " + len(aList)
		if len(aList) <= 0 return ok
		return aList[len(aList)] # Par référence
	func getPoint
		aList + new Point
		if len(aList) <= 0 return ok
		return aList[len(aList)] # Par référence
