/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 20/04/2018
*/

new program {
	1	2	3
	4	5	6
	7	8	9
}

class program 

aList = []

	func BraceExprEval value
		if isNumber(value)
			aList + value
		ok

	func braceend
		nSum = 0
		for nNumber in aList
			nSum += nNumber
		next
		? "Sum :"  + nsum
