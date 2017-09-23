// ================================================================================
/*
 * Entry Point Function - Performs the URL shortening 
 */
func fshortenurl()
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
	 * Google API performs verification of this query string
	 * ANY error is handled at the response point.   Please see the 
	 * function handling the response for any errors in the URL 
	 * ultimately sent to Google for shortening.
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
	link = " | <a href='" + json_objectvalueshort.tostring("") + "' title='" + json_objectvaluelong.tostring("") + "' style='font-family: arial;'>" + json_objectvalueshort.tostring("") + "</a> "
	/*
	 * Append links to the textedit 
	 */
	qtextedit1.inserthtml(link)
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
	 * Write the key to XML
	 */
	xmlwrite(filenames[:apikeyxmlfilename], xmlcontent[:start], xmlcontent[:keyelement], key)
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
	 * Clear the shortened url list field as well
	 */
	mymainwindow{
		qtextedit1.clear()
		table.setrowcount(0)
		statusbar.showmessage(statusbarmessages[:done], 0)
	}
// ================================================================================
/*
 *  Writes the application settings file values
 */
func fsetloaduicontent()
	/*
	 * Handle the option change and update all UI
	 */
	if loadhistorycheckbox.ischecked() = 1
		xmlwrite(filenames[:settingsfilename], xmlcontent[:settingsstart], xmlcontent[:settingselement], "on")
		mymainwindow{
			fgethistoryui()
		}
    else
        xmlwrite(filenames[:settingsfilename], xmlcontent[:settingsstart], xmlcontent[:settingselement], "off")
        mymainwindow{
        	qtextedit1.clear()
        }
    ok