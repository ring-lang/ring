load "guilib.ring"

new qApp {
        openWindow( :MainWindowController )
        exec()
}

class MainWindowController from WindowsControllerParent
        oView = new MainWindowView
        func SubWindowAction
                openWindow( :SubWindowController )
                lastWindow().SetParentObject(self)

class MainWindowView from WindowsViewParent
        win = new qWidget() {
                SetWindowTitle("Main Window")
                btnSub = new qPushButton(win) {
                        setText("Sub Window")
                        setClickEvent( Method( :SubWindowAction ) )
                }
                resize(400,400)
        }

class SubWindowController from WindowsControllerParent
        oView = new SubWindowView
        func SetMainWindowTitleAction
                Parent().oView.win.SetWindowTitle("Message from the Sub Window")
                oView.win.SetWindowTitle("Click Event Done!")

class SubWindowView from WindowsViewParent
        win = new qWidget() {
                SetWindowTitle("Sub Window")
                btnMsg = new qPushButton(win) {
                        setText("Set Main Window Title")
                        setClickEvent( Method( :SetMainWindowTitleAction ) )
                }
                btnClose = new qPushButton(win) {
                        Move(200,0)
                        setText("Close")
                        setClickEvent( Method( :CloseAction ) )
                }
                resize(400,400)
        }