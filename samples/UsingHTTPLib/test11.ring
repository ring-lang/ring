load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/gradient"
oServer.route(:Get,"/gradient",:gradient)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func gradient

	oPage = New HTMLPageFunctions
	{
		boxstart()
			text("StyleGradient() Function")
		boxend()		 
		for x = 1 to 60
			divstart([ :id = x , :align = "center" , 
				   :style = stylefloatleft() + 
							stylesize(string(100/60*6)+"%","50px") + 
							stylegradient(x) ])
				h3(x)
			divend()
 		next
	}		
	oServer.setHTMLPage(oPage)

