#=====================================#
# Random User Application	
# Another version using GameLib
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

		title = "Random User - Using GameLib"
		icon  = "images/appicon.png"

		sprite {

			x=50 y=100 width=100 height=100
			file = C_IMAGEFILENAME
			Animate=false

			AddAttribute(self,:nClock)
			nClock = clock()

			state = func oGame, oSelf { 
				oSelf { 
					if (clock()-nClock)/clockspersecond() > C_DEALYINSECONDS 
						LoadUserData()
						oGame {
							find(:UserName).text = cFirstName + " " + cLastName
							find(:UserEmail).text = "Email: " + cEmail
						}
						# Remove the old image from the Cache
							oResources.UnloadImage(C_IMAGEFILENAME)
						# Load the new Image
							file = C_IMAGEFILENAME	
						nClock = clock()
					ok 
				}
			}
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
	
