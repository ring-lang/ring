#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "signin"
	title = "Sign In"

	func start()
		
		cTemp = getPage( "signin.html" , self )
		new hassounaPage{

			html(cTemp)

		}


