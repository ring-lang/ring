#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 21.01.2018                  
####################################



new Counter {
	First count 1  5
	Second count 10  15
	count 
		20
		25
	count 30 35
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

	func braceerror
