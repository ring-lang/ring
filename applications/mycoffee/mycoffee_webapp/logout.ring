#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "logout"
	title = "Logout"

	func start()

		new hassounaPage{

			logout()
			redirect("index.ring")

		}


