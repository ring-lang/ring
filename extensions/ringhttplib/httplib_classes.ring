mergemethods(:Server,:HTTPLib_Server)

class Server 

	pObject init()

	response func getresponse return response() endfunc
	request  func getrequest  return request()  endfunc

	func route p1,p2
		return wGet(p1,p2)

	func response 
		pTempObj = new Response
		pTempObj.pObject = HTTPLib_Server_response(pObject)
		return pTempObj

	func request 
		pTempObj = new Request
		pTempObj.pObject = HTTPLib_Server_request(pObject)
		return pTempObj

class Response from HTTPLib_Response

	func setContent p1,p2
		return set_content(p1,p2)

class Request from HTTPLib_Request
