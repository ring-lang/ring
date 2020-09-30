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

new Somme{
	1 2 3 4 5 6 7 8 9
}
new Mult{
	1 2 3 4 5 6 7 8 9
}

class Mult from Program

	func braceEnd
		nMul = 1
		if len(aList) > 0

			for nNbr in aList
				nMul *= nNbr
			next

			? "La multiplication est: " + nMul

			else ? "Le tableau est vide!"
		ok


class Somme from Program

	func braceEnd
		nSum = 0
		if len(aList) > 0

			for nNbr in aList
				nSum += nNbr
			next

			? "La somme est: " + nSum

			else ? "Le tableau est vide!"
		ok

class Program

	aList = []

	func braceExprEval value
		if isNumber(value)
			aList + value
			else 
				? "Les entrées doit etres des nombres!"
				bye
		ok
