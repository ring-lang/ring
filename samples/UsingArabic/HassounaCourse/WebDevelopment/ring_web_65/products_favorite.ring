#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "products_favorite"
	title = "Products Favorite"

	if aPageVars['is_login']
		products = get_products_favorite(aPageVars['cookie_login_user'])
	else
		products = ""
		//cOutput += "" + nl + nl+'<script>window.location=index.ring;</script>' + nl + nl
	ok

	func start()
		
		cTemp = getPage( "templates/products_favorite.html" , self )
		new hassounaPage{

			html(cTemp)

			if not is_login()
				redirect("index.ring")
			ok
		}


