Load "guilib.ring"

new qApp {

        win1 = new qWidget()
        {
                setWindowTitle("Test using Event Filter!")
                setGeometry(100,100,400,400)
                setmousetracking(true)
                myfilter = new qallevents(win1)
                myfilter.setKeyPressEvent("pWork()")
                myfilter.setMouseButtonPressevent("pClick()")
                myfilter.setmousemoveevent("pMove()")

                installeventfilter(myfilter)

                show()
        }

        exec()
}

func pWork
        win1.setwindowtitle('KeyPress! : ' + myfilter.getkeycode())

func pClick
        new qmessagebox(win1) {
                setgeometry(100,100,400,100)
                setwindowtitle("click event!")
                settext("x : " + myfilter.getx() +
                        " y : " + myfilter.gety() + " button : " +
                         myfilter.getbutton() )
                show()
        }

func pMove
        win1.setwindowtitle("Mouse Move , X : " + myfilter.getx() +
                            " Y : " + myfilter.gety() )
