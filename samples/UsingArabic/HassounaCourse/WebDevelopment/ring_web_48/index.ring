#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	func start()

		cTempTop    = template("base/top.html", self)
		cTempNav    = template("base/nav.html", self)

		cTempIndex  = template("index.html", self)

		cTempFooter = template("base/footer.html", self)
		cTempBottom = template("base/bottom.html", self)

		new hassounaPage{

			html( cTempTop )
			html( cTempNav )

			html( cTempIndex )
			
			html( cTempFooter )
			html( cTempBottom )


		}


