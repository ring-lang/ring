// Heart Equation
// Bert Mariani 2024-11-25

load "stdlibcore.ring"
load "lightguilib.ring"

//================================================
PI      = 3.14159265

xPos    = 100   ### Canvas position on Screen
yPos    = 25
xWidth  = 700  ### Canvas size on Screen
yHeight = 700  
  
// Need to define variable when using Func StartApp()
MonaLisa = null 
daVinci  = null 
Canvas   = null
myApp    = null

eScale = 4 ;     // Scale the Triage Size

aTri = list(32)


###-------------------------------
### Define Colours, Pens, Brushes

colorGreen   = new qcolor() { setrgb(000,255,000,128) }  ### faint
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ### 64 faint line
colorBright  = new qcolor() { setrgb(255,255,255,255) }  ### 64 faint line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  ### 64 faint line, plave
colorAqua    = new qcolor() { setrgb(000,255,255,255) }  ### 255 full

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(1) }  //
penYellow   = new qpen() { setcolor(colorYellow)  setwidth(1) } 
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(1) }
penBright   = new qpen() { setcolor(colorBright)  setwidth(2) }  //
penBlack    = new qpen() { setcolor(colorBlack)   setwidth(1) }
penGray     = new qpen() { setcolor(colorGray)    setwidth(2) }
penMagenta  = new qpen() { setcolor(colorMagenta) setwidth(2) }
penAqua     = new qpen() { setcolor(colorAqua)    setwidth(1) }

brushSR     = new qbrush() { setstyle(1)  setcolor (colorRed)}      ### Red
brushSG     = new qbrush() { setstyle(1)  setcolor (colorGreen)}    ### Green
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlue)}     ### Blue
brushSY     = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSGR    = new qbrush() { setstyle(1)  setcolor (colorGray)}     ### 
brushSW     = new qbrush() { setstyle(1)  setcolor (colorWhite)}    ### 
brushSM     = new qbrush() { setstyle(1)  setcolor (colorMagenta)}  ### 

brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty


//==========================================
//=========================================
// START the APP

 myApp = new qApp 
 {
	win = new qWidget()
	{
		setWindowTitle("HeartEquation ")
		setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

		Canvas = new qlabel(win)
		{
			### daVinci Paints the MonaLisa on the Canvas
			MonaLisa  = new qPixMap2( xWidth, yHeight)
			
			daVinci = new qpainter()
			{
			   begin(MonaLisa)                       ### Canvas: xWidth=1800  yHeight=1000  
			   translate(xWidth/2 , yHeight/2)       ### TRANSLATE CO-ORD x,y 0,0 Maps Center OFFSET  TO 900,500
			   setCompositionMode(26)                ###  THIS is the MAGIC - Erase Old Line when Redrawn
			   #endpaint()                           ### This will Stop the Painting   
			   
			}
			
			//-------------------------------
			setPixMap(MonaLisa)   // Draw It
		}  
		
	//=====================================================

		btnHE  = new qPushButton(win) { setGeometry(   2, 2, 95, 20)   setText("HeartEquation")  setStyleSheet("background-color: aqua")  setClickEvent("HeartEquation()")  }	
	//===============================================================                                                                      
	  show()
		  
	}
	exec()
 }

return

###==============================================================
###==============================================================
// Clear Images

Func  ClearImages()

	 See "ClearImages() "+nl
	 
		MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
		Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
		MyApp.ProcessEvents()               ### <<< EXEC the Draw
		
return

###==========================================================================
###==========================================================================
//  x   -1.82 to 1.82
//  y = x^(2/3) + ( ( 10/3 - x^2)^(1/2) ) * ( sin(14*PI*x) )
 

Func HeartEquation()

	See "HeartEquation()"+nl
    ClearImages() 
    ScaleX = 120                                   
	ScaleY = 100
	
	//--------------------------------------
	// Draw Axis
	daVinci.setPen(penWhite)
	daVinci.drawLine(-300,   0, 300,   0)         // Horz Axis Left to Right
	daVinci.drawLine(   0,-300,   0, 300)         // Vert Axis Top to Bottom  

	Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
	MyApp.ProcessEvents()               ### <<< EXEC the Draw
	
    //--------------------------------------	

    daVinci.setPen(penYellow)
	oldPointX = -1.82                      // X:-1.8200 Y:1.6351
	oldPointY =  1.6351                    // X: 1.8200 Y:1.3463  
    a=1 b=1 c=1 d=1

	for x = -1.82 to 1.82  step 0.001      // PI step ( PI / 180)
		      
            xA = fabs(x)                   // Fractional Sqrt needs FABS
            a = xA^^(2/3)
			
 			b =  (( 10/3 - (x^^2))^^(1/2)  )   
			
 			c = sin(14*PI*x)
 			
 			y = a + (b * c)
			
			sX = ScaleX * x     
			sY = ScaleY * y
				 
			daVinci.drawPoint( sX, -sY )     // FLIP Y ... Point A ->B -
			
			oldPointX = sX
			oldPointY = sY
	
			Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
			MyApp.ProcessEvents()               ### <<< EXEC the Draw

	next  
	
	
Return  


###==========================================================================
###==========================================================================
