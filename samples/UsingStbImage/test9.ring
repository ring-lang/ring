cData    = ""
width    = 640
height   = 480
channels = 3

? "Creating the image..."
t1 = clock()
for x=1 to height
    for y=1 to width
        cData += Char((x*x)%256)
        cData += Char((x*y)%256)
        cData += Char((x*2)%256)
    next
next
t2 = clock()

load "guilib.ring"
 
MyApp = new QApp 
{
   win1 = new QWidget() 
   {  setwindowtitle("Draw Pixels")
      setgeometry(0,0,Width,Height)
      
      Canvas = new QLabel(win1)
      {  

	 ### daVinci paints the MonaLisa on the Canvas
         MonaLisa  = new QPixMap2( Width, Height)

         daVinci = new QPainter()
         {  
		begin(MonaLisa)
		drawbytes(0,0,cData,width,Height,channels)
            	endpaint()           ### This will Stop the Painting. For Animation comment it out
         }
         
         setPixMap(MonaLisa)
      }
      
      show()
   }
         
   exec()
}