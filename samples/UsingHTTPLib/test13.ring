load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/table"
oServer.route(:Get,"/table",:table)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func table

	oPage = New HTMLPageFunctions
	{
		divstart([ :style = styledivcenter("400px","500px") ] )
			style(styletable() + styletablerows("t01"))
			tablestart([ :id = :t01 , :style = stylewidth("100%") ])
				rowstart([]) 
					headerstart([]) text("Number") headerend()
					headerstart([]) text("square") headerend()
				rowend() 
				for x = 1 to 10
					rowstart([])
						cellstart([]) text(x) cellend()
						cellstart([]) text(x*x) cellend()
					rowend()
				next
			tableend()
		divend()
	}		
	oServer.setHTMLPage(oPage)

