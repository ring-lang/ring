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

GUI = new GUI { setPassError(False) }              // Enable errors

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
 	I want Window                                   // Uses passThisCommand()
}                                                   // No incomplete command error						

Try
GUI {
	1/0                                             // Error
}
Catch
	? "Pass error when using 1/0"
Done