# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

Package MyLanguage.Natural

class Count
           
	func Getcount
		StartCommand()
		CommandData()[:name] = :Count
		CommandData()[:nExpr] = 0
		CommandData()[:aExpr] = []

	func BraceExprEval_Count nValue
		if isCommand() and CommandData()[:name] = :Count {
			if isNumber(nValue) {
				CommandData()[:nExpr]++     
				CommandData()[:aExpr] + nValue
				if CommandData()[:nExpr] = 2 {
					Count_Execute()
				}
			}
		}

	func AddAttributes_Count	
		AddAttribute(self,:count)

	func Count_Execute
		if not isattribute(self,:count_times) {
			AddAttribute(self,:count_times)
			Count_Times = 0
		}
		if Expr(1) > Expr(2) { 
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
		for x = Expr(1) to Expr(2) step nStep {
			see nl+x+nl 
		}
		CommandReturn(fabs(Expr(1)-Expr(2))+1)				
