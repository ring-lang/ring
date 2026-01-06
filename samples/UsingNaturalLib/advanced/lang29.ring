load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsKeyword([
		:Keyword = "hi",
		:Function = func {
			CallerSetVar(:firstmessage,"I")
		} 
	])
	syntaxIsCommand([
		:Command = "How are you", 
		:Function = func {
			aCommandMemory[:Window] = True
			CallerSetVar(:secondmessage,"Love You ")
		}
	])
	syntaxIsCommandExpression([
		:Command = "My name is", 
		:Function = func {
			CallerSetVar(:thirdmessage,Expr(1)+"!")
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

func main

	? copy("=",30)

	GUI  {
		Hi
 		How are you 
		My name is "Mahmoud" 
	}

	// The next variables are local variables 
	// i.e. we can use DSLs that access our local scope

	? firstMessage			// Defined by GUI - Hi
	? secondMessage			// Defined by GUI - How are you
	? thirdMessage			// Defined by GUI - My name is "Mahmoud"

	? copy("=",30)
					
