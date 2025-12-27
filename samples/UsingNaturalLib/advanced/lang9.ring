load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand.startCache(:MyDSL)
	DefineNaturalCommand.SyntaxIsCommand([
		:Package = "MyLanguage.Natural",
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
		}
	])
	DefineNaturalCommand.SyntaxIsCommand([
		:Package = "MyLanguage.Natural",
		:Command = "I want button", 
		:Function = func {
			?  "Command: I want button" 
		}
	])
DefineNaturalCommand.endCache()

MyLang = New NaturalLanguage {

	SetLanguageName(:MyLanguage)
	SetPackageName("MyLanguage.Natural")
	
	loadCommand(:MyDSL)

}

new MyLanguage {
 	I want window	
	I want button
}
