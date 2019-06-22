# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlib.ring"

Class NaturalBase

	aCommandsStack = []
	nCommandID = 0
	nCommandsCount = 0

	aClassMethods = []

	aBraceMethods = []

	func BraceStart
		aMethods = methods(self)	
		for cMethod in aMethods {
			if left(cMethod,14) = "addattributes_" {
				call cMethod()
			}
		}
		aClassMethods = methods(self)	
		for cMethod in aClassMethods {
			if left(cMethod,14) = "braceexpreval_" {
				aBraceMethods + cMethod
			}
		}

	func BraceExprEval Value
		for cMethod in aBraceMethods {
			if isNumber(Value) or isString(Value) {
				call cMethod(Value)
			}
		}

	func BraceError

	func StartCommand 
		nCommandID++
		aCommandsStack + [nCommandID,[/*command data*/]] 
		nCommandsCount++
		return nCommandID

	func EndCommand 
		del(aCommandsStack,nCommandsCount)
		nCommandsCount--

	func CommandID
		return aCommandsStack[nCommandsCount][1]

	func CommandData
		return aCommandsStack[nCommandsCount][2]

	func IsCommand
		return nCommandsCount

	func CommandOutput vValue
		BraceExprEval(vValue)

	func CommandReturn vValue
		EndCommand()
		BraceExprEval(vValue)

	func Expr nIndex
		return CommandData()[:aExpr][nIndex]
