load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand.syntaxIsCommand([
	:Package = "MyLanguage.Natural",
	:Command = "i want window", 
	:Function = func {
		?  "Command: I want window"
	}
])

MyLang = new NaturalLanguage {
	setLanguageName(:MyLanguage)
	setPackageName("MyLanguage.Natural")
	loadCommand("i want window")
}

? copy("=",30)

GUI = new MyLanguage 

GUI {
	for t=1 to 3
		i want window	
	next
}

? copy("=",30)

MyLang.runString(' I want window ')

MyLang.execute(' I want window ')

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
