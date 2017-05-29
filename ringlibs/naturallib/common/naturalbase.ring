# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

Class NaturalBase

	func BraceStart
		aMethods = methods(self)	
		for cMethod in aMethods {
			if left(cMethod,14) = "addattributes_" {
				eval(cMethod+"()")
			}
		}

	func BraceExprEval Value
		aMethods = methods(self)	
		for cMethod in aMethods {
			if left(cMethod,14) = "braceexpreval_" {
				if isNumber(Value) {
					eval(cMethod+"("+Value+")")
				elseif isString(Value) 
					eval(cMethod+"('"+Value+"')")
				}
			}
		}

	func BraceError
