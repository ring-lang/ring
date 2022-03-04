load "httplib.ring"

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/one"
oServer.route("/one",:one)
? "Try localhost:8080/two"
oServer.route("/two",:two)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func one
	oServer.response.setContent("one", "text/plain")

func two
	oServer.response.setContent("two", "text/plain")
