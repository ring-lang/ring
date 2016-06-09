load "guilib.ring"

MyApp = new qApp
{
	win1 = new qWidget()
	{
		setWindowTitle("Weight History")
		resize(600,600)
		show()
		layoutAdd = new qhboxlayout(win1)
		{
			label1 = new qLabel(win1) { setText("Weight") }
			text1 = new qlineedit(win1) 
			btn1 = new qpushbutton(win1) { setText("Add") }
			addwidget(label1)
			addwidget(text1)
			addwidget(btn1)
		}
		layoutData  = new qhboxlayout(win1)
		{
			Table1 = new qTableWidget(win1) {
				setrowcount(0) setcolumncount(4)
				setselectionbehavior(QAbstractItemView_SelectRows)
				setHorizontalHeaderItem(0, new QTableWidgetItem("ID"))
				setHorizontalHeaderItem(1, new QTableWidgetItem("Date"))
				setHorizontalHeaderItem(2, new QTableWidgetItem("Time"))
				setHorizontalHeaderItem(3, new QTableWidgetItem("Weight"))
                		}
			addWidget(Table1)
		}
		layoutClose = new qhboxlayout(win1)
		{
			btnclose = new qpushbutton(win1) { setText("Close") setClickEvent("MyApp.Quit()") }
			addwidget(btnClose)
		}
		layoutMain = new qvboxlayout(win1)
		{
			addlayout(layoutAdd)
			addLayout(LayoutData)
			addLayout(layoutClose)
		}
		setlayout(layoutMain)
	}		
	exec()
}
