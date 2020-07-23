# Author: Bert Mariani, Gal Zsolt, Mahmoud Fayed

Load "guilib.ring"

color1  = new qcolor() { setrgb( 255,0,0,255 ) }
pen1    = new qpen()   { setcolor(color1)  setwidth(2) }
color2  = new qcolor() { setrgb( 0,255,0,255 ) }
pen2    = new qpen()   { setcolor(color2)  setwidth(2) }
color3  = new qcolor() { setrgb( 0,0,255,255 ) }
pen3    = new qpen()   { setcolor(color3)  setwidth(2) }

penArray = [pen1, pen2, pen3]
penNbr   =  1

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
			setinterval(500)
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
		Draw(penArray[penNbr])         
	elseif nCounter % 15 = 0
		nCounter = 0
		penNbr++
		if penNbr > 3
			penNbr = 1
		ok        
		Draw(penArray[penNbr])
        ok
return
 
Func Draw(pen1)
        daVinci.setpen(penArray[penNbr])
        daVinci.drawPolygon([ [350 +nCounter*10, 350 +nCounter*10], [300 +nCounter*10, 200 -nCounter*10], [180 -nCounter*10, 130 -nCounter*10], [160 -nCounter*10, 180 -nCounter*10], [190 -nCounter*10, 220 +nCounter*10] ], 1) 
        Canvas.setpixmap(MonaLisa)      
        win1.show()                     
return
