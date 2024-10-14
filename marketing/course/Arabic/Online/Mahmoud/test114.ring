/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.24
*/

new MyMath {

	sum {
		1   2   3 
	        4   5   6
	        7   8   9
	}
	
	mul {
		1   2   3 
	        4   5   6
	        7   8   9
	}

}
class MyMath 
	sum mul 
	func getSum 
		return new Sum

	func getMul
		return new Mul

class mul from Program 

	func BraceEnd 
		nMul = 1 
		for nNumber in aList 
			nMul *= nNumber
		next 
		? "Mul : " + nMul 

class Sum from Program 

	func BraceEnd 
		nSum = 0 
		for nNumber in aList 
			nSum += nNumber
		next 
		? "Sum : " + nSum 

class Program  

	aList = []

	func BraceExprEval value 
		if isNumber(value) 
			aList + value 
		ok


