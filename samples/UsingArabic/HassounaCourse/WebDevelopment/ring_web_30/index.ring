#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if isNameFound('btn1')
				html('<h1>You Clicked on Button 1</h1>')
			ok

			if isNameFound('btn2')
				html('<h1>You Clicked on Button 2</h1>')
			ok

			if isNameFound('btn3')
				html('<h1>You Clicked on Button 3</h1>')
			ok

		}
