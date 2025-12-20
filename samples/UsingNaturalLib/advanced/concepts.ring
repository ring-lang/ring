load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand.SyntaxIsCommand([
	:Package = "MyLanguage.Natural",
	:Command = "i want window", 
	:Function = func {
		?  "Command: I want window"
	}
])

MyLang = New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	SetPackageName("MyLanguage.Natural")
	loadCommand("i want window")
}

? copy("=",30)

GUI = new MyLanguage 

GUI {
	i want window	
}

? copy("=",30)

MyLang.RunString(' I want window ')

MyLang.Execute(' I want window ')

? copy("=",30)

MyLang {

	setBeforeRun(`ChangeRingKeyword to 	towards`+nl)
	setAfterRun(`ChangeRingKeyword towards	to`+nl)
}

MyLang.execute(`
	for t=1 towards 5
		i want window
	next
`)

? copy("=",30)

MyLang {
	setBeforeRun("")		// Disable Before Run
	setAfterRun("")			// Disable After  Run
	setStartKeywordsWith("@")
	setMaskOperators(False) 
}

MyLang.execute('

	@for t=1 @to 3
 		i want window
	@next

')

? copy("=",30)
