#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "cart"
	title = "Cart"

	func start()
		
		cTemp = getPage( "templates/cart.html" , self )
		new hassounaPage{

			html(cTemp)

		}


