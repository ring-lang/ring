#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "index"
	title = "Home Page"

	func start()
		
		cTemp = getPage( "index.html" , self )
		new hassounaPage{

			html(cTemp)

		}


