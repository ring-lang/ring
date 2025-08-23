#===================================================================#
#	Sample: Color Wheel 
#	Author: Gal Zsolt, Bert Mariani & Ilir Liburn 
#===================================================================#

load "lightguilib.ring"
 
xWidth  = 300
yHeight = 300
 
myApp = new QApp 
{
	win1 = new QWidget() {

		installEventFilter( new QAllEvents(win1) { setCloseEvent("myApp.Quit()") } )
		setWindowTitle("Color wheel")
		setGeometry(500,150,xWidth,yHeight)
            
		Canvas = new QLabel(win1)
		{
			### daVinci paints the MonaLisa on the Canvas
			MonaLisa	= new QPixMap2 ( xWidth, yHeight)
			color		= new QColor() { setRGB(255,255,255,0) }
			MonaLisa.fill(color)

			daVinci = new QPainter()
			{
				begin(MonaLisa)
				#endpaint()                  ### This will Stop the Painting. For Animation comment it out
			}

			setPixMap(MonaLisa)
		}

		show()
	}
               
	colorWheel()
	exec()

}
 
 
func colorWheel()

	pi	= 3.14
	radius	= 150
	x	= xWidth
	y	= yHeight
     
	color	= new QColor() { setrgb(255,255,255,255) }
	pen1	= new QPen()   { setwidth(5) }

	for i = 1 to x
		p = pow(i-radius,2)
		for j = 1 to y
			h = (atan2(i-radius,j-radius)+pi)/(2*pi)
			s = sqrt(p+pow(j-radius,2))/radius
			if s <= 1 and  h <= 1
				color.setHsvF(h,s,1,1)
				pen1.setcolor(color)
				daVinci.setPen(pen1)
				daVinci.drawPoint(i,j)
			ok
		next
		Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
		myApp.ProcessEvents()               ### <<< EXEC the Draw
	next
