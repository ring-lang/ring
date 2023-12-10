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

load "guilib.ring"
 
MyApp = new QApp 
{
   win1 = new QWidget() 
   {  setwindowtitle("Draw Pixels")
      setgeometry(0,0,Width*2,Height*2)
      
      Canvas = new QLabel(win1)
      {  

	 ### daVinci paints the MonaLisa on the Canvas
         MonaLisa  = new QPixMap2( Width*2, Height*2)

         daVinci = new QPainter()
         {  
		begin(MonaLisa)
		drawbytes(100,100,cData,width,Height,channels)
            	endpaint()           ### This will Stop the Painting. For Animation comment it out
         }
         
         setPixMap(MonaLisa)
      }
      
      show()
   }
         
   exec()
}   






