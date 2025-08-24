load "httplib.ring"
load "jsonlib.ring"

? "Start the server..."
oServer = new Server

? `Try: curl -X PUT -H "Content-Type: application/json" -d '{"id": 1, "name": "Updated Item"}' http://localhost:8080/items/1`
oServer.route(:Put,"/items/(\d+)",:handlePut)

? `Try: curl -X PATCH -H "Content-Type: application/json" -d '{"name": "Partially Updated Item"}' http://localhost:8080/items/2`
oServer.route(:Patch,"/items/(\d+)",:handlePatch)

? `Try: curl -X DELETE http://localhost:8080/items/3`
oServer.route(:Delete,"/items/(\d+)",:handleDelete)

? `Try: curl -v -X OPTIONS http://localhost:8080/info`
oServer.route(:Options,"/info",:handleOptions)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func handlePut
	cItemId = oServer.Match(1)
	cBody = oServer.request().body()
	? "Received PUT request for item " + cItemId + " with body: " + cBody
	oServer.setContent("Item " + cItemId + " updated successfully (PUT).", "text/plain")
	oServer.setStatus(200)

func handlePatch
	cItemId = oServer.Match(1)
	cBody = oServer.request().body()
	? "Received PATCH request for item " + cItemId + " with body: " + cBody
	oServer.setContent("Item " + cItemId + " partially updated successfully (PATCH).", "text/plain")
	oServer.setStatus(200)

func handleDelete
	cItemId = oServer.Match(1)
	? "Received DELETE request for item " + cItemId
	oServer.setContent("Item " + cItemId + " deleted successfully (DELETE).", "text/plain")
	oServer.setStatus(200)

func handleOptions
	? "Received OPTIONS request for /info"
	oServer.response().set_header("Access-Control-Allow-Methods", "GET, POST, PUT, PATCH, DELETE, OPTIONS")