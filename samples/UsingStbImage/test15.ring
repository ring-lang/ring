load "guilib.ring"
load "fastpro.ring"

width      = 1024
height     = 768
channels   = 3
cData      = space(width*height*channels)
nRandom    = 0.1
nDirection = 0.05

prepare()

MyApp = new QApp 
{
   win1 = new QWidget() 
   {  setwindowtitle("Fast Animation")
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


func prepare 
    nIndex=0
    for x=1 to height
        for y=1 to width
            cData[nIndex++] = x*x
            cData[nIndex++] = x*y
            cData[nIndex++] = clock()
        next
    next

func pTime

	t1= clock()

	cData2 = updateBytesColumn(cData,channels,width*height,1,
		:mul,1,nRandom*2,
		:mul,2,nRandom,
		:mul,3,nRandom*2)

    daVinci.drawbytes(0,0,cData2,width,Height,channels)
    canvas.setPixMap(MonaLisa)

    nRandom += nDirection
	if nRandom > 5
		nDirection = -0.05
	elseif nRandom < -7
		nDirection = 0.05
	ok

	? "FPS: " + floor(clockspersecond()/(clock()-t1))
