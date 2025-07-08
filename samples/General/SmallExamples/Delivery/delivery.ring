load "stdlibcore.ring"
load "lightguilib.ring"

import System.GUI

aList    = ["Tea", "Coffee", "Sandwich"]
filename = "delivery.txt"

new App {

    win = new Window() {

        setWindowTitle("Delivery")
        setFixedSize(730, 530)

        label1 = new Label(win) {
            setGeometry(15, 10, 700, 120)
            setStyleSheet("background-color: white; font-size:14pt;")
            setText("What do you want ?")
            setalignment(Qt_AlignHCenter | Qt_AlignVCenter )
        }

        label2 = new Label(win) {
            setGeometry(15, 140, 60, 30)
            setText("Item :")
        }

        text1 = new LineEdit(win) {
            setGeometry(80, 140, 500, 30)
            setTextChangedEvent("onTextChanged()")
        }

        listbox = new ListWidget(win) {
            setGeometry(15, 180, 700, 250)
            addList(aList)
            setCurrentRow(1, QItemSelectionModel_SelectCurrent)
        }

        btn1 = new PushButton(win) {
            setGeometry(240, 450, 100, 30)
            setText("Ok")
            setStyleSheet("background-color: white")
            setClickEvent("onOkClick()")
        }

        btnClose = new PushButton(win) {
            setGeometry(360, 450, 100, 30)
            setText("Close")
            setStyleSheet("color: white; background-color: red")
            setClickEvent("onCloseClick()")
        }

        show()
    }

    exec()
}

func onOkClick

    cStr = "Delivery Application"+nl
    cStr += "-------------------------------------------------------------------"+nl
    cStr += "Date  :) " + date() + nl
    cStr += "Time  :) " + time() + nl
    cStr += "Month :) " + timeinfo(:month_long) + nl
    cStr += "Day   :) " + timeinfo(:day_long) + nl
    cStr += "Item  :---------------> " + aList[listbox.currentRow()] + nl
    cStr += "-------------------------------------------------------------------"+nl

    write(filename,cStr)
    system("notepad " + filename)  

func onTextChanged 

    cStr = lower(text1.text())
    for x=1 to len(aList)
	cItem = lower(aList[x])
        if subStr(cItem, cStr)
            listbox.setCurrentRow(x,QItemSelectionModel_SelectCurrent)
            return
        ok
    next

func onCloseClick

    win.close()