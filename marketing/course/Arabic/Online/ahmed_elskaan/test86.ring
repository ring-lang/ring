/*
**	Application Name : Natural programming;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-25;		
*/

new counter {
	count 
		80
	90
}



class counter 
	count 
	nCount = 0
	nStart = 0
	nEnd = 0
	func getCount 
		if nCount = 0
		 	nCount++
		ok
	func braceExprEval value 
		if  nCount = 1 and isnumber(value)
			nStart = value	
			nCount++ 
		but nCount = 2 and isnumber(value)
			nEnd = value
			nCount = 0
			Counter()
		ok
	func Counter
		for x = nStart to nEnd
			? x
		next
	func braceerror
