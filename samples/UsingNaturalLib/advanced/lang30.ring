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
	endCache()
}

new NaturalLanguage {
	setLanguageName(:Chat)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

func main

	? copy("=",30)

	mySecret = "Ring Programming is Fun!"

	new Chat {
		I have a secret
	}

	? "Mmm...."
	? "I know your secret too"

	? yourSecret

	? copy("=",30)
					
