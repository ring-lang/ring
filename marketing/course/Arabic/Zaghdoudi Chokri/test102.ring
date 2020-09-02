/**
 * Application Ring learning
 * Autheur     : Zaghdoudi Chokri
 * Date        : 01/09/2020
*/
# =====================================
# Classes

new Point
{			# Fait appel à braceStart()
	x=10 y=20 z=30
	? self
	abcd 		# Erreur ---> BraceError()
			# Fait appel à braceError()

}			# Fait appel à braceEnd()

class Point 
	x y z
	func braceStart
		? "Start!"
	func braceEnd
		? "End!"
	func braceError
		? "Erreur!"
