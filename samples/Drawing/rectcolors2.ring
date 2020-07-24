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
         setpen(pen)

	 color2 = new qcolor() {
	          setrgb(0,255,0,255)
         }
	 mybrush = new qbrush() { setstyle(1) setcolor(color2) }
	 setbrush(mybrush)

         for n = 1 to 10
             drawrect(n*25,25,25,70)
         next

         endpaint()
     }
     label1 { setpicture(p1) show() }
