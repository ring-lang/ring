Import System.Web

Func TestUpload
	New page 
	{
		boxstart()
			text( "Upload File" )
 			newline()
		boxend()
		link([ :url = website, :title = "back" ]) 	
		for x = 1 to 3 newline() next
		formupload(website)		
			hidden("page",6)
			text( "Customer Name : " )
			textbox([ :name = "custname" ]) 	
			newline() newline()		
			divstart([:style=  styleFloatLeft() + styleWidth("90px") ])
				uploadfile("file") newline() newline()
				uploadfile("file2") newline() newline()
				submit([ :value = "Send"])
			divend()		
		formend()
	}

Func TestUploadResponse
	New page 
	{
		boxstart()
			text( "Upload Result" )
			newline()
		boxend()
		link([ :url = website+"?page=5", :title = "back" ]) 			
		newline() 
		divstart([:style=  styleFloatLeft() + styleWidth("100px") ])
			text( "Name : " + aPageVars["custname"] )
		  	newline()
		divend()
		if aPageVars["file"] != char(13)
			getuploadedfile(self,"file")
		ok
		if aPageVars["file2"] != char(13)
			getuploadedfile(self,"file2")
		ok
	}	

Func getuploadedfile oObj,cFile
	# here we use object.property instead of object { } to avoid executing braceend method
	cFileName = cUploadPath + oObj.getfilename(aPageVars,cFile)
	write(cFileName,aPageVars[cFile])
	system("chmod a+x "+cFileName)
	oObj.newline() 
	oObj.text( "File "+cFileName+ " Uploaded ..." ) 
	oObj.newline()
	imageURL = cUploadFolder + oObj.getfilename(aPageVars,cFile)
	oObj.link([ :url = imageURL, :title = "Download" ]) 
	oObj.newline()
	oObj.image( [ :url = imageURL , :alt = :image  ] )
	oObj.newline()
