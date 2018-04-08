/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.31
*/

new MyMath {

	sum {
		1 2 3
		4 5 6
		7 8 9
	}

	mul {
		1 2 3
		4 5 6
		7 8 9
	}
}

class MyMath
	sum mul
	func getsum
		return new sum 

	func getmul
		return new mul

class mul from program 

	func braceEnd
		nMul = 1
		for nNumber in aList
			nMul *= nNumber
		next
		? "Mul :" + nMul

class sum from program 

	func braceEnd
		nSum = 0
		for nNumber in aList
			nSum += nNumber
		next
		? "Sum :" + nSum

class program

	aList = []

	func BraceExprEval Value 
		if isnumber(value)
			aList + value
		ok

	
