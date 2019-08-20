#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 21.01.2018                  
####################################

new sum {
	1   2   3 
        4   5   6
        7   8   9
	}

new mul {
	1   2   3 
        4   5   6
        7   8   9
	}

class mul from Program 

	func BraceEnd 
		nMul = 1 
		for nNumber in aList 
			nMul *= nNumber
		next 
		? "Mul : " + nMul 

class Sum from Program 

	func BraceEnd 
		nSum = 0 
		for nNumber in aList 
			nSum += nNumber
		next 
		? "Sum : " + nSum 

class Program  

	aList = []

	func BraceExprEval value 
		if isNumber(value) 
			aList + value 
		ok


