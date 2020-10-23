#!ring -cgi
load "hassounaweb.ring"
load "sqlitelib.ring"
import system.web

new my_site{ start() }

class my_site

	conn = sqlite_init()

	func start()
		
		sqlite_open(conn, "emp_test.db")

		cTemp = template("index.html", self)

		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if isNameFound('')
			ok

		}
