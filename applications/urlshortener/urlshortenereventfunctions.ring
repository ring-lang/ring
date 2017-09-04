// ================================================================================
/*
 * Entry Point Function - Performs the URL shortening 
 */
func fshortenurl()
	/*
	 * Clear the contents of Short URL 
	 */
	qtextedit1.clear()
	/*
	 * Clear the status bar
	 */
	statusbar.clearmessage()
	/*
	 * Get the URL provided in the edit field
	 */
	longurl = lower(trimall(longurledit.text()))
	/*
	 * 0 length strings return
	 */
	if len(longurl) = 0
		return 
	ok
	/*
	 * Validate URL
	 */
	 regex = new qregularexpression()
	 {
		setpattern(regularexpression[:urlregex])
		mymatch = match(longurl, 0, 0, 0) 
		if not mymatch.hasmatch()
			statusbar.showmessage(statusbarmessages[:urlwarning], 0)
		ok
	 }
	/*
	 * Create JSON request
	 */
	json = fbuildlongurljsonrequest(longurl)
	/*
	 * Set the API URL to connect to + API Key
	 */
	apiurl = api[:apiurl] + api[:keyvar] + apikeyedit.text()
	qurl = new qurl(apiurl)	
	/*
	 * Setup a  NetWorkRequest to handle our post, specifically for json request/response
	 */
	qnetrequest = new qnetworkrequest(qurl)
	qnetrequest.setrawheader(new qbytearray().append(apiheaders[:headtype]), new qbytearray().append(apiheadertypes[:json]))
	qnetrequest.setrawheader(new qbytearray().append(apiheaders[:headlen]), new qbytearray().append(string(len(json))))
	qnetrequest.setrawheader(new qbytearray().append(apiheaders[:headua]), new qbytearray().append(app[:windowtitle]))
	/*
	 * Use QNetworkManager to post and once finished, return our response to fresponse()
	 */
	qnetacessmgr.setfinishedevent(events[:fentry])
	qnetacessmgr.post(qnetrequest, new qbytearray().append(json))
// ================================================================================
/*
 * Our response function once QNetworkAccessManager is done
 */
func fresponse()
	/*
	 * Clear the status bar
	 */
	statusbar.clearmessage()
	/*
	 * Obtain our reply from QNetworkAccessManager 
	 */
	reply = new qnetworkreply {  pobject = qnetacessmgr.geteventparameters()[1] }
	/*
	 * Check for errors in the response stream
	 */
	 if not reply.error() = 0
		statusbar.showmessage(statusbarmessages[:urlerror], 0)
		return
	 ok
	/*
 	 * Get ALL the response data (in obj form)
	*/
	response = reply.readall()
	/*
	 * Parse the data via QJSON
	 */
	json_parseerror = new qjsonparseerror()
	json_document = new qjsondocument() 
	json_document = json_document.fromjson(response, json_parseerror)
	/*
	 *  TODO: Handle parse-error
	 */
	/*
	 * Get the JSON object and extract our SHORT URL
	 */
	json_object = json_document.object()
	json_keyslist = json_object.keys()
	/*
	 * Index 0 is the shortened URL, 2 is Long URL
	 */
	json_objectvalueshort = json_object.take(json_keyslist.at(0))
	json_objectvaluelong = json_object.take(json_keyslist.at(2))
	/*
 	 * Set the SHORT URL into our ui qtext edit field
	 */
	link = "<a href='" + json_objectvalueshort.tostring("") + "'>" + json_objectvalueshort.tostring("") + "</a>"
	qtextedit1.settextinteractionflags(4|8)
	qtextedit1.sethtml(link)
	/*
	 * Save to our History
	 */
	 fsavehistoryitem(json_objectvalueshort.tostring(""), json_objectvaluelong.tostring(""))
	 /*
	  * Update UI
	  */
	 statusbar.showmessage(statusbarmessages[:done], 0)
// ================================================================================
/*
 * Create an simple about Message window
 */
func fabout()
	new qmessagebox(mymainwindow){
		seticonpixmap(new qpixmap(app[:windowicon]))
		setwindowtitle(app[:windowtitle])
        settext("Author: " + app[:author] + nl + app[:authoremail] + nl + "Version: " + app[:version])
		setstandardbuttons(qmessagebox_ok)
		exec()
	}
// ================================================================================
/*
 * Function to set the API to be saved in an XML file
 */
func fsetapikey()
	/*
	 * Clear the status bar
	 */
	statusbar.clearmessage()
	/*
	 * Get the API Key from the text field
	 */
	key = trim(apikeyedit.text())
	/*
	 * Empty strings return
	 */
	 if len(key) = 0
		return
	 ok
	/*
	 * Verify the Key is valid
	 * TODO
	 */
	if ftestapikey(key) = false
		return 
	ok
	/*
	 * Setup our StreamBuffer to write the XML
	 */
	qbyte = new qbytearray()
	dobj = new qbuffer(NULL)
	dobj.setbuffer(qbyte)
	/*
	 *  Setup the stream for Write only
	 */
	dobj.open(qiodevice_writeonly)
	/*
	 *  Create the StreamWriter object and write the XML File for the key
	 */
	xmlwriter = new qxmlstreamwriter(){
		/*
		 * Set auto format
		 */
		setautoformatting(true)
		/*
		 * We pass a IO buffer to set the XMLwriter device
		 * We will use this buffer to write an xml file
		 */
		setdevice(dobj)
		/*
		 * Build the file
		 */
		writestartdocument(apixmlcontent[:version])
		writestartelement(apixmlcontent[:namespace], apixmlcontent[:start])
		writetextelement_2(apixmlcontent[:keyelement], key)
		writeendelement()
		writeenddocument()
	}
	/*
	 * Write the XMLStreamBuffer to file
	 */
	write(filenames[:apikeyxmlfilename], qbyte.data())
	/*
	 * Update UI
	 */
	mymainwindow{
		tab1.settabenabled(0, true)
		tab1.settabenabled(1, true)
		tab1.setcurrentindex(0)
		statusbar.showmessage(statusbarmessages[:done], 0)
	}
// ================================================================================
/*
 * TODO: Single Delete items
 */
func fclearhistory()
	/*
	 * Clear the status bar
	 */
	statusbar.clearmessage()
	/*
	 * Initialize SQLite class
	 */
	mysql = new mysqlite
	{
		/*
		 * Open the History File
		 */
		file = filenames[:historydbfilename]
		/*
		 * Delete all records
		 */
		execute(sqlbuilder.deleteallhistory())
		/*
		 * Close
		 */
		close()
	}
	/*
	 * Update UI - set all to 0
	 */
	mymainwindow{
		table.setrowcount(0)
		statusbar.showmessage(statusbarmessages[:done], 0)
	}
// ================================================================================