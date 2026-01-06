load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
		}
	])
	syntaxIsCommand([
		:Command = "I want button", 
		:Function = func {
			?  "Command: I want button" 
		}
	])
	endCache()
}

new NaturalLanguage {
	setLanguageName(:MyLanguage)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

GUI = new MyLanguage {
	setPassError(False)
}

Try
GUI {

 	I 
	Want 
	Window	

	I want 
	Button

	I want                          // Produce error at braceEnd()

}                                       // Call braceEnd() and check Errors
catch
	? "Pass NaturalLib Error"
Done