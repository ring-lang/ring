/*  Draw Circle
    Use  Arc, Ellipse
	  Fill Brush - Solid, Hatched, Fine -- Color
*/

Load "guilib.ring"
New qapp {
        win1 =  new qwidget() {
                setwindowtitle("Circle - Draw and Fill -- using QPainter")
                setgeometry(100,100,500,500)

                label1 = new qlabel(win1) {
                        setgeometry(10,10,400,400)
                        settext("")
                }

                new qpushbutton(win1) {
                        setgeometry(200,400,100,30)
                        settext("draw")
                        setclickevent("draw()")
                }

                show()
        }
        exec()
}

Func draw
        p1    = new qpicture()

        blue  = new qcolor() { setrgb(0,0,255,255) } ### Blue
        red   = new qcolor() { setrgb(255,0,0,255) } ### Red
		    green = new qcolor() { setrgb(0,255,0,255) } ### Green

        pen   = new qpen()   { setcolor(blue)  setwidth(1) }
		
		### Brush style 0-Empty 1-Solid 2-Hatched 3-FineHatch
		brushS = new qbrush() { setstyle(1)  setcolor (green) }  
		brushH = new qbrush() { setstyle(2)  setcolor (red) } 

        new qpainter() {
            begin(p1)
            setpen(pen)

            ### drawline(10,20,50,250)

            drawellipse(200,250,100,50)  ### Ellipse
            drawellipse(50,300,100,100)  ### Circle

             // ARC Circles -- can NOT be filled
             // Each step for Angle parameter is 1/16th of a Degree
             // so multiply Angle Value with 16

            drawArc( 50, 30, 150,150, 0,16*360)
            drawArc(200, 80, 100,100, 0,16*360)
            drawArc(300,130,  50, 50, 0,16*360)

			setBrush(brushS);             ### Fill the Rectangle Solid
            drawRect(150,190,150,50)      ### Rectangle

            setBrush(brushH);             ### Fill the Circle Hatched
            drawellipse(200,300,100,100)  ### Circle

            endpaint()
        }

        label1 { setpicture(p1) show() }
return
