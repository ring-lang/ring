load "lightguilib.ring"

oApp = new QApp {

	w = new QWidget() {

		setWindowTitle("Using Graphics View Framework (Click on any object to hide it)")
		resize(800,600)

		scene = new QGraphicsScene(w)

 		color  = new QColor() { setrgb(0,0,255,255) }
 		color2 = new QColor() { setrgb(0,0,0,255) }
 		color3 = new QColor() { setrgb(0,250,0,255) }

                pen = new qpen() {
                        setcolor(color2)
                        setwidth(10)
                }
                pen2 = new qpen() {
                        setcolor(color2)
                        setwidth(1)
                }

		brush = new QBrush() { setStyle(1) setColor(color) }
		brush2 = new QBrush() { setStyle(1) setColor(color3) }

		oMainItem = scene.addrect_2(-200,-100,200,200,PEN,BRUSH)
 		oFont = new QFont("Times",10,-1,0)

		oText = scene.addSimpleText("I LOVE PROGRAMMING",oFont) 
		oText.setBrush(brush2)
		oText.moveBy(-190,10)

		path = new QPainterPath() {
			path.moveTo(20, 80)
			path.lineTo(120, 130)
			path.cubicTo(80, 0, 150, 250, 280, 80)
                }

		oPath = scene.addPath(path,PEN,BRUSH)

		aObjects = []
		nCount   = 0

		for t1=1 to 50
			for t2=1 to 100
				nCount++
				nDX  = (150*t1)
				nDY  = (150*t2)

				path = new QPainterPath() 
				path.moveTo(nDX, nDY)
				path.lineTo(nDX+120, nDY+130)
				path.cubicTo(nDX+80, nDY+0, nDX+150, nDY+250, nDX+280,nDY+ 80)               
				oPath = scene.addPath(path,PEN,BRUSH)

				OItem = scene.addrect_2(nDX,nDY,100,100,PEN2,BRUSH2)
				oText = scene.addsimpletext("No("+nCount+")",oFont)
				oText.setbrush(brush)
				oText.moveby(nDX+15,nDY+40)
				aObjects + [oItem,oText]

			next
		next

		view = new QGraphicsView(w) {

			resize(800,600)
			setScene(scene)

			oFilter = new QAllEvents(view)
			oFilter.setMouseButtonPressEvent("clickEvent()")
			installEventFilter(OfILTER)
		}
		view.show()

		btn1 = new QPushButton(w) {
			setText("Move")
			setClickEvent("moveObjects()")
		}

		view2 = new QGraphicsView(w) {
			resize(800,600)
			setScene(scene)

		}
		view2.rotate(30)
		view2.scale(0.05,0.05)
		view2.show()

		oLayout = new QVBoxLayout() {
			addWidget(view)
			addWidget(btn1)
			addWidget(view2)
		}
		setLayout(oLayout)

		show()

	}

	exec()

}

func moveObjects 

	for aSub in aObjects 
		aSub[1].moveby(10,10)
		aSub[2].moveby(10,10)
	next 

func clickEvent
 
	x = oFilter.getX()
	y = oFilter.getY()
	pos = new QPoint() { setX(x) setY(y) }
	scenePoint = view.mapToScene(pos)
	item = scene.itemAt(scenePoint, new QTransform3())
	scene.removeItem(item)


