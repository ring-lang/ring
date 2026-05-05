$Server = new Server  { host = "http://0.0.0.0" port = 3000 }

// We don't need to use new to create the object because it's already created
$Server {

	// We access host and port attributes from our anonymous function

	@get( "/", func {
		? "Server running on " + host + ":" + port
	})

}	// This will call braceEnd() method

class Server

	host port
	
	myfunc       = NULL
	lRunBraceEnd = True
 
	func @get cURL,fFunc

		// myfunc will be another anonymous function that call our anonymous function as method 
		// Since myfunc is a string (contains the function name)
		// It's easy to pass it to C functions and call it from C libraries 
		// I.e. we created a wrapper so our original anonymous function act as a $Server method 
		// This avoid passing the object to the function or using $server.host to access the host attribute 

		myfunc = Eval( `return func {
			vFunc = "`+fFunc+`" 
			$Server { call { vFunc() } }
			}
		`)

	func braceEnd

		// braceEnd could be a trap if we are not careful
		// because we call myfunc() which access $Server using braces which call braceEnd() again
		// To avoid the infinite loop we use the lRunBraceEnd attribute

		if myfunc 
			if lRunBraceEnd = True
				lRunBraceEnd = False
				call myfunc() 
				lRunBraceEnd = True
			ok
		ok
