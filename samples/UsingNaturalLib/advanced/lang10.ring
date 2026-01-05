load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
		}
	])
	syntaxIsCommand([
		:Command = "I want button", 
		:Function = func {
			?  "Command: I want button" 
		}
	])
	endCache()
}

MyLang = New NaturalLanguage {
	setLanguageName(:MyLanguage)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new MyLanguage {
 	I want window	
	I want button
}
