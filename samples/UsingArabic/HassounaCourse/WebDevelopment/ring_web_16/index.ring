#!ring -cgi
load "weblib.ring"
import system.web

new my_site{ start() }

class my_site
	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)
		}
