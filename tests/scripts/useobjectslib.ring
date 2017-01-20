load "guilib.ring"

new qApp {
	open_window( :MainWindowController )
	exec()
}

class MainWindowController from WindowsControllerParent
	oView = new MainWindowView
	func SubWindowAction
		Open_window( :SubWindowController )
		Last_Window().SetParentObject(self)

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
