load "guilib.ring"

new qApp
{
	win = new qwidget(){
		move(100,100) resize(600,600) 
		setWindowTitle("Using Camera!")
		viewfinder = new qCameraViewFinder(win) {
			move(0,0) resize(500,500)
		}
		camera = new QCamera() {
			setViewfinder(viewfinder)
			setCaptureMode(1)
			start()
		}
		show()
	}
	exec()
}
