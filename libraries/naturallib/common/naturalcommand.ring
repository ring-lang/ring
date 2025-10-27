# The Ring Natural Library
# 2017-2025, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"

DefineNaturalCommand = new NaturalCommand

class NaturalCommand

	cPackage cKeyword  fFunc oObject aAllKeywords=[]
	cCommand cCommandNoSpaces aKeywords


	func Para2Attributes aPara
		cPackage = aPara[:Package]
		cKeyword = aPara[:Keyword]
		fFunc = aPara[:Function]

	func CreateTheTempClass
		cCode = "oObject = new #{f1}.#{f2}
			Package #{f1}
			Class #{f2}" + nl
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cKeyword)
		return cCode

	func DefineAddAttributes
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
		eval(PrepareNewClass(aPara))
		AddMethod(oObject,"Get"+cKeyword,fFunc)

	func DefineExecute
		AddMethod(oObject,"BraceExecute_"+cKeyword,fFunc)

	func SyntaxIsKeywordNumbers aPara,nCount
		cCode = PrepareNewClass(aPara)
		cCode += PrepareCommandExpr()	
		cCode += GetExprNumbers(nCount)
		eval(cCode)	
		DefineExecute()

	func SyntaxIsKeywordNumberNumber  aPara
		SyntaxIsKeywordNumbers(aPara,2)

	func SyntaxIsKeywordNumber  aPara
		SyntaxIsKeywordNumbers(aPara,1)

	func SyntaxIsKeywordStrings aPara,nCount
		cCode = PrepareNewClass(aPara)
		cCode += PrepareCommandExpr()
		cCode += GetExprStrings(nCount)
		eval(cCode)		
		DefineExecute()

	func SyntaxIsKeywordStringString  aPara
		SyntaxIsKeywordStrings(aPara,2)

	func SyntaxIsKeywordString  aPara
		SyntaxIsKeywordStrings(aPara,1)

	func SyntaxIsKeywordExpressions aPara,nCount
		cCode = PrepareNewClass(aPara)
		cCode += PrepareCommandExpr()	
		cCode += GetExprAny(nCount)
		eval(cCode)	
		DefineExecute()

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
		cCode = ' func '+"Get"+cKeyword+' { 
				if processCommandKeyword1(:#{f1}) { processCommandKeyword2(:#{f1},#{f2}) }
				return processCommandKeyword3(#{f2})
			}' + nl
		cCode = substr(cCode,"#{f1}",cKeyword)
		cCode = substr(cCode,"#{f2}","aMethods_" + cKeyword)
		return cCode

	func CommandPara2Attributes aPara
		cPackage = aPara[:Package]
		cCommand = aPara[:Command]
		cCommandNoSpaces = substr(cCommand," ","")
		fFunc = aPara[:Function]				
		aKeywords = split(cCommand," ")

	func CreateCommandClass 
		cCode = `oObject = new #{f1}.#{f2}
			addMethod(oObject,"#{f3}","#{f4}")
			Package #{f1}
			Class #{f2}` + nl
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cCommandNoSpaces)
		cCode = substr(cCode,"#{f3}","BraceExecute_"+cCommandNoSpaces)
		cCode = substr(cCode,"#{f4}",fFunc)
		return cCode

	func DefineCommandAttributes
		cCode = " func "+ "AddAttributes_"+cCommandNoSpaces+ "{ " + nl
		cCode += "defineAttribute(["
		n = 1
		nMax = len(aKeywords)
		for cKeyword in aKeywords {
			cCode += ":"+cKeyword
			if n != nMax { cCode += "," }
		}
		cCode += "])" + nl
		cCode += "} "

		# Define keywords 

		for cKeyword in aKeywords {
			cCode += DefineCommandKeyword(cKeyword)
		}

		return cCode 

	func prepareNewCommand aPara

		CommandPara2Attributes(aPara)

		# Create the Class
		cCode = CreateCommandClass()

		# Add Attributes 
		cCode += DefineCommandAttributes()

		return cCode

	func SyntaxIsCommand  aPara

		cCodeBuf = prepareNewCommand(aPara)

		# Command Keywords Methods 

		cCodeBuf += ` func `+ cCommandNoSpaces+"_getfirstkeyword_"+aKeywords[1] +			
					` { return getFirstKeyword() } ` + nl

		for t = 2 to len(aKeywords) {
			cCode = ` func `+cCommandNoSpaces+"_getkeyword_"+aKeywords[t] +
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

		eval(cCodeBuf)

	func SyntaxIsCommandExpressions_  aPara,cExprType,nCount

		cCodeBuf = prepareNewCommand(aPara)

		# Command Keywords Methods 

		cCodeBuf += ` func `+cCommandNoSpaces+"_getfirstkeyword_"+aKeywords[1] +
			` { return getFirstKeyword() } ` + nl
		for t = 2 to len(aKeywords) {
			cCode = ` func `+cCommandNoSpaces+"_getkeyword_"+aKeywords[t]+
					" { return getSubKeywordBeforeExpr("+t+","+len(aKeywords)+",:"+cCommandNoSpaces+") }" + nl
			cCodeBuf += cCode
		}

		# Command Expressions
		cKeyword = cCommandNoSpaces
		cCodeBuf += GetExpr(nCount,cExprType)

		eval(cCodeBuf)

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
