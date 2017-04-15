Load "guilib.ring"

## MF-RotateTextAndButton-2.ring

WinSizeX   = 300
WinSizeY   = 300
LabelSizeX = 100
LabelSizeY = 100
offSetX    = LabelSizeX / 2

New qapp {
        win1 = new qwidget() 
        {
            setwindowtitle("Label and Button - Rotate Text")
            setgeometry(100,100,WinSizeX, WinSizeY)
 
            
            btn1 = new ButtonWithRotatedText(win1)        
            btn1 {
                    setgeometry(0,0,LabelSizeX, LabelSizeX)
                    settext("A-1")
                    setTranslate(offSetX, 0)
                    setRotationDegree( 45)
                    setClickEvent("see btn1.text() +nl")
                 }
                 
            btn2 = new ButtonWithRotatedText(win1)           
            btn2 {
                    setgeometry(100,0,LabelSizeX, LabelSizeX)
                    settext("B-2")
                    setTranslate(offSetX, 0)
                    setRotationDegree( 90)
                    setClickEvent("see btn2.text() +nl")
                 }
                 
            btn3 = new ButtonWithRotatedText(win1)          
            btn3 {
                    setgeometry(0,100,LabelSizeX, LabelSizeX)
                    settext("C-3")
                    setTranslate(offSetX, 0)
                    setRotationDegree( 180)
                    setClickEvent("see btn3.text() +nl")
                 }
                 
            btn4 = new ButtonWithRotatedText(win1)         
            btn4 {
                    setgeometry(100,100,LabelSizeX, LabelSizeX)
                    settext("D-4")
                    setTranslate(offSetX, 0)
                    setRotationDegree( 270)
                    setClickEvent("see btn4.text() +nl")
                 }               
                 
                 
                
            #showMaximized()
            show()
        }
        exec()
}

Class ButtonWithRotatedText

    oButton oLabel  cText="We are here"  nDegree = 30  nTransX = 50   nTransY = 0

    func init( oParent) 
        See nl +"Init oParent"+ nl
        oButton = new qPushButton(oParent)
        oLabel  = new qLabel(oParent)
        oLabel.setAttribute(Qt_WA_TransparentForMouseEvents,True)
        oLabel.setAttribute(Qt_WA_DeleteOnClose, True)
        oButton.setAttribute(Qt_WA_DeleteOnClose, True)
    return
    
    func close()
        See "Close: "+ nl
        #oButton.close()     ### Comment out - Will leave button active
        oLabel.close()       ### This will erase text
    return    
    
    func setgeometry( x,y,width,height)
        See "SetGeometry: "+ x  +" "+ y +" "+ width +" "+ height +nl
        oButton.setgeometry(x,y,width,height)
        oLabel.setgeometry( x,y,width,height)
        
    func setText( cValue)
        See "SetText: "+ cText +" = "+ cValue +nl
        cText = cValue
    return
    
    func Text() 
        See "Text: "+ cText +nl
        return cText

    ###------------------------------------------
    func setTranslate( x,y )    
        See "SetTranslate: "+ x  +" "+ y +nl
        nTransX = x
        nTransY = y     
    return

    func TranslateOffsetX()
        See "TranslateOffsetX: "+ nTransX +nl
        return nTransX 

    func TranslateOffsetY()
        See "TranslateOffsetY: "+ nTransY +nl
        return nTransY 
    ###-------------------------------------------
    
    func setRotationDegree( nValue)
        See "SetRotationDegree: "+ nValue +nl
        nDegree = nValue
    return
    
    func RotationDegree()
        See "RotationDegree: "+ nDegree +nl
        return nDegree

    func setClickEvent( cEvent)
        See "SetClickEvent: "+ cEvent +nl
        oButton.setClickEvent(cEvent)
    return
    
    func braceend()
        See "BraceEnd"+ nl
        draw() 
    return
    
    ###--------------------------------------------
    
    Func draw()
        See "Draw: "+ nDegree  +" "+ cText +nl
        
                    picture = new qpicture()
                    color   = new qcolor() { setrgb(0,0,255,255) }
                    pen     = new qpen()   { setcolor(color) setwidth(10) }
                    
                    painter = new qpainter() 
                    {
                        begin(picture)        
                            setpen(pen)
                            oFont = font()
                            oFont.setpointsize(20)
                            setfont(oFont)
                            
                            translate(this.TranslateOffsetX(), this.TranslateOffsetY() )
                            rotate(this.RotationDegree())
                            
                            drawtext(0,0,this.Text())          
                        endpaint()
                    }
                    
                    oLabel {
                            setpicture(picture)  
                            show() 
                    }
    return
    
    
