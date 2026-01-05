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
	syntaxIsCommandExpression([
		:Command = "Window backcolor is", 
		:Function = func {
			? "Command: Window backcolor is " + Expr(1) 
			? "Is Identifier: " + isIdentifier(1)
		}
	])
	endCache()
}

MyLang = new NaturalLanguage {
	setLanguageName(:MyLanguage)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new MyLanguage {
 	I want window	
	window backcolor is "white"
	window backcolor is red 
}
