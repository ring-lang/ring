#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "index"
	title = "Home Page"
	products = get_products_desc()

	func start()

		cTemp = getPage( "templates/index.html" , self )
		new hassounaPage{

			html(cTemp)

		}


