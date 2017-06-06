# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

DefineNaturalCommand = new NaturalCommand

class NaturalCommand

	/*
		The next Method will create a similar class during the Runtime 

		Package MyLanguage.Natural
		class Hello
			func AddAttributes_Hello	
				AddAttribute(self,:hello)
			func GetHello   
				See  "Hello, Sire!" + nl + nl
	*/

	func SyntaxIsKeyword  aPara

		cPackage = aPara[:Package]
		cKeyword = aPara[:Keyword]
		fFunc = aPara[:Function]

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
