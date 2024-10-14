Load "guilib.ring"

/*

   IS442_MohammedAbdullahAlotaibi

*/

New qApp {

        win1 = new qWidget() {

                setGeometry(100,100,500,400)

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

        nbrOfItems = list1.count()
        curItemNbr = list1.currentrow()
        curValue   = list1.item(list1.currentrow()).text()

        win1.setwindowtitle( "After Select - NbrOfItems: " + nbrOfItems +
                " CurItemNbr: " + curItemNbr + " CurValue: " + curValue )

        btn1.settext( string(list1.currentrow() ) + " --- " +
                      list1.item(list1.currentrow()).text() )



func pWork2
        list1 {
                takeitem(currentrow())

                nbrOfItems = count()
                curItemNbr = currentrow()
                curValue   = item(currentrow()).text()

                win1.setwindowtitle("After Delete - NbrOfItems: " + nbrOfItems +
                        " CurItemNbr: " + curItemNbr +" CurValue: " + curValue )
        }
