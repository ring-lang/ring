#!ring -cgi
load "db.ring"
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page   = "product"
	title  = "Product"

	func start()
		
		cTemp = getPage( "templates/product.html" , self )
		new hassounaPage{


			html(cTemp)
			if not IsNameFound("pro_id")
				redirect("index.ring")
			ok

		}


