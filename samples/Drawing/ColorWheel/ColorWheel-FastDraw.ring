#===================================================================#
#	Sample: Color Wheel 
#	Author: Gal Zsolt, Bert Mariani, Ilir Liburn & Mahmoud Fayed
#===================================================================#

load "guilib.ring"
 
paint	= null
xWidth	= 300
yHeight	= 300
 
oApp = new QApp 
{
	oWin = new QWidget()
	{
		setWindowTitle("Color wheel")
		setGeometry(500,150,xWidth,yHeight)            
		oCanvas = new QLabel(oWin)
		{
			### daVinci paints the MonaLisa on the Canvas
			MonaLisa  = new QPixMap2( xWidth, yHeight)
			color = new QColor() { setrgb(255,255,255,0) }
			MonaLisa.fill(color)
			daVinci = new QPainter()
			{
				begin(MonaLisa)
			}
			setPixMap(MonaLisa)
		}
		show()
	}               
	colorWheel()
	exec()
}
 
 
func colorWheel

	#=====================================================================#
	? "Start Processing..."
	t1 = clock()
	? "Clock : " + t1
	#=====================================================================#

	aList	= []
	pi	= 3.14
	radius	= 150
	for i = 1 to xWidth
		p = pow(i-radius,2)
		for j = 1 to yHeight
			h = (atan2(i-radius,j-radius)+pi)/(2*pi)
			s = sqrt(p+pow(j-radius,2))/radius             
			if s < = 1 and  h < = 1
				aList + [i,j,h,s,1,1]
			ok
		next 
	next	

	#=====================================================================#
	? "Start drawing..."	
	t2 = clock()
	? "Clock : " + t2
	#=====================================================================#

	daVinci.drawHSVFList(aList)
	oCanvas.setPixMap(MonaLisa)

	#=====================================================================#
	? "Done..."
	t3 = clock()
	? "Clock : " + t3
	#=====================================================================#
	? "Processing Time: " + ( (t2-t1)/ClocksPerSecond() ) + " seconds "
	? "Drawing Time: " + ( (t3-t2)/ClocksPerSecond() ) + " seconds "
	? "Total Time: " + ( (t3-t1)/ClocksPerSecond() ) + " seconds "
	#=====================================================================#
