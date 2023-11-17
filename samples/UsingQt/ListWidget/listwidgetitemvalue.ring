load "guilib.ring"

new QApp {

        win1 = new QWidget() {

                setGeometry(100,100,400,400)

                list1 = new Qlistwidget(win1) {
                        setGeometry(200,100,150,200)
                        alist = ["one","two","three","four","five"]
                        for x in alist additem(x) next
                        setcurrentrow(3,2)
                        win1.setwindowtitle("Items Count : " + count() )
                }

                btn1 = new QPushButton(win1) {
                        setGeometry(10,200,170,30)
                        settext("Selected item")
                        setclickevent("pGetSelectedItem()")
                }

                btn2 = new QPushButton(win1) {
                        setGeometry(10,240,170,30)
                        settext("Delete item")
                        setclickevent("pDeleteItem()")
                }

                show()
        }

        exec()
}

func pGetSelectedItem
	cButtonMessage = "Selected item"
	if list1.currentrow() >= 0
		cButtonMessage +=  ": " + list1.item(list1.currentrow()).text() 
	ok
	btn1.settext( cButtonMessage )

func pDeleteItem
        list1 {
                takeitem(currentrow())
        }
