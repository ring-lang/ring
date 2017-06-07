# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

DefineNaturalCommand = new NaturalCommand

class NaturalCommand

	cPackage cKeyword  fFunc oObject

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
		} "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"Get"+cKeyword,f1)

	func GetExpr nCount,cType
		cCode = " 	f1 = func nValue { 
			if isCommand() and CommandData()[:name] = :#{f1} {
				#{f3}
					CommandData()[:nExpr]++     
					CommandData()[:aExpr] + nValue
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
				cCode = SubStr(cCode,"#{f3}","if isString(nValue) {")
				cCode = SubStr(cCode,"#{f4}","}")
			case :number 
				cCode = SubStr(cCode,"#{f3}","if isNumber(nValue) {")
				cCode = SubStr(cCode,"#{f4}","}")
			# When we don't set #{f3} and #{f4} then they are comments!
			# So we don't have to type a case for :Any
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

	func SyntaxIsKeywordNumbers aPara,nCount
		PrepareNewClass(aPara)
		PrepareCommandExpr()		
		GetExprNumbers(nCount)
		AddMethod(oObject,"BraceExecute_"+cKeyword,fFunc)

	func SyntaxIsKeywordNumberNumber  aPara
		SyntaxIsKeywordNumbers(aPara,2)

	func SyntaxIsKeywordNumber  aPara
		SyntaxIsKeywordNumbers(aPara,1)
