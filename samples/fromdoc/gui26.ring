Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setwindowtitle("Menubar")

                menu1 = new qmenubar(win1) {
                        sub1 = addmenu("File")
                        sub1 {
                                oAction = new qAction(win1) {
                                        settext("New")
                                        setenabled(false)
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Open")
                                        setcheckable(true)
                                        setchecked(true)
                                        setstatustip("open new file")
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Save")
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Save As")
                                }
                                addaction(oAction)

                                addseparator()
                                oAction = new qaction(win1)
                                oAction.settext("Exit")
                                oAction.setclickevent("myapp.quit()")
                                addaction(oAction)
                        }

                }
                status1 = new qstatusbar(win1) {
                        showmessage("Ready!",0)
                }
                setmenubar(menu1)
                setmousetracking(true)
                setstatusbar(status1)
                setStyleSheet("color: black; selection-color: black;
                selection-background-color:white ;
                background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #eef, stop: 1 #ccf);")
                showmaximized()
        }
        exec()
}
