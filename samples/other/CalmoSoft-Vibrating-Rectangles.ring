Load "guilib.ring"

color1  = new qcolor() { setrgb( 255,0,0,255 ) }
pen1    = new qpen()   { setcolor(color1)  setwidth(2) }

New qapp
{
   win1 =  new qwidget()
    {
              setwindowtitle("Drawing using QPixMap")
              setgeometry(100,100,500,500)
              label1 = new qlabel(win1)
              {
                           setgeometry(10,10,500,500)
                           settext("")
              }       
              Canvas = new qlabel(win1)
             {              
                            MonaLisa = new qPixMap2( 500,500)  
                            color    = new qcolor(){ setrgb(255,0,0,255) }

                           daVinci = new qpainter() 
                           {
                                         begin(MonaLisa)               
                           }            
             setpixmap(MonaLisa)         
             }       
	nCounter = 0
	oTimer = new qTimer(win1) {
		setinterval(1000)
		settimeoutevent("DrawCounter()")
		start()
	} 
       show()      
    }
   exec()
}
DrawCounter()

func DrawCounter()
        nCounter++
        if nCounter < 15
           Draw()
        else
           oTimer.stop()
        ok
return
 
Func Draw()
         daVinci.setpen(pen1)
         daVinci.drawrect(50+nCounter*10, 50+nCounter*10, 300-nCounter*20, 300-nCounter*20)
         Canvas.setpixmap(MonaLisa)      
         win1.show()                     
return
