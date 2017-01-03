# Application  : Help2Wiki
# Usage        : convert Sphinix source code style to Wikibooks style
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

Load "guilib.ring"

New qApp
{

	win1 = new qWidget() {

		setWindowTitle("Convert SetEvent() Methods prototype to GetEvent()")
		layout1 = new qhboxlayout() {
                       lbl1 = new qlabel(win1)  { settext("Input") }
                       lbl2 = new qlabel(win1) { settext("Output") }
                       addwidget(lbl1)
                       addwidget(lbl2)
                }
  
               layout2 = new qhboxlayout() {
                        textedit1 = new qtextedit(win1)
                        textedit2 = new qtextedit(win1)
                        addwidget(textedit1)
                        addwidget(textedit2)
                }

                layout3 = new qvboxlayout() {
                        addlayout(layout1)
                        addlayout(layout2)
                        btn1 = new qpushbutton(win1) {
                                setText("convert")
                                setClickEvent("pConvert()")
                        }
                        addwidget(btn1)
                }

                setlayout(layout3)
                showMaximized()

        }
        exec()
}



func pConvert
        cStr = textedit1.toPlainText()
        aList = str2List(cStr)
        pProcess(aList)
        cStr = list2str(aList)
        textedit2.setText(cStr)

Func pProcess aList
	for cFuncPrototype in aList
		cFuncPrototype = substr(cFuncPrototype,"const char *","vvvv")
		cFuncPrototype = substr(cFuncPrototype,"void","const char *")
		cFuncPrototype = substr(cFuncPrototype,"vvvv","void")
		cFuncPrototype = substr(cFuncPrototype,"set","get")
	next

