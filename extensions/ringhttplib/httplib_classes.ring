class Server from HTTPLib_Server

	init()

	func processEvent cCode 
		if ! substr(cCode,"(")
			cCode += " ()"
		ok
		return cCode	

	func route cType,cURL,cCode
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

	func setHTMLPage oPage
		setContent(oPage.Output(),"text/html")

	func variable cPara
		if ! isString (cPara)
			raise("Bad parameter type!")
		ok
		if request().has_param(cPara)
			return request().get_param_value(cPara)
		but request().has_file(cPara)
			return getFileContent(cPara)
		ok

	func operator cOperator, cValue
		if cOperator = "[]"
			return Variable(cValue)
		ok

	func shareFolder cFolder 
		set_mount_point("/"+cFolder, "./"+cFolder);

	func setCookie cStr 
		response().set_header("Set-Cookie",cStr)

	func cookies 
		aOutput = [] 	 
		if ! request().has_header("Cookie")
			return aOutput
		ok
		cStr = request().get_header_value("Cookie")
		if cStr = "NULL" return aOutput 	OK 
		# var1=value; var2=value; var3=value
		cStr += ";"
		nPos = substr(cStr,";")
		While nPos > 0
			nPos2 = substr(cStr,"=") 
			if nPos2 = 0 exit ok
			aRes = []
			aRes + trim(left(cStr,nPos2-1))
			aRes + substr(cStr,nPos2+1,nPos-nPos2-1)
			aOutput + aRes 
			cStr = substr(cStr,nPos+1)
			nPos = substr(cStr,";")
		end
		return aOutput

	func getFileContent cFile
		if request().has_file(cFile)
			return request().get_multipartformdata_content2( request().get_file_value(cFile) )
		ok

	func getFileName cFile
		if request().has_file(cFile)
			return get_multipartformdata_filename( request().get_file_value(cFile) )
		ok

	func match nIndex
		return request().matches(nIndex)

class Response from HTTPLib_Response

	func setContent p1,p2
		return set_content(p1,p2)

class Request from HTTPLib_Request

class Client from HTTPLib_Client
