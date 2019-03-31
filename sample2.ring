/*
IS-422 - AbdulazizAli
*/
Load "guilib.ring"

New qApp {

        win1 = new qWidget() {

                setwindowtitle("Using QComboBox")
                setGeometry(100,100,400,400)

                New QComboBox(win1) {
                        setGeometry(150,100,200,30)
                        alist = ["one","two","three","four","five"]
                        for x in aList additem(x,0) next
                }

                show()
        }

        exec()
}
