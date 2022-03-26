load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/form"
oServer.route(:Get,"/form",:form)
oServer.route(:Post,"/formresponse",:formresponse)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func form

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Post Test")
		 	newline()
		boxend()
		divstart([:style=StyleFloatLeft()+StyleWidth("100px") ])
			newline()
			text( "Number1 : " )  	newline() newline()
			text( "Number2 : " ) 	newline() newline()
		divend()
		formpost("formresponse")
			divstart([ :style = styleFloatLeft()+StyleWidth("200px") ])
				newline()
				textbox([ :name = "Number1" ]) 	newline() newline()
				textbox([ :name = "Number2" ]) 	newline() newline()
				submit([ :value = "Send" ] )
			divend()
		formend()
	}		
	oServer.setHTMLPage(oPage)

func formresponse

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Post Result" )
			newline()
		boxend()
		divstart([ :style = styleFloatLeft()+styleWidth("200px") ])
			newline()
			text( "Number1 : " + oServer["Number1"] )  	
			newline() newline()
			text( "Number2 : " + oServer["Number2"] )  	
			newline() newline()
			text( "Sum : " + (0 + oServer["Number1"] + oServer["Number2"] ) )
			newline()
		divend()		
	}	

	oServer.setHTMLPage(oPage)
