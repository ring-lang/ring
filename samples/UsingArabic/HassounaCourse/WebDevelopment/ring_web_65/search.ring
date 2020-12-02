#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "search"
	title = "Search"

	func start()
		
		cTemp = getPage( "templates/search.html" , self )
		new hassounaPage{

			html(cTemp)

		}


