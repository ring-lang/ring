#!ring -cgi
load "hassounapgdb.ring"
load "hassounaweb.ring"
import system.web

port     = "5433"
password = "123456"
database = "my_test"

new my_site{ start() }

class my_site

	emps = []

	func get_autonum()
		return auto_num("emp","id")

	func fill_emp()
		emps = get_data( "select * from emp")

	func start()

		run( "create table if not exists emp( id integer primary key, name varchar(100), salary float);")
		cTemp = template("index.html", self)

		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if isNameFound('btnadd')
				id = substr(aPageVars['id'], "'", "")
				name = substr(aPageVars['name'], "'", "")
				salary = substr(aPageVars['salary'], "'", "")
				cInsert = "insert into emp values("+id+",'"+name+"',"+salary+");"
				run( cInsert)
				script( scriptredirection("index.ring") )
			ok

			if isNameFound('btnedit')
				id = substr(aPageVars['id'], "'", "")
				name = substr(aPageVars['name'], "'", "")
				salary = substr(aPageVars['salary'], "'", "")
				cUpdate = "update emp set name='"+name+"', salary="+salary+" where id="+id+";"
				run( cUpdate)
				script( scriptredirection("index.ring") )
			ok

			if isNameFound('btndel')
				id = substr(aPageVars['id'], "'", "")
				cDel = "delete from emp where id="+id+";"
				run( cDel)
				script( scriptredirection("index.ring") )
			ok

		}
