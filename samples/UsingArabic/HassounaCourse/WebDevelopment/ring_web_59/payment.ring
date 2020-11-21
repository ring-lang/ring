#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "payment"
	title = "Payment"

	func start()
		
		cTemp = getPage( "templates/payment.html" , self )
		new hassounaPage{

			html(cTemp)

		}


