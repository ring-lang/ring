load "guilib.ring"

new qApp {
	oOpenGLApp = new OpenGLApp { start() }
	exec()
}

class OpenGLApp

	win oOpenGL 
	
	func start
		win = new qWidget() {
			setWindowTitle("Testing OpenGLWidget...")
			resize(600,600)
			move(100,100) 
			oGL = new qOpenGLwidget(this.win) {
				move(0,0) resize(400,400)
				setInitEvent("oOpenGLApp.glinit()")
				setPaintEvent("oOpenGLApp.glpaint()")
				setResizeEvent("oOpenGLApp.glResize()")
			}
			show()
		}	
	
	func glinit
	  	context = new QOpenGLContext(win)
	 	oOpenGL = context.functions()		
		glPaint()	

	func glpaint 
		oOpenGL {
			glclearcolor(0,0,255,0)
		}
	
	func glresize 
