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

			sum = 0
			for x in aPageVars
				sum += Number(aPageVars[ x[1] ])
			next

			html('<h3>' + sum + '</h3>')

		}
