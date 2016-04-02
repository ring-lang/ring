Load "guilib.ring"

lPress = false
nX = 0
nY = 0

new qApp {

        win1 = new qWidget()
        {

                setWindowTitle("Move this label!")
                setGeometry(100,100,400,400)
                setstylesheet("background-color:white;")

                Label1 = new qLabel(Win1){
                        setGeometry(100,100,200,50)
                        setText("Welcome")
                        setstylesheet("font-size: 30pt")
                        myfilter = new qallevents(label1)
                        myfilter.setEnterevent("pEnter()")
                        myfilter.setLeaveevent("pLeave()")
                        myfilter.setMouseButtonPressEvent("pPress()")
                        myfilter.setMouseButtonReleaseEvent("pRelease()")                                                               myfilter.setMouseMoveEvent("pMove()")
                        installeventfilter(myfilter)
                }

                show()
        }

        exec()
}

Func pEnter
        Label1.setStyleSheet("background-color: purple; color:white;font-size: 30pt;")

Func pLeave
        Label1.setStyleSheet("background-color: white; color:black;font-size: 30pt;")

Func pPress
        lPress = True
        nX = myfilter.getglobalx()
        ny = myfilter.getglobaly()

Func pRelease
        lPress = False
        pEnter()

Func pMove
        nX2 = myfilter.getglobalx()
        ny2 = myfilter.getglobaly()
        ndiffx = nX2 - nX
        ndiffy = nY2 - nY
        if lPress
                Label1 {
                        move(x()+ndiffx,y()+ndiffy)
                        setStyleSheet("background-color: Green;
                                 color:white;font-size: 30pt;")
                        nX = nX2
                        ny = nY2
                }

        ok
