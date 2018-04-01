/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

# New language ---->[programming - New solutions]

# programming -----> Management (Complexity)

# software (size) -> Up

# Ring (General purpose) ---> Natural | Declarative
#				OOP Functional

new Sum {
		1 2 3
		4 5 6
		7 8 9
}

new Mul {
		1 2 3
		4 5 6
		7 8 9
}

class Mul from program 

	func BracEend 
		nMul = 1
		for nNumber in alist	
			nMul *= nNumber	
		next
		? "Mul: " + nMul

class Sum from program 

	func BracEend 
		nSum = 0
		for nNumber in alist	
			nSum += nNumber	
		next
		? "Sum: " + nSum

class program
		alist = []
	
	func BraceExprEval value
		if isnumber(value)
			alist + value
		ok

	

