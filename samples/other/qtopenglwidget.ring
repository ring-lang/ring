load "guilib.ring"

oOpenGLApp = new OpenGLApp { start() }

class OpenGLApp

	win oOpenGL 
	
	func start
		new qApp {
			this.win = new qWidget() {
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
			exec()
		}
	
	func glinit
	  	context  = new QOpenGLContext(win)
	 	oOpenGL = context.functions()		
		glPaint()	

	func glpaint 
		oOpenGL {
			glclearcolor(0,0,255,0)
		}
	
	func glresize 
