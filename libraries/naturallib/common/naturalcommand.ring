# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlib.ring"

DefineNaturalCommand = new NaturalCommand

class NaturalCommand

	cPackage cKeyword  fFunc oObject aAllKeywords=[]
	cCommand cCommandNoSpaces aKeywords


	func Para2Attributes aPara
		cPackage = aPara[:Package]
		cKeyword = aPara[:Keyword]
		fFunc = aPara[:Function]

	func CreateTheTempClass
		cCode = "
			oObject = new #{f1}.#{f2}
			Package #{f1}
			Class #{f2}
		"
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cKeyword)
		eval(cCode)

	func DefineAddAttributes
		cCode = " 	f1 = func { AddAttribute(self,:#{f1}) } "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"AddAttributes_"+cKeyword,f1)

	func PrepareNewClass aPara 
		Para2Attributes(aPara)
		CreateTheTempClass()
		DefineAddAttributes()

	func PrepareCommandExpr
		cCode = " 	f1 = func { 
			StartCommand()
			CommandData()[:name] = :#{f1}
			CommandData()[:nExpr] = 0
			CommandData()[:aExpr] = []
			# We return :Natural_Null because the values returned
			# From this function will call braceexpr() !
			# And we need unique value to avoid it.
			return :NATURAL_NULL
		} "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"Get"+cKeyword,f1)

	func GetExpr nCount,cType
		cCode = " 	f1 = func ExprValue { 
			if isCommand() and CommandData()[:name] = :#{f1} {
				#{f3}
					CommandData()[:nExpr]++   
					CommandData()[:aExpr] + ExprValue
					if CommandData()[:nExpr] = #{f2} {
						BraceExecute_#{f1}()
					}
				#{f4}
			}
		} "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		cCode = SubStr(cCode,"#{f2}",""+nCount)
		switch cType {
			case :string
				cCode = SubStr(cCode,"#{f3}","if isString(ExprValue) and ExprValue != :NATURAL_NULL {")
				cCode = SubStr(cCode,"#{f4}","}")
			case :number 
				cCode = SubStr(cCode,"#{f3}","if isNumber(ExprValue) {")
				cCode = SubStr(cCode,"#{f4}","}")
			case :any 
				cCode = SubStr(cCode,"#{f3}","if (isString(ExprValue) and ExprValue != :NATURAL_NULL) or isNumber(ExprValue) {")
				cCode = SubStr(cCode,"#{f4}","}")
		}
		eval(cCode)	
		AddMethod(oObject,"BraceExprEval_"+cKeyword,f1)

	func GetExprNumbers nCount
		GetExpr(nCount,:Number)

	func GetExprStrings nCount
		GetExpr(nCount,:String)

	func GetExprAny nCount
		GetExpr(nCount,:Any)

	func SyntaxIsKeyword  aPara
		PrepareNewClass(aPara)
		AddMethod(oObject,"Get"+cKeyword,fFunc)

	func DefineExecute
		AddMethod(oObject,"BraceExecute_"+cKeyword,fFunc)

	func SyntaxIsKeywordNumbers aPara,nCount
		PrepareNewClass(aPara)
		PrepareCommandExpr()		
		GetExprNumbers(nCount)
		DefineExecute()

	func SyntaxIsKeywordNumberNumber  aPara
		SyntaxIsKeywordNumbers(aPara,2)

	func SyntaxIsKeywordNumber  aPara
		SyntaxIsKeywordNumbers(aPara,1)

	func SyntaxIsKeywordStrings aPara,nCount
		PrepareNewClass(aPara)
		PrepareCommandExpr()		
		GetExprStrings(nCount)
		DefineExecute()

	func SyntaxIsKeywordStringString  aPara
		SyntaxIsKeywordStrings(aPara,2)

	func SyntaxIsKeywordString  aPara
		SyntaxIsKeywordStrings(aPara,1)

	func SyntaxIsKeywordExpressions aPara,nCount
		PrepareNewClass(aPara)
		PrepareCommandExpr()		
		GetExprAny(nCount)
		DefineExecute()

	func SyntaxIsKeywordExpressionExpression  aPara
		SyntaxIsKeywordExpressions(aPara,2)

	func SyntaxIsKeywordExpression  aPara
		SyntaxIsKeywordExpressions(aPara,1)

	func DefineCommandKeyword oObject,cKeyword
		# We uses this method
		# To be able to share keywords between commands 		
		if find(aAllKeywords,cKeyword) { return }
		aAllKeywords + cKeyword 
		cCode = '
			f1 = func {
				if ! isAttribute(self,"aMethods_#{f1}") {
					AddAttribute(self,"aMethods_#{f1}")
					aMethods_#{f1} = []
					aClassMethods = methods(self)	
					for cMethod in aClassMethods {
						if right(cMethod,len("getkeyword_#{f1}")) = "getkeyword_#{f1}" {
							aMethods_#{f1} + cMethod
						}
					}
				}
				for cMethod in aMethods_#{f1} {
					call cMethod()
				}
				return :NATURAL_NULL
			}
		'
		cCode = substr(cCode,"#{f1}",cKeyword)
		eval(cCode)
		AddMethod(oObject,"Get"+cKeyword,f1)

	func CommandPara2Attributes aPara
		cPackage = aPara[:Package]
		cCommand = aPara[:Command]
		cCommandNoSpaces = substr(cCommand," ","")
		fFunc = aPara[:Function]				
		aKeywords = split(cCommand," ")

	func CreateCommandClass 
		cCode = "
			oObject = new #{f1}.#{f2}
			Package #{f1}
			Class #{f2}
		"
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cCommandNoSpaces)
		eval(cCode)

	func DefineCommandAttributes
		cCode = " 	f1 = func { " + nl
		for cKeyword in aKeywords {
			cCode += "
				if not isAttribute(self,:#{f1}) {
					AddAttribute(self,:#{f1})
				}
			"
			cCode = SubStr(cCode,"#{f1}",cKeyword)
		}
		cCode += "} "
		eval(cCode)	
		AddMethod(oObject,"AddAttributes_"+cCommandNoSpaces,f1)

		# Define keywords 

		for cKeyword in aKeywords {
			DefineCommandKeyword(oObject,cKeyword)
		}

	func SyntaxIsCommand  aPara
		CommandPara2Attributes(aPara)

		# Create the Class
		CreateCommandClass()

		# Add Attributes 
		DefineCommandAttributes()

		# Command Keywords Methods 

		cCode = " 	f1 = func { 
			StartCommand()
			CommandData()[:nKeyword] = 1
		} "
		eval(cCode)	
		AddMethod(oObject,cCommandNoSpaces+"_getkeyword_"+aKeywords[1],f1)
		for t = 2 to len(aKeywords) {
			cCode = " 	f1 = func { 
				if (not IsCommand()) or (not isNumber(CommandData()[:nKeyword])) { return }		
				if CommandData()[:nKeyword] = #{f1} - 1 {
					CommandData()[:nKeyword] = #{f1}
					#{f2}
				}
			} "
			cCode = substr(cCode,"#{f1}",""+t)
			cExecuteMethod = "BraceExecute_"+cCommandNoSpaces
			if t = len(aKeywords) {
				cCode = substr(cCode,"#{f2}",cExecuteMethod+"()")
			else
				cCode = substr(cCode,"#{f2}","")
			}
			eval(cCode)	
			AddMethod(oObject,cCommandNoSpaces+"_getkeyword_"+aKeywords[t],f1)
		}

		# Define BraceExecute
		AddMethod(oObject,cExecuteMethod,fFunc)

	func SyntaxIsCommandExpressions_  aPara,cExprType,nCount

		CommandPara2Attributes(aPara)

		# Create the Class
		CreateCommandClass()

		# Add Attributes 
		DefineCommandAttributes()

		# Command Keywords Methods 

		cCode = " 	f1 = func { 
			StartCommand()
			CommandData()[:nKeyword] = 1
		} "
		eval(cCode)	
		AddMethod(oObject,cCommandNoSpaces+"_getkeyword_"+aKeywords[1],f1)
		for t = 2 to len(aKeywords) {
			cCode = " 	f1 = func { 
				if (not IsCommand()) or (not isNumber(CommandData()[:nKeyword])) { return }		
				if CommandData()[:nKeyword] = #{f1} - 1 {
					CommandData()[:nKeyword] = #{f1}
					#{f2}
				}
			} "
			cCode = substr(cCode,"#{f1}",""+t)
			cExecuteMethod = "BraceExecute_"+cCommandNoSpaces

			if t = len(aKeywords) {
				cCode2 = '
					CommandData()[:name] = :#{f1}
					CommandData()[:nExpr] = 0
					CommandData()[:aExpr] = []
				'
				cCode2 = substr(cCode2,"#{f1}",cCommandNoSpaces)
				cCode = substr(cCode,"#{f2}",cCode2)
			else
				cCode = substr(cCode,"#{f2}","")
			}
			eval(cCode)	
			AddMethod(oObject,cCommandNoSpaces+"_getkeyword_"+aKeywords[t],f1)
		}

		# Command Expressions
		cKeyword = cCommandNoSpaces
		GetExpr(nCount,cExprType)

		# Define BraceExecute
		AddMethod(oObject,cExecuteMethod,fFunc)

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
