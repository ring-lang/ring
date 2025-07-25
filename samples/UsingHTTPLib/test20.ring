load "httplib.ring"
load "jsonlib.ring"

? "Start the server..."
oServer = new Server

? `Try: curl -X POST -H "Content-Type: application/json" -d '{"name": "Ring"}' http://localhost:8080/data`
oServer.route(:Post, "/data", :process_data)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func process_data
	// Get the request object
	oRequest = oServer.request()

	// Get the raw body as a string
	cBody = oRequest.body()

	? "Received raw body: " + cBody

	// Now you can parse it (e.g., as JSON)
	aJson = json2list(cBody)
	cName = aJson["name"]

	oServer.setContent("Hello, " + cName + "!", "text/plain")