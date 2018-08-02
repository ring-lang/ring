Load "stdlibcore.ring"
Load "guilib.ring"

oApp = new qApp
{
  posX= -1  posY= -1  mB= -1

  win1 = new qWidget()
  {
    setWindowTitle("Custom Event Loop!")
    setWindowTitle(" X,Y " +posX  +"  " +posY +"  " +mB)
    setGeometry(100,100,400,400)
    setmousetracking(true)
    myfilter = new qallevents(win1)
    myfilter.setKeyPressEvent("pKey()")
    myfilter.setMouseButtonPressevent("pClick()")
    myfilter.setmousemoveevent("pMove()")
    installeventfilter(myfilter)

    show()

    while true
  	oApp.processevents()
        ? " X,Y " +posX  +"  " +posY +"  " +mB
    end 
  }

}

func pClick
  posX=  myfilter.getx()   posY=  myfilter.gety()   mb= myfilter.getbutton()
  win1.setwindowtitle("click(): X : " +posX +  " Y : " +posY  +" Btn " +mb)

func pKey
 win1.setwindowtitle('pKey() Key: ' + myfilter.getkeycode())

func pMove
  posX=  myfilter.getx()   posY=  myfilter.gety()   mb= myfilter.getbutton()
  win1.setwindowtitle("pMove() , X : " + myfilter.getx() +  " Y : " + myfilter.gety() ) 


