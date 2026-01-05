load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
			// Enable executing other commands starting with the same keywords
			PassThisCommand()				
		}
	])
	syntaxIsCommand([
		:Command = "I want window now", 
		:Function = func {
			?  "Command: I want window now" 
		}
	])
	endCache()
}

MyLang = new NaturalLanguage {
	setLanguageName(:MyLanguage)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new MyLanguage {

	// Execute (I want window) and (I want window now) commands 
 	I want window Now
 
}
