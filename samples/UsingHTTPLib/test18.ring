load "httplib.ring"

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/numbers/<number>"
? "Example: localhost:8080/numbers/123"
oServer.route(:Get,"(/numbers/(\d+))",:mytest)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func mytest 
	cOutput = "Match(1): " + oServer.Match(1) + nl
	cOutput += "Match(2): " + oServer.Match(2) + nl
	oServer.setContent(cOutput, "text/plain")
