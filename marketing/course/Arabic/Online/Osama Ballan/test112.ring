/*
**	Application	: Ring lessons - Natural | Declarative .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 20 .
*/

new program {
				1	2	3
				4	5	6
				7	8	9
}

class program
		aList = []
		func BraceExprEval value
			if isnumber(value)
				aList + value
			ok
		func BraceEnd
			nSum = 0
			for nNumber in aList
				nSum += nNumber
			next
			? "Sum = " + nSum
		














