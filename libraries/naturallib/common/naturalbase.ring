# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"

Class NaturalBase

	aCommandsStack = []
	nCommandsCount = 0

	lPrepareExprEval = True
	aExprEvalMethods = []

	func BraceStart
		aMethods = methods(self)	
		for cMethod in aMethods {
			if left(cMethod,14) = "addattributes_" {
				call cMethod()
			}
		}
	
	func BraceExprEval Value

		if (! lPrepareExprEval) {
			if aExprEvalMethods and (isNumber(Value) or isString(Value)) { 
				for cMethod in aExprEvalMethods {
					call cMethod(Value)
				}	
			}
		else
			lPrepareExprEval = False
			aClassMethods = methods(self)	
			for cMethod in aClassMethods {
				if left(cMethod,14) = "braceexpreval_" {
					aExprEvalMethods + cMethod
				}
			}
	
		}

	func BraceError

	func StartCommand 
		nCommandsCount++
		aCommandsStack + [nCommandsCount,[/*command data*/]] 

		return nCommandsCount

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
		return aCommandsStack[nCommandsCount][2][:aExpr][nIndex]
