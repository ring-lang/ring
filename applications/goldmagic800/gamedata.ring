# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameData from GameBase

	TITLE = "Gold Magic 800"

	# General Game Settings 	
	
		C_SHOW_ACTIVE_REGION_ONLY_AFTER_LEVEL	= 118
		C_SHOW_MAP_UP_TO_LEVEL		      	= 118
		C_ACTIVE_REGION_SIZE			= 7
		C_MAX_REQUIRED_SCORE_FOR_GOLD		= 800

	# Screens 

		C_SCREEN_MAINMENU	= 1
		C_SCREEN_GAMEPLAY	= 2
		C_SCREEN_LEVELCOMPLETE  = 3
		C_SCREEN_PLAYERWIN	= 4
		C_SCREEN_SELECTLEVEL	= 5
		C_SCREEN_LOGO		= 6
		C_SCREEN_STORY		= 7
		C_SCREEN_HOWTOPLAY	= 8

		# Screens 
			nActiveScreen = C_SCREEN_LOGO

	# Main Menu

		aMenu = ["Start New Game",
			 "Continue",
			 "Restart Level",
			 "Sound (ON)", 
			 "Music (ON)", 
			 "How to Play?",
			 "Exit From Game"]
	
		nActiveItem = 1
		lGameStarted = False

	# Map Objects
	
		C_PLAYER	= 1
		C_GROUND 	= 2
		C_WALL	 	= 3
		C_DOOR   	= 4
		C_GOLDGROUND 	= 5
		C_DOOR2		= 6
		C_GOLDCUBE	= 7
		C_DOOR3		= 8
		C_DOOR4		= 9
		C_DOOR5		= 10
		C_DOOR6		= 11
		C_DOOR7		= 12
		C_DOOR8		= 13
		C_DOOR9		= 14
		C_DOOR10	= 15
		C_DOOR11	= 16
		C_DOOR12	= 17
		C_DOOR13	= 18
		C_DOOR14	= 19
		C_DOOR15	= 20
		C_DOOR16	= 21
		C_GOLDMARK	= 22
		C_PATHMARK	= 23

	# Game Resources (Images, Textures, Fonts, etc)

		fontArial26	fontArial172		fontArial72
		backGroundMusic
		bitmapWinBackGround  textureWinBackground
		bitmap 		texture 	
		bitmapGround1 	textureGround1

		bitmapWall2 	textureWall2
		bitmapPlayer 	texturePlayer

		bitmapWall4	textureWall4
		bitmapGround2 	textureGround2

		bitmapWall3 	textureWall3
		bitmapGround3 	textureGround3
		bitmapWall1 	textureWall1
		bitmapGold 	textureGold
		bitmapn1	texturen1	
		bitmapn2	texturen2
		bitmapn3	texturen3
		bitmapn4	texturen4
		bitmapn5	texturen5
		bitmapn6	texturen6
		bitmapn7	texturen7
		bitmapn8	texturen8
		bitmapn9	texturen9
		bitmapn10	texturen10
		bitmapn11	texturen11
		bitmapn12	texturen12
		bitmapn13	texturen13
		bitmapn14	texturen14
		bitmapn15	texturen15
		bitmapn16	texturen16
		bitmapnewwall	texturenewWall
		bitmapMainMenu	textureMainMenu
		bitmapLogo	bitmapStoryBackGround
				bitmapStoryBackGround2
				bitmapStoryBackGround3
		bitmapManyGold
		bitmapTheBox
		bitmapGameEnv
		bitmapRemoteControl

		lUseGameTitleImage = True 
		bitmapGameTitle
		bitmapHowToPlay

	# Current Level Style
	
		GroundTexture  WallTexture  PlayerTexture  DoorTexture 
		GoldGroundTexture	Door2Texture	Door3Texture
		Door4Texture	Door5Texture  Door6Texture
		Door7Texture	Door8Texture  Door9Texture
		Door10Texture   Door11Texture Door12Texture
		Door13Texture	Door14Texture Door15Texture Door16Texture

	# Level Map

		nRows = 20
		nCols = 20
	
		aLevel = list(20,20)
		for t1 = 1 to nRows 
			for t2 = 1 to nCols 
				aLevel[t1][t2] = C_GROUND
			next 
		next
	
		aLevel[1][20] 	= C_DOOR
		aLevel[20][1] 	= C_PLAYER

	# General Settings

		# Player Information

			nPlayerX 	= 1
			nPlayerY 	= 20 

		# Door Information	

			nDoorX 	 	= 20
			nDoorY  	= 1

		# Level Data 	

			nLevel 		= 1
			nLevelsCount 	= Len(ListAllFiles("levels","level"))
			nSelectedLevel	= 1

		# Environment Data 

			lShowActiveRegionOnly 	= True
	
			lShow2DMap 		= True
			lIs2DMapVisible 	= False
	
			cDrawingMode		= :GamePlay

			lWallSizeIsSmall 	= True

		# Game Actions 
	
			lIsPoint	= False 
			nScore		= 0	
			nActiveDoor	= 0
			nDoorsCount	= 2

	# Camera Settings

		oGameCamera = new GameCamera
		oGameCamera.SCREEN_W = SCREEN_W
		oGameCamera.SCREEN_H = SCREEN_H
		oGameCamera.SCREEN_W_2D = SCREEN_W_2D
		oGameCamera.SCREEN_H_2D = SCREEN_H_2D
	
	# Sound 

		oGameSound = new GameSound

	# Logo

		oGameLogo = new GameLogo

	# Play using the Mouse 

		lPlayUsingMouse = False
		lShowHideMouse	= True
		lMoveByMouse 	= False

	# Play using 2D Map

		# Playing using the 2D Map is Not Fun and Reduce the Playing time.

		lNoPlayInLarge2D = False

	# Game Story Data 

		nStoryPage = 1
		nStoryLine = 1
		nStoryCharacter = 0
		aStoryContent = [
			["Imagine that we have all of this Gold!",
			 "Oh My Goodness!",
			 "How many Boxes do we need?",
			 "Oh! We will need many of them!",
			 "It's our Time to be the Richest People in the world!",
			 "How?"],
			["I discovered this Box!",
			 "It's a Unique and Special Box", 
			 "Created by the Best Wizard in World",
			 "7000 Years Ago!",			
			 "It's an Infinite Source of Gold!",
			 "When We close it and move it!",
			 "We will find a New Gold under the Box!"],
			["The Box Exists in a Special Environment!",
			 "Full of Puzzles!",
			 "If You tried to enter this Environment",
			 "The Magic Will Destroy You",
			 "So I Created a Robot using Nanotechnology",
			 "To be able to control the Box"],
			 ["Using this Device",
			 "Once We solve all of the Puzzles",
			 "We will own the box!",
			 "Let's go!"]
		]
		cStoryTextPostion	=  :Up
