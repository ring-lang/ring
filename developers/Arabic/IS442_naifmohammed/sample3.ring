/*
 IS442-naifmohammed
*/


Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setwindowtitle("Using QRadioButton")

                new qradiobutton(win1) {
                        setGeometry(100,100,100,30)
                        settext("One")
                }
                new qradiobutton(win1) {
                        setGeometry(100,150,100,30)
                        settext("Two")
                }
                new qradiobutton(win1) {
                        setGeometry(100,200,100,30)
                        settext("Three")
                }


                group2  = new qbuttongroup(win1) {
                        btn4 = new qradiobutton(win1) {
                                setGeometry(200,150,100,30)
                                settext("Four")
                        }
                        btn5 = new qradiobutton(win1) {
                                setGeometry(200,200,100,30)
                                settext("Five")
                        }
                        addbutton(btn4,0)
                        addbutton(btn5,0)

                }

                showMaximized()

        }
        exec()
}
