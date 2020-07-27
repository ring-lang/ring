#!ring -cgi

Load "weblib.ring"
Import System.Web

cUploadPath = exefolder() + "../libraries/weblib/ringapp/upload/"
cUploadFolder = "/upload/"

New page 
{
	boxstart()
		text( "Upload Result" )
		newline()
	boxend()			
	newline() 
	divstart([ :style=  styleFloatLeft() + styleWidth("100px") ])
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
	imageURL = cUploadFolder+oObj.getfilename(aPageVars,cFile)
	oObj.link([ :url = imageURL, :title = "Download" ]) 
	oObj.newline()
	oObj.image( [ :url = imageURL , :alt = :image  ] )
	oObj.newline()
