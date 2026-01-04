load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			aCommandMemory[:IWantWindow] = :Normal
			passThisCommand()
		}
	])
	syntaxIsCommand([
		:Command = "I want window now", 
		:Function = func {
			aCommandMemory[:IWantWindow] = :Now
		}
	])
	endCache()
}

new NaturalLanguage {
	setLanguageName(:GUI)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

GUI = new GUI

addMethod(GUI, :braceNewLine, func { 
		switch aCommandMemory[:IWantWindow] {
			case :Normal 
				?  "Command: I want window" 
			case :Now
				?  "Command: I want window now" 
		} 
		aCommandMemory[:IWantWindow] = NULL
} )

GUI  {
 	I want Window	
	I want Window now
	I want window now 
	I want window
}						

