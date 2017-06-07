# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

DefineNaturalCommand = new NaturalCommand

class NaturalCommand

	cPackage cKeyword  fFunc

	func Para2Attributes aPara
		cPackage = aPara[:Package]
		cKeyword = aPara[:Keyword]
		fFunc = aPara[:Function]

	func SyntaxIsKeyword  aPara

		Para2Attributes(aPara)

		cCode = "
			oObject = new #{f1}.#{f2}
			Package #{f1}
			Class #{f2}
		"
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cKeyword)
		eval(cCode)

		cCode = " 	f1 = func { AddAttribute(self,:#{f1}) } "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"AddAttributes_"+cKeyword,f1)
		AddMethod(oobject,"Get"+cKeyword,fFunc)

	func SyntaxIsKeywordNumberNumber  aPara

		Para2Attributes(aPara)

		cCode = "
			oObject = new #{f1}.#{f2}
			Package #{f1}
			Class #{f2}
		"
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cKeyword)
		eval(cCode)

		cCode = " 	f1 = func { AddAttribute(self,:#{f1}) } "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"AddAttributes_"+cKeyword,f1)

		cCode = " 	f1 = func { 
			StartCommand()
			CommandData()[:name] = :#{f1}
			CommandData()[:nExpr] = 0
			CommandData()[:aExpr] = []
		} "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"Get"+cKeyword,f1)
		
		cCode = " 	f1 = func nValue { 
			if isCommand() and CommandData()[:name] = :#{f1} {
				if isNumber(nValue) {
					CommandData()[:nExpr]++     
					CommandData()[:aExpr] + nValue
					if CommandData()[:nExpr] = 2 {
						BraceExecute_#{f1}()
					}
				}
			}
		} "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"BraceExprEval_"+cKeyword,f1)

		AddMethod(oobject,"BraceExecute_"+cKeyword,fFunc)


	func SyntaxIsKeywordNumber  aPara

		Para2Attributes(aPara)

		cCode = "
			oObject = new #{f1}.#{f2}
			Package #{f1}
			Class #{f2}
		"
		cCode = substr(cCode,"#{f1}",cPackage)
		cCode = substr(cCode,"#{f2}",cKeyword)
		eval(cCode)

		cCode = " 	f1 = func { AddAttribute(self,:#{f1}) } "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"AddAttributes_"+cKeyword,f1)

		cCode = " 	f1 = func { 
			StartCommand()
			CommandData()[:name] = :#{f1}
			CommandData()[:nExpr] = 0
			CommandData()[:aExpr] = []
		} "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"Get"+cKeyword,f1)
		
		cCode = " 	f1 = func nValue { 
			if isCommand() and CommandData()[:name] = :#{f1} {
				if isNumber(nValue) {
					CommandData()[:nExpr]++     
					CommandData()[:aExpr] + nValue
					if CommandData()[:nExpr] = 1 {
						BraceExecute_#{f1}()
					}
				}
			}
		} "
		cCode = SubStr(cCode,"#{f1}",cKeyword)
		eval(cCode)	
		AddMethod(oObject,"BraceExprEval_"+cKeyword,f1)

		AddMethod(oobject,"BraceExecute_"+cKeyword,fFunc)


