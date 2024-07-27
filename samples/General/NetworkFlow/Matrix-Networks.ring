// Netwoks: RoadTraffic, ElectricalNetworks, ChemicalReactions
// Bert Mariani 02024/07/14
 
//--------------------------------------------------------------------
// A network of one-way streets is shown in the accompanying diagram. 
// The rate of flow of cars into intersection A is 500 cars per hour, 
// and 400 and 100 cars per hour emerge from B and C, respectively. 
// Find the possible flows along each street.
//--------------------------------------------------------------------

load "stdlibcore.ring"
load "lightguilib.ring"
Load "MatrixLib.ring"

   
//================================================
decimals(4) 
EN           = 2.71828  // e = Euler's Number
PI           = 3.14159

xPos    = 100   ### Canvas position on Screen
yPos    = 25
xWidth  = 1200  ### Canvas size on Screen
yHeight = 1000  
  
// Need to define variable when using Func StartApp()
MonaLisa = null 
daVinci  = null 
Canvas   = null
myApp    = null

comboShapeType    = null
comboEquationType = 0
ConicEquation     = "Figure"   // DropDown Selection

ImageScale     = 1
PosFigX        = 0 
PosFigY        = 30     // Draw Figure at this Position Top-Left

imageStockP = null      // Figure
imageBlank  = null
imageTF1    = null      
imageTF2    = null
imageTF3    = null
imageEN1    = null
imageEN2    = null
imageEN3    = null
imageEN4    = null
imageCR1    = null
imageCR2    = null
imageCR3    = null

eBox1 = null
eBox2 = null
eBox3 = null
eBox4 = null


###-------------------------------
### Define Colours, Pens, Brushes

colorGreen   = new qcolor() { setrgb(000,255,000,255) }
colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorWhite   = new qcolor() { setrgb(255,255,255,064) }  ### 64 faint line
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  ### Yellow
colorGray    = new qcolor() { setrgb(128,128,128,255) }  ### 
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  ### 64 faint line, plave

penWhiteThin = new qpen() { setcolor(colorWhite)   setwidth(2) }
penGreen     = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed       = new qpen() { setcolor(colorRed)     setwidth(2) }
penBlue      = new qpen() { setcolor(colorBlue)    setwidth(2) }
penWhite     = new qpen() { setcolor(colorWhite)   setwidth(2) }
penYellow    = new qpen() { setcolor(colorYellow)  setwidth(2) }
penGray      = new qpen() { setcolor(colorGray)    setwidth(2) }
penMagenta   = new qpen() { setcolor(colorMagenta) setwidth(2) }
penBlack     = new qpen() { setcolor(colorBlack)   setwidth(2) }

brushSR     = new qbrush() { setstyle(1)  setcolor (colorRed)}      ### Red
brushSG     = new qbrush() { setstyle(1)  setcolor (colorGreen)}    ### Green
brushSB     = new qbrush() { setstyle(1)  setcolor (colorBlue)}     ### Blue
brushSY     = new qbrush() { setstyle(1)  setcolor (colorYellow)}   ### Yellow
brushSGR    = new qbrush() { setstyle(1)  setcolor (colorGray)}     ### 
brushSW     = new qbrush() { setstyle(1)  setcolor (colorWhite)}    ### 
brushSM     = new qbrush() { setstyle(1)  setcolor (colorMagenta)}  ### 

brushE      = new qbrush() { setstyle(0)  setcolor (colorYellow)}   ### Empty

penArray   = [penYellow,  penRed, penBlue, penGreen]
penPointer = 0   // Which color to cycle next to draw figure


//==========================================
//=========================================
// START the APP

Func Main()
     StartApp()
return

//-----------------------------------

Func StartApp()

 myApp = new qApp 
 {
    win = new qWidget()
    {
    
        ###-----------------------------------
        ### Font Type and Size

            oFont = new qfont("Courier",10,0,0)
            setfont(oFont)

        ###-----------------------------------
        
        setWindowTitle("Networks: Traffic-Flow, Electrical, Chemical-Reactions")
        setGeometry(xPos, yPos, xWidth, yHeight)    ### Window Pos and Size


        Canvas = new qlabel(win)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( xWidth, yHeight)

            daVinci = new qpainter()
            {
               begin(MonaLisa)
               translate(xWidth/2 , yHeight/2)     ### TRANSLATE CO-ORD x,y -- 0,0 MAPS TO 300,300
               #endpaint()                         ### This will Stop the Painting   
            }

            setPixMap(MonaLisa)
        }
    
        //-----------------------------------
        
            // Figure - 200x200
            imageStockP = new qlabel(win) 
            {   image = new qPixMap("Blank.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )   // INITAIL STARTING SCREEN
            }
            
            imageBlank = new qlabel(win) 
            {   image = new qPixMap("Blank.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )
            }           
 

            imageTF1 = new qlabel(win) 
            {   image = new qPixMap("TrafficFlow-1.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )
            }
            
            imageTF2 = new qlabel(win) 
            {   image = new qPixMap("TrafficFlow-2.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )
            }               

            imageTF3 = new qlabel(win) 
            {   image = new qPixMap("TrafficFlow-3.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }           


           imageEN1 = new qlabel(win) 
            {   image = new qPixMap("ElectricalNetwork-1.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }           
            
            imageEN2 = new qlabel(win) 
            {   image = new qPixMap("ElectricalNetwork-2.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }           

            imageEN3 = new qlabel(win) 
            {   image = new qPixMap("ElectricalNetwork-3.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }


            imageEN4 = new qlabel(win) 
            {   image = new qPixMap("ElectricalNetwork-4.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }
            
            imageCR1 = new qlabel(win) 
            {   image = new qPixMap("ChemicalReaction-1.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }           

            imageCR2 = new qlabel(win) 
            {   image = new qPixMap("ChemicalReaction-2.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }   

            imageCR3 = new qlabel(win) 
            {   image = new qPixMap("ChemicalReaction-3.png")
                setpixmap( image.scaled(image.width() / ImageScale, image.height() / ImageScale , 0, 0) )   
                setGeometry( -800, -800, image.Width(),image.Height() )             
            }           
              
                      

        //-------------------------------------
        
        comboEquationType = new QComboBox(win) 
        {
            setgeometry( 0, 2, 140, 20)
            comboList = ["NetworkEquations",
                         "--------",
                         "TrafficFlow-1",
                         "TrafficFlow-2",
                         "TrafficFlow-3",
                         "---------",
                         "ElectricalNetwork-1",
                         "ElectricalNetwork-2",
                         "ElectricalNetwork-3",
                         "ElectricalNetwork-4",
                         "--------",
                         "ChemicalReaction-1",                  
                         "ChemicalReaction-2",
                         "ChemicalReaction-3",
                         "--------"    
                        ]
                        
            for x in comboList additem(x,0) next            
        }
        
        btnCS = new qPushButton(win) { setGeometry( 150, 2, 90, 20)  
                    setText("Start/Clear")  
                    setStyleSheet("background-color: aqua")
                    setClickEvent("StartClearScreen()") 
                }
                                        
    
        //-----------------------------------------------------------
        // EQUATION label boxed: Polar, Sine, Cos formats
        //                                          x,   y,   x-l Y-d
        lBox1  =  new qLabel(win)    { setGeometry(520,   2,  80,  20)  
                      setText("Problem:")  
                      setStyleSheet("background-color: yellow")
                  }
                          
        eBox1  = new qlistwidget(win){ setGeometry(590,   2, 600, 200) }  

                
        //-------- 
        lBox2  =  new qLabel(win)    { setGeometry(520, 202,  80,  20)  
                      setText("Format:")    
                      setStyleSheet("background-color: yellow")
                  }
                  
                  
        eBox2  =  new qlistwidget(win){ setGeometry(590, 202, 600, 200) }           
                  
        //--------
        lBox3  =  new qLabel(win)     { setGeometry(520, 404,  80,  20)  
                      setText("Solved:")   
                      setStyleSheet("background-color: yellow")
                  }
        
        eBox3  =  new qlistwidget(win){ setGeometry(590, 404, 600, 200) }           
      
        //--------
        lBox4  =  new qLabel(win)     { setGeometry(520, 606,  80,  20)  
                      setText("General:")   
                      setStyleSheet("background-color: yellow")
                  }
        
        eBox4  =  new qlistwidget(win){ setGeometry(590, 606, 600, 200) }   
        
        //-------------------------------------------------------------      
        //-------------------------------------------------------------
     

      show()
          
    }
    exec()
 }

return

/*

###==========================================================================
###==========================================================================

Func StartClearScreen()
return

Func DrawMatrix()
return

Func Animation()
return


*/

###==========================================================================
###==========================================================================
// START - CLEAR-SCREEN - FIGURE

Func StartClearScreen() 

See "Start Pressed: "+nl

   Figure()                            // <<<=== CALL,  Draw Mini-Conic
   
   MonaLisa.fill(colorBlack)           // <<<=== BLANK OUT OLD IMAGE !!!
   Canvas.setPixMap(MonaLisa)          ### Need this setPixMap to display imageLabel               
   MyApp.ProcessEvents()               ### <<< EXEC the Draw
   
   //DrawMatrix()                        // <<<=== CALL
   
return 

 
###==========================================================================
###==========================================================================
// Called by ClearScreen()


Func Figure()

    Wide = ImageStockP.width()                               //  Alredy scaled by ImageStockP   - Planet
    High = ImageStockP.height()
    imageStockP.setGeometry( -800, -800 , Wide, High)        // BLANK OUT OLD Figure IMAGE 

    networkEquation = comboEquationType.currentText()
    
    if     networkEquation  = "NetworkEquations"     GoTrafficFlow3()        imageStockP = imageTF3   
    elseif networkEquation  = "TrafficFlow-1"        GoTrafficFlow1()        imageStockP = imageTF1
    elseif networkEquation  = "TrafficFlow-2"        GoTrafficFlow2()        imageStockP = imageTF2
    elseif networkEquation  = "TrafficFlow-3"        GoTrafficFlow3()        imageStockP = imageTF3
    elseif networkEquation  = "ElectricalNetwork-1"  GoElectricalNetwork1()  imageStockP = imageEN1
    elseif networkEquation  = "ElectricalNetwork-2"  GoElectricalNetwork2()  imageStockP = imageEN2
    elseif networkEquation  = "ElectricalNetwork-3"  GoElectricalNetwork3()  imageStockP = imageEN3
    elseif networkEquation  = "ElectricalNetwork-4"  GoElectricalNetwork4()  imageStockP = imageEN4
    elseif networkEquation  = "ChemicalReaction-1"   GoChemicalReaction1()   imageStockP = imageCR1
    elseif networkEquation  = "ChemicalReaction-2"   GoChemicalReaction2()   imageStockP = imageCR2
    elseif networkEquation  = "ChemicalReaction-3"   GoChemicalReaction3()   imageStockP = imageCR3  

    ok
        
    //------------------------------
    Wide = ImageStockP.width()                               //  Alredy scaled by ImageStockP
    High = ImageStockP.height()
  
    imageStockP.setGeometry( PosFigX, PosFigY , Wide, High)  // Figure IMAGE 
    Canvas.setPixMap(MonaLisa)                               ### Need this setPixMap to display imageLabel        
    MyApp.ProcessEvents()                                    ### <<< EXEC the Draw  
    
return

###==========================================================================
###==========================================================================
Func GoTrafficFlow1()


//===========================================
See " TRAFFIC FLOW - See Diagram "+nl
See " InterSec FlowIn   = FlowOut    "+nl  
See "   A:      500      = f1+f2+f3   "+nl
See "   B:      f1+f4+f6 = 400        "+nl
See "   C:      f3+f5    = 100+f6     "+nl
See "   D:      f2       = f4+f5      "+nl
See "----------"+nl+nl

//-------------------
eBox1.clear()
eBox1.addItem("TrafficFlow  FlowIn   = FlowOut   ")   
eBox1.addItem("     A       500      = f1+f2+f3  ") 
eBox1.addItem("     B       f1+f4+f6 = 400       ")
eBox1.addItem("     C       f3+f5    = 100+f6    ")
eBox1.addItem("     D       f2       = f4+f5     ")

//---------------------------------------------------            

//   Augmented Matrix
U = [[ 1 , 1 , 1 , 0 , 0 , 0 , 500],
     [ 1 , 0 , 0 , 1 , 0 , 1 , 400],
     [ 0 , 0 , 1 , 0 , 1 ,-1 , 100],
     [ 0 , 1 , 0 ,-1 ,-1 , 0 ,   0]]
     
     See "Original Matrix U "  MatrixPrint(U)    

V = RowReduceEchelonForm(U)

    See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)

See "----------"+nl+nl

//---------------------------------------------

eBox2.clear()
eBox2.addItem(" Write Matrix Format Equations         ")
eBox2.addItem(" A: f1 + f2 + f3 +  0 +  0 +  0 = 500  ")
eBox2.addItem(" B: f1 +  0 +  0 + f4 +  0 + f6 = 400  ")
eBox2.addItem(" C:  0 +  0 + f3 +  0 + f5 - f6 = 100  ")
eBox2.addItem(" D:  0 + f2 +  0 - f4 - f5 +  0 =   0  ")
              
//------------------------------------------------------  

eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm  ")
eBox3.addItem("    |  f1 f2 f3 f4 f5 f6 =   |  ")
eBox3.addItem(" A: |  1, 0, 0, 1, 0, 1, 400 |  ")
eBox3.addItem(" B: |  0, 1, 0,-1,-1, 0, 0   |  ")
eBox3.addItem(" C: |  0, 0, 1, 0, 1,-1, 100 |  ")
eBox3.addItem(" D; |  0, 0, 0, 0, 0, 0, 0   |  ")

//--------------------------------------------------  

eBox4.clear()
eBox4.addItem(" General Solution:                     ")
eBox4.addItem(" A: f1 = 400 - f4 - f6  (f4+f6 <= 400) ")
eBox4.addItem(" B: f2 =   0 + f4 + f5                 ")
eBox4.addItem(" C: f3 = 100 - f5 + f6  (f5-f6 <= 100) ")

//------------------------------------------------------

return

###==========================================================================
###==========================================================================
Func GoTrafficFlow2()
      
//========================================================
// TRAFFIC FLOW 2
//  
//===========================================
See " TRAFFIC FLOW - See Diagram "+nl
See " InterSec FlowIn    = FlowOut  =>  Equation       "+nl  
See "   A:     125 + 350 = x1  + x4  => x1 + x4 =  475 "+nl
See "   B:     x1  + x2  = 225 + 400 => x1 + x2 =  625 "+nl
See "   C:     250 + 800 = x2  + x3  => x2 + x3 = 1050 "+nl
See "   D:     x3  + x4  = 300 + 600 => x3 + x4 =  900 "+nl
See "----------"+nl+nl

//---------------
eBox1.clear()
eBox1.addItem(" TRAFFIC FLOW - See Diagram     ")
eBox1.addItem(" InterSec FlowIn    = FlowOut   ")
eBox1.addItem("   A:     125 + 350 = x1  + x4  ")
eBox1.addItem("   B:     x1  + x2  = 225 + 400 ")
eBox1.addItem("   C:     250 + 800 = x2  + x3  ")
eBox1.addItem("   D:     x3  + x4  = 300 + 600 ")

//---------------------------------------------------
     
//              
// Augemnted Matrix             
  U = [[1,0,0,1, 475],
       [1,1,0,0, 625],
       [0,1,1,0,1050],
       [0,0,1,1, 900]]
       
    See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)

    See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)

eBox2.clear()
eBox2.addItem("Write Matrix Format Equations       ") 
eBox2.addItem("          x1   x2   x3   x4  |  =   ") 
eBox2.addItem("     A:   x1    0    0 + x4  =  475 ") 
eBox2.addItem("     B:   x1 + x2    0    0  =  625 ")
eBox2.addItem("     C:    0   x2 + x3    0  = 1050 ")
eBox2.addItem("     D:    0    0   x3 + x4  =  900 ")
         
//---------------------------------------------
//Results  V: matrix

eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm  ")
eBox3.addItem("    |  x1 x2 x3 x4  =   |  ")
eBox3.addItem(" A: |  1, 0, 0, 1, 475  |  ")
eBox3.addItem(" B: |  0, 1, 0,-1, 150  |  ")
eBox3.addItem(" C: |  0, 0, 1, 1, 900  |  ")
eBox3.addItem(" D; |  0, 0, 0, 0, 0    |  ")

//--------------------------------------------------  

eBox4.clear()
eBox4.addItem(" General Solustion                     ")
eBox4.addItem(" x4 is Free Variable. Can be any value ")
eBox4.addItem(" x1 = 475 - x4    0 <x4< 475           ")
eBox4.addItem(" x2 = 150 + x4    0                    ")
eBox4.addItem(" x3 = 900 - x4    0 <x4< 900           ")
      
//----------------------------------------------

return


###==========================================================================
###==========================================================================
Func GoTrafficFlow3()

//===========================================
// TRAFFIC FLOW 2b Flow-Out B = y + 400
// 
// Node  Flow-In    Flow-Our  Equation    
//   A   500 + 200  x1  + x4   x1 + x4 =  700
//   B   x1  + x2   y   + 400  x1 + x2 =  400 + y 
//   C   600 + 400  x2  + x3   x2 + x3 = 1000
//   D   x3  + x4   700 +      x3 + x4 =  700 
//
// Total Flow-In  500 + 200 + 400 + 600 = 1700
// Total Flow-Out y   + 400 + 700       = 1100 + y
// =>       y   = 600
// =>B   x1  + x2   y   + 400  x1 + x2 =  600
//
// System of Linear equations  
//    x1           + x4 =  700
//    x1 + x2           = 1000
//         x2 + x3      = 1000
//              x3 + x4 =  700
//              
//----------------------------------

//===========================================
See " TRAFFIC FLOW - See Diagram | B = y+400              "+nl
See " FlowIn 1700 = FlowOut-1100+y : Solve y=600          "+nl                                  
See " InterSec FlowIn    = FlowOut  =>  Equation          "+nl  
See "   A:      500 + 200  x1  + x4   x1 + x4 =  700      "+nl
See "   B:      x1  + x2   y   + 400  x1 + x2 =  400 + y  "+nl
See "   C:      600 + 400  x2  + x3   x2 + x3 = 1000      "+nl
See "   D:      x3  + x4   700 +      x3 + x4 =  700      "+nl
See "----------"+nl+nl

//---------------
eBox1.clear()
eBox1.addItem("  TRAFFIC FLOW - See Diagram | B = y+400            ")
eBox1.addItem("  FlowIn 1700 = FlowOut-1100+y : Solve y=600        ")                                
eBox1.addItem("  InterSec FlowIn    = FlowOut  =>  Equation        ")
eBox1.addItem("    A:      500 + 200  x1  + x4   x1 + x4 =  700    ")
eBox1.addItem("    B:      x1  + x2   y   + 400  x1 + x2 =  400 + y")
eBox1.addItem("    C:      600 + 400  x2  + x3   x2 + x3 = 1000    ")
eBox1.addItem("    D:      x3  + x4   700 +      x3 + x4 =  700    ")    
//---------------------------------------------------


// Augemnted Matrix             
  U = [[1,0,0,1, 700],
       [1,1,0,0,1000],
       [0,1,1,0,1000],
       [0,0,1,1, 700]]
       
    See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)

    See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
    
eBox2.clear()
eBox2.addItem("Write Matrix Format Equations     ") 
eBox2.addItem("        x1   x2   x3   x4  |  =   ") 
eBox2.addItem("   A:   x1    0    0 + x4  =  700 ") 
eBox2.addItem("   B:   x1 + x2    0    0  = 1000 ")
eBox2.addItem("   C:    0   x2 + x3    0  = 1000 ")
eBox2.addItem("   D:    0    0   x3 + x4  =  700 ")

//-----------------------------------------------


eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm  ")
eBox3.addItem("    | x1 x2 x3 x4  =  |  ")
eBox3.addItem(" A: | 1, 0, 0, 1, 700 |  ")
eBox3.addItem(" B: | 0, 1, 0,-1, 300 |  ")
eBox3.addItem(" C: | 0, 0, 1, 1, 700 |  ")
eBox3.addItem(" D; | 0, 0, 0, 0, 0   |  ")

//----------------------------------------------

eBox4.clear()
eBox4.addItem(" General Solustion                     ")
eBox4.addItem(" x4 is Free Variable. Can be any value ")
eBox4.addItem(" x1 = 700 - x4    0 <x4< 700           ")
eBox4.addItem(" x2 = 300 + x4    0                    ")
eBox4.addItem(" x3 = 700 - x4    0 <x4< 700           ")


return

###==========================================================================
###==========================================================================
Func GoElectricalNetwork1()
  
//=========================================================
//=========================================================
// ELECTRCAL network
// 
// Kirchhoff’s Laws
// 1. (Junction Rule) The current flow into a junction 
//     equals the current flow out of that junction.
// 2. (Circuit Rule) The algebraic sum of the voltage drops (due to resistances) 
//     around any closed circuit of the network 
//     must equal the sum of the voltage increases around the circuit
//
// Ohm's Laws
// V = IR
//--------------------------------------------------------------


See "First apply the Junction Rule at Junctions A, B "+nl
See "  See Diagram for Current Flow                  "+nl
See "                 Resistor         Battery       "+nl 
See "  Current:        i1 -  i2 + i3 = 0             "+nl
See "  Circuit Top:   7i1 + 4i2      = 15v (2i1+5i1) "+nl
See "  Circuit Lower: 4i1       +2i3 = 20v           "+nl

  See "----------"+nl+nl
  
eBox1.clear()
eBox1.addItem("First apply the Junction Rule at Junctions A, B ")
eBox1.addItem("  See Diagram for Current Flow                  ") 
eBox1.addItem("                 Resistor         Battery       ")
eBox1.addItem("  Current:        i1 -  i2 + i3 = 0             ")
eBox1.addItem("  Circuit Top:   7i1 + 4i2      = 15v (2i1+5i1) ")
eBox1.addItem("  Circuit Lower: 4i1       +2i3 = 20v           ")          

//----------------------------------------------

//     i1 i2 i3 V
U = [[ 1,-1, 1, 0  ],
     [ 7, 4, 0, 15 ],
     [ 0, 4, 2, 20 ]]

    See "Original Matrix U "  MatrixPrint(U)    

V = RowReduceEchelonForm(U)

    See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
 

eBox2.clear()
eBox2.addItem("Write Matrix Format Equations ") 
eBox2.addItem("         i1 i2 i3 V    ") 
eBox2.addItem("   A: |  1,-1, 1, 0, | ") 
eBox2.addItem("   B: |  7, 4, 0, 15 | ")
eBox2.addItem("   C: |  0, 4, 2, 20 | ")
  
//------------------------------------------    
    
eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm  ")
eBox3.addItem("    | i1 i2 i3 V   |  ")
eBox3.addItem(" A: | 1, 0, 0, 0.2 |  ")
eBox3.addItem(" B: | 0, 1, 0, 3.4 |  ")
eBox3.addItem(" C: | 0, 0, 1, 3.2 |  ")

//-------------------------------------------------

eBox4.clear()
eBox4.addItem("General Solustion ")
eBox4.addItem("  i1 = 0.2  ")
eBox4.addItem("  i2 = 3.4  ")
eBox4.addItem("  i3 = 3.2  ")

//------------------------------------------

return

###==========================================================================
###==========================================================================
Func GoElectricalNetwork2()

//=====================================
// ELECTRICAL CIRCUIT 2
//
// Resistor Current   Volts
//  Ohms       Amps  
// [        ] [ i1] = [ ]
// [        ] [ i2] = [ ]
// [        ] [ i3] = [ ]
// 
// 
// Loop 1: Clockwise    (3o +1o + 5o)*i1  + (1o*i2) + (3o*i3)  =  7v
// Loop 2: CounterClock (1o*i1) + (7o +1o + 4o)*i2  - (4o*i3)  = -15v
// Loop 3: Clockwise    (3o*i1) - (4o*i2) + (4o +3o + (4o + 8o + 1o)*i3 =  10v 
// 
// Sum:   (9o*i1) + ( 1o*i2) + ( 3o*i3) =   7v
//        (1o*i1) + (12o*i2) - ( 4o*i3) = -15v
//        (3o*i1) - ( 4o*i2) + (20o*i3) =  10v
//      
//      Resistor Current Volts
//      [9, 1, 3][i1] = [  7]
//      [1,12,-4][i2] = [-15]
//      [3,-4,20][i3] = [ 10]
//      
//-------------------------------------------------

See "Loop1: CW (3+1+5)*i1 + (1*i2)     + (3*i3)           =  7v   "+nl
See "Loop2: CC (1*i1)     + (7+1+4)*i2 - (4*i3)           = -15v  "+nl
See "Loop3: CW (3*i1)     - (4*i2)     + (4+3)+(4+8+1)*i3 =  10v  "+nl
See "                                  "+nl
See "Sum: 9*i1 +  1*i2 +  3*i3 =   7v  "+nl
See "     1*i1 + 12*i2 -  4*i3 = -15v  "+nl
See "     3*i1 -  4*i2 + 20*i3 =  10v  "+nl
  See "----------"+nl+nl

eBox1.clear()
eBox1.addItem(" Loop1: CW (3+1+5)*i1 + (1*i2)     + (3*i3)           =  7v   ")
eBox1.addItem(" Loop2: CC (1*i1)     + (7+1+4)*i2 - (4*i3)           = -15v  ")
eBox1.addItem(" Loop3: CW (3*i1)     - (4*i2)     + (4+3)+(4+8+1)*i3 =  10v  ")
eBox1.addItem("                                   ")
eBox1.addItem(" Sum: 9*i1 +  1*i2 +  3*i3 =   7v  ")
eBox1.addItem("      1*i1 + 12*i2 -  4*i3 = -15v  ")
eBox1.addItem("      3*i1 -  4*i2 + 20*i3 =  10v  ")
    
//--------------------------------------------------------  
                     
        
//Echelon Format
 U =   [[9, 1, 3,  7],
        [1,12,-4,-15],
        [3,-4,20, 10]]
        
    See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)

    See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
    
    
    
eBox2.clear()
eBox2.addItem("Write Matrix Format Equations ") 
eBox2.addItem("      |  i1 i2  i3  V  | ") 
eBox2.addItem("   A: |  9,  1,  3,  7 | ") 
eBox2.addItem("   B: |  1, 12, -4,-15 | ")
eBox2.addItem("   C: |  3, -4, 20, 10 | ")
    
    
//------------------------------------------------- 
     
eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm ")
eBox3.addItem(" A: |  1, 0,    0, 0.88 |             ")
eBox3.addItem(" B: |  0, 1.00, 0,-1.29 |             ")
eBox3.addItem(" C: |  0, 0,    1, 0.11 |             ")
                                                  
//---------------------------------------------------

See "Branch Current Across Common Resistors "+nl
See "B-E across 3o =  i1 + i3 = 0.88 + 0.11 = 0.99 amps in direction of i1 and i3 "+nl  
See "E-G acroos 4o = -i2 + i3 = 1.29 + 0.11 = 1.40 amps in direction of i3 "+nl     
  See "----------"+nl+nl
  
eBox4.clear()  
eBox4.addItem(" Current Flow in Loops   ")
eBox4.addItem(" i1 =  0.88 amps         ")
eBox4.addItem(" i2 = -1.29 amps         ")
eBox4.addItem(" i3 =  0.11 amps         ")

eBox4.addItem(" Branch Current Across Common Resistors ")
eBox4.addItem(" B-E across 3= i1 + i3 = 0.88+0.11 = 0.99 amps in dir. of i1 & i3 ") 
eBox4.addItem(" E-G acroos 4=-i2 + i3 = 1.29+0.11 = 1.40 amps in dir. of i3      ") 

//-------------------------------------------------------
 
return
 
//=========================================================
//=========================================================


###==========================================================================
###==========================================================================
Func GoElectricalNetwork3()

//=====================================
// ELECTRICAL CIRCUIT 3 - 2 Circuit Loops
// 
//         
//  i1   +i2  -i3 = 0       // i1 + i2 = I3
//  20v -2i3 -4i3 = 0       // CounterClock from +20v battery
//  16v -8i2 -2i3 = 0       // Cloclwise    from +16v battery
//  20v +8i2 -16v -4i1 = 0  // BigLoop from +20v battery
//------------------------------------------------------------

See "Two Circuit Loops"+nl
See " A:  i1   +i2  -i3 = 0       // i1 + i2 = i3              "+nl
See " B:  20v -2i3 -4i1 = 0       // CC from +20v battery      "+nl
See " C:  16v -8i2 -2i3 = 0       // CW from +16v battery      "+nl
See " D:  20v +8i2 -16v -4i1 = 0  // BigLoop from +20v battery "+nl
  See "----------"+nl+nl

eBox1.clear()   
eBox1.addItem("Two Circuit Loops")
eBox1.addItem(" A:  i1   +i2  -i3 = 0      // i1 + i2 = i3               ")
eBox1.addItem(" B:  20v -2i3 -4i1 = 0      // CC from +20v battery       ")
eBox1.addItem(" C:  16v -8i2 -2i3 = 0      // CW from +16v battery       ")
eBox1.addItem(" D:  20v +8i2 -16v -4i1 = 0 // BigLoop from +20v battery  ")

        
//Echelon Format
 U =   [[4, 0, 2, 20],
        [0, 8, 2, 16],
        [4,-8, 0,  4],
        [1, 1,-1,  0]]
        
    See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)

    See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
    
eBox2.clear()
eBox2.addItem("Write Matrix Format Equations ") 
eBox2.addItem("      |  i1 i2 i3  V | ") 
eBox2.addItem("   A: |  4, 0, 2, 20 | ") 
eBox2.addItem("   B: |  0, 8, 2, 16 | ")
eBox2.addItem("   C: |  4,-8, 0,  4 | ")
eBox2.addItem("   D: |  1, 1,-1,  0 | ")    

//------------------------------------------        
 
eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm ")
eBox3.addItem("      i1 i2 i3  V |  ")
eBox3.addItem(" A: |  1, 0, 0, 3 |  ")
eBox3.addItem(" B: |  0, 1, 0, 1 |  ")
eBox3.addItem(" C: |  0, 0, 1, 4 |  ")
eBox3.addItem(" A: |  0, 0, 0, 0 |  ")

//----------------------------------------------


eBox4.clear()  
eBox4.addItem(" Current Flow in Loops   ")
eBox4.addItem(" i1 =  3.0 amps          ")
eBox4.addItem(" i2 =  1.0 amps          ")
eBox4.addItem(" i3 =  4.0 amps          ")
  
//------------------------------------------------  
  
 
 return
 
###==========================================================================
###==========================================================================
Func GoElectricalNetwork4()
 
 
//=========================================================
//=========================================================
// ELECTRICAL CIRCUIT 4
// 
//  1 nodeX  i1 + i2 - i3   .    .  = 0
//  2 nodeZ  .    .    i3 - i4 - i5 = 0
//  3 nodeY  .    .    i3   .    .  = 0
//  4 nodeW  .    i2   .    .    .  = 0
//  
//  5 vX     =>      vX          = 48v
//  6 r1     =>      vX -vY      = 8i3
//  7 v2     =>          vY -vZ  = 19v
//  8 r2     =>              vZ  = 2.5i4
//  9 r3     =>              vZ  = 5i5
// 10 r4     =>  vW -vX          = i2   = 2
// 11 i2     =>  i2              = 2
//  
//  Matrix
//      i1 i2 i3 i4  i5  vW vX vY vZ
//    | 1  1  -1  0   0  0  0  0  0 | i1 | 0
//    | 0  0   1 -1  -1  0  0  0  0 | i2 | 0
//    | 0  0   0  0   0  0  1  0  0 | i3 | 48
//    | 0  0  -8  0   0  0  1 -1  0 | i4 | 0
//    | 0  0   0  0   0  0  0  1 -1 | i5 | 19
//    | 0  0   0 -2.5 0  0  0  0  1 | vW | 0
//    | 0  0   0  0  -5  0  0  0  1 | vX | 0
//    | 0 -1   0  0   0  1 -1  0  0 | vY | 0
//    | 0  1   0  0   0  0  0  0  0 | vZ | 2
// 
//
//           vv                      vv                     // Remove i2 vX
//       i1  i2   i3    i4   i5  vW  vX  vY  vZ
// U = [[ 1,  1, -1,    0,   0,  0,  0,  0,  0,  0],  // | i1 |
//      [ 0,  0,  1,   -1,  -1,  0,  0,  0,  0,  0],  // | i2 |
//      [ 0,  0,  0,    0,   0,  0,  1,  0,  0, 48],  // | i3 | // vX =48
//      [ 0,  0, -8,    0,   0,  0,  1, -1,  0,  0],  // | i4 |
//      [ 0,  0,  0,    0,   0,  0,  0,  1, -1, 19],  // | i5 |
//      [ 0,  0,  0, -2.5,   0,  0,  0,  0,  1,  0],  // | vW |
//      [ 0,  0,  0,    0,  -5,  0,  0,  0,  1,  0],  // | vX |
//      [ 0, -1,  0,    0,   0,  1, -1,  0,  0,  0],  // | vY |
//      [ 0,  1,  0,    0,   0,  0,  0,  0,  0,  2]]  // | vZ | // i2 = 2
// 
//                        vv
//        i1  i3    i4   i5  vW   vY  vZ            //Remore i2 and vX vertical and horx
// U = [[ 1,  -1,    0,   0,  0,   0,  0,  -2],  // | i1 |
//      [ 0,   1,   -1,  -1,  0,   0,  0,   0],  // | i3 |
//      [ 0,   0,    0,   0,  0,  -1,  0, -48],  // | i4 |
//      [ 0,  -8,    0,   0,  0,   1, -1,  19],  // | i5 |
//      [ 0,   0, -2.5,   0,  0,   0,  1,   0],  // | vW |
//      [ 0,   0,    0,  -5,  0,   0,  1,   0],  // | vY |
//      [ 0,   0,    0,   0,  1,   0,  0,  50]]  // | vZ |  // Remove vW =50
//                                                
// 
//------------------------------------------------------

See "Three Circuit Loops"+nl
See "  1 nodeX  i1 + i2 - i3   .    .  = 0      "+nl
See "  2 nodeZ  .    .    i3 - i4 - i5 = 0      "+nl
See "  3 nodeY  .    .    i3   .    .  = 0      "+nl
See "  4 nodeW  .    i2   .    .    .  = 0      "+nl
See "                                           "+nl
See "  5 vX     =>      vX          = 48v    ok "+nl
See "  6 r1     =>      vX -vY      = 8i3       "+nl
See "  7 v2     =>          vY -vZ  = 19v    ok "+nl
See "  8 r2     =>              vZ  = 2.5i4     "+nl
See "  9 r3     =>              vZ  = 5i5       "+nl
See " 10 r4     =>  vW -vX          = i2 = 2 ok "+nl
See " 11 i2     =>  i2              = 2      ok "+nl
  See "----------"+nl+nl

eBox1.clear()   
eBox1.addItem("Three Circuit Loops                        ")
eBox1.addItem("  1 nodeX  i1 + i2 - i3   .    .  = 0      ")
eBox1.addItem("  2 nodeZ  .    .    i3 - i4 - i5 = 0      ")
eBox1.addItem("  3 nodeY  .    .    i3   .    .  = 0      ")
eBox1.addItem("  4 nodeW  .    i2   .    .    .  = 0      ")
eBox1.addItem("                                           ")
eBox1.addItem("  5 vX     =>      vX          = 48v    ok ")
eBox1.addItem("  6 r1     =>      vX -vY      = 8i3       ")
eBox1.addItem("  7 v2     =>          vY -vZ  = 19v    ok ")
eBox1.addItem("  8 r2     =>              vZ  = 2.5i4     ")
eBox1.addItem("  9 r3     =>              vZ  = 5i5       ")
eBox1.addItem(" 10 r4     =>  vW -vX          = i2 = 2 ok ")
eBox1.addItem(" 11 i2     =>  i2              = 2      ok ")

//----------------------------------------------------------------

                                                            
//     i1  i3    i4   i5  vY  vZ  =             //Removed  i2 and vX vertical and horx   
U = [[ 1,  -1,    0,   0,  0,  0, -2], //| i1 |  
     [ 0,   1,   -1,  -1,  0,  0,  0], //| i3 |  
     [ 0,  -8,    0,   0, -1,  0,-48], //| i4 |  
     [ 0,   0,    0,   0,  1, -1, 19], //| i5 |  
     [ 0,   0, -2.5,   0,  0,  1,  0], //| vY |  
     [ 0,   0,    0,  -5,  0,  1,  0]] //| vZ |  
     
                                                                                         
    See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)
  See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
  See "----------"+nl+nl  
 
eBox2.clear()
eBox2.addItem("Write Matrix Format Equations ") 
eBox2.addItem("Known: i2=2, v2=19, vX=48     ")
eBox2.addItem("                              ")
eBox2.addItem("       | i1   i3    i4   i5  vY  vZ   V | ") 
eBox2.addItem("   i1: |  1,  -1,    0,   0,  0,  0, -2 | ") 
eBox2.addItem("   i3: |  0,   1,   -1,  -1,  0,  0,  0 | ")
eBox2.addItem("   i4: |  0,  -8,    0,   0, -1,  0,-48 | ")
eBox2.addItem("   i5: |  0,   0,    0,   0,  1, -1, 19 | ") 
eBox2.addItem("   vY: |  0,   0, -2.5,   0,  0,  1,  0 | ")
eBox2.addItem("   vZ: |  0,   0,    0,  -5,  0,  1,  0 | ")
 
//-----------------------------------------------------------
 
eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm ")
eBox3.addItem("      i1 i3 i4 i5 vY vZ  V    | ")
eBox3.addItem(" i1 |  1, 0, 0, 0, 0, 0, 1    | ")   
eBox3.addItem(" i3 |  0, 1, 0, 0, 0, 0, 3    | ")   
eBox3.addItem(" i4 |  0, 0, 1, 0, 0, 0, 2.00 | ")
eBox3.addItem(" i5 |  0, 0, 0, 1, 0, 0, 1.00 | ")
eBox3.addItem(" vY |  0, 0, 0, 0, 1, 0, 24   | ")  
eBox3.addItem(" vZ |  0, 0, 0, 0, 0, 1, 5.00 | ")
eBox3.addItem("                              | ")
eBox3.addItem(" i2 = 2  vX = 48 vW = 50      | ")
 
 //------------------------------------------------------
 
 eBox4.clear()  
 eBox4.addItem("Voltages and Currents   ")
 eBox4.addItem("  vX = 48v   11 = 1 amp ")
 eBox4.addItem("  vW = 50v   i3 = 3 amp ")
 eBox4.addItem("  vY = 24v   i4 = 2 amp ")
 eBox4.addItem("  vZ =  5v   i5 = 1 amp ")
   
 //------------------------------------------------ 
 
return

###==========================================================================
###==========================================================================
Func GoChemicalReaction1()

//=====================================
// CHEMICAL REACTION 1
//
// SnO2 +H2 → Sn + H2O
// 
// The tools of linear algebra can also be used in the subject area of Chemistry, specificallyfor balancing chemical reactions.
// 
// Consider the chemical reaction: Tin ( Sn), Oxygen (O), and Hydrogen (H).
//      SnO2 +H2 → Sn + H2O
// 
// We want to find numbers  x,y,z,w such that
//     xSnO2 +yH2 → zSn + wH2O
//  
// Thus you need by molecule count
//     Sn:  x =  z
//     O:  2x =  w
//     H:  2y = 2w  
//     
// We can rewrite these equations as
//     Sn:  x −  z = 0
//     O:  2x −  w = 0
//     H:  2y − 2w = 0     
//     
// The augmented matrix for this system of equations is given by    
//       x y  z  w    =
//     [ 1 0 -1  0  | 0 ]  // Sn
//     [ 2 0  0 -1  | 0 ]  // O
//     [ 0 2  0 -2  | 0 ]  // H
//-------------------------------------------------------     

See "CHEMICAL REACTION"+nl
See " SnO2 +H2 -> Sn + H2O             "+nl
See " Tin(Sn), Oxygen(O), Hydrogen(H)  "+nl
See " Find numbers  x,y,z,w  such that "+nl
See " xSnO2 +yH2 -> zSn + wH2O         "+nl
  See "----------"+nl+nl

eBox1.clear()   
eBox1.addItem("CHEMICAL REACTION")
eBox1.addItem(" SnO2 +H2 → Sn + H2O              ")             
eBox1.addItem(" Tin(Sn), Oxygen(O), Hydrogen(H)  ")
eBox1.addItem(" Find numbers  x,y,z,w  such that ")
eBox1.addItem(" xSnO2 +yH2 → zSn + wH2O          ")

eBox1.addItem(" Sn:  x =  z   ")
eBox1.addItem(" O:  2x =  w   ")
eBox1.addItem(" H:  2y = 2w   ")

//------------------------------------------------------

       
 U =  [[ 1, 0, -1,  0, 0], 
       [ 2, 0,  0, -1, 0], 
       [ 0, 2,  0, -2, 0]] 
    
      See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)
  See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
  
  
eBox2.clear()
eBox2.addItem("Write Matrix Format Equations ") 
eBox2.addItem("       x  y   z   w  =   ") 
eBox2.addItem(" Sn: | 1, 0, -1,  0, 0 | ")
eBox2.addItem(" O:  | 2, 0,  0, -1, 0 | ") 
eBox2.addItem(" H:  | 0, 2,  0, -2, 0 | ") 

//------------------------------------------------- 

eBox3.clear()
eBox3.addItem(" Solved using RowReduceEchelonForm ")
eBox3.addItem("        x  y  z   w     =   ")
eBox3.addItem(" Sn: |  1, 0, 0, -0.50, 0 | ") 
eBox3.addItem(" O:  |  0, 1, 0, -1   , 0 | ")   
eBox3.addItem(" H:  |  0, 0, 1, -0.50, 0 | ")   
eBox3.addItem("                            ") 
eBox3.addItem(" Need round number of Molecules ") 

//----------------------------------

   
eBox4.clear()  
eBox4.addItem(" Solution is given by: ")
eBox4.addItem("   x -0.5w = 0 ")
eBox4.addItem("   y -1.0w = 0 ")
eBox4.addItem("   z -0.5w = 0 ")
eBox4.addItem(" Which we can write using -t- as         ")
eBox4.addItem("            x=0.5t, y=t, z=0.5t, w=t     ")
eBox4.addItem(" Let w=2 => x=1,    y=2, z=1             ")
eBox4.addItem("   Put values back in to balnce equation ")
eBox4.addItem("   Original:  xSnO2 + yH2 -> zSn + wH2O   ")
eBox4.addItem("   Solved  :  1SnO2 + 2H2 -> 1Sn + 2H2O   ")

//------------------------------------------------------------
        
return


###==========================================================================
###==========================================================================
Func GoChemicalReaction2()    
      
//=====================================
//=====================================
// CHEMICAL REACTION 2
//
// KOH+H3PO4→K3PO4+H2O
//
//  Potassium  K,
//  Oxygen     O,
//  Phosphorus P
//  Hydrogen   H
//  
// Solution 
//  xKOH + yH3PO4 → zK3PO4 + wH2O
//  
//  (xK xO xH)  + (3yH yP 4yO) => (3zK zP 4zO) + (2wH wO)
//   xK        = 3zK
//   xO + 4yO  = 4zO + wO
//   xH + 3yH  =      2wH
//   yP        =  zP
//   
//   
// Format Matrix
//       x  y   z  w  = 
//  K    1  0  -3  0   0  
//  O    1  4  -4 -1   0
//  H    1  3   0 -2   0
//  P    0  1   1  0   0
//-------------------------------------------------

See "CHEMICAL REACTION"+nl
See " KOH + H3PO4 -> K3PO4 + H2O             "+nl
See " Potassium(K) Oxygen(O) Phosphorus(P) Hydrogen(H)"+nl
See " Find numbers  x,y,z,w  such that       "+nl
See " xKOH + yH3PO4 -> zK3PO4 + wH2O         "+nl
  See "----------"+nl+nl

eBox1.clear()   
eBox1.addItem("CHEMICAL REACTION")
eBox1.addItem(" KOH + H3PO4 -> K3PO4 + H2O              ")             
eBox1.addItem(" Potassium(K) Oxygen(O) Phosphorus(P) Hydrogen(H) ")
eBox1.addItem(" Find numbers  x,y,z,w  such that        ")
eBox1.addItem(" xKOH + yH3PO4 -> zK3PO4 + wH2O          ")
eBox1.addItem("                                         ")
eBox1.addItem(" (xK xO xH) + (3yH yP 4yO) => (3zK zP 4zO) + (2wH wO) ")
eBox1.addItem("  xK        = 3zK       ")
eBox1.addItem("  xO + 4yO  = 4zO + wO  ")
eBox1.addItem("  xH + 3yH  =      2wH  ")
eBox1.addItem("  yP        =  zP       ")

//----------------------------------------------
  
 U =  [[ 1, 0,-3, 0, 0],
       [ 1, 4,-4,-1, 0],
       [ 1, 3, 0,-2, 0],
       [ 0, 1,-1, 0, 0]]
       
    
      See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)
  See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
  
 
eBox2.clear()
eBox2.addItem("Write Matrix Format Equations ") 
eBox2.addItem("      x  y   z   w  =   ") 
eBox2.addItem(" K: | 1, 0, -3,  0, 0 | ")
eBox2.addItem(" O: | 1, 4, -4, -1, 0 | ") 
eBox2.addItem(" H: | 1, 3,  0, -2, 0 | ") 
eBox2.addItem(" P: | 0, 1, -1,  0, 0 | ")

//------------------------------------------- 
  
eBox3.clear()
eBox3.addItem("Solved using RowReduceEchelonForm ")
eBox3.addItem("        x  y  z   w     =     ")
eBox3.addItem("  K: |  1, 0, 0, -1,    0 |   ")
eBox3.addItem("  O: |  0, 1, 0, -0.33, 0 |   ")
eBox3.addItem("  H: |  0, 0, 1, -0.33, 0 |   ")
eBox3.addItem("  P: |  0, 1,-1,  0,    0 |   ")
eBox3.addItem("                              ")
eBox3.addItem(" Normalize 0.33 to 1 by Scalar Multply ")

//-------------------------------------------------
  
W =  scalarMultiply( 3, V)

  See "ScalarMutiply V x S3 => W " MatrixPrint(W)
  
  
//------------------------------------------------------
  
eBox4.clear()  
eBox4.addItem(" Solution is given by:               ")
eBox4.addItem(" Result:  x=3, y=1,z=1 w=3           ")
eBox4.addItem("   xKOH +  yH3PO4 ->  zK3PO4 +  wH2O ")
eBox4.addItem("   3KOH +  1H3PO4 ->  1K3PO4 +  3H2O ")
 
//--------------------------------------------
  
return



###==========================================================================
###==========================================================================
Func GoChemicalReaction3()

//=====================================
// CHEMICAL REACTION 1
// x      y    z      w
// c3h8 +o2 -> co2 + h2o
// 
// c3h8 + 5o2 = 3co2 + 4h2o  <====
// 
//          x  y = z y
//   | C |  3  0   1 0
//   | H |  8  0   0 2
//   | O |  0  2   2 1
//---------------------------------------- 	   

See "CHEMICAL REACTION                         "+nl
See " c3h8 +o2 -> co2 + h2o                    "+nl
See " Propane + Oxogen = CarbonDioxide + Water "+nl
See " Find numbers  x1,x2,x3,x4  such that     "+nl
See " x1*c3h8 + x2*o2 -> x3*co2 + x4*h2o       "+nl
  See "----------"+nl+nl


eBox1.clear()   
eBox1.addItem("CHEMICAL REACTION          ")
eBox1.addItem(" c3h8 +o2 -> co2 + h2o     ")             
eBox1.addItem(" Propane + Oxogen = CarbonDioxide + Water ")
eBox1.addItem(" Find numbers  x1,x2,x3,x4  such that     ")
eBox1.addItem(" x1*c3h8 + x2*o2 -> x3*co2 + x4*h2o       ")


//--------------------------------------------

 U =  [[ 3, 0, 1, 0, 0],
       [ 8, 0, 0, 2, 0],
       [ 0, 2, 2, 1, 0]]
       
    
      See "Original Matrix U "  MatrixPrint(U)    

  V = RowReduceEchelonForm(U)
  See "Solved using RowReduceEchelonForm U => V " MatrixPrint(V)
  

eBox2.addItem("Write Matrix Format Equations ") 
eBox2.addItem("      x1 x2 = x3 x4 =   ") 
eBox2.addItem(" C: | 3, 0,   1, 0, 0 | ")
eBox2.addItem(" H: | 8, 0,   0, 2, 0 | ") 
eBox2.addItem(" O: | 0, 2,   2, 1, 0 | ") 

//------------------------------------------------

eBox3.clear()
eBox3.addItem("Solved using RowReduceEchelonForm ")
eBox3.addItem("       x1 x2 x3 x4      =  ")
eBox3.addItem(" C: |  1, 0, 0, 0.25, 0 |  ")
eBox3.addItem(" H: |  0, 1, 0, 1.25, 0 |  ")
eBox3.addItem(" O: |  0, 0, 1,-0.75, 0 |  ")
eBox3.addItem("                         ")
eBox3.addItem(" Normalize 0,25 to 1 by Scalar Multply ")

//-------------------------------------------

 W =  scalarMultiply( 4, V)

 See "ScalarMutiply V x S3 => W " MatrixPrint(W) 

// ScalarMutiply V x S3 => W
//    x  y  z  y
// |  4, 0, 0, 1, 0 |
// |  0, 4, 0, 5, 0 |
// |  0, 0, 4,-3, 0 |

 
See " Solution is given by:           "+nl
See " x4 is Free Variable.  Set x4=4  "+nl
See " Result:  x1=1, x2=5, x3=3 x4=4  "+nl
See "   c3h8 +  o2 ->  co2 +  h2o     "+nl
See "   c3h8 + 5o2 -> 3co2 + 4h2o     "+nl
  See "----------"+nl+nl  

eBox4.clear()  
eBox4.addItem(" Solution is given by:             ")
eBox4.addItem(" Scalar Multiply by 4 to Normalize ")
eBox4.addItem("  x4 is Free Variable.  Set x4=4   ")
eBox4.addItem("                                   ")
eBox4.addItem("  Result:  x1=1, x2=5, x3=3 x4=4   ")
eBox4.addItem("    c3h8 +  o2 ->  co2 +  h2o      ")
eBox4.addItem("    c3h8 + 5o2 -> 3co2 + 4h2o      ")    

//-----------------------------------------
 
return

###==========================================================================
###==========================================================================
