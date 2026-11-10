? "Ignore some expressions"
1 
(10)
1 (10)
1(10)

? "Print some expressions"
? 1
? (10)
? 1(10)		# Will print 1 because ( starts new statement

? "Print some expressions using braces"
new Expr {
	1 
	(10)
	1 
	(2+3)
	1 
	(5*2)
	1 (10)
	1 (2+3)
	1 (5*2)
	1(10)
	1(2+3)
	1(5*2)	
}

class Expr

	nCount = 0

	func braceExprEval vValue
		nCount++
		? vValue

	func braceEnd
		? "Expressions count: " + nCount