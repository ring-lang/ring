# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlib.ring"

Class NaturalBase

	aCommandsStack = []
	nCommandID = 0

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
					call cMethod(Value)
				elseif isString(Value) 
					call cMethod(Value)
				}
			}
		}

	func BraceError

	func StartCommand 
		nCommandID++
		aCommandsStack + [nCommandID,[/*command data*/]] 
		return nCommandID

	func EndCommand 
		del(aCommandsStack,len(aCommandsStack))

	func CommandID
		return aCommandsStack[len(acommandsStack)][1]

	func CommandData
		return aCommandsStack[len(acommandsStack)][2]

	func IsCommand
		return len(aCommandsStack)

	func CommandOutput vValue
		BraceExprEval(vValue)

	func CommandReturn vValue
		EndCommand()
		BraceExprEval(vValue)

	func Expr nIndex
		return CommandData()[:aExpr][nIndex]
