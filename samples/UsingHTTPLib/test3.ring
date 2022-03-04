load "httplib.ring"

? "Start the server..."
oServer = new Server 

? "Define /one"
oServer.route("/one",:one)
? "Define /two"
oServer.route("/two",:two)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

? "End of program!"

func one
	oServer.response.setContent("one", "text/plain")

func two
	oServer.response.setContent("two", "text/plain")
