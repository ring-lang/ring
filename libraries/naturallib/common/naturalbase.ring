# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"

Class NaturalBase

	aCommandsStack = []
	nActiveCommand = 0

	lPrepareExprEval = True
	aExprEvalMethods = []

	lPassError = True 

	func BraceStart
		aMethods = methods(self)	
		for cMethod in aMethods {
			if left(cMethod,14) = "addattributes_" {
				call cMethod()
			}
		}
	
	func BraceExprEval Value

		if isString(Value) and value = :NLNV { return }
		if (! lPrepareExprEval) {
			if aExprEvalMethods { 
				for cMethod in aExprEvalMethods {
					if call cMethod(Value) { exit }
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
			BraceExprEval(Value)
		}

	func BraceError
		if lPassError { return }
		new NatLibError { raise(cCatchError) }

	func StartCommand 
		if len(aCommandsStack) = 16 {
			del(aCommandsStack,1)
		}
		aCommandsStack + [nActiveCommand,[/*command data*/]] 
		nActiveCommand = len(aCommandsStack)
		return nActiveCommand

	func EndCommand 
		del(aCommandsStack,nActiveCommand)
		nActiveCommand = len(aCommandsStack)

	func CommandID
		return aCommandsStack[nActiveCommand][1]

	func CommandData
		return aCommandsStack[nActiveCommand][2]

	func IsCommand
		return nActiveCommand

	func CommandOutput vValue
		BraceExprEval(vValue)

	func CommandReturn vValue
		EndCommand()
		BraceExprEval(vValue)

	func Expr nIndex
		return aCommandsStack[nActiveCommand][2][:aExpr][nIndex]


class NatLibError
