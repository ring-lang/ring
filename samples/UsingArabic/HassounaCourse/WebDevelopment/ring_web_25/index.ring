#!ring -cgi
load "weblib.ring"
load "stdlib.ring"
import system.web

new my_site{ start() }

class my_site

	func isFound(elName)
		found = false
		for x in aPageVars
			if find(x,elName)
				found = true
				exit
			ok
		next
		return found

	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if this.isFound('btn1')
				html('<h1>You Clicked on Button 1</h1>')
			ok

			if this.isFound('btn2')
				html('<h1>You Clicked on Button 2</h1>')
			ok

			if this.isFound('btn3')
				html('<h1>You Clicked on Button 3</h1>')
			ok

		}
