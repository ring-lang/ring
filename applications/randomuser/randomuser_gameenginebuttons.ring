#=====================================#
# Random User Application	
# Version using GameLib (Buttons)
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"

# Global Variables

	cFirstName = ""
	cLastName  = ""
	cEmail     = ""
	cImageFile = ""

# Constants

	C_IMAGEFILENAME  = "UserPhoto.jpg"

	# Delay time before getting new User data
		C_DEALYINSECONDS = 3		
	
Load "gameengine.ring"				# Give control to the game engine

func main					# Called by the Game Engine

	LoadUserData()

	GE_SCREEN_W = 750
	GE_SCREEN_H = 450

	oGame = New Game			# Create the Game Object
	{

		title = "Random User - Using GameLib (Buttons)"
		icon  = "images/appicon.png"

		sprite {
			name = :UserImage
			x=50 y=100 width=100 height=100
			file = C_IMAGEFILENAME
			Animate=false
		}

		text {
			name = :UserName
			x = 50	y=250
			animate = false
			size = 20
			file = "fonts/pirulen.ttf"
			text = cFirstName + " " + cLastName
			color = rgb(0,0,0)				# Color = black	
		}

		text {
			name = :UserEmail
			x = 50	y=300
			animate = false
			size = 20
			file = "fonts/pirulen.ttf"
			text = "Email: " + cEmail
			color = rgb(0,0,0)				# Color = black	
		}

		NewButton(oGame,300,100,400,40,"New User Data",:NewUserData)
		NewButton(oGame,300,150,400,40,"Close Application",:CloseApplication)


	}

func LoadUserData

	? "Loading..."
	
	cData= download("https://randomuser.me/api")
		
	aList= JSON2List(cData)
			
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cImageFile = aList[:Results][1][:picture][:large]
	
	write(C_IMAGEFILENAME,download(cImageFile))
	
	? "Ready..."

func NewButton oGame,nX,nY,nWidth,nHeight,cText,cFunc
	oGame {
		Object {
                        x = nX y=nY width = nWidth height=nHeight
			AddAttribute(self,:Text)
			AddAttribute(self,:EventCode)
			AddAttribute(self,:oFont)
			oFont = oResources.LoadFont("fonts/pirulen.ttf",20)
			Text = cText
			EventCode = cFunc
                        draw = func oGame,oSelf {
                                oSelf {
					gl_draw_filled_rectangle(x,y,x+width,y+height,gl_map_rgb(0,100,255))
					gl_draw_rectangle(x,y,x+width,y+height,gl_map_rgb(0,0,0),2)
					gl_draw_text(oFont,gl_map_rgb(0,0,0),x+width/2,y+5,1,Text)
				}
			}
			mouse = func oGame,oSelf,nType,aMouseList {
				if nType = GE_MOUSE_UP
					MouseX = aMouseList[GE_MOUSE_X]
					MouseY = aMouseList[GE_MOUSE_Y]
					oSelf {
						if MouseX >= x and MouseX <= X+270 and
						   MouseY >= y and MouseY <= Y+40		
						       call EventCode(oGame,oSelf)
						ok  
					}
				ok
			}
		}
	}
	return len(oGame.aObjects)

func NewUserData oGame,oSelf 
	LoadUserData()
	oGame {
		find(:UserName).text = cFirstName + " " + cLastName
		find(:UserEmail).text = "Email: " + cEmail
		# Remove the old image from the Cache
			oResources.UnloadImage(C_IMAGEFILENAME)
		# Load the new Image
			find(:UserImage).file = C_IMAGEFILENAME	
	}

func CloseApplication oGame,oSelf 
	oGame.Shutdown()
