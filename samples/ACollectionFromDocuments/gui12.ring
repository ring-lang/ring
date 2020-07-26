Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setwindowtitle("Using QTabWidget")
                setGeometry(100,100,400,400)

                page1 = new qwidget() {
                        new qpushbutton(page1) {
                                settext("The First Page")
                        }
                }

                page2 = new qwidget() {
                        new qpushbutton(page2) {
                                settext("The Second Page")
                        }
                }

                page3 = new qwidget() {
                        new qpushbutton(page3) {
                                settext("The Third Page")
                        }
                }

                tab1 = new qtabwidget(win1) {
                        inserttab(0,page1,"Page 1")
                        inserttab(1,page2,"Page 2")
                        inserttab(2,page3,"Page 3")
                        setGeometry(100,100,400,400)
                }

                status1 = new qstatusbar(win1) {
                        showmessage("Ready!",0)
                }

                setstatusbar(status1)
                showMaximized()
        }

        exec()
}
