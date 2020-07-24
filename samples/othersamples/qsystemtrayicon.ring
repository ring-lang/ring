Load "guilib.ring"

myapp = New qApp 
{
	win1 = new qWidget() 
	{
		setWindowTitle("QSystemTrayIcon Sample")
		resize(400,400)

		new QSystemTrayIcon() {

		mymenu = new QMenu(win1)  {
                                oAction = new qAction(win1) {
                                        settext("New")
                                        setenabled(false)
                                }
                                addaction(oAction)
                                oAction = new qAction(win1) {
                                        settext("Open")
                                        setcheckable(true)
                                        setchecked(true)
                                        setstatustip("open new file")
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
                                oAction = new qaction(win1)
                                oAction.settext("Exit")
                                oAction.setclickevent("myapp.quit()")
                                addaction(oAction)
                        }

		setContextMenu(myMenu)
		setIcon( new QIcon(new QPixMap("images/notepad.png") ) )
		show()

		}

		show()
	}

	exec()
}
