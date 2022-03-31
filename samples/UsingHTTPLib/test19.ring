load "httplib.ring"

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/time"
? "Try localhost:8080/stop"
oServer.route(:Get,"/time",:gettime)
oServer.route(:Get,"/stop",:stop)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func gettime
	oServer.setContent("Time: " + time(), "text/plain")

func stop
	oServer.stop()