# The Ring Natural Library
# 2017-2025, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"

Class NaturalBase

	aCommandsStack = []
	nActiveCommand = 0

	lPrepareExprEval = True
	aExprEvalMethods = []

	lPassError = True 

	aClassMethods = []

	aKeywordMethods = []

	lPrepareAttributes = True

	lTreatIdentifierAsString = True
	lStringIsIdentifier = False

/*
	We separate the methods to add it using mergemethods() instead of inheritance
	This gives these methods higher order when searching for methods (Better Performance)
*/

class NaturalBaseMethods

	func prepareClassMethods 
		if ! aClassMethods {
			aClassMethods = methods(self)	
		}

	func BraceStart
		if ! lPrepareAttributes { return }
		lPrepareAttributes = False
		prepareClassMethods()
		for cMethod in aClassMethods {
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
			prepareClassMethods()
			for cMethod in aClassMethods {
				if left(cMethod,14) = "braceexpreval_" {
					aExprEvalMethods + cMethod
				}
			}
			BraceExprEval(Value)
		}

	func BraceError
		if lTreatIdentifierAsString {
			cVarName = getVarName(cCatchError)
			if cVarName {
				lStringIsIdentifier = True 
				BraceExprEval(cVarName)
				lStringIsIdentifier = False
				return 
			}
		}
		if lPassError { return }
		new NatLibError { raise(cCatchError) }

	func getVarName cError
		if left(cError,11) = "Error (R24)" {
			return substr(cError,45)
		}

	func isIdentifier nIndex
		return aCommandsStack[nActiveCommand][2][:aIsIdentifier][nIndex]

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
		return :NLNV

	func getKeyword cKeyword
		StartCommand()
		CommandData()[:name] = cKeyword
		CommandData()[:nExpr] = 0
		CommandData()[:aExpr] = []
		CommandData()[:aIsIdentifier] = []
		return :NLNV

	func processExprValue ExprValue,cKeyword,nCount,cType

		if isCommand() and CommandData()[:name] = cKeyword {
			if ( cType = :String and (! isString(ExprValue)) ) or
			   ( cType = :Number and (! isNumber(ExprValue)) ) { return }
			CommandData()[:nExpr]++   
			CommandData()[:aExpr] + ExprValue
			CommandData()[:aIsIdentifier] + lStringIsIdentifier
			if CommandData()[:nExpr] = nCount {
				cMethodName = "BraceExecute_"+cKeyword
				call cMethodName()
			}
			return True
		}

	func getSubKeyword nIndex, cMethodName
		if IsCommand() and isNumber(CommandData()[:nKeyword]) and		
		   CommandData()[:nKeyword] = nIndex - 1 {
			CommandData()[:nKeyword] = nIndex
			if cMethodName { call cMethodName() }
			return True
		}

	func getSubKeywordBeforeExpr nIndex, nCount, cCommand
		if IsCommand() and isNumber(CommandData()[:nKeyword]) and		
		   CommandData()[:nKeyword] = nIndex - 1 {
			CommandData()[:nKeyword] = nIndex
			if nIndex = nCount {
					CommandData()[:name] = cCommand
					CommandData()[:nExpr] = 0
					CommandData()[:aExpr] = []
					CommandData()[:aIsIdentifier] = []
			}
			return True
		}

	func processCommandKeyword cKeyword 
		if ! aKeywordMethods[cKeyword] {
			aKeywordMethods[cKeyword] = []
			processCommandKeyword2(cKeyword,aKeywordMethods[cKeyword])

		}
		return processCommandKeyword3(aKeywordMethods[cKeyword])

	func processCommandKeyword2 cKeyword,aMethods 
		prepareClassMethods()
		nSize1 = len("getkeywordn_"+cKeyword)
		nSize2 = len("getkeyword1_"+cKeyword)
		for cMethod in aClassMethods {
			if right(cMethod,nSize1) = "getkeywordn_"+cKeyword {
				insert(aMethods,0,cMethod)
			elseif right(cMethod,nSize2) = "getkeyword1_"+cKeyword
				aMethods + cMethod						
			}
		}

	func processCommandKeyword3 aMethods
		for cMethod in aMethods {
			if call cMethod() { exit }
		}
		return :NLNV

class NatLibError
