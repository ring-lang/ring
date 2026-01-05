load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand.startCache(:MyDSL)
DefineNaturalCommand.setPackageName("MyLanguage.Natural")
	DefineNaturalCommand.syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
		}
	])
	DefineNaturalCommand.syntaxIsCommand([
		:Command = "I want button", 
		:Function = func {
			?  "Command: I want button" 
		}
	])
DefineNaturalCommand.endCache()

MyLang = new NaturalLanguage {
	setLanguageName(:MyLanguage)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new MyLanguage {
 	I want window	
	I want button
}
