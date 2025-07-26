load "httplib.ring"
load "jsonlib.ring"

# A simple list API keys.
aValidApiKeys = [
    "secret-key-123",
    "power-user-456",
    "limited-access-789"
]

# Create the main server object
oServer = new Server {

    # Define the protected API route
    route(:Get, "/api/data", func() {

        # Authentication check
        if isAuthenticated(oServer.request())
            # Success: Client is Authenticated
            ? "Request received with valid API Key. Sending data."

            # Prepare the JSON data response
            aJsonData = [
                :status = "success",
                :messag = "Welcome, authenticated user!",
                :data = [
                    :user_id = 12345,
                    :permissions = ["read_data", "view_reports"]
				]
			]
            cJsonResponse = list2json(aJsonData)

            # Send the 200 OK response with the JSON data
            oServer.setStatus(200)
            ? "Status for '/api/data' route is: " + oServer.getStatus()
            oServer.setContent(cJsonResponse, "application/json")

        else
            # Failure: Client is Not Authenticated
            ? "Request received with missing or invalid API Key. Denying access."

            # Prepare the JSON error response
            aErrorData = [
                :error = "Unauthorized",
                :message = "A valid 'X-API-KEY' header is required to access this resource."
			]
            cErrorResponse = list2json(aErrorData)

            # Send the 401 Unauthorized response
            oServer.setStatus(401)
            ? "Status for '/api/data' route is: " + oServer.getStatus()
            oServer.setContent(cErrorResponse, "application/json")
        ok
    })

    ? "REST API Server listening at http://localhost:8080"
    ? "Try accessing the protected route '/api/data' with and without an API key."
    ? "Try: curl -H 'X-API-KEY: secret-key-123' http://localhost:8080/api/data"
    ? "Or without a key: curl -v http://localhost:8080/api/data"
    listen("0.0.0.0", 8080)
}

# Helper function to check for a valid API key in the request headers
func isAuthenticated oRequest
    # Check if the 'X-API-KEY' header is present
    if not oRequest.has_header("X-API-KEY")
        return false
    ok

    # Get the key provided by the client
    cClientKey = oRequest.get_header_value("X-API-KEY")

    # Check if the client's key exists in our list of valid keys
    if find(aValidApiKeys, cClientKey)
        return true
    else
        return false
    ok