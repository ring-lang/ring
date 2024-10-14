/*
**	Application	: Ring lessons - Natural | Declarative .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 20 .
*/

new sum {
				1	2	3
				4	5	6
				7	8	9
}
new mul {
				1	2	3
				4	5	6
				7	8	9
}

class sum from program
		func BraceEnd
			nSum = 0
			for nNumber in aList
				nSum += nNumber
			next
			? "Sum = " + nSum

class mul from program
		func BraceEnd
			nMul = 1
			for nNumber in aList
				nMul *= nNumber
			next
			? "Mul  = " + nMul
		
class program
		aList = []
		func BraceExprEval value
			if isnumber(value)
				aList + value
			ok













