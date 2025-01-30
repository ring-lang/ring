### Triangle Calculator and Visual
### Triangle Draw Calculated Parameters
### Bert Mariani  2024-12-30
### -------------------------------------------------


load "stdlibcore.ring"
load "lightguilib.ring"
load "TriangleLibrary.ring"

//--------------------------------------------------------------
// aTri = TriangleAAS(35,62, 7)  Angle Angle Side  aA,aC,sC  TWO Agnles and a Side NOT BETWEEN
// aTri = TriangleASA(76, 9,34)  Angle Side  Angle aA,sC,aB  TWO Angles and ONE Side BETWEEN
// aTri = TriangleSAS( 5,49, 7)  Side  Angle Side  sb,aA,sC  TWO Sides and ONE Angle BETWEEN
// aTri = TriangleSSA( 8,13,31)  Side  Side  Angle sb,sC,aB  TWO Sides and ONE angle NOT BETWEEN
// aTri = TriangleSSS( 8, 6, 7)  Side  Side  Side  sA,sB,sC  THREE Sides Find the MISSING ANGLES
// aTri = TriangleAAA(45,55,80,120)  Angle Angle Angle Side  aA,aB,aC,sC  THREE ANGLES + side-C to Scale
//        TrianglePrintData(aAngleSide)                      Print Data Array Return
//        TriangleAAA()                                      THREE Angles and ZERO Sides can NOT be Solved 
//-------------------------------------------------


//================================================
decimals(2)  // 4
PI         = 3.14159265
ImageScale = 1

xPos    = 100   ### Canvas position on Screen
yPos    = 25
xWidth  = 1800  ### Canvas size on Screen
yHeight = 1000  
  
// Need to define variable when using Func StartApp()
MonaLisa = null 
daVinci  = null 
Canvas   = null
myApp    = null


eScale = 5 ;     // Scale the Triage Size

aTri = list(32)


###-------------------------------
### Define Colours, Pens, Brushes

colorGreen   = new qcolor() { setrgb(000,255,000,128) }  ### faint
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ###  64 faint  line
colorWhite2  = new qcolor() { setrgb(255,255,255,255) }  ### 255 bright line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  ### 64 faint line, plave
colorAqua    = new qcolor() { setrgb(000,255,255,255) }  ### 255 full

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(2) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(1) }  //
penYellow   = new qpen() { setcolor(colorYellow)  setwidth(1) } 
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(1) }
penWhite2   = new qpen() { setcolor(colorWhite2)  setwidth(1) }  //
penBlack    = new qpen() { setcolor(colorBlack)   setwidth(1) }
penGray     = new qpen() { setcolor(colorGray)    setwidth(1) }
penMagenta  = new qpen() { setcolor(colorMagenta) setwidth(1) }
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
        setWindowTitle("Triangle Calculator and Draw ")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size

        Canvas = new qlabel(win)
        {
            ### daVinci Paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)
            
            daVinci = new qpainter()
            {
               begin(MonaLisa)                       ### Canvas: xWidth=1800  yHeight=1000  
               translate(xWidth/3 , yHeight/3*2)     ### TRANSLATE CO-ORD x,y 0,0 Maps Center OFFSET  TO 900,500
               //setCompositionMode(26)                ###  THIS is the MAGIC - Erase Old Line when Redrawn
               //endpaint()                           ### This will Stop the Painting   
               
            }

            //================================================
            // IMAGES 
            
            //------------------------------------
            // Splash on Starting
             imageSplash = new qlabel(win)                             
            {
              //image = new qPixMap("Euler_diagram_of_triangle_types.png") 
              //image = new qPixMap("TriangleClouds.png")               
                image = new qPixMap("TriangleOrgami.png")
                
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )  

                xPos = (xWidth  - image.width()  ) / 2  
                yPos = (yHeight - image.height() ) / 2
                
                setGeometry( xPos, yPos, image.Width(), image.Height())   
            }  
            
            //-------------------------------------------------
            // TRIANGLE IMAGE
            imageTriABC = new qlabel(win)                             
            {
                image = new qPixMap("Triangle-ABC.png")                          
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( 2, 40, image.Width(), image.Height())   
            }    

            //-------------------------------
            setPixMap(MonaLisa)   // Draw It
        }  
        
    //=====================================================
    // EXECUTE Triangle Test and Draw
    
        
       //   "Equilateral"  
       //   "Isosceles"    
       //   "RightAngle-B" 
       //   "RightAngle-C" 
       //   "Obtuse-R-1"   
       //   "Obtuse-R-2"   
       //   "Obtuse-L-1"   
	   //   "WideTop-1"
	   //   "WideTop-S"


        comboTriangleType = new QComboBox(win) 
        {
            setgeometry( 2, 2, 95, 20)
            comboList = ["TriangleType","Equilateral","Isosceles","RightAngle-B", 
                         "RightAngle-C","Obtuse-R-1","Obtuse-R-2","Obtuse-L-1","WideTop-1","WideTop-S"
                        ]
            for x in comboList additem(x,0) next                    
        } 
        
        btnTT  = new qPushButton(win) { setGeometry( 100, 2, 110, 20)   
                                        setText("TriangleDraw-Selection")  
                                        setStyleSheet("background-color: aqua")
                                        setClickEvent("TriangleTest()")  
                                      } 

 
//       btnTD  = new qPushButton(win) { setGeometry( 200, 2, 95, 20)   
//                                       setText("Triangle Draw")  
//                                       setStyleSheet("background-color: aqua")
//                                       setClickEvent("TriangleDraw(aTri)")                          
//                                     }        
//                                    
        //--------------------------
        
        //--------------------------------------------------------------
        // aTri = TriangleAAS(35,62, 7)  Angle Angle Side  aA,aC,sC  TWO Agnles and a Side NOT BETWEEN
        // aTri = TriangleASA(76, 9,34)  Angle Side  Angle aA,sC,aB  TWO Angles and ONE Side BETWEEN
        // aTri = TriangleSAS( 5,49, 7)  Side  Angle Side  sb,aA,sC  TWO Sides and ONE Angle BETWEEN
        // aTri = TriangleSSA( 8,13,31)  Side  Side  Angle sb,sC,aB  TWO Sides and ONE angle NOT BETWEEN
        // aTri = TriangleSSS( 8, 6, 7)  Side  Side  Side  sA,sB,sC  THREE Sides Find the MISSING ANGLES
        //        TriangleAAA(30,60,90)  Angle Angle Angle aA,aB,aC  Three Angles, Use Defaut Size-10-sA
        //        TrianglePrintData(aAngleSide)                      Print Data Array Return
        //------------------------------------------------------------------------------------
        
        //------------------------------------------------
        // RADIO BUTTON Selection
        btnTTN  = new qPushButton(win) { setgeometry( 500, 02 , 220, 20)                                           
                                      settext("Show Triangle Fields Needed ==>")                                
                                      setStyleSheet("background-color: aqua")
                                      setClickEvent("TriTypeNeed()") }
                               
        eCheckTriASA  =  new qradiobutton(win)  { setgeometry( 500, 24 , 220, 20) 
                                               settext("Tri-ASA( aA,cS,aB) Side Between ")                                             
                                               setStyleSheet("background-color: lightGray")}

        eCheckTriAAS  =  new qradiobutton(win)  { setgeometry( 500, 46 , 220, 20) 
                                               settext("Tri-AAS( aA,aC,cS) Side NOT Between ")           
                                               setStyleSheet("background-color: lightGray")}        

        eCheckTriSAS  =  new qradiobutton(win)  { setgeometry( 500, 68 , 220, 20) 
                                               settext("Tri-SAS( bS,aA,cS) Angle Between ")       
                                               setStyleSheet("background-color: lightGray")}

        eCheckTriSSA  =  new qradiobutton(win)  { setgeometry( 500, 90 , 220, 20) 
                                               settext("Tri-SSA( bS,cS,aB) Angle NOT Between ")         
                                               setStyleSheet("background-color: lightGray")}

        eCheckTriSSS  =  new qradiobutton(win)  { setgeometry( 500, 112 , 220, 20) 
                                               settext("Tri-SSS( aS,bS,cS) Three Sides ")           
                                               setStyleSheet("background-color: lightGray")
											   setChecked(true) }

        eCheckTriAAA  =  new qradiobutton(win)  { setgeometry( 500, 134 , 220, 20) 
                                               settext("Tri-AAA( aA,aB,aC,sC) Three Angles + Size")           
                                               setStyleSheet("background-color: lightGray")}
											   
                                    

        //---------------------------------------------------------------       

        lEnterABC =  new qLabel(win)  { setgeometry( 740, 02 , 55, 20)  
                                        settext("-EnterValue-")  
                                        setStyleSheet("background-color: yellow")}
        
        lAngleABC =  new qLabel(win)  { setgeometry( 740, 22 , 55, 20)  
                                        settext("  -Angle-")  
                                        setStyleSheet("background-color: yellow")}
        
        lSideABC  =  new qLabel(win)  { setgeometry( 740, 44 , 55, 20)  
                                        settext("  -Side-")   
                                        setStyleSheet("background-color: yellow")}        

        //-----------------
        // Angles - USER SPECIFIED Required
        
        lAngleA  =  new qLabel(win)   { setgeometry( 800,  2 , 50, 20)  settext("  -A-")  setStyleSheet("background-color: yellow")}
        eAngleA  =  new qlineedit(win){ setgeometry( 800, 24 , 50, 20)  settext("45") }
                                      
        lAngleB  =  new qLabel(win)   { setgeometry( 855,  2 , 50, 20)  settext("  -B")  setStyleSheet("background-color: yellow")}
        eAngleB  =  new qlineedit(win){ setgeometry( 855, 24 , 50, 20)  settext("55") }
                                      
        lAngleC  =  new qLabel(win)   { setgeometry( 910,  2 , 50, 20)  settext("  -C")  setStyleSheet("background-color: yellow")}
        eAngleC  =  new qlineedit(win){ setgeometry( 910, 24 , 50, 20)  settext("80") }      

        //-----------------
        // Sides USER
        
        eSideA  =  new qlineedit(win) { setgeometry( 800, 46 , 50, 20)  settext("60") }
        eSideB  =  new qlineedit(win) { setgeometry( 855, 46 , 50, 20)  settext("100") }
        eSideC  =  new qlineedit(win) { setgeometry( 910, 46 , 50, 20)  settext("80") }   

		
    
        //---------------------------------------------- 
        // MESSAGE      
        lSizeAngleSide  =  new qLabel(win)    { setgeometry( 740, 68 , 55, 20)  settext("  -Msg-")  setStyleSheet("background-color: yellow")}
        eSizeAngleSide  =  new qlineedit(win) { setgeometry( 800, 68 , 160, 20)  settext("Msg") }  
		
		//---------------------------------------------
		// USER Triangle Draw
        btnUTD  = new qPushButton(win) { setGeometry( 970, 2, 110, 20)   
                                        setText("USER Triangle Draw")  
                                        setStyleSheet("background-color: aqua")
                                        setClickEvent("UserTriangleDraw(aTri)")                          
                                      }		
        
        //----------------------------------------------  
        //-----------------------------
        
        lDisplayRadius  =  new qLabel(win)     { setgeometry( 320, 2 , 80, 20) settext(" - Display More")           
                               setStyleSheet("background-color: yellow")}   
    
        eCheckInRadius  =  new qCheckBox(win)  { setgeometry( 320, 24 , 80, 20) settext("InRadius")           
                               setStyleSheet("background-color: lightGray")}
                              
        eCheckOutRadius =  new qCheckBox(win)  { setgeometry( 320, 46 , 80, 20) settext("OutRadius")           
                               setStyleSheet("background-color: lightGray")}                              


        eCheckHeight    =  new qCheckBox(win)  { setgeometry( 320, 68 , 80, 20) settext("Height")           
                               setStyleSheet("background-color: lightGray")}                              
 
        eCheckMeridian  =  new qCheckBox(win)  { setgeometry( 320, 90 , 80, 20) settext("Meridian")           
                               setStyleSheet("background-color: lightGray")}

                              
        eCheckBiSector  =  new qCheckBox(win)  { setgeometry( 320, 112 , 80, 20) settext("BiSector")           
                               setStyleSheet("background-color: lightGray")}    
                               
        //----------------------------------------------
        
        lScale  =  new qLabel(win)   { setgeometry( 420,  2 , 50, 20)  settext(" - Scale ")  setStyleSheet("background-color: yellow")}
        eScale  =  new qlineedit(win){ setgeometry( 420, 22 , 50, 20)  settext("5") }                              
                               
        //------------------------- 
        //==============================================
        ###===================================   
         

//----------------------------------------------------------------                                                                  
      show()
          
    }
    exec()
 }

return

###==============================================================
###==============================================================



Func TriangleTest()

    See "TriangleTest()"+nl

    //------------------------------------
    // USER VALUES -- READ for Angles and Side 
    // MAKE SURE its NUMERIC
    
    aA = 0+ eAngleA.text()   // Angles text to Number
    aB = 0+ eAngleB.text()
    aC = 0+ eAngleC.text()
    
    sA = 0+ eSideA.text()    // Sides  text to Number
    sB = 0+ eSideB.text()
    sC = 0+ eSideC.text()  
    
    //See "Tri-ConvertToNbr: ANGLES: "+ aA +" "+ aB +" "+ aC  +" SIDES: " + sA +" "+ sB +" "+ sC +nl
    
    //-------------------------------------
    // TRIANGLE TESTING - Select Triangle Type
       
    TriSelect  = comboTriangleType.currentText()
        See "TriSelect: "+ TriSelect +nl
    

        if TriSelect = "Equilateral"   sA=60  sB=60   sC=60     ok
        if TriSelect = "Isosceles"     sA=100 sB=100  sC=50     ok
        if TriSelect = "RightAngle-B"  sA=60  sB=100  sC=80     ok
        if TriSelect = "RightAngle-C"  sA=80  sB=60   sC=100    ok
        if TriSelect = "Obtuse-R-1"    sA=50  sB=100  sC=70     ok
        if TriSelect = "Obtuse-R-2"    sA=70  sB=110  sC=50     ok
        if TriSelect = "Obtuse-L-1"    sA=140 sB=60   sC=100    ok
		if TriSelect = "WideTop-1"     sA=80  sB=90   sC=140    ok
		if TriSelect = "WideTop-S"     sA=90  sB=100  sC=120    ok
        
        See   "Values Selected: ("+sA +","+sB +","+sC +")" +nl 
        
    //------------------------------------------------------
    // TEST -USE THESE SIDE Values   TriangleSSS(sA,sB,sC)
    
        TriMsg = " "                            // Clear Error Msg
        eSizeAngleSide.setText(TriMsg)          // Fill in MSG from Tri-Lib into EditBox    
    
    aTRI = TriangleSSS( sA, sB, sC)         // <<<=== CALL

        if aTri = 1                             // Check Returned ERROR
           eSizeAngleSide.setText(TriMsg)       // TriMsg from TriLibrary checks for ZERO
           return
        ok
    
    
    // TriangleShowData(aTri)        // <<<=== Data array in Console
	
    DisplayWidgetTable(aTri)        // <<<=== Data array in Table
	TriangleDraw(aTri)              // <<<=== Draw the CAlculated Lines and Angle
    
       
Return  

###==========================================================================
// Draw Triangle - CAlled bt TriangleTest()

Func TriangleDraw(aTri)  



    imageSplash.setGeometry( -900, -900, image.Width(), image.Height()) // Move it OFF Screen

    if aTri = 1    // Error from TriMsg  in TriangleLibrary
       Return
    ok

    See "TriangleDraw() "+nl

    ClearImages()

    Scale = eScale.text()               // From Display Entry

    See "TriangleDraw: Vertex: A:"+ aAngleSide[7]+"-"+aAngleSide[8] +
                             " B:"+ aAngleSide[9]+"-"+aAngleSide[10] +
                             " C:"+ aAngleSide[11]+"-"+aAngleSide[12]  +nl

    pAx =  Scale * aAngleSide[7]        // Vertex A
    pAy =  Scale * aAngleSide[8]  
      
    pBx =  Scale * aAngleSide[9]        // Vertex B  
    pBy =  Scale * aAngleSide[10]    
      
    pCx =  Scale * aAngleSide[11]       // Vertex C
    pCy =  Scale * aAngleSide[12]       



    //---------------------------------------
    // Draw Axis
//    daVinci.setPen(penWhite)
//    daVinci.drawLine(-1000,   0, 1000,   0)         // Horz Axis Left to Right
//    daVinci.drawLine(   0,-800,   0, 800)         // Vert Axis Top to Bottom  
    
    //---------------------------------------
    // Draw Grid
    daVinci.setPen(penWhite)
    
    for i = -1000 to 1000 Step (10 * Scale)                          
       daVinci.drawLine(  i,  -1000,   i, 1000)     // Vert Axis Top  to Bottom
       daVinci.drawLine( -1000,   i, 1000,   i)    // Horz Axis Left to Right  
    next
    
    //----------------------------------------
    // Draw Triangle 
    daVinci.setPen(penYellow)       
    daVinci.drawLine( pAx, -pAy,  pBx, -pBy )     // FLIP Y ... Point A ->B - C
    daVinci.drawLine( pBx, -pBy,  pCx, -pCy )     // Paper and Screen are Opposite
    daVinci.drawLine( pCx, -pCy,  pAx, -pAy )   
   
    //---------------------------------------
   
    DrawCheckBoxValues(aTri)            // FILL IN the Values Calculated
   
    Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
    MyApp.ProcessEvents()               ### <<< EXEC the Draw
    

    
return 

###==========================================================================

##==============================================================
###==============================================================   
// Show Triangle Data - Array 28
//

Func TriangleShowData(aTri)


   See "TriangleShowData:() "+nl
   
   for i = 1 to len(aTri)
      See "i: "+i +"  "+ aTri[i] +nl
   next


return 



//=====================================================
// USER SPECIFIED Triangle Draw

Func UserTriangleDraw(aTri)

    //------------------------------------
    // USER VALUES -- READ for Angles and Side 
    // MAKE SURE its NUMERIC
    
    aA = 0+ eAngleA.text()   // Angles text to Number
    aB = 0+ eAngleB.text()
    aC = 0+ eAngleC.text()
    
    sA = 0+ eSideA.text()    // Sides  text to Number
    sB = 0+ eSideB.text()
    sC = 0+ eSideC.text()  
    
    
    GoUserTriangle(aA,aB,aC,sA,sB,sC) 
     

Return

//=====================================================
// USER Triangle Specified 1 of 6
// Text-Values were Converted to Numeber by  TriangleTest()


Func GoUserTriangle(aA,aB,aC,sA,sB,sC)

    BlankMsg = " "                            // Clear Error Msg
    eSizeAngleSide.setText(BlankMsg)          // Fill in MSG from Tri-Lib into EditBox  

    if eCheckTriASA.isChecked() = 1   aTri = TriangleASA(aA,sC,aB)  ok            
    if eCheckTriAAS.isChecked() = 1   aTri = TriangleAAS(aA,aC,sC)  ok            
    if eCheckTriSAS.isChecked() = 1   aTri = TriangleSAS(sB,aA,sC)  ok            
    if eCheckTriSSA.isChecked() = 1   aTri = TriangleSSA(sB,sC,aB)  ok           
    if eCheckTriSSS.isChecked() = 1   aTRI = TriangleSSS(sA,sB,sC)  ok 
    if eCheckTriAAA.isChecked() = 1   aTRI = TriangleAAA(aA,aB,aC,sC)  ok 

    if aTri = 1                             // Check Returned ERROR
       eSizeAngleSide.setText(TriMsg)       // TriMsg from TriLibrary checks for ZERO
       return
    ok
    
    
    TriangleShowData(aTri)        // <<<=== Data array in Console
    DisplayWidgetTable(aTri)      // <<<=== Data array in Table 
	
	TriangleDraw(aTri)

Return

//=====================================================
//=====================================================
// Which Lines, Radius, Circles to DRAW

Func DrawCheckBoxValues(aTri)

    if aTri = 1    // Error from TriMsg  in TriangleLibrary
       Return
    ok
    
    //-------------------------------------
    
    if (eCheckInRadius.isChecked() = 1  )
        DrawInRadius(aTri)  
    ok  

    if (eCheckOutRadius.isChecked() = 1 )
        DrawOutRadius(aTri)
    ok

    if (eCheckHeight.isChecked() = 1 ) 
        DrawHeight(aTri)
    ok

    if (eCheckMeridian.isChecked() = 1 )
        DrawMeridian(aTri)
    ok
                
    if (eCheckBiSector.isChecked() = 1 )
        DrawBiSector(aTri)
    ok 
Return

//=====================================================
// Which Triangle Type Selected to Calc and Draw
//  eCheckTriASA


Func TriTypeNeed()

    if aTri = 1    // Error From TriMsg in TriangleLibrary
       Return
    ok


    //---------------------------------------------
    // Boxes to White
    eAngleA.setStyleSheet("background-color: white")    //-------------------
    eAngleB.setStyleSheet("background-color: white")    // Tri-AAS( aA,aC,sC 
    eAngleC.setStyleSheet("background-color: white")    // Tri-ASA( aA,sC,aB 
    eSideA.setStyleSheet( "background-color: white")    // Tri-SAS( sb,aA,sC 
    eSideB.setStyleSheet( "background-color: white")    // Tri-SSA( sb,sC,aB 
    eSideC.setStyleSheet( "background-color: white")    // Tri-SSS( sA,sB,sC  Tri-AAA( aA,aB,aC  
                                                        // 
    //----------------------------------                                                    
                                                                          
    if (eCheckTriAAS.isChecked() = 1  )                 // Tri-AAS( aA,aC,sC 
        eAngleA.setStyleSheet("background-color: aqua")
        eAngleC.setStyleSheet("background-color: aqua")
        eSideC.setStyleSheet( "background-color: aqua") 
    ok  

    if (eCheckTriASA.isChecked() = 1 )                  // Tri-ASA( aA,sC,aB 
        eAngleA.setStyleSheet("background-color: aqua")
        eSideC.setStyleSheet(" background-color: aqua")
        eAngleB.setStyleSheet("background-color: aqua")
    ok

    if (eCheckTriSAS.isChecked() = 1 )                  // Tri-SAS( sb,aA,sC
        eSideB.setStyleSheet( "background-color: aqua") 
        eAngleA.setStyleSheet("background-color: aqua")
        eSideC.setStyleSheet( "background-color: aqua") 
    ok

    if (eCheckTriSSA.isChecked() = 1 )                  // Tri-SSA( sb,sC,aB
        eSideB.setStyleSheet( "background-color: aqua")
        eSideC.setStyleSheet( "background-color: aqua")     
        eAngleB.setStyleSheet("background-color: aqua")
    ok
                
    if (eCheckTriSSS.isChecked() = 1 )                  // Tri-SSS( sA,sB,sC
        eSideA.setStyleSheet( "background-color: aqua")
        eSideB.setStyleSheet( "background-color: aqua")
        eSideC.setStyleSheet( "background-color: aqua")         
    ok 
    
    if (eCheckTriAAA.isChecked() = 1 )                  // Tri-SSS( sA,sB,sC
        eAngleA.setStyleSheet( "background-color: aqua")
        eAngleB.setStyleSheet( "background-color: aqua")
        eAngleC.setStyleSheet( "background-color: aqua")   
        eSideC.setStyleSheet(  "background-color: aqua") 		
    ok  

    
Return

//=============================================================

    


###==========================================================================

###==========================================================================
// Clear Images
Func  ClearImages()

     See "ClearImages() "+nl
     
        MonaLisa.fill(colorBlack)           // ===<<< BLANK OUT OLD IMAGE !!!
        Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
        MyApp.ProcessEvents()               ### <<< EXEC the Draw
        
return

###==========================================================================
###==========================================================================


Func DisplayWidgetTable(aTri)

    See "DisplayWidgetTable(aTri) " +nl

        
    ###--------------------------------
    ### QWidgetTable
    ###--------------------------------
    
    Table1 = new qTableWidget(win) 
    {
        setrowcount(14) setcolumncount(4)    // <<<=== TABLE X-Y Siz
        setGeometry(2,204,380,460)
        setselectionbehavior(QAbstractItemView_SelectRows)
        setSelectionMode(QAbstractItemView_SelectItems) 

        //-----------------------
        // Append TITLES
        
        myCols = new qStringList() 
        {
                append("PARAMETER")    // TopLabel PARAMETER COL 1
                append("Value-A")      // TopLabel Value-A   COL 2
                append("Value-B")      // TopLabel Value-B   COL 3
                append("Value-C")      // TopLabel Value-C   COL 4
                append(" ")            // TopLabel           COL 5
                append(" ")            // TopLabel           COL 6
        }
        
        //---------------------------
        
        SetColumnWidth(0,100)    
        SetColumnWidth(1,80)   
        SetColumnWidth(2,80)    
        SetColumnWidth(3,80)    
        SetColumnWidth(4,80)    
        SetColumnWidth(5,80)   
        SetColumnWidth(6,80)    
        SetColumnWidth(7,80)        
        
        //--------------------------
        // Fill R-C in Cells Vert-Horz
                
        for x = 1 to 11             // Vert
            for y = 1 to 5          // Horz
                item1 = new qtablewidgetitem("R"+X+"-C"+Y)
                setitem(x-1,y-1,item1) 
            next
        next
        
        //---------------------------------------
        // Fill TABLE Cells with aTri[] Values
            
        item1 = new qtablewidgetitem("Angles-A,B,C")     setitem( 0, 0, item1)
        item1 = new qtablewidgetitem("aA: "+aTri[1])         setitem( 0, 1, item1)
        item1 = new qtablewidgetitem("aB: "+aTri[2])         setitem( 0, 2, item1)
        item1 = new qtablewidgetitem("aC: "+aTri[3])         setitem( 0, 3, item1)      

        item1 = new qtablewidgetitem("Sides-A,B,C")      setitem( 1, 0, item1)
        item1 = new qtablewidgetitem("sA: "+aTri[4])         setitem( 1, 1, item1)
        item1 = new qtablewidgetitem("sB: "+aTri[5])         setitem( 1, 2, item1)
        item1 = new qtablewidgetitem("sC:"+aTri[6])          setitem( 1, 3, item1)          

        item1 = new qtablewidgetitem("Vertex-A(x,y)")    setitem( 2, 0, item1)
        item1 = new qtablewidgetitem("x: "+aTri[7])         setitem( 2, 1, item1)
        item1 = new qtablewidgetitem("y: "+aTri[8])         setitem( 2, 2, item1)
        item1 = new qtablewidgetitem(" ")                   setitem( 2, 3, item1)  
        
        
        item1 = new qtablewidgetitem("Vertex-B(x,y)")    setitem( 3, 0, item1)
        item1 = new qtablewidgetitem("x: "+aTri[9])         setitem( 3, 1, item1)
        item1 = new qtablewidgetitem("y: "+aTri[10])        setitem( 3, 2, item1)
        item1 = new qtablewidgetitem(" ")                   setitem( 3, 3, item1)      

        item1 = new qtablewidgetitem("Vertex-C(x,y)")    setitem( 4, 0, item1)
        item1 = new qtablewidgetitem("x: "+aTri[11])        setitem( 4, 1, item1)
        item1 = new qtablewidgetitem("y: "+aTri[12])        setitem( 4, 2, item1)
        item1 = new qtablewidgetitem(" ")                   setitem( 4, 3, item1)          

        item1 = new qtablewidgetitem("Area,Peri,S")      setitem( 5, 0, item1)
        item1 = new qtablewidgetitem("A: "+aTri[13])        setitem( 5, 1, item1)
        item1 = new qtablewidgetitem("P: "+aTri[14])        setitem( 5, 2, item1)
        item1 = new qtablewidgetitem("S: "+aTri[15])        setitem( 5, 3, item1)      
        

        item1 = new qtablewidgetitem("Height-A,B,C")     setitem( 6, 0, item1)
        item1 = new qtablewidgetitem("a: "+aTri[16])        setitem( 6, 1, item1)
        item1 = new qtablewidgetitem("b: "+aTri[17])        setitem( 6, 2, item1)
        item1 = new qtablewidgetitem("c: "+aTri[18])        setitem( 6, 3, item1)      
        

        item1 = new qtablewidgetitem("Median-A,B,C")     setitem( 7, 0, item1)
        item1 = new qtablewidgetitem("a: "+aTri[19])        setitem( 7, 1, item1)
        item1 = new qtablewidgetitem("b: "+aTri[20])        setitem( 7, 2, item1)
        item1 = new qtablewidgetitem("c: "+aTri[21])        setitem( 7, 3, item1)      
 
        item1 = new qtablewidgetitem("BiSector-A,B,C")   setitem( 8, 0, item1)
        item1 = new qtablewidgetitem("a: "+aTri[22])        setitem( 8, 1, item1)
        item1 = new qtablewidgetitem("b: "+aTri[23])        setitem( 8, 2, item1)
        item1 = new qtablewidgetitem("c: "+aTri[24])        setitem( 8, 3, item1)  

        //--------------------------
        
        item1 = new qtablewidgetitem("InRadius")         setitem( 9, 0, item1)   
        item1 = new qtablewidgetitem("iR: "+aTri[25])       setitem( 9, 1, item1) // iR
        item1 = new qtablewidgetitem(" ")                   setitem( 9, 2, item1)
        item1 = new qtablewidgetitem(" ")                   setitem( 9, 3, item1)      

        item1 = new qtablewidgetitem("InCircle-X,Y")     setitem(10, 0, item1)
        item1 = new qtablewidgetitem("x: "+aTri[27])        setitem(10, 1, item1)  // Co-Ord iR
        item1 = new qtablewidgetitem("y: "+aTri[28])        setitem(10, 2, item1)
        item1 = new qtablewidgetitem(" ")                   setitem(10, 3, item1)      
        
        //---------------------------
        
        item1 = new qtablewidgetitem("OutRadius")        setitem(11, 0, item1)
        item1 = new qtablewidgetitem("cR: "+aTri[26])       setitem(11, 1, item1)  // cR
        item1 = new qtablewidgetitem(" ")                   setitem(11, 2, item1)  // AP 
        item1 = new qtablewidgetitem(" ")                   setitem(11, 3, item1)

        item1 = new qtablewidgetitem("CircumCircle-XY")  setitem(12, 0, item1)
        item1 = new qtablewidgetitem("x: "+aTri[29])        setitem(12, 1, item1)  // Co-Ord cR
        item1 = new qtablewidgetitem("y: "+aTri[30])        setitem(12, 2, item1)
        item1 = new qtablewidgetitem(" ")                   setitem(12, 3, item1)  // 31 = AP
        
                                
        //----------------------------          
                    
        setHorizontalHeaderLabels(myCols)
        setAlternatingRowColors(true)
            
        setStyleSheet("QHeaderView::section { background-color: yellow }")
           
        horizontalHeader().setStyleSheet("color: blue")
          verticalHeader().setStyleSheet("color: red")          
            
        show() // NEEDED to Display Table after it is Populated
    
    }
return
        
//=====================================================
//=====================================================
// 60,100,80 
// Radius 20 Inscribed Circle Center [60,20]

Func DrawInRadius(aTri) 

    daVinci.setpen(penRed)       

    Scale = eScale.text()
    
    See "Circle iR: "+aTri[25] +" x:"+aTri[27] +" y:"+aTri[28] +nl

    iR =  (aTri[25]) * Scale      // Inner Circle Radius 
    OX =  (aTri[27]) * Scale      // Inner Circle Center P(x,y)
    OY =  (aTri[28]) * Scale       

     
    pX  = OX // - (iR/2)
    pY  = OY // + (iR/2)   
       
    daVinci.DrawPoint( pX, -pY)
    DrawCircle( pX, -pY, iR)
           
Return

//====================================================
//====================================================
// 60,100,80 
// OurRadius 50   CircumScribedCircle Center [40,30]

Func DrawOutRadius(aTri)

    Scale = eScale.text()
    
    See "Circle cR: "+aTri[26] +" x:"+aTri[29] +" y:"+aTri[30] +nl
 
    cR  =  (aTri[26]) * Scale      // Outer Circle Radius 
    OX  =  (aTri[29]) * Scale      // Outer Circle Center P(x,y)
    OY  =  (aTri[30]) * Scale      // 

    pX  = OX                      // Offset the TopLeft Corner od Square that Circle is in.
    pY  = OY                      // Offset for Circle Center actually needed
    
    daVinci.setpen(penRed)
    daVinci.DrawPoint( pX, -pY)
    
    daVinci.setpen(penGreen)
    DrawCircle( pX, -pY, cR)

Return

//====================================================
//====================================================   
// HEIGHT -- Draw Perpindicular Line from Vertex to Othe Side

Func DrawHeight(aTri)


    Scale = eScale.text()

    aA =  aTri[1]               // Angles
    aB =  aTri[2]  
    aC =  aTri[3]

    hA =  Scale * aTri[16]      // Height
    hB =  Scale * aTri[17] 
    hC =  Scale * aTri[18]  
         
    sA =  Scale * aTri[4]       // Sides
    sB =  Scale * aTri[5]  
    sC =  Scale * aTri[6]  
             
    VAx = Scale * aTri[7]       // Vertex - Co-Ordinates
    VAy = Scale * aTri[8]  
             
    VBx = Scale * aTri[9]  
    VBy = Scale * aTri[10] 
             
    VCx = Scale * aTri[11] 
    VCy = Scale * aTri[12]  

   
    //===========================================
	// From Vertex-C
	
    pointX = VCx                        // Match X to Vertex C - Height
    pointY = VAy                        // Match Y to Base Line C at 0 (VAy or VBy)

    daVinci.setPen(penBlue)	
    daVinci.DrawLine(  VCx, -VCy, pointX, -pointY )
	
	

    //============================================
    // From Vertex-B 

    aTriH = TriangleAAS( aA, 90, sC)  // <<<== CALL sameA 90 sameC	 
			  
    NAx =  aTriH[7]  
    NAy =  aTriH[8]  
				  
    NBx =  aTriH[9]  
    NBy =  aTriH[10] 
				  
    NCx =  aTriH[11] 
    NCy =  aTriH[12] 

    daVinci.setPen(penBlue)
    daVinci.DrawLine( VBx, -VBy, NCx, -NCy  )  	
	
    //===========================================
	// From Vertex A  Isosceles: a:48 b:48 c:97
	// aTriH = TriangleAAA(  (90-aB), aB, 90, sC)  // Height = 90deg, aA = complenment aB

    aTriH = TriangleAAA( (90-aB), aB, 90, sC)  // <<<== CALL height, same sC same aB


    NAx =  aTriH[7]  
    NAy =  aTriH[8]  
				  
    NBx =  aTriH[9]  
    NBy =  aTriH[10] 
				  
    NCx =  aTriH[11] 
    NCy =  aTriH[12]
	
	//-------
	
    NaA =  aTriH[1]       // Angles
    NaB =  aTriH[2]  
    NaC =  aTriH[3]
	
    NhA =  aTriH[16]      // Height
    NhB =  aTriH[17] 
    NhC =  aTriH[18]  
			  
    NsA =  aTriH[4]       // Sides
    NsB =  aTriH[5]  
    NsC =  aTriH[6] 

    //--------------
	// TriangleDraw: Vertex: A:0-0 B:60-0 C:30-52
	// CoOrd: NAx:0 0 NBx:300 0 NCx:75 130
	// Angle: NaA:60 NaB:30 NaC:90
	// Sides: NsA:260 NsB:150 NsC:300	
	
	NewPx = VBx - NCx
	NewPy = VBy + NCy
	
    daVinci.setPen(penBlue)
    daVinci.DrawLine(  VAx, -VAy, NCx, -NCy  ) 
	
    //daVinci.DrawLine(  VAx, -VAy, NewPx, -NewPy  )
	
	//---------------------------------------
	// Use as Visual to see NsB Lenght
	// daVinci.setPen(penWhite2)
	// daVinci.DrawLine(NAx, NAy, NBx, NBy)  // Use as Visual to see NsB Lenght
	// daVinci.DrawLine(NBx, NBy, NCx, NCy)
	// daVinci.DrawLine(NCx, NCy, NAx, NAy)	


	// See "CoOrd: NAx:"+NAx +" "+NAy +" NBx:"+NBx +" "+NBy +" NCx:"+NCx +" "+NCy +nl
	// See "Angle: NaA:"+NaA +" NaB:"+NaB +" NaC:"+NaC +nl
	// See "Sides: NsA:"+NsA +" NsB:"+NsB +" NsC:"+NsC +nl
	

Return

//====================================================
//====================================================  
// MERIDIAN - Draw from Vertex to 1/2 of SIDE
 
Func DrawMeridian(aTri)

   daVinci.setPen(penRed) 
   Scale = eScale.text()

   mA =  Scale * aTri[19]      // Median
   mB =  Scale * aTri[20] 
   mC =  Scale * aTri[21]  

   sA =  Scale * aTri[4]        // Sides
   sB =  Scale * aTri[5]  
   sC =  Scale * aTri[6]  
                 
   VAx = Scale * aTri[7]       // Vertex - Co-Ordinates
   VAy = Scale * aTri[8]  
                 
   VBx = Scale * aTri[9]  
   VBy = Scale * aTri[10] 
                 
   VCx = Scale * aTri[11] 
   VCy = Scale * aTri[12]   
   
   //-------------------------
     
   sCxH = (VBx  -  VAx)       / 2             // Half way only Side C
   sCyH = (VBy  -  VAy)       / 2    
       if (VBx  <= VAx)                       // VA=0  VB Neg
           sCxH  =(VAx - VBx) / 2 +VBx        // Add point VBx
       ok
   
                                      
   sBxH = (VCx  -  VAx)       / 2             // Half way only Side B
   sByH = (VCy  -  VAy)       / 2 
       if (VCx  <= VAx)                       // VA=0  VC Neg
           sBxH  =(VAx - VCx) / 2 +VCx        // Add point VCx
       ok   

   sAxH = (VCx  -  VBx)       / 2 +VBx        // Add point VBx
   sAyH = (VCy  -  VBy)       / 2 
       if (VCx  <= VBx)                       // VA=0  VB Neg
           sAxH  =(VBx - VCx) / 2 +VCx        // Add point VCx
       ok
   
   daVinci.DrawLine( VCx, -VCy, sCxH, -sCyH )  // From Vertex to 1/2 Base
   daVinci.DrawLine( VBx, -VBy, sBxH, -sByH )
   daVinci.DrawLine( VAx, -VAy, sAxH, -sAyH )   
   

Return

//====================================================
//====================================================



//====================================================
//==================================================== 
// BISECTOR -- Angles divided by 2
  
Func DrawBiSector(aTri)

   daVinci.setPen(penGreen) 
   Scale = eScale.text()

   tA  =  Scale * aTri[22]       //BiSector Lenght
   tB  =  Scale * aTri[23] 
   tC  =  Scale * aTri[24]   
   
   aA  =  aTri[1]                // Angles
   aB  =  aTri[2] 
   ac  =  aTri[3] 
                 
   sA  =  Scale * aTri[4]        // Sides
   sB  =  Scale * aTri[5]  
   sC  =  Scale * aTri[6]  
                 
   VAx = Scale * aTri[7]         // Vertex - Co-Ordinates
   VAy = Scale * aTri[8]  
                 
   VBx = Scale * aTri[9]  
   VBy = Scale * aTri[10] 
                 
   VCx = Scale * aTri[11] 
   VCy = Scale * aTri[12]   
   
   //-------------------------
   // Bisect the Angles
   
   aA2 = aA / 2
   aB2 = aB / 2
   aC2 = aC / 2
   
    //------------------
	// Angle A

    aTriH = TriangleASA( aA2, sC, aB)  // <<<== CALL 	 
			  
    NAx =  aTriH[7]  
    NAy =  aTriH[8]  
				  
    NBx =  aTriH[9]  
    NBy =  aTriH[10] 
				  
    NCx =  aTriH[11] 
    NCy =  aTriH[12] 

    daVinci.DrawLine( VAx, -VAy, NCx, -NCy  )  
	
	//--------------------
	// Angle B

    aTriH = TriangleASA( aA, sC, aB2)  // <<<== CALL 	 
			  
    NAx =  aTriH[7]  
    NAy =  aTriH[8]  
				  
    NBx =  aTriH[9]  
    NBy =  aTriH[10] 
				  
    NCx =  aTriH[11] 
    NCy =  aTriH[12] 

    daVinci.DrawLine( VBx, -VBy, NCx, -NCy  )
	
	//--------------------
	// Angle C

    aTriH = TriangleASA( aA, sB, aC2)  // <<<== CALL  Rotate +aA for PointB or Lenght of B

    NAx =  aTriH[7]   // Co-Ordinates
    NAy =  aTriH[8]  
				  
    NBx =  aTriH[9]  
    NBy =  aTriH[10] 
				  
    NCx =  aTriH[11] 
    NCy =  aTriH[12] 
	
	NsA =  aTriH[4]   // Sides New
	NsB =  aTriH[5]  
	NsC =  aTriH[6] 	
	
	//---------------------------------------
	// daVinci.DrawLine(NAx, NAy, NBx, NBy)  // Use as Visual to see NsB Lenght
	// daVinci.DrawLine(NBx, NBy, NCx, NCy)
	// daVinci.DrawLine(NCx, NCy, NAx, NAy)	
	
	//---------------------------------------------
	// Because Base-Line-C is on the Y=0 Axis
	// The New-Tri Mirror-Image, the Lenght of New sideB 
	// can be uses of Offset from 0,0 in X-Direction
	
	daVinci.DrawLine( VCx, -VCy, NsB, -NBy ) // Base C is on Y=0, Use New NBy lenght 
	
Return

###=========================================

###-----------------------------------------
### DrawCircle(x,y,radius)
### DrawCirclePoint(x,y,radius,angle
### DrawCircleLine(x,y,radius,angle
###
### See "Sin(15) radians = " + sin(15)            =>    0.65
### See "Sin(15) degree  = " + sin(15 * 3.14/180) =>    0.26


//------------------------------------------
// DrawCircle using Center-X-Y and Radius

Func DrawCircle(x,y,radius)

    HCenter = x
    VCenter = y
    HWidth  = 2 * radius
    VHeight = 2 * radius

    HCorner = HCenter - (HWidth  /2)
    VCorner = VCenter - (VHeight /2)

    daVinci.drawEllipse(HCorner, VCorner, HWidth, VHeight)  // LeftCorner, HWidth, VHeight

return

//------------------------------------------

//====================================================
//====================================================
/*

        
TriangleTest()
TriangleSSS(60,100,80)
TriangleShowData:()
i: 1  36.8699     Angles
i: 2  90.0000
i: 3  53.13

i: 4  60       <<< Sides
i: 5  100      <<<
i: 6  80       <<<

i: 7  0            A CoOrd xy
i: 8  0            
i: 9  80           B
i: 10  0
i: 11  64          C
i: 12  48.0000

i: 13  2400.0000   Area =  1/2(r * p)
i: 14  240         Peri
i: 15  120         Semi-Peri

i: 16  80.0000     A-Height   
i: 17  48.0000     B
i: 18  60.0000     C

https://www.endmemo.com/geometry/triangle.php
https://www.calculator.io/triangle-calculator/
https://www.thinkcalculator.com/planegeometry/ultratriangle.php
https://www.inchcalculator.com/triangle-calculator/

i: 19  85.4400     5k 3k 2k 1? A-Median       
i: 20  50          5k 3k 2k 1? B
i: 21  72.1110     5k 3k 2k 1? C

i: 22  84.3274     3k 2k 1k A BiSector ??
i: 23  48.4873     3k 2k 1?  B
i: 24  67.0820     3k 2k 1?  C

i: 25  20          InnerRadius
i: 26  50.0000     CircumCircleRadius

----------
z                                Vertex CoOrd: A[0, 0] B[80,0] C[80, 60]
i: 27  48          X-Centroid    Centroid                   [53.333, 20]
i: 28  16.0000     Y             Inscribed Circle Center    [60,     20]
                                 CircumScribedCircle Center [40,     30]
i: 29  40          X-CircumCircle
i: 30  13.3333     Y

i: 31  42.1637     CircumCircleRadius=AP - Alt
i: 32  0
DisplayWidgetTable(aTri)


=======================================
=======================================
                         ^ C             A[?,?]
Triangle ABC            / \
AB = c               b /   \ a
AC = b-               /     \
BC = a            A  /_______\ B    B[0,0]     C[0,a]
    

 A[?,?] = ( c^2 +a^2 -b^2 )   +-  sqrt[ c^2 - (c^2 + a^2 -b^2)^2 ]
                / 2a                          / 4a^2


 A[x,?]  = (( c^^2  + a^^2  - b^^2 ) / 2a)
 
 A[?,y]  =  ( c^^2 - ( ((c^^2 + a^^2 - b^^2)^^2) / 4 * (a^^2))  ) ^^(1/2) 
 
 
 ================================
https://www.calculator.io/triangle-calculator/

Meridian
A median to side a is usually denoted as mₐ. 
Similarly, the other two medians are denoted as mb mb  and m꜀. 
We can find the lengths of the medians with the following formula


MA = 1/2 * sqrt ( 2*sb^^2 + 2*sc^^2 - 1*sa^^2 )

==========================
Height

               aA:36.8699   aB:90.0000     aC:53.1301
               sA:300       sB:500         sC:400
               
Call TRI-AAS aAL :36.8699  aCL :90       sCL :400
Call TRI-AAS aAL :36.8699  aCL :90       sCL :400

Retu TRI-AAS sALn:240.0000 sBLn:320.0000 sCLn:320.0000
Retu hB:240  aAn :36.8699  aBn :53.1301  aCn :90

==================





    c
*/
