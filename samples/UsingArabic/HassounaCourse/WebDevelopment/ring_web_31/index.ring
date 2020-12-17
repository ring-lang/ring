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

			if isNameFound('btnCreateCookie')
				cookie('name', 'Ahmed Amr')
				cookie('salary',850)
			ok

			if isNameFound('btnReadCookie')
				text(aPageVars['name'])
				newline()
				text(aPageVars['salary'])
			ok


		}
