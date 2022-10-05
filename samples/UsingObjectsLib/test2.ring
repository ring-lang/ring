load "guilib.ring"

new qApp {
        openWindow( :MainWindowController )
        exec()
}

class MainWindowController from WindowsControllerParent
        oView = new MainWindowView
        func SubWindowAction
                openWindowAndLink( :SubWindowController,self)
		subWindow().oView.win {
			move(50,100)
			setStyleSheet("background-color:yellow;")
		}
	
class MainWindowView from WindowsViewParent
        win = new qWidget() {
                setWindowTitle("Main Window")
                resize(500,400)
                btnSub = new qPushButton(win) {
                        setText("Sub Window")
                        setClickEvent( Method( :SubWindowAction ) )
                }
        }

class SubWindowController from WindowsControllerParent
        oView = new SubWindowView
        func SetMainWindowTitleAction
                MainWindow().oView.win.SetWindowTitle(
			"Message from the Sub Window - Window ID = " + ObjectID()
		)
                oView.win.SetWindowTitle("Click Event Done!")

class SubWindowView from WindowsViewParent
        win = new qWidget() {
                setWindowTitle("Sub Window")
                resize(300,400)
                btnMsg = new qPushButton(win) {
                        setText("Set Main Window Title")
                        setClickEvent( Method( :SetMainWindowTitleAction ) )
                }
                btnClose = new qPushButton(win) {
                        Move(200,0)
                        setText("Close")
                        setClickEvent( Method( :CloseAction ) )
                }
        }