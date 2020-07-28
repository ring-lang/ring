load "guilib.ring"

new QSqlDatabase(){
	conn = addDatabase("QSQLITE"){
		setDatabaseName("mynotes.db")
		Open()
	}
}


new QSqlQuery(){
	exec("create table notes ( note varchar(255) unique );")
	delete()
}

MyApp = new qApp{
	win = new qWidget() {
		setWindowTitle("My Notes")
		resize(600,600)
		fnt = new qFont( win.font().family() , 14 , 10 , 0 )
		setFont(fnt)
		layout1 = new qhboxLayout() {
			label1 = new qLabel(win){setText("Note: ")}
			txtNote = new qlineedit(win)
			addwidget(label1)
			addwidget(txtNote)
		}
		layout2 = new qhboxLayout() {
			btnAdd = new qpushbutton(win){
				setText("Add")
				setClickEvent( "addnote()" )
			}
			addwidget(btnAdd)
		}
		layout3 = new qhboxLayout() {
			mylist = new qListwidget(win)
			addwidget(mylist)
		}
		layoutMain = new qvboxLayout() {
			addLayout(layout1)
			addLayout(layout2)
			addLayout(layout3)
		}
		setLayout(layoutMain)
		show()
	}
	fillnotes()
	exec()
}

func addnote()
	new QSqlQuery(){
		strNote = txtNote.Text()
		exec("insert into notes values( '" + strNote + "' );")
		delete()
	}
	fillnotes()
	txtNote.setText("")
	txtNote.setFocus(1)


func fillnotes()
	query = new QSqlQuery(){
		exec("select * from notes;")
		myList.Clear()
		while movenext()
			mylist.addItem( query.value(0).toString() )
		end
		delete()
	}

