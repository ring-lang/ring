/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

new myMath {

	 Sum {
		1 2 3
		4 5 6
		7 8 9 
}

	 Mul {
		1 2 3
		4 5 6
		7 8 9 
}
}

//====================================================

class myMath

	sum mul

func getSum 
	return new sum 

func getMul
	return new mul


class Mul from Program  

	func BraceEnd 
		nMul = 1 
		for nNumber in aList
			nMul *= nNumber
		next
		? "Mul :" + nMul
 

class Sum from Program  

	func BraceEnd 
		nSum = 0 
		for nNumber in aList
			nSum += nNumber
		next
		? "Sum :" + nSum
 

class Program
	aList = []

	func BraceExprEval value
		if isNumber(value) 
			aList + value
		ok 
	
