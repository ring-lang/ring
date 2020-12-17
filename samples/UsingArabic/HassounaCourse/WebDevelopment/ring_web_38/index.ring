#!ring -cgi
load "hassounaweb.ring"
load "sqlitelib.ring"
import system.web

new my_site{ start() }

class my_site

	conn = sqlite_init()

	func start()
		
		sqlite_open(conn, "emp_test.db")
		sqlite_execute(conn, "create table if not exists emp( id integer primary key, name varchar(100), salary double);")
		cTemp = template("index.html", self)

		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if isNameFound('btnadd')
				id = substr(aPageVars['id'], "'", "")
				name = substr(aPageVars['name'], "'", "")
				salary = substr(aPageVars['salary'], "'", "")
				cInsert = "insert into emp values("+id+",'"+name+"',"+salary+");"
				sqlite_execute(this.conn, cInsert)
			ok

		}
