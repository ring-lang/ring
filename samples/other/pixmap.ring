Load "guilib.ring"
New qapp 
{
    win1 =  new qwidget() 
    {
        setwindowtitle("Drawing using QPixMap")
        setgeometry(100,100,500,500)

        label1 = new qlabel(win1) 
        {
            setgeometry(10,10,400,400)
            settext("")
        }

        imageStock = new qlabel(win1) 
        {               
            image = new qPixMap2(200,200)   
	 color = new qcolor() {
                        setrgb(255,255,255,255)
                }
	    pen = new qpen() {
                        setcolor(color)
                        setwidth(10)
                }
                new qpainter() {
                        begin(image)
                        setpen(pen)
                        drawline(0,0,200,200)
                        drawline(200,0,0,200)
                        endpaint()
                }
            setpixmap(image)   

        }   



        show()
    }
    exec()
}
