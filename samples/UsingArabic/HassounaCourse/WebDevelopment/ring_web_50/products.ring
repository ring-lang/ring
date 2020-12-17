#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "products"
	title = "Products"

	func start()
		
		cTemp = getPage( "products.html" , self )
		new hassounaPage{

			html(cTemp)

		}


