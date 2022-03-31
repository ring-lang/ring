load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/template"
oServer.route(:Get,"/template"," new numbersController { start() } ")

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

class numbersController

	MyHeader aNumbers		

	func Start

		MyHeader = New Header
		{
			cColumn1 = "Number" cColumn2 = "Square"
		}

		aNumbers = list(20)

		for x = 1 to len(aNumbers)
			aNumbers[x] = new number
			{
				nValue  = x   nSquare = x*x
			}
		next	  

		cTemp = Template("templates/mynumbers.html",self)

		oPage = new HTMLPageFunctions
		{ 			
			boxstart()
				text( "Test Templates" )  			
				newline()
			boxend()
			html(cTemp)  
		} 

		oServer.setHTMLPage(oPage)

Class Header cColumn1 cColumn2

Class Number nValue   nSquare