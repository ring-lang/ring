width    = 640
height   = 480
channels = 3
cData    = space(width*height*channels)

nRandom  = 0.1
nDirection = 0.1

load "guilib.ring"
 
MyApp = new QApp 
{
   win1 = new QWidget() 
   {  setwindowtitle("Animation")
      setgeometry(0,0,Width,Height)
      
      Canvas = new QLabel(win1)
      {  

         MonaLisa  = new QPixMap2( Width, Height)

         daVinci = new QPainter()
         {  
		begin(MonaLisa)
         }

         new qtimer(win1) {
                setinterval(100)
                settimeoutevent("pTime()")
                start()
         }
         
         setPixMap(MonaLisa)
      }
      
      show()
   }
         
   exec()
}   


func pTime

    nIndex=0
    for x=1 to height
        for y=1 to width
            cData[nIndex++] = (x*x*nRandom)%256
            cData[nIndex++] = (x*y*nRandom)%256
            cData[nIndex++] = clock()%256
        next
    next

    daVinci.drawbytes(0,0,cData,width,Height,channels)
    canvas.setPixMap(MonaLisa)

    nRandom += nDirection
    if nRandom >= 2
	nDirection = -0.05
    ok
    if nRandom <= 0.1
	nDirection = 0.05
    ok