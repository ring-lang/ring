load "guilib.ring"

new qapp 
{
        win1 = new qwidget() {
               setwindowtitle("drawing using qpainter")
               setgeometry(100,100,500,600)
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

func draw
     p1 = new qpicture()
          color = new qcolor() {
          setrgb(0,0,255,255)
     }
     pen = new qpen() {
           setcolor(color)
           setwidth(1)
     }
     new qpainter() {
        begin(p1)
	mycolor = new qcolor() { setrgb(0,0,255,255) }
	mybrush = new qbrush() { setstyle(1)  setcolor (mycolor) }
	setpen(pen)
	setRenderHint(1,1)
	mypath = new qpainterpath()
	mypath.addRect(10, 10, 100, 200)
	fillpath(mypath,mybrush)
	drawpath(mypath)
        endpaint()
     }
     label1 { setpicture(p1) show() }
