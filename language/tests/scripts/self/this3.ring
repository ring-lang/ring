oOpenGLApp = new OpenGLApp { start() }

class OpenGLApp

	win oOpenGL 
	
	func start
		oApp = new qApp { 
			this.win = new qWidget() {
				oGL = new qOpenGLwidget(this.win) {
				}
			}	
		}
	
 
class qApp
class qWidget func init return self
class qOpenGLWidget func init oPara ? Type(oPara) return self