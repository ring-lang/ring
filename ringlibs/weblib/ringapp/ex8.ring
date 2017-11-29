#!ring -cgi

Load "weblib.ring"
Import System.Web
New page 
{
	boxstart()
		text( "Upload File" )
		newline()
	boxend()
	for x = 1 to 3 newline() next
	formupload("ex9.ring")		
		text( "Customer Name : " )
		textbox([ :name = "custname" ]) 	
		newline() newline()		
		divstart([ :style = styleFloatLeft() + styleWidth("90px") ])
			uploadfile("file")  newline() newline()
			uploadfile("file2") newline() newline()
			submit([ :value = "Send" ])
		divend()		
	formend()
}

