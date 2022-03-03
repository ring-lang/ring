load "httplib.ring"

? "Start the server..."
oServer = new Server() 

? "Define /hi"
oServer.wGet("/hi",:mytest)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

? "End of program!"

func mytest 
	oServer.response().set_content("Hello World!", "text/plain")
