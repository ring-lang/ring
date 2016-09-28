# Application  : QtClass2RingCodeGen
# Usage        : convert Qt Class Methods prototypes to Ring Code Generator Style!
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>
# Date          : 2016.09.25

# To use this program, open the class documentation in Qt
# Replace <class_name> with the class name
# Replace <enum> with enum/flags in this class
# Replace <functions> with functions prototype
# Click "Convert" button.

Load "guilib.ring"

New qApp
{
	win1 = new qWidget() {

		setWindowTitle("Convert Qt Class Methods prototypes to Ring Code Generator Style!")
		layout1 = new qhboxlayout(win1) {
			lbl1 = new qlabel(win1)  { settext("Input") }
			lbl2 = new qlabel(win1) { settext("Output") }
			addwidget(lbl1)
			addwidget(lbl2)
	                }
  
	          layout2 = new qhboxlayout(win1) {
                        textedit1 = new qtextedit(win1) {
			setAcceptRichText(false) 
			settext("class <class_name>"+nl+"<enum>"+nl+"<functions>") 
			setstylesheet("font-size:18pt")
		}
                        textedit2 = new qtextedit(win1) {setAcceptRichText(false) setstylesheet("font-size:18pt") }
                        addwidget(textedit1)
                        addwidget(textedit2)
                }

                layout3 = new qvboxlayout(win1) {
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

	cClassName = ""
	aEnum = []

	for cLine in aList
		cLine = trim(cLine)
		cLine = substr(cLine,char(9)," ")
		cLine = substr(cLine,") const",")")
		cLine = substr(cLine,"()","(void)")
		cLine = substr(cLine,"&"," ")
		cLine = substr(cLine,"const "," ")
		nPos = substr(cLine,"=")
		while nPos > 0
			cSub = substr(cLine,nPos+1)
			nPos2 = substr(cSub,",")
			if nPos2 = 0
				nPos2 = substr(cSub,")")
			ok
			cLine = left(cLine,nPos-1) + substr(cLine,nPos+nPos2)
			nPos = substr(cLine,"=")
		end
		if  left(cLine,4) = "enum"  
			cItem = trim(substr(cLine,5,substr(cLine,"{")-5))
			see cItem  + nl
			aEnum + cItem
			cLine = 'aEnumTypes + "' + cClassName + "::"+cItem+'"'
		but  left(cLine,5) = "flags" 
			cItem = trim(substr(cLine,6))
			see cItem  + nl
			aEnum + cItem
			cLine = 'aEnumTypes + "' + cClassName + "::"+cItem+'"'
		but  left(cLine,5) = "class" 
			cClassName = trim(substr(cLine,6))
			cLine = "#include <" + cClassName + ">" 
		ok
	next

	for cLine in aList
		for cEnum in aEnum
			cLine = substr(cLine,cClassName+"::"+cEnum,cEnum)
			cLine = substr(cLine,cEnum,cClassName+"::"+cEnum)
		next
	next


