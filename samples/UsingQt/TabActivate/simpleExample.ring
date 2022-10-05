Load "guilib.ring"

New qApp {

	win1 = new qMainWindow() {

		setwindowtitle("Using QTabWidget")
		setGeometry(100,100,400,400)

		page1 = new qwidget() {
			lineedit1 = new qlineedit(page1) {
				setGeometry(10,100,350,30)
			}
		}

		page2 = new qwidget() {
			lineedit2 = new qlineedit(page2) {
				setGeometry(10,100,350,30)
			}
		}


		page3 = new qwidget() {
			lineedit3 = new qlineedit(page3) {
				setGeometry(10,100,350,30)
			}
		}

		tab1 = new qtabwidget(win1) {
			inserttab(0,page1,"Page 1")
			inserttab(1,page2,"Page 2")
			inserttab(2,page3,"Page 3")
			setGeometry(100,100,400,400)
			setCurrentChangedEvent("pageChanged()")
		}

		status1 = new qstatusbar(win1) {
			showmessage("Ready!",0)
		}

		setstatusbar(status1)

		pageChanged()

		showMaximized()

	}

	exec()

}

func pageChanged
	switch tab1.currentIndex()
	on 0
		lineedit1.setText("Page (1) - Time: " + Time())
	on 1
		lineedit2.setText("Page (2) - Time: " + Time())
	on 2
		lineedit3.setText("Page (3) - Time: " + Time())
	off 