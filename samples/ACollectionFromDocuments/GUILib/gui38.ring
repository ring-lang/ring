Load "guilib.ring"

new qApp {

        win1 = new qWidget()
        {

                label1 = new qLabel(win1)
                {
                        setText("Welcome")
                        setgeometry(10,10,200,50)
                        setstylesheet("color: purple ; font-size: 30pt;")
                }

                new qTimer(win1)
                {
                        setInterVal(10)
                        setTimeOutEvent("pMove()")
                        start()
                }

                setWindowTitle("Movable Label")
                setgeometry(100,100,600,80)
                setStyleSheet("background-color: white;")
                show()

        }

        exec()
}

Func pMove
        label1
        {
                move(x()+1,y())
                if x() > 600
                        move(10,y())
                ok
        }
