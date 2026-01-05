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
		:Command = "Window title", 
		:Function = func {
			?  "Command: Window Title" 
			passThisCommand()
			commandReturn(aCommandMemory[:windowtitle])
		}
	])

	syntaxIsCommandExpression([
		:Command = "Window title is", 
		:Function = func {
			if ! aCommandMemory[:window] {
				? "Please create the window first!"
				return 
			}
			?  "Command: Window title is " + Expr(1)
			aCommandMemory[:windowtitle] = Expr(1) 
		}
	])

	endCache()
}

mylang = new NaturalLanguage {
	setLanguageName(:GUI)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

GUI = new GUI

GUI  {
 	I Want Window	
	window title is "welcome" 
	? "========"
	Window title is "Hello, World!"
	? "========"
	window title
	window title
	window title
	window title
	window title
	? "========"
}

? copy("*",20)
mylang.runstring(`I want window and the window title is "Welcome" `)
? mylang.runstring("window title")
					
