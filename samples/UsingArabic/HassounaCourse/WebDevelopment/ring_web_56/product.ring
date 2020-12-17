#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "product"
	title = "Product"

	func start()
		
		cTemp = getPage( "product.html" , self )
		new hassounaPage{

			html(cTemp)

		}


