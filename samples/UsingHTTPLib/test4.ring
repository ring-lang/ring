load "httplib.ring"

? "Try localhost:8080/hello"

oServer = new Server()  {

	wGet("/hello",func {
		oServer.response().set_content("Hello, World!", "text/plain")
	})

	listen("0.0.0.0", 8080)

}