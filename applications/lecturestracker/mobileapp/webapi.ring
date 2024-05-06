/*
**
** Functions to call a Web Service 
**
*/

aManager = []

func useWebAPI cURL, cFunc 

	request = prepareRequest(cURL)
	aManager + 0
	nSize = len(aManager)
	aManager[nSize] = new QNetworkAccessManager(w) 
	{
		setfinishedevent(cFunc + "("+nSize+")")
		getvalue(request)
	}

func prepareRequest cURL 

	oUrl = new QUrl(cURL)
	request = new QNetworkRequest(oUrl)
	request.setrawheader(   new QByteArray().append("User-Agent"), 
				new QByteArray().append("Application")   )
	return request 

func getRequestData oManager 

	reply = new QNetworkReply {  pObject = oManager.getEventParameters()[1] }
	return reply.readall().data()

func getAPIData nManagerID

	return getRequestData(aManager[nManagerID])
