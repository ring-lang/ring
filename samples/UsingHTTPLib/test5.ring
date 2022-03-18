load "httplib.ring"

? "Try localhost:8080/hi - See output in console at Server-Side"
? "Try localhost:8080/hello - See output in web browser at Client-Side"

oServer = new Server {

	route("/hi",:Get,'? "Wow, I love Ring programming!"')
	route("/hello",:Get,'oServer.setContent("Hello, World!", "text/plain")')

	listen("0.0.0.0", 8080)

}
