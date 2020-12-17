#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "profile"
	title = "Profile"

	func start()
		
		cTemp = getPage( "profile.html" , self )
		new hassounaPage{

			html(cTemp)

		}


