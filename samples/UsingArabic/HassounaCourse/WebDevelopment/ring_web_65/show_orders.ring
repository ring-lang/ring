#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "show_orders"
	title = "Show Orders"
	orders = []
	
	if aPageVars['is_login']
		orders = get_orders(aPageVars['cookie_login_user'])
	ok

	func start()
		
		cTemp = getPage( "templates/show_orders.html" , self )
		new hassounaPage{

			html(cTemp)

			if not is_login()
				redirect("index.ring")
			ok


		}


