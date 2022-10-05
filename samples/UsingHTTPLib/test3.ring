load "httplib.ring"

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/one"
oServer.route(:Get,"/one",:one)
? "Try localhost:8080/two"
oServer.route(:Get,"/two",:two)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func one
	oServer.setContent("one", "text/plain")

func two
	oServer.setContent("two", "text/plain")
