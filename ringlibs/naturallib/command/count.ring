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
					if CommandData()[:aExpr][1] > CommandData()[:aExpr][2] { 
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
					for x = CommandData()[:aExpr][1] to CommandData()[:aExpr][2] step nStep {
						see nl+x+nl 
					}
					CommandReturn(fabs(CommandData()[:aExpr][1]-CommandData()[:aExpr][2]))				
				}
			}
		}

	func AddAttributes_Count	
		AddAttribute(self,:count)
		AddAttribute(self,:count_times)
		Count_Times = 0
