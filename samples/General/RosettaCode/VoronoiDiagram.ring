# Project : Voronoi diagram
# Date    : 2018/03/30
# Author : Gal Zsolt [~ CalmoSoft ~]
# Email   : <calmosoft@gmail.com>
 
load "guilib.ring"
load "stdlib.ring"
paint = null
 
new qapp 
        {
        spots	= 100
        leftside = 400
        rightside = 400
 
        locx = list(spots)
        locy = list(spots)
        rgb = list(spots,3)
        seal = list(leftside, rightside)
        reach = list(leftside, rightside)
 
        win1 = new qwidget() {
                  setwindowtitle("Voronoi diagram")
                  setgeometry(100,100,800,600)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,800,600)
                              settext("")
                  }
                  new qpushbutton(win1) {
                          setgeometry(150,550,100,30)
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
        paint = new qpainter() {
                  begin(p1)
                  setpen(pen)
 
        for i =1 to spots
             locx[i] = floor(leftside  * randomf())
             locy[i] = floor(rightside * randomf())
             rgb[i][1] = floor(256 * randomf())
             rgb[i][2] = floor(256 * randomf())
             rgb[i][3] = floor(256 * randomf())
        next 
        for x = 1 to leftside 
             for y = 1 to rightside 
                 reach[x][y] = pow((locx[1] - x),2) + pow((locy[1] - y),2)
                 seal[x][y] = 1
             next 
        next 
        for i = 2 to spots
             for x = locx[i] to 0 step -1		
                 if not (chkpos(i,x,1, rightside-1))
                   exit 
                 ok
             next 
             for x = locx[i] + 1 to leftside - 1		
                  if not (chkpos(i, x, 1, rightside-1))
                     exit
                  ok
             next 
        next  
        for x = 1 to leftside 
             for y = 1 to rightside
           	  c1 = rgb[seal[x][y]][1]
        	  c2 = rgb[seal[x][y]][2]
	          c3 = rgb[seal[x][y]][3]
                  color = new qcolor() { setrgb(c1,c2,c3,255) }
                  pen = new qpen()   { setcolor(color) setwidth(10) }
                  setpen(pen)
                  starty = y
                  nearest = seal[x][y]
                  for y = (y + 1)  to rightside
                       if seal[x][y] != nearest 
                          y = y - 1
                          exit 
                       ok
                  next
                  paint.drawline(x,starty,x,y + 1)
             next
        next
        endpaint()
        }
        label1 { setpicture(p1) show() }
        return
 
func chkpos(site,x,starty,endy)
        chkpos = 0
        dxsqr = 0
	dxsqr = pow((locx[site]- x),2)
	for y = starty to endy
	     dsqr = pow((locy[site] - y),2) + dxsqr
             if x <= leftside and y <= leftside and x > 0 and y > 0
	     if dsqr <= reach[x][y]
		reach[x][y]	= dsqr
		seal[x][y] = site
		chkpos = 1
             ok
	     ok
	next 
        return chkpos
 
func randomf()
       decimals(10)
       str = "0."
       for i = 1 to 10
            nr = random(9)
            str = str + string(nr)
       next
       return number(str)
