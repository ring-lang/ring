#=====================================#
# Random User Application	
# Version using RayLib
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"
load "raylib.ring"

cFirstName = ""
cLastName  = ""
cEmail     = ""
cGender    = ""
cImageFile = ""

GetUserData()

screenWidth = 800
screenHeight = 600

InitWindow(screenWidth, screenHeight, "Random User application")

icon = LoadImage("images/appicon.png")

userphoto = LoadTexture("UserPhoto.jpg")        

frameWidth = userphoto.width
frameHeight = userphoto.height

sourceRec = Rectangle( 0.0, 0.0, frameWidth, frameHeight )
destRec = Rectangle( screenWidth/2, screenHeight/2, frameWidth*2, frameHeight*2 )

origin = Vector2( frameWidth, frameHeight )

rotation = 0

nClock = 0

SetTargetFPS(60)

while !WindowShouldClose()

	rotation++

	BeginDrawing()
		if cGender = "male"
			ClearBackground(WHITE)
		else 
			ClearBackground(YELLOW)
		ok
		SetWindowIcon(icon)
		DrawTexturePro(userphoto, sourceRec, destRec, origin, rotation, WHITE)
		DrawText(cFirstName+" "+cLastName,100,50, 20, BLACK)
		DrawText("Email: " + cEmail,100,90, 20, BLACK)
	EndDrawing()

	if rotation > 360 and (clock()-nClock)/clockspersecond() > 3
			GetUserData()
			userphoto = LoadTexture("UserPhoto.jpg")   
			nClock   = Clock()
			rotation = 0
	ok

end

UnloadTexture(userphoto)       

CloseWindow()

func GetUserData

	cData= download("https://randomuser.me/api")
		
	aList= JSON2List(cData)
			
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cGender    = aList[:Results][1][:gender]
	cImageFile = aList[:Results][1][:picture][:large]
	
	write("UserPhoto.jpg",download(cImageFile))
	
	
