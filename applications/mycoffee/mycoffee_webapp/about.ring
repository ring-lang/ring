#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "about"
	title = "About"

	func start()
		
		cTemp = getPage( "templates/about.html" , self )
		new hassounaPage{

			html(cTemp)

		}


