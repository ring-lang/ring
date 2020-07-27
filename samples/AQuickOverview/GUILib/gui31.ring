Load "guilib.ring"

New qapp {
        win1 = new qwidget() {
                setwindowtitle("open file")
                setgeometry(100,100,400,400)
                new qpushbutton(win1) {
                        setgeometry(10,10,200,30)
                        settext("open file")
                        setclickevent("pOpen()")
                }
                show()
        }
        exec()
}

Func pOpen
        new qfiledialog(win1) {
                cName = getopenfilename(win1,"open file","c:\","source files(*.ring)")
                win1.setwindowtitle(cName)
        }
