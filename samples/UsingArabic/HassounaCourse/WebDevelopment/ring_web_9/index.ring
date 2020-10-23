#!ring -cgi
load "weblib.ring"
import system.web

/*
my = new my_site
my.start()
*/
new my_site{ start() }

class my_site
	name = "Adel"
	numbers = [77, 33, 99]
	is_active = False
	func start()
		cTemp = template("index.html", self)
		new page{
			title = "Home Page"
			html(cTemp)
		}
