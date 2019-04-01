/*
 is442-saad mohammed alajlan 435102029
*/
Load "guilib.ring"

MyApp = New qApp {

        win1 = new qWidget() {

                setwindowtitle("Using QMenubar")
                setGeometry(100,100,400,400)

                menu1 = new qmenubar(win1) {
                        sub1 = addmenu("File")
                        sub2 = addmenu("Edit")
                        sub3 = addmenu("Help")
                        sub1 {
                                oAction = new qAction(win1) {
                                        settext("New")
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Open")
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Save")
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Save As")
                                }
                                addaction(oAction)
                                addseparator()
                                oAction = new qaction(win1) {
                                        settext("Exit")
                                        setclickevent("myapp.quit()")
                                }
                                addaction(oAction)
                        }
                        sub2 {
                                oAction = new qAction(win1) {
                                        settext("Cut")
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Copy")
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Paste")
                                }
                                addaction(oAction)
                                addseparator()
                                oAction = new qAction(win1) {
                                        settext("Select All")
                                }
                                addaction(oAction)
                        }
                        sub3 {
                                oAction = new qAction(win1) {
                                        settext("Reference")
                                }
                                addaction(oAction)
                                sub4 = addmenu("Sub Menu")
                                sub4 {
                                        oAction = new qAction(win1) {
                                                settext("Website")
                                        }
                                        addaction(oAction)
                                        oAction = new qAction(win1) {
                                                settext("Forum")
                                        }
                                        addaction(oAction)
                                        oAction = new qAction(win1) {
                                                settext("Blog")
                                        }
                                        addaction(oAction)
                                }
                                addseparator()
                                        oAction = new qAction(win1) {
                                                settext("About")
                                        }
                                        addaction(oAction)
                        }
                }
                show()
        }
        exec()
}
