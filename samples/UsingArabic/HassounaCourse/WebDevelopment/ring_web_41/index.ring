#!ring -cgi
load "hassounaweb.ring"
load "sqlitelib.ring"
import system.web

new my_site{ start() }

class my_site

	conn = sqlite_init()
	emps = []

	func get_autonum()
		autonum = sqlite_execute(conn, "select max(id)+1 as 'num' from emp")[1]['num']
		if autonum = 'NULL'
			return '1'
		else
			return autonum 
		ok

	func fill_emp()
		emps = sqlite_execute(conn, "select * from emp")

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
				script( scriptredirection("index.ring") )
			ok

		}
