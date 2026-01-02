load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	SyntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
		}
	])
	SyntaxIsCommand([
		:Command = "I want button", 
		:Function = func {
			?  "Command: I want button" 
		}
	])
	endCache()
}

MyLang = New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	SetPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new MyLanguage {
 	I want window	
	I want button
}
