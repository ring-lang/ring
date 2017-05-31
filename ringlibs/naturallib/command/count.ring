# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

Package MyLanguage.Natural

class Count
           
	func Getcount
		StartCommand()
		ActiveCommandData()[:cCmd] = :Count
		ActiveCommandData()[:nExpr] = 0
		ActiveCommandData()[:aExpr] = []

	func BraceExprEval_Count nValue
		if isActiveCommand() and ActiveCommandData()[:cCmd] = :Count {
			if isNumber(nValue) {
				ActiveCommandData()[:nExpr]++     
				ActiveCommandData()[:aExpr] + nValue
				if ActiveCommandData()[:nExpr] = 2 {
					if ActiveCommandData()[:aExpr][1] > ActiveCommandData()[:aExpr][2] { 
						nStep = -1 
					else 
						nStep = 1
					}
					if Count_Times = 0 { 
						see nl+"The Numbers!" + nl 
						Count_Times++
					else 
						see nl + "I will count Again!" +nl 
					}
					for x = ActiveCommandData()[:aExpr][1] to ActiveCommandData()[:aExpr][2] step nStep {
						see nl+x+nl 
					}
					EndCommand()
				}
			}
		}

	func AddAttributes_Count	
		AddAttribute(self,:count)
		AddAttribute(self,:count_times)
		Count_Times = 0
