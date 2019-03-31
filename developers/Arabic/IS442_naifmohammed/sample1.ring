/*

     IS442-naifmohammed

*/

Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setwindowtitle("QDockWidget")
                setGeometry(100,100,400,400)

                label1 = new qlabel(win1) {
                        settext("Hello")
                        setGeometry(300,300,100,100)
                }

                label2 = new qlabel(win1) {
                        settext("How are you ?")
                        setGeometry(100,100,100,100)
                }

                dock1 = new qdockwidget(win1,0) {
                        setwidget(label1)
                        SetAllowedAreas(1)
                }

                dock2 = new qdockwidget(win1,0) {
                        setwidget(label2)
                        SetAllowedAreas(2)
                }

                adddockwidget(Qt_LeftDockWidgetArea,dock1,Qt_Horizontal)
                adddockwidget(Qt_LeftDockWidgetArea,dock2,Qt_Vertical)

                show()
        }
        exec()
}
