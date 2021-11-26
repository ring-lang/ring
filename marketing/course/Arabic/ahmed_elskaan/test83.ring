/*
**	Application Name : Natural programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-25;		
*/
new prog {
	1	2	3
	4	5	6
	7	8	9
}


class prog 
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
		? "Sum: " + nSum
