load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
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
	SetPackageName("MyLanguage.Natural")
	SetLanguageName(:MyLanguage)
	loadCommand(:MyDSL)
}

new MyLanguage {

	// Execute (I want window) and (I want window now) commands 
 	I want window Now
 
}
