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

new Program{
	1 2 3 4 5 6 7 8 9
}

class Program

	aList = []

	func braceExprEval value
		if isNumber(value)
			aList + value
			else 
				? "Les entrées doit etres des nombres!"
				bye
		ok

	func braceEnd
		nSum = 0
		if len(aList) > 0

			for nNbr in aList
				nSum += nNbr
			next

			? "La somme est: " + nSum

			else ? "Le tableau est vide!"
		ok
