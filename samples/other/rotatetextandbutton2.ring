Load "guilib.ring"
New qapp {
        win1 = new qwidget() {
                setwindowtitle("Label and Button - Rotate Text")
                setgeometry(100,100,500,500)
                btn1 = new ButtonWithRotatedText(win1) 
	      btn1 {
			setgeometry(100,100,400,400)
			settext("Test")
			setClickEvent("see btn1.text()")
                }
                showMaximized()
        }
        exec()
}

Class ButtonWithRotatedText

	oButton oLabel  cText=""  nDegree = 30

	func init oParent 
		oButton = new qPushButton(oParent)
		oLabel = new qLabel(oParent)
		oLabel.setAttribute(Qt_WA_TransparentForMouseEvents,True)

	func setgeometry x,y,width,height
		oButton.setgeometry(x,y,width,height)
		oLabel.setgeometry(x,y,width,height)

	func setText cValue
		cText = cValue

	func Text 
		return cText

	func setRotationDegree nValue
		nDegree = nValue

	func RotationDegree
		return nDegree

	func setClickEvent cEvent
		oButton.setClickEvent(cEvent)

	func braceend
		draw() 

	Func draw
	                p1 = new qpicture()
          	      color = new qcolor() {
	                   	    setrgb(0,0,255,255)
          	      }
	                pen = new qpen() {
          	              setcolor(color)
                    	    setwidth(10)
	                }
          	      painter = new qpainter() {
			begin(p1)		
				setpen(pen)
				oFont = font()
				oFont.setpointsize(20)
				setfont(oFont)
				rotate(this.RotationDegree())
				drawtext(0,0,this.Text()) 		 
			endpaint()
	                }
          	      oLabel {
			setpicture(p1)  
			show() 
		      }

