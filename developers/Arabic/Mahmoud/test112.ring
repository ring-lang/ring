/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.24
*/

new program {
	1   2   3 
        4   5   6
        7   8   9
}

class program 

	aList = []

	func BraceExprEval value 
		if isNumber(value) 
			aList + value 
		ok

	func BraceEnd 
		nSum = 0 
		for nNumber in aList 
			nSum += nNumber
		next 
		? "Sum : " + nSum 
