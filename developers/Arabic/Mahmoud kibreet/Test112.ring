/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.31
*/

new program {
	1 2 3
	4 5 6
	7 8 9
}

class program

	aList = []

	func BraceExprEval Value 
		if isnumber(value)
			aList + value
		ok

	func braceEnd
		nSum = 0
		for nNumber in aList
			nSum += nNumber
		next
		? "Sum :" + nSum
