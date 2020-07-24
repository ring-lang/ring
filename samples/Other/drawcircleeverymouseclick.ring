Load "guilib.ring"

# List of points - Each point is a Hash Table contains X and Y
aCircles = []

new qApp {

         win1 = new qWidget()
         {
                setWindowTitle("Draw Circles!")
                setGeometry(100,100,500,500)
                setmousetracking(true)
                label1 = new qlabel(win1) 
                myfilter = new qallevents(win1)
                myfilter.setMouseButtonPressevent("pClick()")
                installeventfilter(myfilter)
	      oLayout = new qVBoxLayout() {
			AddWidget(Label1)
	      }
	      setLayout(oLayout)
                show()
         }
         exec()
}

func pClick

         new qpainter() 
          {
	    p1 = new qpicture()  
               begin(p1) 
	    drawpoint(0,0)
	   drawpoint(500,500)
              cx = myfilter.getx()
              cy = myfilter.gety()
	    see "" + cx + " " + cy + nl
	    # Add the point Hash Table to the List
		    aPoint = []
		    aPoint[:x] = cx
		    aPoint[:y] = cy
		    aCircles + aPoint
	    # Draw Circles
		    for point in aCircles 
	          	    drawellipse(point[:x]-15,point[:y]-15,30,30)
		   next          
            endpaint()
          }
          label1 { setpicture(p1) show() }
          return
