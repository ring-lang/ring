/*
	Application	: Natural Programming Part 2 Version 2
	Author		: Ahmed Mohamed
	Date		: 2019/10/30
*/

new program {
	1 2 3
	4 5 6
	7 8 9
}

class program

	aList = []

	func braceExprEval value
		if isNumber(value)
			aList + value
		ok
	
	func braceEnd
		nSum = 0
		for nNumber in aList
			nSum = nSum + nNumber
		next
		? "Sum : " + nSum
