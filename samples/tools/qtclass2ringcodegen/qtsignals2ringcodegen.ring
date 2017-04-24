# Application  : QtSignals2RingCodeGen
# Usage        : convert Qt Signals prototypes to Ring Code Generator Lists and Methods prototype!
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>
# Date          : 2016.09.25

# To use this program, open the class documentation in Qt
# Replace <signals> with the signals prototypes
# Click "Convert" button.

Load "guilib.ring"

New qApp
{
	win1 = new qWidget() {

		setWindowTitle("Convert Qt Signals Prototypes to Ring Code Generator Lists and Methods prototype")
		layout1 = new qhboxlayout() {
			lbl1 = new qlabel(win1)  { settext("Input") }
			lbl2 = new qlabel(win1) { settext("Output") }
			addwidget(lbl1)
			addwidget(lbl2)
	                }
  
	          layout2 = new qhboxlayout() {
                        textedit1 = new qtextedit(win1) {
			setAcceptRichText(false) 
			settext("<signals>") 
			setstylesheet("font-size:18pt")
		}
                        textedit2 = new qtextedit(win1) {setAcceptRichText(false) setstylesheet("font-size:10pt") }
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

Func pProcess aList

	/* Output Example :
				[ 	:signal = "collapsed(QModelIndex)" ,
					:slot = "collapsedSlot()" ,
					:event = "collapsed"
				] ,
	*/

	cEvent =  "void set<name>Event(const char *)"
	cEvents = ""

	for x=1 to len(aList)
		cLine = aList[x]
		cLine = trim(cLine)
		cLine = substr(cLine,char(9)," ")
		cLine = substr(cLine,substr(cLine," ")+1)
		nPos = substr(cLine,"(")
		cName = left(cLine,nPos-1)
		cOutput = '
					[ 	:signal = "<prototype>" ,
						:slot = "<name>Slot()" ,
						:event = "<name>"
					]'
		if not x=len(aList) cOutput += "," ok
		cOutput = substr(cOutput,"<prototype>",cLine)
		cOutput = substr(cOutput,"<name>",cName)
  	        	textedit2.setText(textedit2.toPlainText() + cOutput)
		cEvents += substr(cEvent,"<name>",cName) + nl
	next
	textedit2.setText(textedit2.toPlainText() + nl + nl + nl + cEvents)




