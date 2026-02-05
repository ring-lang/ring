# The Ring Natural Library
# 2017-2026, Mahmoud Fayed <msfclipper@yahoo.com>

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

	lCommandReturnIsUsed = False
	lPassThisCommand = False

	lUse@BeforeNumbers = False	 

	lEnableBraceExprEval = True

	aCommandMemory = []  // Used for sharing interal data between commands
	vCommandOutput       // Used for command output to DSL caller

	v = []               // Used for storing external state ["key",value] for DSL user/caller 

	cCurrentKeyword

	nCallerScope = 1

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
		vCommandOutput = NULL
		if ! lPrepareAttributes { return }
		lPrepareAttributes = False
		prepareClassMethods()
		for cMethod in aClassMethods {
			if left(cMethod,14) = "addattributes_" {
				call cMethod()
			}
		}
		lUse@BeforeNumbers = isMethod(self,:Get@)
	
	func BraceExprEval Value
		if ! lEnableBraceExprEval { return }
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
		nCallerScope = ringvm_scopescount()-1
		if lTreatIdentifierAsString {
			cVarName = getVarName(cCatchError)
			if cVarName {
				if lUse@BeforeNumbers and left(cVarName,1) = "@"  {
					get@()
					cVarName = substr(cVarName,2)
					if isDigit(substr(cVarName,2)) {
						cNumValue = Number(cVarName)
						BraceExprEval(cNumValue)
						return :NLNV
					}
					return NatLibCallerGetVar(self,cVarName)
				}
				lStringIsIdentifier = True 
				BraceExprEval(cVarName)
				lStringIsIdentifier = False
				return :NLNV 
			}
		}
		if lPassError { return }
		new NatLibError { raise(cCatchError) }

	func braceEnd 
		if ! lPassError {
			removeCommandsThatUsesPass()
			if aCommandsStack {
				new NatLibError { raise(C_NATLIB_ERROR_INCOMPLETECMD) }
			}
		}

	func removeCommandsThatUsesPass
		nMax = len(aCommandsStack)
		for t=nMax to 1 step -1 {
			if aCommandsStack[t][2][:lPassThisCommand] {
				del(aCommandsStack,t)
			}
		}

	func getVarName cError
		if left(cError,11) = "Error (R24)" {
			return substr(cError,45)
		}

	func isIdentifier nIndex
		return aCommandsStack[nActiveCommand][2][:aIsIdentifier][nIndex]

	func IdentifierToString lStatus 
		lTreatIdentifierAsString = lStatus

	func StartCommand 
		vCommandOutput = NULL
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

	func CommandReturn vValue
		lCommandReturnIsUsed = True 
		vCommandOutput = vValue
		if ! lPassThisCommand {
			EndCommand()
		}
		BraceExprEval(vValue)

	func PassThisCommand
		lPassThisCommand = True 
		aCommandsStack[nActiveCommand][2][:lPassThisCommand] = True

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
		CommandData()[:cCmdBuf] += cCurrentKeyword
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
			if ! cMethodName {
				CommandData()[:nKeyword] = nIndex
				CommandData()[:cCmdBuf] += cCurrentKeyword
				return True 
			}			
			if right(cMethodName,len(CommandData()[:cCmdBuf]+cCurrentKeyword)) = CommandData()[:cCmdBuf]+cCurrentKeyword {
				CommandData()[:nKeyword] = nIndex
				CommandData()[:cCmdBuf] += cCurrentKeyword
				call cMethodName() 
				return True
			}
		}

	func getSubKeywordBeforeExpr nIndex, nCount, cCommand
		if IsCommand() and isNumber(CommandData()[:nKeyword]) and		
		   CommandData()[:nKeyword] = nIndex - 1 {
			if nIndex < nCount {
				CommandData()[:nKeyword] = nIndex
				CommandData()[:cCmdBuf] += cCurrentKeyword
				return True 
			}
			if CommandData()[:cCmdBuf] + cCurrentKeyword = cCommand {
				CommandData()[:nKeyword] = nIndex
				CommandData()[:cCmdBuf] += cCurrentKeyword
				CommandData()[:name] = cCommand
				CommandData()[:nExpr] = 0
				CommandData()[:aExpr] = []
				CommandData()[:aIsIdentifier] = []
				return True
			}
		}

	func processCommandKeyword cKeyword 
		// -2 because this method is called from Getter method like GetWant()
		nCallerScope = ringvm_scopescount()-2	
		cCurrentKeyword = cKeyword
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

	func executeCommandFunction fMethod
		NATLIB_TEMP_OUT = call { fMethod() }
		if ! lCommandReturnIsUsed and ! lPassThisCommand { EndCommand() }
		lCommandReturnIsUsed = False 
		lPassThisCommand = False
		return NATLIB_TEMP_OUT

	func setPassError lStatus 
		lPassError = lStatus

	func setTreatIdentifierAsString lStatus
		lTreatIdentifierAsString = lStatus

	func @ cCode 
		return NatLibExecute(self,cCode)
	
	func register cAttr 
		if ! isAttribute(self,cAttr) {
			addAttribute(self,cAttr)
		}

	func prepareCallerScope
		nCallerScope = ringvm_scopescount() - 2

	func CallerGetVar cVar
		return NatLibCallerGetVar(self,cVar)

	func CallerSetVar cVar,cValue
		NatLibCallerSetVar(self,cVar,cValue)

class NatLibError
