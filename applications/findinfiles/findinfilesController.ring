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
		new QFileDialog(oView.win)
			{
				cFolder = getExistingDirectory(this.oView.win,"Open Directory","Folder",0)
			}
		oView.txtFolder.setText(cFolder)
	func close
		oView.win.close()
private
