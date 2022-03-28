load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/cookie"
oServer.route(:Get,"/cookie",:cookie)
oServer.route(:Get,"/cookieresponse",:cookieresponse)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func cookie

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Cookie Test" )
 			newline()
		boxend()
		link([ :url = "/cookieresponse", :title = "Use Cookies" ]) 	
	}		

	oServer.setCookie("programminglanguage=Ring")
	oServer.setCookie("library=HTTPLib")

	oServer.setHTMLPage(oPage)

func cookieresponse

	aCookies = oServer.Cookies()

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text( "Cookies Values" )
			newline()
		boxend()
		link([ :url = "cookie", :title = "back" ]) 			
		newline() 
		divstart([:style="float:left;width:200px"])
			text( "Programming Language : " + aCookies[:programminglanguage] )
		  	newline()
		  	text( "Library : " + aCookies[:library] )
		  	newline()
		divend()
	}	
	oServer.setHTMLPage(oPage)
