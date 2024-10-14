/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.31
*/

new counter {
	first count 1 5
	second count 10 15
	count 
	20
	25
	count 30 35
}

class counter

	count 
	nCountCmd = 0
	nStart = 0
	nEnd = 0

	func getcount 
		if nCountcmd = 0
			nCountcmd++
		ok

	func BraceExprEval value
		if nCountCmd = 1 and isnumber(value)
		nStart = value
		nCountCmd++
		but nCountCmd = 2 and isnumber(value)
			nEnd = value
			nCountCmd = 0
			Counter()
		ok

	func Counter 
		for x = nStart to nEnd 
			? x
		next

	func Braceerror
