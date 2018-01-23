/*
**	Application	: Ring lessons - Natural .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 20 .
*/

new counter {
	first count 1 5	
	count 10 15
}

class counter
		count
		nCountCmd = 0
		nStart = 0
		nEnd = 0
		func getCount
			if nCountCmd = 0
				nCountCmd++
			ok
		func BraceExprEval value
			if nCountCmd = 1 and isnumber(value)
				nStart = value
				nCountCmd++
			but nCountCmd = 2 and isnumber(value)
				nEnd = value
				nCountCmd = 0
				counter()				
			ok
		func counter
			for x = nStart to nEnd
				? x
			next
		func BraceError







