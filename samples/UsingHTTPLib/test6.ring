load "httplib.ring"

new Client("localhost:8080") {
	? download("/one")
	? download("/two")
}
