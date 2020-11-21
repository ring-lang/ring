#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "coffee"
	title = "Coffee"

	func start()
		
		cTemp = getPage( "templates/coffee.html" , self )
		new hassounaPage{

			html(cTemp)

		}


