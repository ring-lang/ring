# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameStory

	func ShowStory

		oGameSound.PlayStorySound()

		Start2DScreen()
		al_clear_to_color(al_map_rgb(40,40,40))
		DisplayStoryImage()
		DisplayCurrentPage()
		End2DScreen()
		WaitForText()
		if KEY[KEY_ESCAPE]
			KEY[KEY_ESCAPE] = False
			ExitFromMainLoop()
		ok
		if KEY[KEY_SPACE] or Mouse_Button_Down 
			KEY[KEY_SPACE] 		= False 
			Mouse_Button_Down	= False
			oGameSound.StopStorySound()
			nActiveScreen 	= C_SCREEN_MAINMENU
		ok

		if KEY[KEY_ENTER] 
			KEY[KEY_ENTER] = False 
			oGameSound.StopStorySound()
			if nStoryPage < len(aStoryContent)
				nStoryPage++
				nStoryLine = 1
				nStoryCharacter = 0
			else 
				nActiveScreen 	= C_SCREEN_MAINMENU
			ok
		ok

	
	func DisplayCurrentPage

		aCurrentStoryPage = aStoryContent[ nStoryPage ]
		cCurrentLine = aCurrentStoryPage[ nStoryLine ]

		if nStoryCharacter < len(cCurrentLine)
			nStoryCharacter++
		else 
			if nStoryLine < len(aCurrentStoryPage)
				nStoryLine++
				nStoryCharacter = 0
			else 
				if nStoryPage < len(aStoryContent)
					nStoryPage++
					nStoryLine = 1
					nStoryCharacter = 0
				else 
					nActiveScreen 	= C_SCREEN_MAINMENU
					oGameSound.StopStorySound()
				ok
			ok
		ok

		cString = left( cCurrentLine , nStoryCharacter )
		nTextWidth = al_get_text_width(fontArial72,cCurrentLine)
		nXStart = (SCREEN_W_2D - nTextWidth ) / 2
		nXStart = nXStart - ( (len(cCurrentLine) - len(cString)) * 2 )
		if cStoryTextPostion = :Up
			DrawTextWithShadow(cString,100,nXStart,fontArial72,COLOR_WHITE)
		but cStoryTextPostion = :Down  
			DrawTextWithShadow(cString,SCREEN_H_2D-120,nXStart,fontArial72,COLOR_WHITE)
		but cStoryTextPostion = :Center
			DrawTextWithShadow(cString,(SCREEN_H_2D/2)-50,nXStart,fontArial72,COLOR_WHITE)
		but cStoryTextPostion = :DownUp
			if nStoryLine % 2 = 0
				DrawTextWithShadow(cString,100,nXStart,fontArial72,COLOR_WHITE)
			else cStoryTextPostion = :Down  
				DrawTextWithShadow(cString,SCREEN_H_2D-120,nXStart,fontArial72,COLOR_WHITE)
			ok	  
		ok

	func WaitForText

		al_flip_display()
		lFlipDisplay = False

		aCurrentStoryPage = aStoryContent[ nStoryPage ]
		cCurrentLine = aCurrentStoryPage[ nStoryLine ]
		if nStoryCharacter = len(cCurrentLine)
			sleep(2)
		else 
			sleep(0.01)
		ok

	func DisplayStoryImage

		switch nStoryPage 
		on 1
			cStoryTextPostion = :DownUp
			DrawStoryBackGroundImage3()
			DrawManyGoldImage()
		on 2
			cStoryTextPostion = :Down
			DrawStoryBackGroundImage3()
			DrawTheBoxImage()
		on 3
			cStoryTextPostion = :Center
			DrawStoryBackGroundImage2()
			DrawGameEnvImage()
		on 4
			cStoryTextPostion = :Down
			DrawStoryBackGroundImage3()
			DrawRemoteControlImage()
		off

	func ShowTheFinalStory
		nActiveScreen 		= C_SCREEN_STORY
		nActiveItem 		= 1
		lGameStarted 		= False
		nLevel 			= 1
		nSelectedLevel		= 1
		aStoryContent = [
			["Now we have a lot of Gold!",
			 "Yes we did it!"],
			["Using this Infinite Source of Gold!",
			 "You will change the world!",
			 "You can change the world with money", 
			 "Where you spend your money",
			 "And where you don't",
			 "Makes a big difference",
			 "Change is something you can buy, wear and give away.",
			 "Change is also something you can invest in",
			 "Through the everyday choices you make",
			 "About what to do with your money!"],
			["Thanks for playing the Game",
			 "You are a Smart and Intelligent Person"
			]
		]
		nStoryPage = 1
		nStoryLine = 1
		nStoryCharacter = 0
		cStoryTextPostion = :Up

 
