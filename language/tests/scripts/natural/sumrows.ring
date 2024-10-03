new SumRows {
	10 20 30		# 60
	10			# 10
	400 100			# 500
	30 40			# 70

}

class SumRows

	nSum     = 0
	nLastRow = 0

	func braceExprEval  value 

		aCallList = ringvm_calllist()
		nLine     = aCallList[len(aCallList)-1][7]

		if nLastRow = 0      nLastRow = nLine        nSum = value return ok
		if nLine != nLastRow nLastRow = nLine ? nSum nSum = value return ok

		nSum += value 

	func braceEnd 
		
		? nSum 
