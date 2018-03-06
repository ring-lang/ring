load "findinfilesview.ring"
import System.GUI
if isMainSourceFile() { 
	new App
		{
			StyleFusion()
			open_window(:findinfilesController)
			exec()
		}
}
class findinfilesController from WindowsControllerParent
	oView = new findinfilesView
	func search
	func browse
	func close
		oView.win.close()
private
