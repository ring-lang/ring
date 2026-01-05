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

// We can use runString()/execute()/$() methods to run commands 
// They does the same thing!

? copy("*",20)
mylang.runstring(`I want window and the window title is "one" `)
? mylang.runstring("window title")
? copy("*",20)				
mylang.execute(`I want window and the window title is "two" `)
? mylang.execute("window title")
? copy("*",20)				
mylang.$(`I want window and the window title is "three" `)
? mylang.$("window title")
