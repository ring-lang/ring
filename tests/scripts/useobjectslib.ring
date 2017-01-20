load "guilib.ring"

new qApp {
	open_window( :MainWindowController )
	exec()
}

class MainWindowController from WindowsControllerParent
	oView = new MainWindowView
	func SubWindowAction
		open_window( :SubWindowController )
		Last_Window().SetParentObject(self)

class MainWindowView
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

class SubWindowView
	win = new qWidget() {
		SetWindowTitle("Sub Window")
		btnSub = new qPushButton(win) {
			setText("Set Main Window Title")
			setClickEvent( Method( :SetMainWindowTitleAction ) )
		}
		resize(400,400)
	}
