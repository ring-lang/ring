// ================================================================================
/*
 * Helper Function to ensure the TABLE exists
 */
func createdbtable()
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
		 * Query ensures the history db file is created if not exists
		 */
		execute(sqlbuilder.createdbtable())
		/*
		 * Close the Stream
		 */
		close()
	}
/*
 * Helper function to build the json REQUEST
 */
func fbuildlongurljsonrequest(longurl)
	json = trimall('{"' + apirequestparams[:longurlrequest] + '":"' + longurl +  '"}')
	return json
// ================================================================================
/*
 * Save a History Item into our Database
 */
func fsavehistoryitem(shorturl, longurl)
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
		 * Get the count of items in file
		 */
		count = execute(sqlbuilder.gethistorycount())
		index = 1
		if not isnull(count)
			for x in count 
				index = number(x["COUNT(*)"]) + 1
			next
		ok
		/*
		* INSERT our new item to DB Index + 1
		*/
		execute(sqlbuilder.insertshortened(index, shorturl, longurl))
		close()
	}
	/*
	 * Update the UI Table
	 */
	mymainwindow{
		table.setsortingenabled(false)
		column = 0
		row = 0
		table.insertrow(row)
		item1 = new qtablewidgetitem(shorturl)
		table.setitem(0, column, item1)
		column += 1
		item2 = new qtablewidgetitem(longurl)
		table.setitem(row, column, item2)
		table.setsortingenabled(true)
	}
// ================================================================================
/*
 * Get API Key from XML File
 */
func fgetapikey()
	/*
	 * Load the Settings file if it exists
	 */
	if fexists(filenames[:apikeyxmlfilename])
		settings = read(filenames[:apikeyxmlfilename])
		/*
		 * Setup the XML Reader and data holders
		 */
		reader = new qxmlstreamreader() 
		qbyte = new qbytearray()
		qbyte.append(settings)
		reader.adddata(qbyte)
		/*
		 * Read the settings file XML 
		 */
		while not reader.atend()
			if reader.error()
				see xml.errorstring() see nl
			ok
			/*
			 * Extract the key
			 */ 
			if reader.qualifiedname().tostring() = apixmlcontent[:keyelement]
				key = reader.readelementtext(1)
			ok
			reader.readnext()
		end
		/*
		 * Return the key, else empty str
		 */
		return key
	else
		return ""
	ok
// ================================================================================
/*
 * Get URL Shortener History from Database - Called on start
 */
func fgethistory()
	/*
	 * Ensures Table exists
	 */
	createdbtable()
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
		* Get All items in History
		*/
		ret = execute(sqlbuilder.getallhistory())
		/*
		* Close sqlite
		*/
		close()
	}
	/*
	 * Parse the Results from the Database and Create our Widget items & insert them to the table
	 */
	mymainwindow{
		row = 0 column = 0
		for i in ret
			table.insertrow(row)
			item1 = new qtablewidgetitem(i[dbcontent[:shorturlelement]])
			table.setitem(row, column, item1)
			column = 1
			item2 = new qtablewidgetitem(i[dbcontent[:longurlelement]])
			table.setitem(row, column, item2)
			column = 0
		next
	}
// ================================================================================
/*
 * TODO: Test the API ID
 */
func ftestapikey(key)
	return true
// ================================================================================
/*
 * Helper Function to print variables with nl formatting
 */
func printr(var)
	see var see nl