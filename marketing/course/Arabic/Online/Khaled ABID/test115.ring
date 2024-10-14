/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 23/04/2018
*/

new Counter { 
	First count 1 5
	Second count -8 7
	count 
		20
		35
	count 88 91
}


class Counter

	count

	nCountCmd = 0 
	nStart = 0
	nEnd = 0

	func getCount
		if nCountCmd = 0
			nCountCmd++
		ok

	func BraceExprEval value
		if nCountCmd = 1 and isNumber(value)
			nStart = value
			nCountCmd++
		but nCountCmd = 2 and isNumber(value)
			nEnd = value
			nCountCmd = 0
			Counter()
		ok

	func Counter
		for x = nStart to nEnd
			? x
		next

	func BraceError
