// ================================================================================
/*
 * Wraps the XML Write functions 
 */
func xmlwrite(filename, start, element, value)
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
		writestartdocument(xmlcontent[:version])
		writestartelement(xmlcontent[:namespace], start)
		writetextelement_2(element, value)
		writeendelement()
		writeenddocument()
	}
	/*
	 * Write the XMLStreamBuffer to file
	 */
	write(filename, qbyte.data())
// ================================================================================
/*
 * Wraps the XML Open Facilities returns contents
 */
 func xmlopenread(filename, element)
 	/*
	 * Load the Settings file if it exists
	 */
	if fexists(filename)
		settings = read(filename)
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
			 * Extract the value
			 */ 
			if reader.qualifiedname().tostring() = element
				value = reader.readelementtext(1)
			ok
			reader.readnext()
		end
		/*
		 * Return else empty str
		 */
		return value
	else
		return ""
	ok
// ================================================================================