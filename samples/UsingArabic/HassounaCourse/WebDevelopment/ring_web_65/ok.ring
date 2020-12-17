#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "ok"
	title = "Messages"

	func start()
		
		cTemp = getPage( "templates/ok.html" , self )
		new hassounaPage{

			html(cTemp)

		}


