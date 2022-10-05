load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

cUploadFolder = "upload/"
oServer.shareFolder(cUploadFolder)

? "Try localhost:8080/upload"
oServer.route(:Get,"/upload",:upload)
oServer.route(:Post,"/uploadresponse",:uploadresponse)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func upload

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Upload File" )
			newline()
		boxend()
		for x = 1 to 3 newline() next
		formupload("/uploadresponse")		
			text( "Customer Name : " )
			textbox([ :name = "custname" ]) 	
			newline() newline()		
			divstart([ :style = styleFloatLeft() + styleWidth("90px") ])
				uploadfile("file1")  newline() newline()
				uploadfile("file2") newline() newline()
				submit([ :value = "Send" ])
			divend()		
		formend()
	}		

	oServer.setHTMLPage(oPage)

func uploadresponse

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Upload Result" )
			newline()
		boxend()			
		newline() 
		divstart([ :style=  styleFloatLeft() + styleWidth("100px") ])
			text( "Name : " + oServer["custname"] )
			newline()
		divend()
		getuploadedfile(self,"file1")
		getuploadedfile(self,"file2")
	}	

	oServer.setHTMLPage(oPage)


Func getUploadedFile oObj,cFile
	cNewFileName = oServer.getfilename(cFile)
	if cNewFileName = NULL return ok
	cNewFileContent = oServer.getFileContent(cFile)
	/*
		Here we use object.property instead of object { } 
		To avoid executing braceend() method
	*/
	cFileName = cUploadFolder + cNewFileName
	write(cFileName,cNewFileContent)
	if isLinux()
		system("chmod a+x "+cFileName)
	ok
	oObj.newline() 
	oObj.text( "File "+cFileName+ " Uploaded ..." ) 
	oObj.newline() 
	imageURL = cFileName
	oObj.link([ :url = imageURL, :title = "Download" ]) 
	oObj.newline()
	oObj.image( [ :url = imageURL , :alt = :image  ] )
	oObj.newline()
