#===================================================================#
#	Sample: Color Wheel 
#	Author: Gal Zsolt, Bert Mariani & Ilir Liburn 
#===================================================================#

load "guilib.ring"
 
xWidth  = 300
yHeight = 300
 
MyApp = new qapp 
        {
         win1 = new qwidget() {
               setwindowtitle("Color wheel")
               setgeometry(500,150,xWidth,yHeight)
            
               Canvas = new qlabel(win1)
               {
                  ### daVinci paints the MonaLisa on the Canvas
                  MonaLisa  = new qPixMap2( xWidth, yHeight)
		  color = new qcolor() { setrgb(255,255,255,0) }
                  MonaLisa.fill(color)

                  daVinci = new qpainter()
                  {
                     begin(MonaLisa)
                     #endpaint()                  ### This will Stop the Painting. For Animation comment it out
                  }

                  setPixMap(MonaLisa)
               }

               show()
            }
               
            ColorWheel()
            exec()
         }
 
 
func colorWheel()
     pi     = 3.14
     radius = 150
     x = xWidth
     y = yHeight
     
     color = new qcolor() { setrgb(255,255,255,255) }
     pen1  = new qpen() { setwidth(5) }

     for i = 1 to x
         p = pow(i-radius,2)
         for j = 1 to y

             h = (atan2(i-radius,j-radius)+pi)/(2*pi)
             s = sqrt(p+pow(j-radius,2))/radius
             
             if s < = 1 and  h < = 1
                color.setHsvF(h,s,1,1)
                pen1.setcolor(color)
                daVinci.setPen(pen1)
                daVinci.drawPoint(i,j)
             ok

         next
            Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
            MyApp.ProcessEvents()               ### <<< EXEC the Draw
 
     next
