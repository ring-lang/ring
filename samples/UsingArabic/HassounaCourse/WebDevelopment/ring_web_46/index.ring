#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	func start()
		cTemp = template("index.html", self)

		new hassounaPage{
			title = "Home Page"
			html(cTemp)

		}
