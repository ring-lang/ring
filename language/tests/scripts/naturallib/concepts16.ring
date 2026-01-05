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

	syntaxIsCommand([
		:Command = "Window title", 
		:Function = func {
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
			aCommandMemory[:windowtitle] = Expr(1) 
		}
	])

	endCache()
}

MyLang = new NaturalLanguage {
	setLanguageName(:GUI)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

? copy("=",30)

// Using the GUI object from the GUI class 

GUI = new GUI
GUI {

 	I Want Window and the window title is "Welcome" 

	cTitle = @(`window title`)
	? "The window title is: " + cTitle
}

? GUI.@("window title")

// Using the MyLang object (from the NaturalLanguage class)

MyLang.@("I want window and the window title is 'GREAT'")
? "The window title is: " + MyLang.@("window title")

? copy("=",30)
					
