load "httplib.ring"

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/hi"
oServer.route(:Get,"/hi",:mytest)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func mytest 
	oServer.setContent("Hello World!", "text/plain")
