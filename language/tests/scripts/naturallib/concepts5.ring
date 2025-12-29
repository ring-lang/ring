load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackage("MyLanguage.Natural")
	SyntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
			// Enable executing other commands starting with the same keywords
			PassThisCommand()				
		}
	])
	SyntaxIsCommand([
		:Command = "I want window now", 
		:Function = func {
			?  "Command: I want window now" 
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

	// Execute (I want window) and (I want window now) commands 
 	I want window Now
 
}
