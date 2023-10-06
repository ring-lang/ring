# Load the library
	load "stbimage.ring"
# Image Information
	width=0	height=0 channels=0
# Ring will Free cData automatically in the end of the program
	cData = stbi_load("ring.jpg",:width,:height,:channels,STBI_rgb)
# Display the output
	? "Size (bytes): " + len(cData)
	? "Width : " + width
	? "Height: " + height
	? "Channels: " + channels
# Convert to [x,y,r,g,b] List 
	aList = stbi_bytes2list(cData,width,height)
	for aPoint in aList
		aPoint[3] /= 255
		aPoint[4] /= 255
		aPoint[5] /= 255
	next

load "guilib.ring"
 
MyApp = new qapp 
{
   win1 = new qwidget() 
   {  setwindowtitle("Draw Pixels")
      setgeometry(500,150,Width,Height)
      
      Canvas = new qlabel(win1)
      {  

	 ### daVinci paints the MonaLisa on the Canvas
         MonaLisa  = new qPixMap2( Width, Height)
             color = new qcolor(){ setrgb(0,0,0,255) }
         MonaLisa.fill(color)

         daVinci = new qpainter()
         {  
		begin(MonaLisa)
		drawRGBFList(aList)
            	endpaint()           ### This will Stop the Painting. For Animation comment it out
         }
         
         setPixMap(MonaLisa)
      }
      
      show()
   }
         
   exec()
}   






