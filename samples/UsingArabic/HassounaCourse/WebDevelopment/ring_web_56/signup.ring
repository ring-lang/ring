#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "signup"
	title = "Sign Up"

	func start()
		
		cTemp = getPage( "signup.html" , self )
		new hassounaPage{

			html(cTemp)

		}


