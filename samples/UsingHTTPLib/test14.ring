load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/play"
oServer.route(:Get,"/play",:play)

? "We support files in the res folder like res/horse.ogg and res/movie.mp4"
oServer.shareFolder("res")

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func play

	oPage = New HTMLPage
	{
		Title = "Welcome"
		h1 { text("Play sound and video!") }
		div 
		{
			audio
			{
				src = "res/horse.ogg"
				type = "audio/ogg"
			}
	
			video
			{
				width = 320
				height = 240
				src = "res/movie.mp4"
				type = "video/mp4" 
			}
	
		}
	}		
	oServer.setHTMLPage(oPage)

