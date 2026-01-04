new SumRows {
	10 20 30      # 60
	10            # 10
	400 100       # 500
	30 40         # 70
}

class SumRows

	lSum	 = False
	nSum     = 0
	nLastRow = 0

	func braceExprEval  value 

		lSum  = True
		nSum += value 

	func braceNewLine

		if lSum ? nSum nSum=0 lSum=False ok
