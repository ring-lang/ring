load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsCommand([
		:Command = "I have a secret", 
		:Function = func {
			? "Your secret is: " 
			? callerGetVar(:mysecret)
			? copy("*",30)
			callerSetVar(:yoursecret,"The Natural Library is GREAT!")
		}
	])
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

MyLang = new NaturalLanguage {
	setLanguageName(:Chat)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
	setMaskOperators(False)				// So we can use ? and = operators 
}

func main

	MyLang.@(`

		? copy("=",30)

		mySecret = "Ring Programming is Fun!"

		I have a secret
	
		? "Mmm...."
		? "I know your secret too"

		? yourSecret

		? copy("=",30)
					
	`)

	test()
	test2()

func test

	? copy("=",30)

	mySecret = "Ring Programming is Fun!"

	new Chat {
		I have a secret
	}

	? "Mmm...."
	? "I know your secret too"

	? yourSecret

	? copy("=",30)
				
func test2

	GUI = new Chat

	? copy("=",30)

	GUI  {

 		I Want Window and the window title is "Welcome" 
		? "The window title is: " + windowTitle

	}

	? copy("=",30)
					
