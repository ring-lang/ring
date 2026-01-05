load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			aCommandMemory[:window] = True
			?  "Command: I want window" 
		}
	])
	syntaxIsCommand([
		:Command = "I want button", 
		:Function = func {
			if ! aCommandMemory[:window] {
				? "Please create the window first!"
				return 
			}
			?  "Command: I want button" 
		}
	])
	endCache()
}

new NaturalLanguage {
	setLanguageName(:GUI)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new GUI  {
 	I Want Window	
	I want Button
}						

? copy("*",25)

new GUI  {
	I want Button
}		
