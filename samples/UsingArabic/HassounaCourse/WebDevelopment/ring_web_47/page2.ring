#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	func start()

		new hassounaPage{
			title = "Page 2"
			html('<h1>Page 2</h1>')


		}
