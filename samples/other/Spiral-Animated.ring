###  Draw Spiral - Animated
###  2017-08-08  Bert Mariani

Load "guilib.ring"

horzSize  = 400
vertSize  = 400 

counter     = 0  ### cycle thru colors       
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorYellow = new qcolor() { setrgb(255,255,000,255) }

penUseR = new qpen() { setcolor(colorRed)    setwidth(1) }
penUseG = new qpen() { setcolor(colorGreen)  setwidth(1) }
penUseB = new qpen() { setcolor(colorBlue)   setwidth(1) }
penUseY = new qpen() { setcolor(colorYellow) setwidth(1) }

        deg2rad    = atan(1) * 4 / 180  
        screensize = 600                 
        turns      = 5                
        halfscrn   = screensize / 2    
        sf         = (turns * (screensize - 100)) / halfscrn 
        x = 1
        y = 1
        r = 0
        inc = 0.50   ### control increment speed of r
        
MyApp = New qapp
{
   win1 =  new qwidget()
    {
        setwindowtitle("Draw Spiral")
        setgeometry(100,100,600,700)
   
		label1 = new qlabel(win1) 
		{
				  setgeometry(10,10,500,500)
				  settext("label1")
		}

		new qpushbutton(win1) 
		{
			  setgeometry(50,620,100,30)
			  settext("Draw")
			  setclickevent("Draw()")
		}
		
		new qpushbutton(win1) 
		{
			  setgeometry(200,620,100,30)
			  settext("Stop")
			  setclickevent("Stop()")
		}

		new qpushbutton(win1) 
		{
			  setgeometry(350,620,100,30)
			  settext("Exit")
			  setclickevent("Leave()")
		}
		
		Canvas = new qlabel(win1)
        {              
            MonaLisa = new qPixMap2( 600,600)  
            color    = new qcolor(){ setrgb(255,0,0,255) }

            daVinci  = new qpainter() 
            {
               begin(MonaLisa)             
               penUse = new qpen() { setcolor(colorRed) setwidth(1) }
               setpen(penUseR)
               #endpaint()      ### This will Stop the Painting
            }
            
            setpixmap(MonaLisa)        
        }       


    
        oTimer = new qTimer(win1) 
        {
            setinterval(1)    ### 1 millisecond
            settimeoutevent("DrawCounter()")
            #start()
        }   
		
                
       show()   ### Will show Painting ONLY after exec   
    }
   exec()
}


###====================================================

Func Draw()
 oTimer.start()
return
 
Func Stop()
 oTimer.stop()
return 

Func Leave()
  MyApp.quit()
return
  
Func DrawCounter()

    x  = cos(r * deg2rad) * r / sf 
    y  = sin(r * deg2rad) * r / sf
    r += inc   ###  0.20 fast, 0.90 slow

        if r >= turns * 360
            r = inc 
            x = 1 
            y = 1   
            counter++
            whichColor = counter % 4
            See  "whichColor: "+ whichColor +nl

                if whichColor = 0 daVinci.setpen(penUseR)  ok
                if whichColor = 1 daVinci.setpen(penUseG)  ok
                if whichColor = 2 daVinci.setpen(penUseB)  ok
                if whichColor = 3 daVinci.setpen(penUseY)  ok
 ok

    hpoint = halfscrn + x
    ypoint = halfscrn - y

    daVinci.drawpoint(hpoint, ypoint)  
    Canvas.setpixmap(MonaLisa)          ### Need this setpixmap to display imageLabel
    win1.show()                         ### Need this show      to display imageLabel
    
return

