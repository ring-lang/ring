/*
        IS442 - AbdullahKhaled
*/
Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setwindowtitle("Using QToolbar")
                setGeometry(100,100,600,400)

                abtns = [
                                new qpushbutton(win1) { settext("Add") } ,
                                new qpushbutton(win1) { settext("Edit") } ,
                                new qpushbutton(win1) { settext("Find") } ,
                                new qpushbutton(win1) { settext("Delete") } ,
                                new qpushbutton(win1) { settext("Exit")
                                                        setclickevent("win1.close()") }
                        ]

                tool1 = new qtoolbar(win1) {
                        for x in abtns addwidget(x) addseparator() next
                        setmovable(true)
                        setGeometry(0,0,500,30)
                        setFloatable(true)
                }

                show()
        }

        exec()
}
