Load "guilib.ring"

/*
 +--------------------------------------------------------------------------
 +        Program Name : ScreenReSizeMove.ring
 +        Date         : 2016.06.16
 +        Author       : Bert Mariani
 +        Purpose      : Re-Draw Chart after ReSize or move
 +--------------------------------------------------------------------------
*/


###-------------------------------
### DRAW CHART  size 1000 x 1000
###
    
###------------------------------

### Window Size
    WinLeft   = 80                  ### 80    Window position on screen
    WinTop    = 80                  ### 80    Window position on screen
    WinWidth  = 1000                ### 1000  Window Size - Horizontal-X WinWidth
    WinHeight = 750                 ### 750   Window Size - Vertical-Y WinHeight
    WinRight  = WinLeft + WinWidth  ### 1080
    WinBottom = WinTop  + WinHeight ### 830
             
### Label Box Size           
    BoxLeft   = 40                  ###  Start corner   Label1 Box Start Position inside WIN1
    BoxTop    = 40                  ###  Start corner 
    BoxWidth  = WinWidth  -80       ###  End   corner   Label1 Box Size
    BoxHeight = WinHeight -80       ###  End   corner  

###----------------------------    
   

New qapp {
        win1 = new qwidget() {
        
                ### Position and Size of WINDOW on the Screen
                setwindowtitle("DrawChart using QPainter")
                setgeometry( WinLeft, WinTop, WinWidth, WinHeight)
                
                win1{ setwindowtitle("Initial Window Position: " +" L " + WinLeft +" T " + WinTop +" Width" + width() +" Height " +  height() ) }

                ### ReSizeEvent ... Call WhereAreWe function
                myfilter = new qallevents(win1)
                myfilter.setResizeEvent("WhereAreWe()")
                installeventfilter(myfilter)
                
                ### Draw within this BOX
                label1 = new qlabel(win1) {
                        setgeometry(BoxLeft, BoxTop, BoxWidth, BoxHeight)
                        settext("We are Here")
                }

                
                ### Button Position and Size ... Call DRAW function
                new qpushbutton(win1) {
                        setgeometry( 30, 30, 80, 20)
                        settext("Draw")
                        setclickevent("Draw()")
                }

                ###---------------

                show()
        }
        
    exec()
}


###-----------------
### FUNCTION Draw
###-----------------

Func WhereAreWe
        Rec = win1.framegeometry()
    
        WinWidth  = win1.width()            ### 1000 Current Values 
        WinHeight = win1.height()           ### 750 
        
        WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
        WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title 
        WinRight  = Rec.right()
        WinBottom = Rec.bottom()

        BoxWidth  = WinWidth  -80           ### 950
        BoxHeight = WinHeight -80           ### 700

        win1{ setwindowtitle("Window ReSize: Win " +  WinWidth + "x" + WinHeight + " --- Box " + BoxWidth  + "x" + BoxHeight  + 
                              " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom      ) }
        
        See "We Are Here - setResizeEvent - " 
        See " Win "  + WinWidth  + "x" + WinHeight + " --- Box  "  + BoxWidth + "x" + BoxHeight  
        See " --- LT " + Winleft   + "-"   + WinTop    + " --- RB " + WinRight + "-"   + WinBottom +nl
        
          win1.setgeometry( WinLeft, WinTop, WinWidth, WinHeight )
        label1.setgeometry( BoxLeft, BoxTop, BoxWidth, BoxHeight )
        
    
return

Func Draw

        win1{ setwindowtitle("Draw Position: Win " +  WinWidth + "x" + WinHeight + " --- Box " + BoxWidth  + "x" + BoxHeight  + 
                              " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom      ) }
                              
        See "Draw Position: " +  WinWidth + "x" + WinHeight + " --- Box " + BoxWidth  + "x" + BoxHeight  + 
                              " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom  + nl
                              
  
        ###-----------------------------
        ### PEN Colors
        
        p1 = new qpicture()

            colorBlue = new qcolor() { setrgb(0,    0,255,255) }
            penBlue   = new qpen() { setcolor(colorBlue)  setwidth(1) }


        ###-----------------------
        ### PAINT the Chart

        new qpainter() {
                begin(p1)
                setpen(penBlue)

                ###---------------------
                ### Draw Line Chart

                drawline(        1 ,         1 , BoxWidth ,         1 )     ### WinTop line horizontal
                drawline(        1 ,         1 ,        1 , BoxHeight )     ### WinLeft Line vertical
                
                drawline(        1 , BoxHeight , BoxWidth , BoxHeight )     ### Bottom Line horizontal
                drawline( BoxWidth ,         1 , BoxWidth , BoxHeight )     ### WinRight Line vertical
                
                drawline( BoxWidth / 2 ,             1 , BoxWidth / 2 ,   BoxHeight     )    ### Central vertical   
                drawline(            1 , BoxHeight / 2 , BoxWidth     ,   BoxHeight / 2 )    ### Central horizontal

                                      
                ###--------------------------------------------------


                endpaint()
        }
        
        
        label1 { setpicture(p1) show() }
        
return


