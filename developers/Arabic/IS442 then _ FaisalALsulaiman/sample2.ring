/*
IS442-FAISAL ALSULAIMAN
*/
Load "guilib.ring"

New qApp {

        win1 = new qWidget() {

                setGeometry(100,100,400,400)

                list1 = new qlistwidget(win1) {
                        setGeometry(150,100,200,200)
                        alist = ["one","two","three","four","five"]
                        for x in alist additem(x) next
                        setcurrentrow(3,2)
                        win1.setwindowtitle("Items Count : " + count() )
                }

                btn1 = new qpushbutton(win1) {
                        setGeometry(10,200,100,30)
                        settext("selected item")
                        setclickevent("pWork()")
                }

                btn2 = new qpushbutton(win1) {
                        setGeometry(10,240,100,30)
                        settext("Delete item")
                        setclickevent("pWork2()")
                }

                show()
        }

        exec()
}

func pWork
        btn1.settext(string(list1.currentrow()))

func pWork2
        list1 {
               takeitem(currentrow())
        }
