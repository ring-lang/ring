#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "show_orders"
	title = "Show Orders"

	func start()
		
		cTemp = getPage( "templates/show_orders.html" , self )
		new hassounaPage{

			html(cTemp)

		}


