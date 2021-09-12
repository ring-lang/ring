#===================================================================#
#  Sample: Color Wheel 
#  Author: Gal Zsolt, Bert Mariani, Ilir Liburn & Mahmoud Fayed
#===================================================================#

load "guilib.ring"
 
xWidth  = 400
yHeight = 400
 
MyApp = new qapp 
{
   win1 = new qwidget() 
   {  setwindowtitle("ColorWheel-FastDraw")
      setgeometry(500,150,xWidth,yHeight)
      
      Canvas = new qlabel(win1)
      {  ### daVinci paints the MonaLisa on the Canvas
         MonaLisa  = new qPixMap2( xWidth, yHeight)
             color = new qcolor(){ setrgb(255,255,255,0) }
              pen  = new qpen()  { setwidth(1) }  
         MonaLisa.fill(color)

         daVinci = new qpainter()
         {  begin(MonaLisa)
            #endpaint()           ### This will Stop the Painting. For Animation comment it out
         }
         
         setPixMap(MonaLisa)
      }
      
      show()
   }
         
   ColorWheel()
   exec()
}
 
//=====================
 
Func colorWheel

   #=====================================================================#
   ? "Start Processing..."
   t1 = clock()
   ? "Clock : " + t1
   #=====================================================================#

   aList = []
   pi       = 3.14159265359
   diameter = pi * 2
   radius   = yHeight / 2
   v        = 1                    // value/brightness  1 to 100  1=bright 0=dark

   for i = 1 to xWidth
      iradius = i - radius
            p = pow( iradius, 2)

      for j = 1 to yHeight

          h = (atan2( iradius, j-radius ) + pi ) / diameter   // hue/color  1 to 360 
          s =   sqrt( p + pow( j-radius, 2)) / radius         // saturation/intensity 1 to 100
        
         if s <= 1 and h <= 1 
            aList + [i,j,h,s,v,1]
         ok
         
      next 
   next  

   #=====================================================================#
   ? "Start drawing..." 
   t2 = clock()
   ? "Clock : " + t2
   #=====================================================================#

   daVinci.drawHSVFList(aList)
   Canvas.setPixMap(MonaLisa)

   #=====================================================================#
   ? "Done..."
   t3 = clock()
   ? "Clock : " + t3
   #=====================================================================#
   ? "Processing Time: " + ( (t2-t1)/ClocksPerSecond() ) + " seconds "
   ? "Drawing Time: " + ( (t3-t2)/ClocksPerSecond() ) + " seconds "
   ? "Total Time: " + ( (t3-t1)/ClocksPerSecond() ) + " seconds "
   #=====================================================================#
   
 return  
   
//==================






