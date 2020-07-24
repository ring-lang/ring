load "guilib.ring"

new QSqlDatabase(){
	conn = addDatabase("QSQLITE"){
		setDatabaseName("mynotes.db")
		Open()
	}
}


new QSqlQuery(){
	exec("create table notes ( id integer primary key , note varchar(255) );")
	exec("insert into notes values(1,'My1');")
	exec("insert into notes values(2,'My1');")
	exec("insert into notes values(3,'My1');")
	delete()
}


query = new QSqlQuery(){
	exec("select * from notes;")
	while movenext()
		for x = 0 to 1
			str = query.value(x).toString()
			see str + TAB
		next
		see NL
	end
	delete()
}

