#!ring -cgi
load "weblib.ring"
import system.web

new my_site{ start() }

class my_site
	name = "Adel"
	numbers = [77, 33, 99, 155]
	is_active = False
	func start()
		cTemp = template("index.html", self)
		new page{
			title = "Home Page"
			html(cTemp)
		}
