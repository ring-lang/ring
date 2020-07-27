Load "guilib.ring"
see "Add Records to SQLite Database" + nl
cDir = currentdir() + "\"
oCon = new QSqlDatabase()
oCon = oCon.addDatabase("QSQLITE")
oCon.setDatabaseName("test.db")
oCon.open()
query = new QSqlQuery( )
query.exec("insert into person (id, firstname, lastname, age) values (1,'Mahmoud','Fayed',29) ") 
query.exec("insert into person (id, firstname, lastname, age) values (2,'Mohammed','Fayed',31) ") 
query.exec("insert into person (id, firstname, lastname, age) values (3,'Ahmed','Fayed',26) ") 
query.exec("insert into person (id, firstname, lastname, age) values (4,'Ibrahim','Fayed',24) ") 
see copy("*",60) + nl
See "Display records" + nl
query.exec("select * from person")

while query.movenext()
	for x = 0 to 3
	see query.value(x).tostring() + nl next
	see copy("*",60) + nl
end
	
