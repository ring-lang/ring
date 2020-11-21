#!ring -cgi
load "db.ring"
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "products"
	title = "Products"
	products = get_products_desc()

	func start()
		
		cTemp = getPage( "templates/products.html" , self )
		new hassounaPage{

			html(cTemp)

		}


