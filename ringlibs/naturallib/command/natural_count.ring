# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

class Natural_Count from NaturalCommand
           
	func Getcount
		count_data[:nCmd] = 1   

	func BraceExprEval_Count nValue
		if isNumber(nValue) {
			count_data[:nExpr]++     
			count_data[:aExpr] + nValue
			if count_data[:nExpr] = 2 and count_data[:nCmd] = 1 {
				if count_data[:aExpr][1] > count_data[:aExpr][2] { 
					nStep = -1 
				else 
					nStep = 1
				}
				if count_data[:nTime] = 0 { 
					see nl+"The Numbers!" + nl 
					count_data[:nTime]++
				else 
					see nl + "I will count Again!" +nl 
				}
				for x = count_data[:aExpr][1] to count_data[:aExpr][2] step nStep {
					see nl+x+nl 
				}
				ClearState()
			}
		}

	func AddAttributes_Count	
		AddAttribute(self,:count)
		AddAttribute(self,:count_data)
		count_data = []
		ClearState()
		count_data[:nTime] = 0

	func ClearState
		count_data[:nCmd] = 0
		count_data[:nExpr] = 0
		count_data[:aExpr] = []   	
