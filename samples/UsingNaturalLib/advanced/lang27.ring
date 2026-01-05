load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")

	syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			aCommandMemory[:window] = True
		}
	])

	syntaxIsCommandExpression([
		:Command = "Window title is", 
		:Function = func {
			if ! aCommandMemory[:window] {
				? "Please create the window first!"
				return 
			}
			v["window title"] = Expr(1) 
		}
	])


	endCache()
}

mylang = new NaturalLanguage {
	setLanguageName(:GUI)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new GUI  {
 	I Want Window and the window title is "Welcome " + "my friend"
	? "The window title is: " + v["Window Title"]
}
					
