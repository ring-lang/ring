class Server from HTTPLib_Server

	init()

	func processEvent cCode 
		if ! substr(cCode,"(")
			cCode += " ()"
		ok
		return cCode	

	func route cURL,cType,cCode
		# **Support anonymous functions - Also support normal Ring code**
		cCode = processEvent(cCode)
		switch lower(cType)
			on :Get
				return wGet(cURL,cCode)
			on :Post 
				return wPost(cURL,cCode)
			other 
				raise("Undefined type!")
		off

	func post cURL,cCode
		cCode = processEvent(cCode)
		return wPost(cURL,cCode)

	func response 
		pTempObj = new Response
		pTempObj.pObject = HTTPLib_Server_response(pObject)
		return pTempObj

	func request 
		pTempObj = new Request
		pTempObj.pObject = HTTPLib_Server_request(pObject)
		return pTempObj

	func setContent p1,p2
		return response().set_Content(p1,p2)

	func variable cPara
		if ! isString (cPara)
			raise("Bad parameter type!")
		ok
		return request().get_param_value(cPara)

class Response from HTTPLib_Response

	func setContent p1,p2
		return set_content(p1,p2)

class Request from HTTPLib_Request

class Client from HTTPLib_Client
