/*
IS442-Mohammed Mosoud 
*/
Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setGeometry(100,100,1100,370)
                setwindowtitle("Using QTableWidget")

                Table1 = new qTableWidget(win1) {

                        setrowcount(10) setcolumncount(10)
                        setGeometry(0,0,800,400)
                        setselectionbehavior(QAbstractItemView_SelectRows)

                        for x = 1 to 10
                                for y = 1 to 10
                                        item1 = new qtablewidgetitem("R"+X+"C"+Y)
                                        setitem(x-1,y-1,item1)
                                next
                        next

                }

                setcentralwidget(table1)
                show()

        }

        exec()
}
