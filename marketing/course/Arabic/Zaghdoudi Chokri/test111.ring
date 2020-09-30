/**
 * Application Ring learning
 * Autheur     : Zaghdoudi Chokri
 * Date        : 01/09/2020
*/
# =====================================

/*
	Ring 
		Natural
		Declaratives (Nested Structure)
		OOP Functional
*/

# Déclaration des commandes avec parametres
new Counter{
# En déclarant l'atribut count, on fait appel à getCount()
# et nCountCmd sera 1
	premier copteur count 1 5
# En déclarant l'atribut 1, on fait appel à braceExprEval()
# ou nStart prend la valeur de nCountCmd (1)
# et nCountCmd sera 2
	deuxiéme compteur count 10 15
}

class Counter

	count
	nCountCmd = 0
	nStart = 0
	nEnd = 0

	func getCount
		if nCountCmd = 0 nCountCmd++ ok

	func braceExprEval value
		if nCountCmd = 1 and isnumber(value)
			nStart = value
			nCountCmd++
		but nCountCmd = 2 and isnumber(value)
			nEnd = value
			nCountCmd = 0
			counter()
		ok

	func Counter
		for x=nStart to nEnd
			? x
		next

	func braceError
		/*? "Handle Error!: " + cCatchError
                if ( left(cCatchError,11) = "Error (R24)" ) and not isattribute(self,"test")
                        ? "add attribute"
                        addattribute(self,"test")
                        test = 10
                ok
                ? "done"*/
                return
