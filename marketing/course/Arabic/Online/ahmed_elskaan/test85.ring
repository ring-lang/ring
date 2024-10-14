/*
**	Application Name : Natural programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-25;		
*/
new myMath {
	sum {
		1	2	3
		4	5	6
		7	8	9
	}
	mul {
		1	2	3
		4	5	6
		7	8	9
	}
}
class myMath 
	sum mul 
	func getSum 
		return new sum
	func getMul 
		return new mul
class mul from prog
	func BraceEnd 
		nMul = 1
		for nNumber in aList
			nMul *= nNumber
		next
		? "Mul: " + nMul

class sum from prog
	func BraceEnd 
		nSum = 0
		for nNumber in aList
			nSum += nNumber
		next
		? "Sum: " + nSum

class prog 
	aList = []
	func BraceExprEval value
		if isnumber(value)
		 	aList + value
		ok 
