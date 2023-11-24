# Sample : Draw Lines Using the Mouse
# Author : Mahmoud Fayed, Gal Zsolt, Bert Mariani
# Date : 2017/02/04
# Date : 2020/09/20  Added Bezier Curves with up to 7 pPoints
#
# http://doc.qt.io/qt-4.8/qpainter.html#CompositionMode-enum
#
Load "guilib.ring"

flag = 0

nX = 0  nY = 0 # initial position of cursor
fX = 0  fY = 0 # final   position of cursor
oX = 0  oY = 0 # old     position of cursor

width  = 10
height = 12

xPos    = 100
yPos    = 100
xWidth  = 700
yHeight = 700   ### Canvas position on Screen

indent  = 30    ### Make Canvas smaller

counter = 1     ### Modulo 3 to change Pen Color

###--------------

colorGreen  = new qcolor() { setrgb(000,255,000,255) }
colorRed    = new qcolor() { setrgb(255,000,000,255) }
colorBlue   = new qcolor() { setrgb(000,000,255,255) }
colorWhite  = new qcolor() { setrgb(255,255,255,255) }
colorBlack  = new qcolor() { setrgb(000,000,000,255) }
colorMix    = new qcolor() { setrgb(255,255,000,255) }  ### Yellow

penGreen    = new qpen() { setcolor(colorGreen)  setwidth(1) }
penRed      = new qpen() { setcolor(colorRed)    setwidth(1) }
penBlue     = new qpen() { setcolor(colorBlue)   setwidth(1) }
penWhite    = new qpen() { setcolor(colorWhite)  setwidth(8) }
penBlack    = new qpen() { setcolor(colorBlack)  setwidth(1) }

brushS      = new qbrush() { setstyle(1)  setcolor (colorMix)  }   ### Yellow
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlack)}   ### Black
brushE      = new qbrush() { setstyle(0)  setcolor (colorMix)  }   ### Empty

//----------------------
// Bezier Points
/*
W = [ [120,160],
      [ 35,200],
      [220,260],
      [220, 40]
    ]
    
W = [ [240,320],
      [ 70,400],
      [440,520],
      [440, 80],
		[520,160]
    ]    
*/
	 
W = [ [131, 81],  // 7 Points
      [170,300],
      [240, 80],
      [340,480],
		[420, 60],
      [580,280],
		[460,480]
    ]    	 
    

selectBezierPoint = 0  // Select and Move Point for New drawing
oldBezierX = 0
oldBezierY = 0

###-----------------

new qApp 
{
    win = new qWidget()
    {
        setWindowTitle("Draw Lines Using the Mouse")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

        myfilter = new qallevents(win)

            ###------------------------------------------
            ### Mouse Event
        
            myfilter.setMouseButtonPressEvent("pPress()")
            myfilter.setMouseButtonReleaseEvent("pRelease()")
            myfilter.setMouseMoveEvent("pMove()")
        
            installeventfilter(myfilter)
        
            ###------------------------------------------
            ### ReSizeEvent ... Call WhereAreWe function

            myfilter.setResizeEvent( "WhereAreWe()")
            myfilter.setMoveEvent( "WhereMoved()" )  

        Canvas = new qlabel(win)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( 2000, 2000)

            daVinci = new qpainter()
            {
               begin(MonaLisa)
               #endpaint()                  ### This will Stop the Painting

               ###-------------------------------
               ### Drw Yellow Rect in the Middle
                   #setBrush(brushS)             ### Brush - Solid, Yellow    
                   #setpen(penBlue)
                   #drawRect(indent, indent, xWidth - (2*indent), yHeight - (2*indent))    
            }

            setPixMap(MonaLisa)
        }

        btnL = new qpushbutton(win)
        {
            setgeometry(20, 500, 100, 20)
            settext("Line")
            setclickevent("pLine()")
        }

        btnR = new qpushbutton(win)
        {
            setgeometry(140, 500, 100, 20)
            settext("Rectangle")
            setclickevent("pRect()") 
        }

        btnC = new qpushbutton(win)
        {
            setgeometry(260, 500, 100, 20)
            settext("Circle")
            setclickevent("pCircle()") 
        }
        
        btnB = new qpushbutton(win)
        {
            setgeometry(380, 500, 100, 20)
            settext("Bezier")
            setclickevent("pBezier()") 
        }           

        btnP = new qpushbutton(win)
        {
            setgeometry(500, 500, 100, 20)
            settext("Point")
            setclickevent("pPoint()") 
        }
        
        btnClr = new qpushbutton(win)
        {
            setgeometry(620, 500, 100, 20)
            settext("Clear")
            setclickevent("pClear()") 
        }
   

        
        
        show()
    }
    exec()
}

###--------------------------------------------------------------------

Func pPress
    win.setWindowTitle("Press: New-Screen: " + nX +"-" +nY +" Final: "+ fX +"-" +fY + " Window-Getx: "+ myfilter.getx() +"-"+ myfilter.gety() )
    
    nX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    ny = myfilter.getglobaly()      ### Screen co-ord, NOT Canvas

    ### Change Pen Color
    if  counter % 3 = 0  daVinci.setpen(penRed)
    but counter % 3 = 1  daVinci.setpen(penGreen)
    else                 daVinci.setpen(penBlue)
    ok
    counter++
    
    daVinci.setCompositionMode(26)  ###  THIS is the MAGIC - Erase Old Line when Redrawn
    
    oX = nX  ### Save Pressed point as OLD points
    oY = nY
	 
	 //----------------------------------
	 // Select BezierPoint = Press
	 
	 if flag = 4   					// Bezier selected
		bX = myfilter.getx()  
		bY = myfilter.gety()
		
		range = 5
		selectBezierPoint = 0
		
		for i = 1 to 7
			if bX >= W[i][1] - range AND bX <= W[i][1] + range  AND 
				bY >= W[i][2] - range AND bY <= W[i][2] + range 
				selectBezierPoint = i
				//See "pPress selectBezierPoint: "+ i +nl
			ok
		next
		
	 ok
	 
return

###------------------------------------------------------------------------

Func pRelease
    win.setWindowTitle("Press: New-Screen: " + nX +"-" +nY +" Release: "+ fX +"-" +fY +" Dist: "+ (fX-nX) + "-"+ (fY-nY) + " Window-Getx: "+ myfilter.getx() +"-"+ myfilter.gety() )

	 //---------------------------------------------
	 // Bezier Release - Update Point
	 
	 if flag = 4   				 	// Bezier selected
		//selectBezierPoint = 1 to 7
		
		if selectBezierPoint > 0
			W[selectBezierPoint][1] = myfilter.getx() 
			W[selectBezierPoint][2] = myfilter.gety() 
		ok
		
		Bezier()   // Update drawing of Bezier Points	
	 ok
	 


	 //----------------------------------------------------------------
	
    fX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()

    Canvas.setPixMap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
	 

return

###------------------------------------------------------------------------

Func pMove
    win.setWindowTitle("Press: New-Screen: " + nX +"-" +nY +" Move: "+ fX +"-" +fY +" Dist: "+ (fX-nX) + "-"+ (fY-nY) + " Window-Getx: "+ myfilter.getx() +"-"+ myfilter.gety())

	 //----------------------------------
	 // Select BezierPoint = Move
	 
	 if flag = 4   				 	// Bezier selected
		//selectBezierPoint = 1 to 7
		if selectBezierPoint > 0
	
			daVinci.setpen(penWhite)
			
			//daVinci.drawPoint( W[selectBezierPoint][1], W[selectBezierPoint][2] )  // Erase Old point
			
			W[selectBezierPoint][1] = myfilter.getx() 
			W[selectBezierPoint][2] = myfilter.gety() 
			
		   //daVinci.drawPoint( nX - xPos, nY - yPos )  // Starting point
		   //daVinci.drawPoint( oX - xPos, oY - yPos )  // Erase Old point
         //daVinci.drawPoint( fX - xPos, fY - yPos )    // Current point
			
			daVinci.drawPoint( oldBezierX, oldBezierY )  // Erase Old point
			daVinci.drawPoint( myfilter.getx(), myfilter.gety() )
			
			Bezier()   // Update drawing of Bezier Points
			
			oldBezierX = myfilter.getx()
			oldBezierY = myfilter.gety()
		ok		
	 ok
	 
	 //-------------------------------------------------------------
	 
    fX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

    pDrawObjects()

    Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
    
    oX = fX  ### Save OLD points
    oY = fY
	     
return


###-----------------------------------------
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe()
    Rec = win.framegeometry()

    WinWidth  = Rec.width()             ### Current Values
    WinHeight = Rec.height()            ### 
    
    WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
    WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title
    WinRight  = Rec.right()
    WinBottom = Rec.bottom()

    win{ setwindowtitle("Window ReSize: Win " +  WinWidth + "x" + WinHeight + 
            " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom      ) }
return

###---------------------------------------
### Window Moved

Func WhereMoved()

    xPos = win.x()  +8          ### <<< QT FIX because of Win Title
    yPos = win.y() +30          ### <<< QT FIX because of Win Title

    win{ setwindowtitle("Window Moved: xPos: " + xPos +" yPos: "+ yPos ) }  
return

###---------------------------

Func pClear()

    //flag = 0                        ### No pLine etc -- reset
	 //ClearButtonColor()
	 
    daVinci.setCompositionMode(0)   ### Put back to default mode 0
    
    daVinci.setBrush(brushSB)       ### Brush - Solid Black  
    daVinci.setPen(penBlack)
    daVinci.drawRect(0, 0, xWidth, yHeight)
    
    daVinci.setCompositionMode(26)  ### THIS is the MAGIC - Erase Old Line when Redrawn
    
    Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
return

###---------------

Func pLine()
         flag = 1
			ClearButtonColor()
			btnL.setStyleSheet("background-color: yellow") 	
return

Func pRect()
         flag = 2
			ClearButtonColor()
			btnR.setStyleSheet("background-color: yellow") 	
return

Func pCircle()
         flag = 3
			ClearButtonColor()
			btnC.setStyleSheet("background-color: yellow")	
return

Func pBezier()
         flag = 4
			ClearButtonColor()
			btnB.setStyleSheet("background-color: yellow")	
         

Func pPoint()
         flag = 5
			ClearButtonColor()
			btnP.setStyleSheet("background-color: yellow")	
         
return

###--------------------
Func ClearButtonColor()

			btnL.setStyleSheet("background-color: lightgray") 	
			btnR.setStyleSheet("background-color: lightgray") 	
			btnC.setStyleSheet("background-color: lightgray")	
			btnB.setStyleSheet("background-color: lightgray")	
			btnP.setStyleSheet("background-color: lightgray")	
         
return

###--------------------

Func pDrawObjects()

    if flag = 1    // Line
       daVinci.drawLine( nX - xPos, nY - yPos, oX - xPos, oY - yPos )  ### ReDraw OLD Line to Erase
       daVinci.drawLine( nX - xPos, nY - yPos, fX - xPos, fY - yPos )  ### Draw NEW Line
    
    but flag = 2   // Rect
       daVinci.drawRect( nX - xPos, nY - yPos, oX - nX, oY - nY )
       daVinci.drawRect( nX - xPos, nY - yPos, fX - nX, fY - nY )
    
    but flag = 3   // Circle
        rad1 = sqrt(pow(oX - nX, 2) + pow(oY - nY, 2))
        daVinci.drawellipse(nX - xPos, nY - yPos, rad1, rad1)
          
        rad2 = sqrt(pow(fX - nX, 2) + pow(fY - nY, 2))
        daVinci.drawellipse(nX -xPos, nY - yPos, rad2, rad2)
        
    but flag = 4   // Bezier
        Bezier()
        
    but flag = 5   // Point

     //daVinci.drawPoint( nX - xPos, nY - yPos )  // Starting point
     //daVinci.drawPoint( oX - xPos, oY - yPos )  // Erase Old point
       daVinci.drawPoint( fX - xPos, fY - yPos )  // Current point      
             
    ok
                 
return



###---------------------------
###////////////////////////////////////
### https://pomax.github.io/bezierinfo/
#
#lut = [      [1],           // n=0
#            [1,1],          // n=1
#           [1,2,1],         // n=2
#          [1,3,3,1],        // n=3
#         [1,4,6,4,1],       // n=4
#        [1,5,10,10,5,1],    // n=5
#       [1,6,15,20,15,6,1]]  // n=6
#
#
//   X = (pow(1-t, 3)*X1) + ( 3*pow(1-t,2)*t*X2)  +(3*(1-t)*pow(t,2)*X3) +(pow(t,3)*X4)
//   Y = (pow(1-t, 3)*Y1) + ( 3*pow(1-t,2)*t*Y2)  +(3*(1-t)*pow(t,2)*Y3) +(pow(t,3)*Y4)


Func Bezier()

pClear()

X1 = W[1][1]  X2 = W[2][1]  X3 = W[3][1]  X4 = W[4][1]  X5 = W[5][1]  X6 = W[6][1]  X7 = W[7][1] 
Y1 = W[1][2]  Y2 = W[2][2]  Y3 = W[3][2]  Y4 = W[4][2]  Y5 = W[5][2]  Y6 = W[6][2]  Y7 = W[7][2]

Inc = 0.01
daVinci.setpen(penRed)



daVinci.setpen(penWhite)
   daVinci.DrawPoint(X1,Y1 )
   daVinci.DrawPoint(X2,Y2 )	
   daVinci.DrawPoint(X3,Y3 )	
   daVinci.DrawPoint(X4,Y4 )	
	daVinci.DrawPoint(X5,Y5 )
   daVinci.DrawPoint(X6,Y6 )
	daVinci.DrawPoint(X7,Y7 )

daVinci.setpen(penBlue)
   daVinci.DrawLine(X1,Y1, X2,Y2 )	
   daVinci.DrawLine(X2,Y2, X3,Y3 )	
   daVinci.DrawLine(X3,Y3, X4,Y4 )	
   daVinci.DrawLine(X4,Y4, X5,Y5 )
   daVinci.DrawLine(X5,Y5, X6,Y6 )
	daVinci.DrawLine(X6,Y6, X7,Y7 )



//-----------------------
### ALL 7 Points

for t = 0 to 1 step Inc  
   t1  = t
	t2  = t1 * t1
	t3  = t2 * t1
	t4  = t3 * t1
   t5  = t4 * t1
   t6  = t5 * t1
	
	mt1 = 1-t
	mt2 = mt1 * mt1
	mt3 = mt2 * mt1 
	mt4 = mt3 * mt1
	mt5 = mt4 * mt1   
	mt6 = mt5 * mt1

   //------------------------------
   ### 3 Points
	daVinci.setpen(penRed)
	X = mt2*X1 + 2*mt1*t*X2 + t2*X3
	Y = mt2*Y1 + 2*mt1*t*Y2 + t2*Y3  
   daVinci.DrawPoint(X,Y )	
	
  //------------------------------
  ### 4 Points
  daVinci.setpen(penGreen)
  X = mt3*X1 + 3*mt2*t*X2 + 3*mt1*t2*X3 + t3*X4
  Y = mt3*Y1 + 3*mt2*t*Y2 + 3*mt1*t2*Y3 + t3*Y4
  daVinci.DrawPoint(X,Y )	

   //------------------------------
   ### 5 Points
   daVinci.setpen(penRed)
	X = mt4*X1 + 4*mt3*t1*X2 + 6*mt2*t2*X3 + 6*mt1*t3*X4	+ t4*X5           
	Y = mt4*Y1 + 4*mt3*t1*Y2 + 6*mt2*t2*Y3 + 6*mt1*t3*Y4	+ t4*Y5
   daVinci.DrawPoint(X,Y )			

   //------------------------------
   ### 6 Points
	daVinci.setpen(penGreen) 
   X = mt5*X1 +  5*mt4*t1*X2 + 10*mt3*t2*X3 + 10*mt2*t3*X4 + 5*mt1*t4*X5 + t5*X6        
   Y = mt5*Y1 +  5*mt4*t1*Y2 + 10*mt3*t2*Y3 + 10*mt2*t3*Y4 + 5*mt1*t4*Y5 + t5*Y6  
   daVinci.DrawPoint(X,Y )

	//------------------------------
	### 7 Points

	daVinci.setpen(penRed) 
   X = mt6*X1 +  6*mt5*t1*X2 + 15*mt4*t2*X3  + 20*mt3*t3*X4+ 15*mt2*t4*X5 + 6*mt1*t5*X6 + t6*X7        
   Y = mt6*Y1 +  6*mt5*t1*Y2 + 15*mt4*t2*Y3  + 20*mt3*t3*Y4+ 15*mt2*t4*Y5 + 6*mt1*t5*Y6 + t6*Y7 
	daVinci.DrawPoint(X,Y )	
	
next 

return

###-----------------------------------
/*


function Bezier3(3,t):
  t2  = t  * t
  t3  = t2 * t
  mt  = 1-t
  mt2 = mt  * mt
  mt3 = mt2 * mt
  X   = mt3*X1 + 3*mt2*t*X2 + 3*mt*t2*X3 + t3*X4
  Y   = mt3*Y1 + 3*mt2*t*Y2 + 3*mt*t2*Y3 + t3*Y4
  
  
### https://pomax.github.io/bezierinfo/
#
#lut = [      [1],           // n=0
#            [1,1],          // n=1
#           [1,2,1],         // n=2
#          [1,3,3,1],        // n=3
#         [1,4,6,4,1],       // n=4
#        [1,5,10,10,5,1],    // n=5
#       [1,6,15,20,15,6,1]]  // n=6
# 
###
###-----------------------------

m = (1-t)

###-----------------------------

2 Points
B(+) =  SUM i=0 to 1   COM i to 1  (m)^1-i * t^i *P 

=> B(+) = i=0 >>>    1*(m)^1 * t^0 * P0  
          i=1 >>> +  1*(m)^0 * t^1 * P1   


###-----------------------------
3 Points
B(+) =  SUM i=0 to 2   COM i to 2  (m)^2-i * t^i *P 

=> B(+) = i=0 >>>    1*(m)^2 * t^0 * P0  
          i=1 >>> +  2*(m)^1 * t^1 * P1   
			 i=2 >>> +  1*(m)^0 * t^2 * P2

###-----------------------------
4 Points
B(+) =  SUM i=0 to 3   COM i to 3  (m)^3-i * t^i *P 

=> B(+) = i=0 >>>    1*(m)^3 * t^0 * P0  
          i=1 >>> +  3*(m)^2 * t^1 * P1   
			 i=2 >>> +  3*(m)^1 * t^2 * P2  
			 i=3 >>> +  1*(m)^0 * t^3 * P3
			 
###-----------------------------
5 Points	
B(+) =  SUM i=0 to 4   COM i to 4  (m)^4-i * t^i *P 	

=> B(+) = i=0 >>>    1*(m)^4 * t^0 * P0  
          i=1 >>> +  4*(m)^3 * t^1 * P1   
			 i=2 >>> +  6*(m)^2 * t^2 * P2 
          i=3 >>> +  4*(m)^1 * t^3 * P3			 
			 i=4 >>> +  1*(m)^0 * t^4 * P4			 
			 
###-----------------------------
6 Points
B(+) =  SUM i=0 to 5   COM i to 5  (m)^5-i * t^i *P 	

=> B(+) = i=0 >>>    1*(m)^5 * t^0 * P0  
          i=1 >>> +  5*(m)^4 * t^1 * P1   
			 i=2 >>> + 10*(m)^3 * t^2 * P2 
          i=3 >>> + 10*(m)^2 * t^3 * P3			 
			 i=4 >>> +  5*(m)^1 * t^4 * P4
          i=5 >>> +  1*(m)^0 * t^5 * P5	

###-----------------------------
7 Points
B(+) =  SUM i=0 to 6   COM i to 6  (m)^6-i * t^i *P 	
[1,6,15,20,15,6,1]]

=> B(+) = i=0 >>>    1*(m)^6 * t^0 * P0  
          i=1 >>> +  6*(m)^5 * t^1 * P1   
			 i=2 >>> + 15*(m)^4 * t^2 * P2 
			 i=2 >>> + 20*(m)^3 * t^3 * P2
          i=3 >>> + 15*(m)^2 * t^4 * P3			 
			 i=4 >>> +  6*(m)^1 * t^5 * P4
          i=5 >>> +  1*(m)^0 * t^6 * P5			

###-----------------------------			 
*/ 
