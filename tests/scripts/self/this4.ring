oOpenGLApp = new OpenGLApp { start() }

class OpenGLApp

	win 
	
	func start
		oApp = new qApp { 
			this.win = new qWidget() {
				? type(this.win)
				oGL = new qOpenGLwidget(this.win) {
				}
				show()
			}	
		}

class qApp
	func exec

class qWidget
	func init return self
 	func show

class qOpenGLWidget
	func init oObject
		return self