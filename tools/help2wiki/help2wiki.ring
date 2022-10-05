# Application  : Help2Wiki
# Usage        : convert Sphinx source code style to Wikibooks style
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

Load "guilib.ring"

New qApp
{

	win1 = new qWidget() {

		setWindowTitle("Convert Help to Wikibooks style!")
		layout1 = new qhboxlayout() {
                       lbl1 = new qlabel(win1)  { settext("Help Source") }
                       lbl2 = new qlabel(win1) { settext("Wiki Source (output)") }
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
        aSubTitles = []
        nState = 0     # nState : 0=Normal   1=start of source code 2=source code
        nLine = 0
        for x in aList
                nLine++
                switch nState
                on 0
                        if x = ".. code-block:: none"
                                x = '<source lang="ring">'
                                nState++
                        but x = ".. code-block:: C"
                                x = '<source lang="C">'
                                nState++
                        but x = copy("=",len(x)) and len(x) > 1
                                x = ""
                                if nLine != 1
                                        if len(trim(aList[nLine-1])) != 0
                                           if left(aList[nLine-1],1) != " "
                                                aSubTitles + aList[nLine-1]    
                                                aList[nLine-1] = "==" + aList[nLine-1] + "=="
                                           ok
                                        ok
                                ok
                        but trim(x) = ".. index::"
                                x = ""
                                aList[nLine+1] = " "
                        ok                      
                on 1
                        if left(x,1) = char(9) # Tab
                                nState++
                        ok
                on 2
                        if left(x,1) != char(9)  # Not Tab
                                x = "</source>"
                                insert(aList,nLine,"")
                                nState=0
                        ok
                off
        next
        if nState = 2
                aList + "</source>"
        ok
        aList + "{{Subjects|Ring programming language}}"
        aList + nl
        aList + "**** End of Text ****"
        aList + nl
        aList + "The next links to be used in the Table of contents"
        if len(aSubTitles) < 2 return ok
        cFirst = substr(aSubTitles[1]," ","_")  
        for t=2 to len(aSubTitles)
                x = aSubTitles[t]
                aList + ("*[[/Lessons/"+cFirst+"#"+substr(x," ","_")+"|"+x+"]]")
        next
