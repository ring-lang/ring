load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")

	syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			aCommandMemory[:Window] = True
		}
	])

	syntaxIsCommandExpression([
		:Command = "Window title is", 
		:Function = func {
			if ! aCommandMemory[:Window] {
				? "Please create the window first!"
				return 
			}
			aCommandMemory[:windowTitle] = Expr(1) 
			register(:windowTitle)
			windowTitle = aCommandMemory[:windowTitle]
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

? copy("=",30)

GUI  {

 	I Want Window and the window title is "Welcome" 
	? "The window title is: " + windowTitle

}

? copy("=",30)
					
