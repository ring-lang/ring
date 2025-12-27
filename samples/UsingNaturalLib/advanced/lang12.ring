load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackage("MyLanguage.Natural")
	SyntaxIsCommand([
		:Command = "I want window", 
		:Function = func {
			?  "Command: I want window" 
		}
	])
	SyntaxIsCommandExpression([
		:Command = "Window backcolor is", 
		:Function = func {
			? "Command: Window backcolor is " + Expr(1) 
			? "Is Identifier: " + isIdentifier(1)
		}
	])
	endCache()
}

MyLang = New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	SetPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new MyLanguage {
 	I want window	
	window backcolor is "white"
	window backcolor is red 
}
