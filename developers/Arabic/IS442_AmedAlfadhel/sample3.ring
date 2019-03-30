/*
		IS442 - Ahmed Alfadhel 
*/ 

load "guilib.ring"

new qApp {
        win = new qwidget() {
                setwindowtitle("Context Menu")
                resize(400,400)
                myfilter = new qAllEvents(win) {
                        setContextmenuEvent("mymenu()")
                }
                installeventfilter(myfilter)
                show()
        }
        exec()
}


func mymenu

        new qMenu(win) {
                oAction = new qAction(win) {
                        settext("new")
                        SetCLickevent("See :New")
                }
                addaction(oAction)
                oAction = new qAction(win) {
                        settext("open")
                        SetCLickevent("See :Open")
                }
                addaction(oAction)
                oAction = new qAction(win) {
                        settext("save")
                        SetCLickevent("See :Save")
                }
                addaction(oAction)
                oAction = new qAction(win) {
                        settext("close")
                        SetCLickevent("See :Close")
                }
                addaction(oAction)
                oCursor  = new qCursor()
                exec(oCursor.pos())
        }
