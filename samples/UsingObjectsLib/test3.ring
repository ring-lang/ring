load "guilib.ring"

new qApp {
        openWindow( :MainWindowController )
        exec()
}

class MainWindowController from WindowsControllerParent

        oView = new MainWindowView

	nFirstWindowID  nSecondWindowID  nThirdWindowID

        func CreateThreeWindowsAction

                openWindow( :SubWindowController )
		nFirstWindowID = lastWindow().ObjectID()
                openWindow( :SubWindowController )
		nSecondWindowID = lastWindow().ObjectID()
                openWindow( :SubWindowController )
		nThirdWindowID = lastWindow().ObjectID()

		FirstWindow().oView.win { 
			setWindowTitle("One")
			move(100,100)
		}
		SecondWindow().oView.win {
			setWindowTitle("Two")
			move(200,200)
		}
		ThirdWindow().oView.win {
			setWindowTitle("Three")
			move(300,300)
		}
		
	func FirstWindow
		return GetWindowByID(nFirstWindowID)

	func SecondWindow
		return GetWindowByID(nSecondWindowID)

	func ThirdWindow
		return GetWindowByID(nThirdWindowID)

class MainWindowView from WindowsViewParent

        win = new qWidget() {
                setWindowTitle("Main Window")
		move(500,100)
                btnSub = new qPushButton(win) {
                        setText("Create Three Windows")
                        setClickEvent( Method( :CreateThreeWindowsAction ) )
                }
                resize(400,400)
        }

class SubWindowController from WindowsControllerParent

        oView = new SubWindowView

class SubWindowView from WindowsViewParent

        win = new qWidget() {
                SetWindowTitle("Sub Window")
                btnClose = new qPushButton(win) {
                        Move(200,0)
                        setText("Close")
                        setClickEvent( Method( :CloseAction ) )
                }
                resize(400,400)
        }