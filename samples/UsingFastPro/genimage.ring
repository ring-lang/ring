load "stbimage.ring"
load "fastpro.ring"
load "lightguilib.ring"

width    = 640
height   = 480
channels = 3
cImage   = space(width*height*channels)
RVALUE   = 3
GVALUE   = 4
BVALUE   = 5

nIndex=0
for x=1 to height
        for y=1 to width
                cImage[nIndex++] = x*x
                cImage[nIndex++] = x*y
                cImage[nIndex++] = x*2
        next
next

aList = Bytes2List(cImage,Width,Height,Channels,255)
updateColumn(aList,:mul,RVALUE,0.3,              # R *= 0.3
                    :mul,GVALUE,0.59,            # G *= 0.59
                    :mul,BVALUE,0.11,            # B *= 0.11
                    :merge,RVALUE,GVALUE,        # R += G
                    :merge,RVALUE,BVALUE,        # R += B
                    :copy,RVALUE,GVALUE,         # G = R
                    :copy,RVALUE,BVALUE)         # B = R

cGrayImage = list2Bytes(aList,Channels,255)
   
nWindowWidth = Width*2 + 100

MyApp = new QApp 
{
   win1 = new QWidget() 
   {  setwindowtitle("Generate Image & Convert it to Gray")
      setgeometry(0,0,nWindowWidth,Height)
      
      Canvas = new QLabel(win1)
      {  

         MonaLisa  = new QPixMap2( nWindowWidth, Height)

         daVinci = new QPainter()
         {  
		begin(MonaLisa)
		drawbytes(0,0,cImage,width,Height,channels)
		drawbytes(width+10,0,cGrayImage,width,Height,channels)
            	endpaint()           
         }
         
         setPixMap(MonaLisa)
      }
      
      show()
   }
         
   exec()
}