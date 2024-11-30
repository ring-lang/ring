# HassounaGameLib by Ahmed Hassouna (Free Course - YouTube)

$bgCount              = 0
$txtCount             = 0
$btnCount             = 0
$imgCount             = 0
$rectCount            = 0
$RoundRectCount       = 0
$lineCount            = 0
$circleCount          = 0
$ellipseCount         = 0
$triangleCount        = 0
$rectBorderCount      = 0
$roundRectBorderCount = 0
$circleBorderCount    = 0
$ellipseBorderCount   = 0

load "gameengine.ring"

func getColliders(blockWidth, blockHeight, aMap)
	xNow=0 yNow=0
	aColliders = []
	for x in aMap		
		for i in x
			if i != 0
				aColliders + [xNow, yNow, blockWidth, blockHeight]
			ok
			xNow += blockWidth
		next
		yNow += blockHeight
		xNow = 0	
	next
	return aColliders

func drawColliders(aColliders, oGame)
	for i in aColliders		
		oGame.addObj( getRectBorder(i[1], i[2], i[3], i[4], al_map_rgb(255,0,0), 2) )
	next

func setCollidersForAnimate(aColliders, obj)
	obj{
		addAttribute(self , :Colliders)
		Colliders = aColliders

		if not IsAttribute(self , "keypressFunctions")
			AddAttribute(self , :keypressFunctions)
			keypressFunctions = []
		ok

		keypressFunctions + func oGame, oSelf, nKey{
			oSelf{
				for c in Colliders
					cX=c[1] cY=c[2] cWidth=c[3] cHeight=c[4]
					
					if x+width  > cX && x < cX+cWidth &&
						y+height > cY && y < cY+cHeight

						if nKey=KEY_RIGHT x=cX-cWidth  +(cWidth-width)  ok
						if nKey=KEY_LEFT  x=cX+cWidth  ok
						if nKey=KEY_UP    y=cY+cHeight ok
						if nKey=KEY_DOWN  y=cY-cHeight +(cHeight-height) ok

					ok

				next
			}
		}

		keypress = func oGame, oSelf, nKey{
			oSelf{
				for cFunc in keypressFunctions
					call cFunc(oGame, oSelf, nKey)
				next
			}
		}

	}


func getMySound(cFile)
	return new sound{file=cFile once=true playing=true}

func playSound(oSound)
	oSound.playing=false
	oSound.playSound()

func stopSound(oSound)
	al_stop_sample(oSound.sampleid)

func loopSoundOK(oSound)
	oSound.once=false
	playSound(oSound)

func loopSoundNO(oSound)
	oSound.once=true
	stopSound(oSound)

func getFrames(cFile, nWidth, nHeight, nFramesCount, nTargetStep, nIsLoop)
	return new animate{
			addAttribute(self,:FramesCount)
			addAttribute(self,:TargetStep)
			addAttribute(self,:IsLoop)

			if not IsAttribute(self , "stateFunctions")
				AddAttribute(self , :stateFunctions)
				stateFunctions = []
			ok

			FramesCount = nFramesCount
			TargetStep = nTargetStep
			IsLoop = nIsLoop
			file=cFile x=10 y=10
			framewidth = nWidth
			width = nWidth
			height = nHeight
			transparent = true
			nStep = TargetStep
			stateFunctions + func oGame,oSelf{
				oSelf{
					nStep--
					if nStep=0
						nStep=TargetStep
						if frame<FramesCount
							frame++	
						else
							if IsLoop=0
								oGame.remove(oSelf.nIndex)
							else
								frame=1
							ok
						ok
					ok
				}
			}

			state = func oGame,oSelf{
				oSelf{
					for cFunc in stateFunctions
						call cFunc(oGame,oSelf)
					next
				}
			}

		}

func newFrames(oGame,cFile, nWidth, nHeight, nFramesCount, nTargetStep, nIsLoop)
		oGame.addObj( getFrames(cFile, nWidth, nHeight, nFramesCount, nTargetStep, nIsLoop) )

func newFramesWithXandY(oGame,cFile, nWidth, nHeight, nFramesCount, nTargetStep, nIsLoop, nX, nY)
		oGame.addObj( getFrames(cFile, nWidth, nHeight, nFramesCount, nTargetStep, nIsLoop){x=nX y=nY} )

func addBounds(obj)
obj{

	if not IsAttribute(self , "stateFunctions")
		AddAttribute(self , :stateFunctions)
		stateFunctions = []
	ok

	stateFunctions + func oGame, oSelf{
		oSelf{
			if x<0 x=0 ok
			if y<0 y=0 ok
			if x>oGame.width-width x=oGame.width-width ok
			if y>oGame.height-height y=oGame.height-height ok
		}
	}

	state = func oGame,oSelf{
		oSelf{
			for cFunc in stateFunctions
				call cFunc(oGame,oSelf)
			next
		}
	}

}

func addObjects(oGame,objectsList)
	for obj in objectsList
		ogame.addObj(obj)
	next

func addMove(obj)
	addBounds(obj)
	obj{move=true}

func addMouseMove(obj)
obj{
	addattribute(self,:isDown)
	addattribute(self,:mouseXdown)
	addattribute(self,:mouseYdown)

	if not IsAttribute(self , "mouseFunctions")
		AddAttribute(self , :mouseFunctions)
		mouseFunctions = []
	ok

	isDown=false mouseXdown=0 mouseYdown=0
	mouseFunctions + func oGame,oSelf,nType,aMouseList{
		oSelf{
			mX = aMouseList[GE_MOUSE_X]
			mY = aMouseList[GE_MOUSE_Y]
			if nType=GE_MOUSE_UP   isDown=false ok
			if mX >= x and mX <= x+width and mY >= y and mY <= y+height
				if nType=GE_MOUSE_DOWN 
					isDown=true mouseXdown=x-mX mouseYdown=y-mY
				ok
			ok
			if isDown 
				x=mX+mousexdown y=mY+mouseYdown
			ok
		}
	}

	mouse = func oGame,oSelf,nType,aMouseList{
		oSelf{
			for cFunc in mouseFunctions
				call cFunc(oGame,oSelf,nType,aMouseList)
			next
		}
	}

}

func addHoverMove(obj)
obj{
	mouseXdown=0 mouseYdown=0

	if not IsAttribute(self , "mouseFunctions")
		AddAttribute(self , :mouseFunctions)
		mouseFunctions = []
	ok

	mouseFunctions + func oGame,oSelf,nType,aMouseList{
		oSelf{
			mX = aMouseList[GE_MOUSE_X]
			mY = aMouseList[GE_MOUSE_Y]

			x=mX y=mY

		}
	}

	mouse = func oGame,oSelf,nType,aMouseList{
		oSelf{
			for cFunc in mouseFunctions
				call cFunc(oGame,oSelf,nType,aMouseList)
			next
		}
	}

}

func addClick(oObj, cFunc)
	oObj{

		if not isAttribute(self,:Click) 
			AddAttribute(self,:Click)
		ok
		if not IsAttribute(self , "mouseFunctions")
			AddAttribute(self , :mouseFunctions)
			mouseFunctions = []
		ok

		Click = cFunc
		mouseFunctions + func oGame, oSelf, nType, aMouseList{
			if nType = GE_MOUSE_UP
				MouseX = aMouseList[GE_MOUSE_X]
				MouseY = aMouseList[GE_MOUSE_Y]
				oSelf{
					if MouseX >= x and MouseX <= x+Width and
						MouseY >= y and MouseY <= y+Height
							call Click(oGame,oSelf)
					ok
				}
			ok
		}

		mouse = func oGame,oSelf,nType,aMouseList{
			oSelf{
				for cFunc in mouseFunctions
					call cFunc(oGame,oSelf,nType,aMouseList)
				next
			}
		}

	}

func addClickWithMouseMove(obj, cFunc)
	addMouseMove(obj)
	addClick(obj , cFunc)

func addClickWithHoverMove(obj, cFunc)
	addHoverMove(obj)
	addClick(obj , cFunc)

func getBgImage( imagePath )
	return new sprite{
		$bgCount += 1
		name = "bg" + $bgCount
		file = imagePath
		animate = false
		x=0 y=0 width=ge_screen_w height=ge_screen_h
		scaled = true
	}

func newBgImage(oGame, imagePath)
	oGame.addObj( getBgImage(imagePath) )

func getImage( nX,nY,nWidth,nHeight,imagePath )
	return new sprite{
		$imgCount += 1
		name = "img" + $imgCount
		file = imagePath
		animate = false
		x=nX y=nY width=nWidth height=nHeight
		scaled = true
		transparent = true
	}

func newImage( oGame,nX,nY,nWidth,nHeight,imagePath )
	oGame.addObj( getImage( nX,nY,nWidth,nHeight,imagePath ) )

func getImageMove( nX,nY,nWidth,nHeight,imagePath )
	img = getImage( nX,nY,nWidth,nHeight,imagePath )
	addMove(img)
	return img

func newImageMove( oGame,nX,nY,nWidth,nHeight,imagePath )
	oGame.addObj( getImageMove( nX,nY,nWidth,nHeight,imagePath ) )

func getImageMouseMove( nX,nY,nWidth,nHeight,imagePath )
	img = getImage( nX,nY,nWidth,nHeight,imagePath )
	addMouseMove(img)
	return img

func newImageMouseMove( oGame,nX,nY,nWidth,nHeight,imagePath )
	oGame.addObj( getImageMouseMove( nX,nY,nWidth,nHeight,imagePath ) )

func getTxt(text, fontSize, ALMapColor)
	return new gameObject{
		$txtCount += 1
		name = "txt" + $txtCount
		addattribute(self,:text)
		addattribute(self,:fontSize)	
		addattribute(self,:ALMapColor)
		addattribute(self,:TextFont)
		addattribute(self,:FontFile)
		self.ALMapColor = ALMapColor
		self.text = text
		self.fontSize = fontSize
		self.FontFile = "fonts/pirulen.ttf"
		TextFont = oResources.LoadFont(self.FontFile,fontSize)
		fontWidth  = al_get_text_width(TextFont,text)
		fontHeight = al_get_font_line_height(TextFont) 
		width=fontWidth height=fontHeight
		draw = func oGame,oSelf{
			oSelf{
				al_draw_text(TextFont, ALMapColor, x,y , GL_ALIGN_LEFT , text )
			}
		}
	}

func newTxt(oGame, text, fontSize, ALMapColor)
	oGame.addObj( getTxt(text,fontSize, ALMapColor) )

func getTxtMove(text, fontSize, ALMapColor)
	txt = getTxt(text, fontSize, ALMapColor)
	addMove(txt)
	return txt

func newTxtMove(oGame,text, fontSize, ALMapColor)
	oGame.addObj( getTxtMove(text, fontSize, ALMapColor) )

func getTxtMouseMove(text, fontSize, ALMapColor)
	txt = getTxt(text, fontSize, ALMapColor)
	addMouseMove(txt)
	return txt

func newTxtMouseMove(oGame,text, fontSize, ALMapColor)
	oGame.addObj( getTxtMouseMove(text, fontSize, ALMapColor) )

func getLine(nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	return new gameObject
	{
		$lineCount += 1
		name = "line" + $lineCount
		addattribute(self,:ALMapColor)
		addattribute(self,:x1)
		addattribute(self,:y1)
		addattribute(self,:x2)
		addattribute(self,:y2)
		addattribute(self,:Stroke)
		x=0 y=0 x1=nX1 y1=nY1 x2=nX2 y2=nY2 Stroke=nStroke
		width  = max(x1,x2) - min(x1,x2)
		height = max(y1,y2) - min(y1,y2)
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_line(x+x1,y+y1 , x+x2,y+y2 , ALMapColor , Stroke )
			}
		}
	}

func newLine(oGame,nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	oGame.addObj( getLine(nX1,nY1,nX2,nY2,nStroke,ALMapColor) )

func getLineMove(nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	myLine = getLine(nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	addMove(myLine)
	return myLine

func newLineMove(oGame,nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	oGame.addObj( getLineMove(nX1,nY1,nX2,nY2,nStroke,ALMapColor) )

func getLineMouseMove(nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	myLine = getLine(nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	addMouseMove(myLine)
	return myLine

func newLineMouseMove(oGame,nX1,nY1,nX2,nY2,nStroke,ALMapColor)
	oGame.addObj( getLineMouseMove(nX1,nY1,nX2,nY2,nStroke,ALMapColor) )

func getRect(nX,nY,nWidth,nHeight,ALMapColor)
	return new gameObject
	{
		$rectCount += 1
		name = "rect" + $rectCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_rectangle(x,y,x+width,y+height,ALMapColor)
			}
		}
	}

func newRect(oGame,nX,nY,nWidth,nHeight,ALMapColor)
	oGame.addObj( getRect(nX,nY,nWidth,nHeight,ALMapColor) )

func getRectMove(nX,nY,nWidth,nHeight,ALMapColor)
	rect = getRect(nX,nY,nWidth,nHeight,ALMapColor)
	addMove(rect)
	return rect

func newRectMove(oGame,nX,nY,nWidth,nHeight,ALMapColor)
	oGame.addObj( getRectMove(nX,nY,nWidth,nHeight,ALMapColor) )

func getRectMouseMove(nX,nY,nWidth,nHeight,ALMapColor)
	rect = getRect(nX,nY,nWidth,nHeight,ALMapColor)
	addMouseMove(rect)
	return rect

func newRectMouseMove(oGame,nX,nY,nWidth,nHeight,ALMapColor)
	oGame.addObj( getRectMouseMove(nX,nY,nWidth,nHeight,ALMapColor) )

func getRectBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	return new gameObject
	{
		$rectBorderCount += 1
		name = "rectBorder" + $rectBorderCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		addattribute(self,:Stroke)
		Stroke = nStroke
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_rectangle(x,y,x+width,y+height,ALMapColor,Stroke)
			}
		}
	}

func newRectBorder(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	oGame.addObj( getRectBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke) )

func getRectBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	rectBorder = getRectBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	addMove(rectBorder)
	return rectBorder

func newRectBorderMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	oGame.addObj( getRectBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke) )

func getRectBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	rectBorder = getRectBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	addMouseMove(rectBorder)
	return rectBorder

func newRectBorderMouseMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	oGame.addObj( getRectBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke) )

func getRectWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	return new gameObject
	{
		$rectCount += 1
		name = "rect" + $rectCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		addattribute(self,:ALMapColorStroke)
		addattribute(self,:Stroke)
		Stroke = nStroke
		self.ALMapColor=ALMapColor
		self.ALMapColorStroke=ALMapColorStroke
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_rectangle(x,y,x+width,y+height,ALMapColor)
				al_draw_rectangle(x,y,x+width,y+height,ALMapColorStroke,Stroke)
			}
		}
	}

func newRectWithBorder(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getRectWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke) )

func getRectWithBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	rect = getRectWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	addMove(rect)
	return rect

func newRectWithBorderMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getRectWithBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke) )

func getRectWithBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	rect = getRectWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	addMouseMove(rect)
	return rect

func newRectWithBorderMouseMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getRectWithBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke) )

func getRoundRect(nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	return new gameObject
	{
		$roundRectCount += 1
		name = "roundRect" + $roundRectCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		addattribute(self,:Radius)
		self.ALMapColor=ALMapColor
		Radius = nRadius
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_rounded_rectangle(x,y,x+width,y+height,Radius,Radius,ALMapColor)
			}
		}
	}

func newRoundRect(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	oGame.addObj( getRoundRect(nX,nY,nWidth,nHeight,nRadius,ALMapColor) )

func getRoundRectMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	roundRect = getRoundRect(nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	addMove( roundRect )
	return roundRect

func newRoundRectMove(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	oGame.addObj( getRoundRectMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor) )

func getRoundRectMouseMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	roundRect = getRoundRect(nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	addMouseMove( roundRect )
	return roundRect

func newRoundRectMouseMove(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor)
	oGame.addObj( getRoundRectMouseMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor) )

func getRoundRectBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	return new gameObject
	{
		$roundRectBorderCount += 1
		name = "roundRectBorder" + $roundRectBorderCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		addattribute(self,:Radius)
		addattribute(self,:Stroke)
		self.ALMapColor=ALMapColor Stroke=nStroke
		Radius = nRadius
		draw = func oGame,oSelf{
			oSelf{
				al_draw_rounded_rectangle(x,y,x+width,y+height,Radius,Radius,ALMapColor,Stroke)
			}
		}
	}

func newRoundRectBorder(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	oGame.addObj( getRoundRectBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke) )

func getRoundRectBorderMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	roundRectBorder = getRoundRectBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	addMove(roundRectBorder)
	return roundRectBorder

func newRoundRectBorderMove(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	oGame.addObj( getRoundRectBorderMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke) )

func getRoundRectBorderMouseMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	roundRectBorder = getRoundRectBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	addMouseMove(roundRectBorder)
	return roundRectBorder

func newRoundRectBorderMouseMove(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke)
	oGame.addobj( getRoundRectBorderMouseMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke) )

func getRoundRectWithBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	return new gameObject
	{
		$roundRectCount += 1
		name = "roundRect" + $roundRectCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		addattribute(self,:Radius)
		addattribute(self,:Stroke)
		addattribute(self,:ALMapColorStroke)
		self.ALMapColor=ALMapColor Stroke=nStroke
		self.ALMapColorStroke=ALMapColorStroke
		Radius = nRadius
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_rounded_rectangle(x,y,x+width,y+height,Radius,Radius,ALMapColor)
				al_draw_rounded_rectangle(x,y,x+width,y+height,Radius,Radius,ALMapColorStroke,Stroke)
			}
		}
	}

func newRoundRectWithBorder(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getRoundRectWithBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke) )

func getRoundRectWithBorderMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	rRect = getRoundRectWithBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	addMove(rRect)
	return rRect

func newRoundRectWithBorderMove(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getRoundRectWithBorderMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke) )

func getRoundRectWithBorderMouseMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	rRect = getRoundRectWithBorder(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	addMouseMove(rRect)
	return rRect

func newRoundRectWithBorderMouseMove(oGame,nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getRoundRectWithBorderMouseMove(nX,nY,nWidth,nHeight,nRadius,ALMapColor,nStroke,ALMapColorStroke) )

func getCircle(nX,nY,nRadius,ALMapColor)
	return new gameObject
	{
		$circleCount += 1
		name = "circle" + $circleCount
		x=nX y=nY width=nRadius*2 height=nRadius*2
		addattribute(self,:ALMapColor)
		addattribute(self,:Radius)
		Radius = nRadius
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_circle(x+Radius,y+Radius,Radius,ALMapColor)
			}
		}
	}

func newCircle(oGame,nX,nY,nRadius,ALMapColor)
	oGame.addObj( getCircle(nX,nY,nRadius,ALMapColor) )

func getCircleMove(nX,nY,nRadius,ALMapColor)
	circle = getCircle(nX,nY,nRadius,ALMapColor)
	addMove(circle)
	return circle

func newCircleMove(oGame,nX,nY,nRadius,ALMapColor)
	oGame.addObj( getCircleMove(nX,nY,nRadius,ALMapColor) )

func getCircleMouseMove(nX,nY,nRadius,ALMapColor)
	circle = getCircle(nX,nY,nRadius,ALMapColor)
	addMouseMove(circle)
	return circle

func newCircleMouseMove(oGame,nX,nY,nRadius,ALMapColor)
	oGame.addObj( getCircleMouseMove(nX,nY,nRadius,ALMapColor) )

func getCircleBorder(nX,nY,nRadius,ALMapColor,nStroke)
	return new gameObject
	{
		$circleBorderCount += 1
		name = "circleBorder" + $circleBorderCount
		x=nX y=nY width=nRadius*2 height=nRadius*2
		addattribute(self,:ALMapColor)
		addattribute(self,:Radius)
		addattribute(self,:Stroke)
		Stroke=nStroke
		Radius = nRadius
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_circle(x+Radius,y+Radius,Radius,ALMapColor,Stroke)
			}
		}
	}

func newCircleBorder(oGame,nX,nY,nRadius,ALMapColor,nStroke)
	oGame.addObj( getCircleBorder(nX,nY,nRadius,ALMapColor,nStroke) )

func getCircleBorderMove(nX,nY,nRadius,ALMapColor,nStroke)
	circleB = getCircleBorder(nX,nY,nRadius,ALMapColor,nStroke)
	addMove(circleB)
	return circleB

func newCircleBorderMove(oGame,nX,nY,nRadius,ALMapColor,nStroke)
	oGame.addObj( getCircleBorderMove(nX,nY,nRadius,ALMapColor,nStroke) )

func getCircleBorderMouseMove(nX,nY,nRadius,ALMapColor,nStroke)
	circleB = getCircleBorder(nX,nY,nRadius,ALMapColor,nStroke)
	addMouseMove(circleB)
	return circleB

func newCircleBorderMouseMove(oGame,nX,nY,nRadius,ALMapColor,nStroke)
	oGame.addObj( getCircleBorderMouseMove(nX,nY,nRadius,ALMapColor,nStroke) )

func getCircleWithBorder(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	return new gameObject
	{
		$circleCount += 1
		name = "circle" + $circleCount
		x=nX y=nY width=nRadius*2 height=nRadius*2
		addattribute(self,:ALMapColor)
		addattribute(self,:Radius)
		addattribute(self,:Stroke)
		addattribute(self,:ALMapColorStroke)
		Stroke=nStroke
		Radius = nRadius
		self.ALMapColor=ALMapColor
		self.ALMapColorStroke=ALMapColorStroke
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_circle(x+Radius,y+Radius,Radius,ALMapColor)
				al_draw_circle(x+Radius,y+Radius,Radius,ALMapColorStroke,Stroke)
			}
		}
	}

func newCircleWithBorder(oGame,nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getCircleWithBorder(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke) )

func getCircleWithBorderMove(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	circle = getCircleWithBorder(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	addMove(circle)
	return circle

func newCircleWithBorderMove(oGame,nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getCircleWithBorderMove(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke) )

func getCircleWithBorderMouseMove(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	circle = getCircleWithBorder(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	addMouseMove(circle)
	return circle

func newCircleWithBorderMouseMove(oGame,nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getCircleWithBorderMouseMove(nX,nY,nRadius,ALMapColor,nStroke,ALMapColorStroke) )

func getEllipse(nX,nY,nWidth,nHeight,ALMapColor)
	return new gameObject
	{
		$ellipseCount += 1
		name = "ellipse" + $ellipseCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_ellipse(x+(width/2),y+(height/2),(width/2),(height/2),ALMapColor)
			}
		}
	}

func newEllipse(oGame,nX,nY,nWidth,nHeight,ALMapColor)
	oGame.addObj( getEllipse(nX,nY,nWidth,nHeight,ALMapColor) )

func getEllipseMove(nX,nY,nWidth,nHeight,ALMapColor)
	ell = getEllipse(nX,nY,nWidth,nHeight,ALMapColor)
	addMove(ell)
	return ell

func newEllipseMove(oGame,nX,nY,nWidth,nHeight,ALMapColor)
	oGame.addObj( getEllipseMove(nX,nY,nWidth,nHeight,ALMapColor) )

func getEllipseMouseMove(nX,nY,nWidth,nHeight,ALMapColor)
	ell = getEllipse(nX,nY,nWidth,nHeight,ALMapColor)
	addMouseMove(ell)
	return ell

func newEllipseMouseMove(oGame,nX,nY,nWidth,nHeight,ALMapColor)
	oGame.addObj( getEllipseMouseMove(nX,nY,nWidth,nHeight,ALMapColor) )

func getEllipseBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	return new gameObject
	{
		$ellipseBorderCount += 1
		name = "ellipseBorder" + $ellipseBorderCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		addattribute(self,:Stroke)
		Stroke=nStroke
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_ellipse(x+(width/2),y+(height/2),(width/2),(height/2),ALMapColor,Stroke)
			}
		}
	}

func newEllipseBorder(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	oGame.addObj( getEllipseBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke) )

func getEllipseBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	ellB = getEllipseBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	addMove(ellB)
	return ellB

func newEllipseBorderMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	oGame.addObj( getEllipseBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke) )

func getEllipseBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	ellB = getEllipseBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	addMouseMove(ellB)
	return ellB

func newEllipseBorderMouseMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke)
	oGame.addObj( getEllipseBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke) )

func getEllipseWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	return new gameObject
	{
		$ellipseCount += 1
		name = "ellipse" + $ellipseCount
		x=nX y=nY width=nWidth height=nHeight
		addattribute(self,:ALMapColor)
		addattribute(self,:Stroke)
		addattribute(self,:ALMapColorStroke)
		Stroke=nStroke
		self.ALMapColor=ALMapColor
		self.ALMapColorStroke=ALMapColorStroke
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_ellipse(x+(width/2),y+(height/2),(width/2),(height/2),ALMapColor)
				al_draw_ellipse(x+(width/2),y+(height/2),(width/2),(height/2),ALMapColorStroke,Stroke)
			}
		}
	}

func newEllipseWithBorder(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getEllipseWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke) )

func getEllipseWithBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	ell = getEllipseWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	addMove(ell)
	return ell

func newEllipseWithBorderMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getEllipseWithBorderMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke) )

func getEllipseWithBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	ell = getEllipseWithBorder(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	addMouseMove(ell)
	return ell

func newEllipseWithBorderMouseMove(oGame,nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getEllipseWithBorderMouseMove(nX,nY,nWidth,nHeight,ALMapColor,nStroke,ALMapColorStroke) )

func getTriangle(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	return new gameObject
	{
		$triangleCount += 1
		name = "triangle" + $triangleCount
		addattribute(self,:ALMapColor)
		addattribute(self,:x1)
		addattribute(self,:y1)
		addattribute(self,:x2)
		addattribute(self,:y2)
		addattribute(self,:x3)
		addattribute(self,:y3)
		x=0 y=0 x1=nX1 y1=nY1 x2=nX2 y2=nY2 x3=nX3 y3=nY3
		width  = max(max(x1,x2),x3) - min(min(x1,x2),x3)
		height = max(max(y1,y2),y3) - min(min(y1,y2),y3)
		self.ALMapColor=ALMapColor
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_triangle(x+x1,y+y1, x+x2,y+y2, x+x3,y+y3 ,ALMapColor)
			}
		}
	}

func newTriangle(oGame,nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	oGame.addObj( getTriangle(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor) )

func getTriangleMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	tri = getTriangle(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	addMove(tri)
	return tri

func newTriangleMove(oGame,nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	oGame.addObj( getTriangleMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor) )

func getTriangleMouseMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	tri = getTriangle(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	addMouseMove(tri)
	return tri

func newTriangleMouseMove(oGame,nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor)
	oGame.addObj( getTriangleMouseMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor) )

func getTriangleBorder(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	return new gameObject
	{
		$triangleCount += 1
		name = "triangle" + $triangleCount
		addattribute(self,:ALMapColorStroke)
		addattribute(self,:Stroke)
		addattribute(self,:x1)
		addattribute(self,:y1)
		addattribute(self,:x2)
		addattribute(self,:y2)
		addattribute(self,:x3)
		addattribute(self,:y3)
		x=0 y=0 x1=nX1 y1=nY1 x2=nX2 y2=nY2 x3=nX3 y3=nY3
		width  = max(max(x1,x2),x3) - min(min(x1,x2),x3)
		height = max(max(y1,y2),y3) - min(min(y1,y2),y3)
		self.ALMapColorStroke=ALMapColorStroke
		self.Stroke=nStroke
		draw = func oGame,oSelf{
			oSelf{
				al_draw_triangle(x+x1,y+y1, x+x2,y+y2, x+x3,y+y3 ,ALMapColorStroke,Stroke)
			}
		}
	}


func newTriangleBorder(oGame,nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	oGame.addObj( getTriangleBorder(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke) )

func getTriangleBorderMove(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	tri = getTriangleBorder(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	addMove(tri)
	return tri

func newTriangleBorderMove(oGame,nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	oGame.addObj( getTriangleBorderMove(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke) )


func getTriangleBorderMouseMove(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	tri = getTriangleBorder(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	addMouseMove(tri)
	return tri

func newTriangleBorderMouseMove(oGame,nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke)
	oGame.addObj( getTriangleBorderMouseMove(nX1,nY1,nX2,nY2,nX3,nY3,nStroke,ALMapColorStroke) )


func getTriangleWithBorder(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	return new gameObject
	{
		$triangleCount += 1
		name = "triangle" + $triangleCount
		addattribute(self,:ALMapColor)
		addattribute(self,:ALMapColorStroke)
		addattribute(self,:Stroke)
		addattribute(self,:x1)
		addattribute(self,:y1)
		addattribute(self,:x2)
		addattribute(self,:y2)
		addattribute(self,:x3)
		addattribute(self,:y3)
		x=0 y=0 x1=nX1 y1=nY1 x2=nX2 y2=nY2 x3=nX3 y3=nY3
		width  = max(max(x1,x2),x3) - min(min(x1,x2),x3)
		height = max(max(y1,y2),y3) - min(min(y1,y2),y3)
		self.ALMapColor=ALMapColor
		self.ALMapColorStroke=ALMapColorStroke
		self.Stroke=nStroke
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_triangle(x+x1,y+y1, x+x2,y+y2, x+x3,y+y3 ,ALMapColor)
				al_draw_triangle(x+x1,y+y1, x+x2,y+y2, x+x3,y+y3 ,ALMapColorStroke,Stroke)
			}
		}
	}

func newTriangleWithBorder(oGame,nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getTriangleWithBorder(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke) )

func getTriangleWithBorderMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	tri = getTriangleWithBorder(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	addMove(tri)
	return tri

func newTriangleWithBorderMove(oGame,nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getTriangleWithBorderMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke) )

func getTriangleWithBorderMouseMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	tri = getTriangleWithBorder(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	addMouseMove(tri)
	return tri

func newTriangleWithBorderMouseMove(oGame,nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke)
	oGame.addObj( getTriangleWithBorderMouseMove(nX1,nY1,nX2,nY2,nX3,nY3,ALMapColor,nStroke,ALMapColorStroke) )


func getButton(nX,nY,nWidth,nHeight,cText,cFunc)
	return new gameObject{
		$btnCount += 1
		name = "btn" + $btnCount
		move=false
		width=nWidth height=nHeight x=nX y=nY
		addAttribute(self,:Text)
		addAttribute(self,:Font)
		addAttribute(self,:fontWidth)
		addAttribute(self,:fontHeight)
		addAttribute(self,:center_txt_x)
		addAttribute(self,:center_txt_y)
		AddAttribute(self,:Click)
		Click = cFunc
		Text = cText
		Font = oResources.LoadFont("fonts/pirulen.ttf",25)
		fontWidth  = al_get_text_width(Font,Text)
		fontHeight = al_get_font_line_height(Font) 
		center_txt_x = (width-fontWidth)/2
		center_txt_y = (height-fontHeight)/2

		addClick(self , cFunc)

		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_rectangle(x,y,x+width,y+height,al_map_rgb(0,120,250))
				al_draw_rectangle(x,y,x+width,y+height,al_map_rgb(0,0,0),2)
				al_draw_text(Font,al_map_rgb(0,0,0),x+center_txt_x,y+center_txt_y,0,Text)
			}
		}
	}

func newButton(oGame, nX,nY,nWidth,nHeight,cText,cFunc)
	oGame.addObj( getButton(nX,nY,nWidth,nHeight,cText,cFunc) )

func getRoundButton(nX,nY,nWidth,nHeight,nRadius,cText,cFunc)
	return new gameObject{
		$btnCount += 1
		name = "btn" + $btnCount
		move=false
		width=nWidth height=nHeight x=nX y=nY
		addAttribute(self,:Text)
		addAttribute(self,:Font)
		addAttribute(self,:fontWidth)
		addAttribute(self,:fontHeight)
		addAttribute(self,:center_txt_x)
		addAttribute(self,:center_txt_y)
		AddAttribute(self,:Click)
		addAttribute(self,:Radius)
		Radius = nRadius
		Click = cFunc
		Text = cText
		Font = oResources.LoadFont("fonts/pirulen.ttf",25)
		fontWidth  = al_get_text_width(Font,Text)
		fontHeight = al_get_font_line_height(Font) 
		center_txt_x = (width-fontWidth)/2
		center_txt_y = (height-fontHeight)/2
		addClick(self , cFunc)
		draw = func oGame,oSelf{
			oSelf{
				al_draw_filled_rounded_rectangle(x,y,x+width,y+height,Radius,Radius,al_map_rgb(0,120,250))
				al_draw_rounded_rectangle(x,y,x+width,y+height,Radius,Radius,al_map_rgb(0,0,0),2)
				al_draw_text(Font,al_map_rgb(0,0,0),x+center_txt_x,y+center_txt_y,0,Text)
			}
		}
	}

func newRoundButton(oGame,nX,nY,nWidth,nHeight,nRadius,cText,cFunc)
	oGame.addObj( getRoundButton(nX,nY,nWidth,nHeight,nRadius,cText,cFunc) )


class animiAll
	imageBase=NULL imageLeft=NULL imageTop=NULL imageRight=NULL imageBottom=NULL
	width=NULL height=NULL framesCount=NULL 
	targetStep=9 speed=5 IsLoop=True IsBounds=True

	func getAnimi()
		return new animate{

			addAttribute(self , :imageBase)
			addAttribute(self , :imageLeft)
			addAttribute(self , :imageTop)
			addAttribute(self , :imageRight)
			addAttribute(self , :imageBottom)
			addAttribute(self , :framesCount)
			addAttribute(self , :targetStep)
			addAttribute(self , :speed)
			addAttribute(self , :IsLoop)
			addAttribute(self , :IsBounds)

			if not IsAttribute(self , "stateFunctions")
				AddAttribute(self , :stateFunctions)
				stateFunctions = []
			ok

			if not IsAttribute(self , "keypressFunctions")
				AddAttribute(self , :keypressFunctions)
				keypressFunctions = []
			ok

			transparent=true
			imageBase=this.imageBase 
			imageLeft=this.imageLeft
			imageTop=this.imageTop
			imageRight=this.imageRight
			imageBottom=this.imageBottom
			framesCount=this.framesCount
			targetStep=this.targetStep
			speed=this.speed
			IsLoop=this.IsLoop
			IsBounds=this.IsBounds
			nStep=targetStep
			file=this.imageBase
			frameWidth=this.width
			width=this.width
			height=this.height

			stateFunctions + func oGame,oSelf{
				oSelf{
					if IsBounds
						if x<0 x=0 ok
						if y<0 y=0 ok
						if x>oGame.width-width x=oGame.width-width ok
						if y>oGame.height-height y=oGame.height-height ok
					ok
					nStep--
					if nStep=0
						file=imageBase
						nStep=targetStep
						if frame<framesCount 
							frame++
						else
							if IsLoop=0
								oGame.remove(oSelf.nIndex)
							else
								frame=1
							ok
						ok
					ok
				}
			}

			state = func oGame,oSelf{
				oSelf{
					for cFunc in stateFunctions
						call cFunc(oGame,oSelf)
					next
				}
			}


			keypressFunctions + func oGame, oSelf, nKey{
				oSelf{
					switch nKey
						on KEY_LEFT
							file = imageLeft
							x -= speed
						on KEY_RIGHT
							file = imageRight
							x += speed
						on KEY_UP
							file = imageTop
							y -= speed
						on KEY_DOWN
							file = imageBottom
							y += speed
					off
					doTransparent()
				}
			}

			keypress = func oGame, oSelf, nKey{
				oSelf{
					for cFunc in keypressFunctions
						call cFunc(oGame, oSelf, nKey)
					next
				}
			}


		}


