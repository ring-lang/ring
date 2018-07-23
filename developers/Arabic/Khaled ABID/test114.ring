/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 20/04/2018
*/

new MyMath {

	sum {
		1	2	3
		4	5	6
		7	8	9
	}	# Sum :45
	
	mul {	
		1	2	3
		4	5	6
		7	8	9
	}	
}

class MyMath 
	sum mul	
	func getSum
		return new Sum

	func getMul
		return new Mul

class mul from program 

	func braceend
		nMul = 1
		for nNumber in aList
			nMul *= nNumber
		next
		? "Mul :"  + nMul

class sum from program 

	func braceend
		nSum = 0
		for nNumber in aList
			nSum += nNumber
		next
		? "Sum :"  + nSum

class program 

aList = []

	func BraceExprEval value
		if isNumber(value)
			aList + value
		ok

	

