Load "guilib.ring"
app1 = new qapp {
        win1 = new qwidget() {
                setwindowtitle("First")
                setgeometry(100,100,500,500)

                new qpushbutton(win1) {
                        setgeometry(100,100,100,30)
                        settext("close")
                        setclickevent("app1.quit()")
                }

                new qpushbutton(win1) {
                        setgeometry(250,100,100,30)
                        settext("Second")
                        setclickevent("second()")
                }

                showmaximized()
        }
        exec()
}

func second
        win2 = new qwidget() {
                setwindowtitle("Second")
                setgeometry(100,100,500,500)
                setwindowflags(Qt_dialog)
                show()
        }
