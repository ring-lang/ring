# The Ring Natural Library
# 2017-2025, Mahmoud Fayed <msfclipper@yahoo.com>

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

	func defineAttribute vAttr
		if isString(vAttr) {
			if ! isAttribute(self,vAttr) {
				AddAttribute(self,vAttr)
			}
		elseif isList(vAttr)
			for cAttr in vAttr {
				if ! isAttribute(self,cAttr) {
					AddAttribute(self,cAttr)
				}
			}
		}

	func getFirstKeyword
		StartCommand()
		CommandData()[:nKeyword] = 1
		return True

	func getKeyword cKeyword
		StartCommand()
		CommandData()[:name] = cKeyword
		CommandData()[:nExpr] = 0
		CommandData()[:aExpr] = []
		return :NLNV

	func processExprValue ExprValue,cKeyword,nCount,cType

		if isCommand() and CommandData()[:name] = cKeyword {
			if cType = :String and (! isString(ExprValue)) { return }
			if cType = :Number and (! isNumber(ExprValue)) { return }
			CommandData()[:nExpr]++   
			CommandData()[:aExpr] + ExprValue
			if CommandData()[:nExpr] = nCount {
				cMethodName = "BraceExecute_"+cKeyword
				call cMethodName()
			}
			return True
		}

	func getSubKeyword nIndex, cMethodName
		if (not IsCommand()) or (not isNumber(CommandData()[:nKeyword])) { return }		
		if CommandData()[:nKeyword] = nIndex - 1 {
			CommandData()[:nKeyword] = nIndex
			if cMethodName { call cMethodName() }
			return True
		}

	func getSubKeywordBeforeExpr nIndex, nCount, cCommand
		if (not IsCommand()) or (not isNumber(CommandData()[:nKeyword])) { return }		
		if CommandData()[:nKeyword] = nIndex - 1 {
			CommandData()[:nKeyword] = nIndex
			if nIndex = nCount {
					CommandData()[:name] = cCommand
					CommandData()[:nExpr] = 0
					CommandData()[:aExpr] = []
			}
			return True
		}

	func processCommandKeyword1 cKeyword
		cMethodsList = "aMethods_" + cKeyword
		if ! isAttribute(self,cMethodsList) {
			addAttribute(self,cMethodsList)
			setAttribute(self,cMethodsList,[])
			return True 
		}

	func processCommandKeyword2 cKeyword, aMethods 
		aClassMethods = methods(self)	
		for cMethod in aClassMethods {
			if right(cMethod,len("getkeyword_"+cKeyword)) = "getkeyword_"+cKeyword {
				insert(aMethods,0,cMethod)
			elseif right(cMethod,len("getfirstkeyword_"+cKeyword)) = "getfirstkeyword_"+cKeyword
				aMethods + cMethod						
			}
		}

	func processCommandKeyword3 aMethods 
		for cMethod in aMethods {
			if call cMethod() { exit }
		}
		return :NLNV

class NatLibError
