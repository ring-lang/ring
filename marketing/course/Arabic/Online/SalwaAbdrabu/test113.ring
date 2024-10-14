/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

# New language ---> [ Programming - New solutions ]

# Programming ---> Management ( Complexity )

# Software ( Size ) ----> Up

# Ring ( General Purpose ) ----> Natural | Declarative

# 			OOP - Functional 

new Sum {
		1 2 3
		4 5 6
		7 8 9 
}

new Mul {
		1 2 3
		4 5 6
		7 8 9 
}


//====================================================



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
	
