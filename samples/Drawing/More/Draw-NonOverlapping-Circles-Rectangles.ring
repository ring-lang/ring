Load "guilib.ring"

/*
 +------------------------------------------------------------
 +        Program Name : DrawCircles.ring
 +        Date         : 2016.11.16
 +        Author       : Bert Mariani
 +        Purpose      : Draw Circles - Non Overlapping
 +------------------------------------------------------------
*/

nbrOfCircles = 5000                    ### How many circles
CountMax     = 250125                  ### Max loop count

BoxLeft    = 10                       ### TopLeft corner of Label Box
BoxTop     = 50

horzSize   = 400                      ### Geometry size
vertSize   = 400            
radSize    = 100                      ### Largest  Radius size
radSizeMin =   5                      ### Smallest Radius size

arrayCol   = list(nbrOfCircles)       ### arrayOfCollisions
posCol     = 1                        ### Position in the array Collision table
ButtonNbr  = 1                        ### 1-Circle  2-rectangle

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
                ### Window Position and Size inside Screen
                setwindowtitle("Circle - Draw and Fill -- using QPainter")
                setgeometry(100, 100, horzSize +100, vertSize +100)

                ###------------------------------------------
                ### ReSizeEvent ... Call WhereAreWe function

                myfilter = new qallevents(win1)
                myfilter.setResizeEvent("WhereAreWe()") ### ==>>> Func
                installeventfilter(myfilter)

                ### Output Box Position and Size inside Window
                label1 = new qlabel(win1) 
                {
                        setgeometry(BoxLeft, BoxTop, horzSize, vertSize)
                        settext("")
                }
                
                label2 = new qlabel(win1) 
                {
                        setgeometry( (10) , (0), 70, 20 )
                        settext("Nbr of Circles")
                }
                
                lineEdit1 = new qlineedit(win1) {
                        setGeometry( (10) , (20), 50, 20 )
                        settext( "150" )                  ### <<<< Initial Value
                }

                new qpushbutton(win1) 
                {
                        setgeometry((80), (10), 100, 30)
                        settext("Draw Circles")
                        setclickevent("Draw(1)")  ###  ===>>> Func
                }

                new qpushbutton(win1) 
                {
                        setgeometry((200), (10), 100, 30)
                        settext("Draw Rectangles")
                        setclickevent("Draw(2)")  ###  ===>>> Func
                }
                

                show()
        }
        exec()
}

###---------------------------------------------------------

Func Draw ButtonNbr

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
                    Status = Count % 1000
                    
                    if Status = 0
                        See "Count: "+ Count +" Circles: "+ posCol +nl
                    ok
                
                    if Count > CountMax
                        See "Exit max iteration count reached" +nl
                        exit
                    ok
                
                    ### Call Collision Function
                    if ButtonNbr = 1
                        ReturnCode = CollisionDetectionCircle (horz, vert, rad)
                    else
                        ReturnCode = CollisionDetectionRect (horz, vert, rad)
                    ok
                    
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
                        #brushE = new qbrush() { setstyle(0) setcolor ($arrayColor[y]) } 
                        #setBrush(brushE)                   
                        #drawRect(horz,vert,rad,rad)        

                        ### Circle - Solid
                        setBrush(brushS)
                        
                        if ButtonNbr = 1
                           drawEllipse(horz,vert,rad,rad)  
                        else
                           drawRect(horz,vert,rad,rad)
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

Func CollisionDetectionCircle (horz, vert, rad)

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
            
        else        
            HC  = (horz + ( rad / 2) )
            VC  = (vert + ( rad / 2) )
            RC  =  rad / 2
            
            oHC  = arrayCol[i][2]   
            oVC  = arrayCol[i][3] 
            oRC  = arrayCol[i][4] 

            DeltaH   = (HC - oHC)  
            DeltaV   = (VC - oVC)   
            DeltaR   = (RC + oRC) 
            
            HypothRR =  (DeltaR * DeltaR)
            HypothHV = ((DeltaH * DeltaH) + (DeltaV * DeltaV))
            
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
   
Func CollisionDetectionRect (horz, vert, rad)

        ### Rectangle
        ### Check 4 corners for overlap
        ### if New Rect -- Any Corner -- Inside Each Rect ==> Overlap 

    for i = 1 to nbrOfCircles
        if arrayCol[i][1] = 0
         
            ### Empty slot
            HorzT  = (horz ) ; HorzB = horz +rad
            VertL  = (vert ) ; VertR = vert +rad
            Radius =  rad 
            
            arrayCol[i] = [ posCol, HorzT, VertL, Radius ]  
            
            posCol++
            return 0
            
        else   
            ###-------------------
            ### NEW Rect Corners
            
            HT = (horz)         ### Horz Top
            HB = (horz + rad)   ### Horz Bottom     
            VL = (vert)         ### Vert Left
            VR = (vert + rad)   ### Vert Right

            ###-------------------
            ### OLD Rect Corners
            
                oHorz  = arrayCol[i][2]   
                oVert  = arrayCol[i][3]  
                oRad   = arrayCol[i][4] 
                
            oHT = (oHorz)           ### Old Horz Top
            oHB = (oHorz + oRad)    ### Old Horz Bottom             
            oVL = (oVert)           ### Old Vert Left
            oVR = (oVert + oRad)    ### Old Vert Right  


            ###------------------------------------------------------------------------                     
            ### Rectangle Collision -- Any Corner -- Inside Each Other -- New and Old
            
            H1 = 0  ### HorzTop
            H2 = 0  ### HorzBottm
            V1 = 0  ### VertTop
            V2 = 0  ### VertBottom

            if     ( ((oHT <= HT ) and (HT <= oHB )) or ((HT <= oHT ) and (oHT <= HB )) ) H1 = 1  ok  ### HorzTop
            if     ( ((oHT <= HB ) and (HB <= oHB )) or ((HT <= oHB ) and (oHB <= HB )) ) H2 = 1  ok  ### HorzBottom

            if     ( ((oVL <= VL ) and (VL <= oVR )) or ((VL <= oVL ) and (oVL <= VR )) ) V1 = 1  ok  ### VertLeft          
            if     ( ((oVL <= VR ) and (VR <= oVR )) or ((VL <= oVR ) and (oVR <= VR )) ) V2 = 1  ok  ### VertRight

            ###     TopLeft          BottomLeft     TopRight       BottomRight
            if  ( ( H1 and V1 ) or ( H2 and V1) or (H1 and V2) or (H2 and V2) )
             
                Overlap = 1
                ### See "NEW-1: "+ i +" "+ HT +"-"+ HB +" "+ VL +"-"+ VR +" OLD: "+ oHT +"-"+ oHB +" "+ oVL +"-"+ oVR +" "+ H1 + H2 +" "+ V1 + V2   +nl
                
                return 1
            else
                Overlap = 0
                ### See "NEW-0: "+ i +" "+ HT +"-"+ HB +" "+ VL +"-"+ VR +" OLD: "+ oHT +"-"+ oHB +" "+ oVL +"-"+ oVR +" "+ H1 + H2 +" "+ V1 + V2    +nl
            ok
        ok
    next
    
return 2    

###----------------------------  

Func WhereAreWe

        ### horzSize   = 400                      ### Geometry size
        ### vertSize   = 400    
        
        Rec = win1.framegeometry()

        WinWidth  = Rec.width()             ### 1000 Current Values
        WinHeight = Rec.height()            ### 750
        
        WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
        WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title
        WinRight  = Rec.right()
        WinBottom = Rec.bottom()

        BoxWidth  = WinWidth  -50           ###  End   corner   Label1 Box Size
        BoxHeight = WinHeight -100          ###  End   corner

        win1{ setwindowtitle("Window ReSize: Win " +  WinWidth + "x" + WinHeight + " --- Box " + BoxWidth  + "x" + BoxHeight  +
                              " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom      ) }

        ### New Label box Size
        horzSize =  BoxWidth
        vertSize =  BoxHeight
        

    
        
        label1.setgeometry( BoxLeft, BoxTop,  horzSize, vertSize )

return

###---------------------------
       
