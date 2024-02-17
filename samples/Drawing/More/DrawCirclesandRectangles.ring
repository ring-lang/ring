Load "guilib.ring"

/*
 +------------------------------------------------------------
 +        Program Name : DrawCircles.ring
 +        Date         : 2016.11.16
 +        Author       : Bert Mariani
 +        Purpose      : Draw Circles - Non Overlapping
 +------------------------------------------------------------
*/

nbrOfCircles = 300                    ### How many circles
CountMax     = 50125                  ### Max loop count

horzSize   = 400                      ### Geometry size
vertSize   = 400            
radSize    = 100                      ### Largest  Radius size
radSizeMin =   5                      ### Smallest Radius size

arrayCol   = list(nbrOfCircles)       ### arrayOfCollisions
posCol     = 1                        ### Position in the array Collision table

    colorWhite  = new qcolor() { setrgb(255,255,255,255) }
    colorRed    = new qcolor() { setrgb(204,000,000,255) }
    colorGreen  = new qcolor() { setrgb(000,204,000,255) }
    colorBlue   = new qcolor() { setrgb(000,000,255,255) }
    
    colorGray   = new qcolor() { setrgb(128,128,128,255) }  
    colorBrown  = new qcolor() { setrgb(153,076,000,255) }
    colorBlack  = new qcolor() { setrgb(000,000,000,255) }
    colorOrange = new qcolor() { setrgb(255,128,000,255) }
    
    colorYellow = new qcolor() { setrgb(255,255,000,255) }
    colorPurple = new qcolor() { setrgb(153,153,255,255) }
    colorPink   = new qcolor() { setrgb(255,051,255,255) }
    colorLime   = new qcolor() { setrgb(128,255,000,255) }
 
$arrayColor  = [colorWhite,colorGray,colorRed,colorGreen,colorBlue,colorBrown,colorBlack,colorOrange,colorYellow,colorPurple,colorPink,colorLime]
 
          

New qapp {
        win1 =  new qwidget() 
        {
                setwindowtitle("Circle - Draw and Fill -- using QPainter")
                setgeometry(100, 100, horzSize +100, vertSize +200)

                label1 = new qlabel(win1) 
                {
                        setgeometry(10, 10, horzSize, vertSize)
                        settext("")
                }
                
                label2 = new qlabel(win1) 
                {
                        setgeometry( (horzSize / 2) -80 , vertSize +40, 70, 20 )
                        settext("Nbr of Circles")
                }
                
                lineEdit1 = new qlineedit(win1) {
                        setGeometry( (horzSize / 2) -70 , vertSize +60, 50, 20 )
                        settext( "150" )                  ### <<<< Initial Value
                }

                new qpushbutton(win1) 
                {
                        setgeometry(horzSize / 2, vertSize +50, 100, 30)
                        settext("Draw circles")
                        setclickevent("draw(1)")  ###  ===>>> Func
                }

                new qpushbutton(win1) 
                {
                        setgeometry(horzSize / 2+150, vertSize +50, 100, 30)
                        settext("Draw rectangles")
                        setclickevent("draw(2)")  ###  ===>>> Func
                }

                new qpushbutton(win1) 
                {
                        setgeometry(horzSize / 2+75, vertSize +100, 100, 30)
                        settext("Draw mixed")
                        setclickevent("draw(3)")  ###  ===>>> Func
                }

                show()
        }
        exec()
}

###---------------------------------------------------------

Func draw nr

        nbrOfCircles = number(lineedit1.text() )        ### Read text field 
	if nbrOfCircles < 1 return ok
        arrayCol     = []
        arrayCol     = list(nbrOfCircles)   ### arrayOfCollisions
        
        p1    = new qpicture()

        new qpainter() 
        {
            begin(p1)
            
            for i = 1 to nbrOfCircles       ### Clear array
                arrayCol[i] = [0,0,0,0]
            next
            
            posCol = 1                      ### Pointer to arrayOfCollisions[]                  
            Count  = 1                      ### Max iteration exit limit
            
            while posCol <= nbrOfCircles
            
                horz   = random(horzSize)
                vert   = random(vertSize)           
                rad    = random(radSize)
                
                if rad > radSizeMin
                
                    #drawPoint(horz + (rad / 2), vert +(rad /2) )

                    Count++
                    Status = Count % 5000
                    
                    if Status = 0
                        See "Count: "+ Count +" Circles: "+ posCol +nl
                    ok
                
                    if Count > CountMax
                        See "Exit max iteration count reached" +nl
                        exit
                    ok
                
                    ### Call Collision Function
                    ReturnCode = CollisionDetection (horz, vert, rad)
                    
                    if ReturnCode = 0
                        #See "Overlap-----: "+ ReturnCode +" "+ Count +" "+  posCol +" "+ horz +" "+ vert +" "+ rad   +nl
                        
                        ### Random Color
                        y = posCol % 12 +1                  
                        
                        ### Pen - color - random
                        penUse = new qpen() { setcolor($arrayColor[y]) setwidth(1) }    
                        setpen(penUse)                      
                        
                        ### Brush - color - random  
                        brushS = new qbrush() { setstyle(1) setcolor ($arrayColor[y]) } 
                        setBrush(brushS)                    
                        
                        ### Rectangle - Empty
                        #setBrush(brushE)                   
                        #drawRect(horz,vert,rad,rad)        

                        ### Circle - Solid
                        setBrush(brushS)
                         
                        if nr = 1
                           drawellipse(horz,vert,rad-10,rad-10)  
                        but nr = 2
                           drawrect(horz,vert,rad-10,rad-10)
                        else
                           flag = random(1)
                           if flag = 1
                              drawellipse(horz,vert,rad-10,rad-10)
                           else
                             drawrect(horz,vert,rad-10,rad-10)
                           ok
                        ok
                   
                    else
                        #See "Overlap: "+ ReturnCode +" "+ Count +" "+ posCol +" "+ horz +" "+ vert +" "+ rad  +nl
                    ok
                ok  
            end
            See "Finished Circles" +nl
            
            endpaint()
        }

        label1 { setpicture(p1) show() }
return

###---------------------------------------------------

Func CollisionDetection (horz, vert, rad)
        # Check for no overlapse with existing circle
        # Ellipse uses TopLeft and width and height
        # Circle Center is  Horz = (TopLeft + ( Width / 2) ), Vert =  (TopLeft + (Height / 2) )
        
    for i = 1 to nbrOfCircles
        if arrayCol[i][1] = 0
         
            ### Empty slot
            HorzC  = (horz + ( rad / 2) )
            VertC  = (vert + ( rad / 2) )
            Radius =  rad / 2
            
            arrayCol[i] = [ posCol, HorzC, VertC, Radius ]
                
            posCol++
            return 0
            exit
            
        else    
            
            HC  = (horz + ( rad / 2) )
            VC  = (vert + ( rad / 2) )
            RC  =  rad / 2
            
            oHC  = arrayCol[i][2]   
            oVC  = arrayCol[i][3];  
            oRC  = arrayCol[i][4] 

            DeltaH   = (HC - oHC)  
            DeltaV   = (VC - oVC)   
            DeltaR   = (RC + oRC) 
            
            HypothRR = (DeltaR * DeltaR)
            HypothHV = ( (DeltaH * DeltaH) + (DeltaV * DeltaV) )
            
            if HypothHV >= HypothRR
                Overlap  = 0
                
            else
                Overlap  = 1
                return 1
            ok
        
        ok  

    next
return  2   
        
###--------------------------------------------     
