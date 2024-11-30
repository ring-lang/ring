# HassounaSuperman by Ahmed Hassouna (Free Course - YouTube)

oGame        = null
txt1         = null
btn1         = null
sound1       = null
sound2       = null
starCount    = 0
starGetCount = 0
aColliders   = null

load "HassounaGameLib.ring"

func main

	ge_screen_w = 1600 
	ge_screen_h = 800

	oGame = New Game
	{
		title = "Welcome to Hassouna Superman ON Any OS"
		icon = "images/superman.png"
		newBGImage(oGame, "images/supermancity.jpg")
		sound1 = getMySound("sound/sfx_point.wav")
		sound2 = getMySound("sound/sfx_magic.wav")
		
		a1 = new animiAll{
			imageBase = 'images/smbase.png'
			imageLeft = 'images/smleft.png'
			imageTop = 'images/smup.png'
			imageRight = 'images/smright.png'
			imageBottom = 'images/smdown.png'
			width=60 height=97 framesCount=2
		}
		myPlayer = a1.getAnimi(){name=:player}
		
		myBlockWidth = 80
		myBlockHeight = 80
		myAMap = [
			[0,2,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,1],
			[0,0,0,2,0,1,0,0,1,0,2,0,2,0,0,0,1,0,0,1],
			[0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,1,0,0,2],
			[0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0],
			[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
			[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
			[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
			[0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0],
			[3,0,0,0,3,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0],
			[1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,3,0,0]
		]

		map{
			blockWidth = myBlockWidth
			blockHeight = myBlockHeight
			aMap = myAMap
			aImages = [
				"images/smwall.png" , "images/smwalldown.png" , "images/smwallup.png"
			]
		}

		aColliders = getColliders(myBlockWidth, myBlockHeight, myAMap)
		setCollidersForAnimate(aColliders, myPlayer)
		myPlayer.y=100
		myStart()
		addObj(myPlayer)
	}

func myNewGame(oGame,oSelf)
	oGame.remove(txt1.nIndex)
	oGame.remove(btn1.nIndex)
	myStart()

func myStart()
	starWidth=90 starHeight=90
	for i=1 to 15
		starX = random(ge_screen_w-starWidth)
		starY = random(ge_screen_h-starHeight)
		IsCollider=False
		for c in aColliders
			cX=c[1] cY=c[2] cWidth=c[3] cHeight=c[4]

			if starX+starWidth  > cX && starX < cX+cWidth &&
				starY+starHeight > cY && starY < cY+cHeight
					IsCollider=True
			ok
		next

		if not IsCollider
			img = getImage(starX, starY, starWidth, starHeight, "images/smstar.png")
			img{
				state = func oGame,oSelf{
					oSelf{
						myPlayer = oGame.find(:player)
						if myPlayer.x+myPlayer.width  > x && myPlayer.X < x+width &&
							myPlayer.y+myPlayer.height > y && myPlayer.Y < y+height
								playSound(sound1)
								oGame.remove(oSelf.nIndex)
								starGetCount++
								if starCount=starGetCount
									playSound(sound2)
									txt1 = getTxt("* You Win *",90,al_map_rgb(190,0,0))
									{ x=450 y=330 }
									oGame.addObj(txt1)
									btn1 = getRoundButton(690,440,250,75,10,"New Game",:myNewGame)
									oGame.addObj(btn1)
								ok
						ok
					}
				}
			}
			oGame.addObj(img)
			starCount++
		ok

	next
