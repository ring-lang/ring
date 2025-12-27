# The Ring Natural Library
# 2017-2025, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"

DefineNaturalCommand = new NaturalCommand

class NaturalCommand

	cPackage cKeyword  fFunc  
	cCommand cCommandNoSpaces aKeywords

	aAllKeywords = []
	aAllAttributes = []
	aAllKeywordsMethods = []

	lSyntaxIsKeyword = False

	lCacheCommands = False
	cCommandsCache = ""
	cGroupName = :ManyCommands

	func Para2Attributes aPara
		cPackage = aPara[:Package]
		cKeyword = aPara[:Keyword]
		fFunc = aPara[:Function]
		cCommandNoSpaces = cKeyword

	func CreateTheTempClass
		cCode = ""
		if ! lCacheCommands {
			cCode = "Package #{f1}" + nl + "Class #{f2}" + nl 
		}
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cCommandNoSpaces)
		cCode = substr(cCode,"#{f3}",fFunc)

		if lSyntaxIsKeyword {
			cCode += "func Get" +cCommandNoSpaces + nl +
					" fMethod = :" + fFunc + nl +
					"call { fMethod() }" + nl 
		else
			cCode += "func BraceExecute_" +cCommandNoSpaces + nl +
					" fMethod = :" + fFunc + nl +
					"call { fMethod() }" + nl 
		}

		return cCode

	func DefineAddAttributes
		if find(aAllAttributes,cKeyword) { return }
		aAllAttributes + cKeyword
		cCode = " func "+ "AddAttributes_"+cKeyword +
				" {  defineAttribute(:"+cKeyword+") } " + nl
		return cCode

	func PrepareNewClass aPara 
		Para2Attributes(aPara)
		cCode = CreateTheTempClass()
		cCode += DefineAddAttributes()
		return cCode

	func PrepareCommandExpr
		# We return :NLNV because the values returned
		# From this function will call braceexpr() !
		# And we need unique value to avoid it.
		cCode = " func "+"Get"+cKeyword+" { return getKeyword(:"+cKeyword+") } " + nl
		return cCode	

	func GetExpr nCount,cType
		cCode = " func "+"BraceExprEval_"+cKeyword+" ExprValue { 
				processExprValue(ExprValue,:"+cKeyword+","+nCount+",:"+cType+")
		} 
		"
		return cCode

	func GetExprNumbers nCount
		return GetExpr(nCount,:Number)

	func GetExprStrings nCount
		return GetExpr(nCount,:String)

	func GetExprAny nCount
		return GetExpr(nCount,:Any)

	func SyntaxIsKeyword  aPara
		lSyntaxIsKeyword = True
		cmdEval(PrepareNewClass(aPara))
		lSyntaxIsKeyword = False

	func SyntaxIsKeywordNumbers aPara,nCount
		cCode = PrepareNewClass(aPara)
		cCode += PrepareCommandExpr()	
		cCode += GetExprNumbers(nCount)
		cmdEval(cCode)	

	func SyntaxIsKeywordNumberNumber  aPara
		SyntaxIsKeywordNumbers(aPara,2)

	func SyntaxIsKeywordNumber  aPara
		SyntaxIsKeywordNumbers(aPara,1)

	func SyntaxIsKeywordStrings aPara,nCount
		cCode = PrepareNewClass(aPara)
		cCode += PrepareCommandExpr()
		cCode += GetExprStrings(nCount)
		cmdEval(cCode)		

	func SyntaxIsKeywordStringString  aPara
		SyntaxIsKeywordStrings(aPara,2)

	func SyntaxIsKeywordString  aPara
		SyntaxIsKeywordStrings(aPara,1)

	func SyntaxIsKeywordExpressions aPara,nCount
		cCode = PrepareNewClass(aPara)
		cCode += PrepareCommandExpr()	
		cCode += GetExprAny(nCount)
		cmdEval(cCode)	

	func SyntaxIsKeywordExpressionExpression  aPara
		SyntaxIsKeywordExpressions(aPara,2)

	func SyntaxIsKeywordExpression  aPara
		SyntaxIsKeywordExpressions(aPara,1)

	func DefineCommandKeyword cKeyword
		# We uses this method
		# To be able to share keywords between commands 		
		if find(aAllKeywords,cKeyword) { return }
		aAllKeywords + cKeyword 
		/* 
			If the keyword is the first keyword in a command, add it to the end of the list()
			So the same keyword in the middle/end of other commands are executed first
		*/
		cCode = ' func '+"Get"+cKeyword+' { return processCommandKeyword(:'+cKeyword+') }' + nl
		return cCode

	func CommandPara2Attributes aPara
		cPackage = aPara[:Package]
		cCommand = aPara[:Command]
		cCommandNoSpaces = substr(cCommand," ","")
		fFunc = aPara[:Function]				
		aKeywords = split(cCommand," ")

	func DefineCommandAttributes
		cCode = " func "+ "AddAttributes_"+cCommandNoSpaces+ " { "
		cCode += "defineAttribute(["
		n = 0
		nMax = len(aKeywords)
		for cKeyword in aKeywords {
			if find(aAllAttributes,cKeyword) { n++ loop }
			aAllAttributes + cKeyword
			cCode += ":"+cKeyword
			if n++ != nMax { cCode += "," }
		}
		cCode += "]) }" + nl

		# Define keywords 

		for cKeyword in aKeywords {
			cCode += DefineCommandKeyword(cKeyword)
		}

		return cCode 

	func prepareNewCommand aPara

		CommandPara2Attributes(aPara)

		# Create the Class
		cCode = CreateTheTempClass()

		# Add Attributes 
		cCode += DefineCommandAttributes()

		return cCode

	func SyntaxIsCommand  aPara

		cCodeBuf = prepareNewCommand(aPara)

		# Command Keywords Methods 
		if ! find(aAllKeywordsMethods,aKeywords[1]+"_1") {
			aAllKeywordsMethods + (aKeywords[1]+"_1")
			cCodeBuf += ` func `+ cCommandNoSpaces+"_getkeyword1_"+aKeywords[1] +			
					` { return getFirstKeyword() } ` + nl
		}

		for t = 2 to len(aKeywords) {
			if find(aAllKeywordsMethods,aKeywords[t]+"_"+t) {
				loop
			}
			aAllKeywordsMethods + (aKeywords[t]+"_"+t)
			cCode = ` func `+cCommandNoSpaces+"_getkeywordn_"+aKeywords[t] +
					` { return getSubKeyword(#{f1},"#{f2}") } ` + nl
			cCode = substr(cCode,"#{f1}",""+t)
			if t = len(aKeywords) {
				cExecuteMethod = "BraceExecute_"+cCommandNoSpaces
				cCode = substr(cCode,"#{f2}",cExecuteMethod)
			else
				cCode = substr(cCode,"#{f2}","")
			}
			cCodeBuf += cCode
		}

		cmdEval(cCodeBuf)

	func SyntaxIsCommandExpressions_  aPara,cExprType,nCount

		cCodeBuf = prepareNewCommand(aPara)

		# Command Keywords Methods 

		if ! find(aAllKeywordsMethods,aKeywords[1]+"_1") {
			aAllKeywordsMethods + (aKeywords[1]+"_1")
			cCodeBuf += ` func `+cCommandNoSpaces+"_getkeyword1_"+aKeywords[1] +
			` { return getFirstKeyword() } ` + nl
		}
		for t = 2 to len(aKeywords) {
			if find(aAllKeywordsMethods,aKeywords[t]+"_"+t) {
				loop
			}
			aAllKeywordsMethods + (aKeywords[t]+"_"+t)
			cCode = ` func `+cCommandNoSpaces+"_getkeywordn_"+aKeywords[t]+
					" { return getSubKeywordBeforeExpr("+t+","+len(aKeywords)+",:"+cCommandNoSpaces+") }" + nl
			cCodeBuf += cCode
		}

		# Command Expressions
		cKeyword = cCommandNoSpaces
		cCodeBuf += GetExpr(nCount,cExprType)

		cmdEval(cCodeBuf)

	func SyntaxIsCommandExpression  aPara
		SyntaxIsCommandExpressions_(aPara,:Any,1)

	func SyntaxIsCommandExpressionExpression  aPara
		SyntaxIsCommandExpressions_(aPara,:Any,2)

	func SyntaxIsCommandString  aPara
		SyntaxIsCommandExpressions_(aPara,:String,1)

	func SyntaxIsCommandStringString  aPara
		SyntaxIsCommandExpressions_(aPara,:String,2)

	func SyntaxIsCommandStrings  aPara,nCount
		SyntaxIsCommandExpressions_(aPara,:String,nCount)

	func SyntaxIsCommandNumber  aPara
		SyntaxIsCommandExpressions_(aPara,:Number,1)

	func SyntaxIsCommandNumberNumber  aPara
		SyntaxIsCommandExpressions_(aPara,:Number,2)

	func SyntaxIsCommandNumbers  aPara,nCount
		SyntaxIsCommandExpressions_(aPara,:Number,nCount)

	func SyntaxIsCommandExpressions  aPara,nCount
		SyntaxIsCommandExpressions_(aPara,:any,nCount)

	func startCache cName
		lCacheCommands = True 
		cGroupName = cName
		cCommandsCache = ""

	func endCache
		lCacheCommands = False
		cCommandsCache = "Package " + cPackage + nl +
			"Class " + cGroupName + nl + cCommandsCache
		eval(cCommandsCache)
		cCommandsCache = ""

	func cmdEval cCode
		if lCacheCommands {
			cCommandsCache += cCode + nl
		else
			eval(cCode)
		} 
