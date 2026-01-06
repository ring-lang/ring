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
	setTreatIdentifierAsString(False)	// Don't convert new Indentifiers to a String 
}

Try
GUI {

 	I 
	Want 
	Window	

	I want nothing		// Produce error (Using uninitialized variable: nothing)

	I want 
	Button

}						
Catch
	? "Pass NaturalLib Error when using I want nothing"
Done