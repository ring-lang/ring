# Gold Magic 800 3D Game
# 2018, Etqan Company

class GameScreen

	func DisplayActiveScreen

		switch nActiveScreen
			on C_SCREEN_LOGO
				HideMouse()
				DrawLogo()
			on C_SCREEN_STORY
				HideMouse()
				ShowStory()
			on C_SCREEN_MAINMENU
				ShowMouse()
				MainMenu()
				if key[KEY_ESCAPE]
					key[KEY_ESCAPE] = False
					ExitFromMainLoop()
				ok
			on C_SCREEN_GAMEPLAY
				HideMouse()
				# To Enable or Disable (Continue and Restart) options 
					lGameStarted = True
				PlayLevel()
				if key[KEY_ESCAPE]
					key[KEY_ESCAPE] = False
					nActiveScreen 	= C_SCREEN_MAINMENU
					nActiveItem 	= 2
				ok
			on C_SCREEN_LEVELCOMPLETE
				HideMouse()
				LevelComplete()
				lFlipDisplay = False
			on C_SCREEN_PLAYERWIN 
				HideMouse()
				PlayerWin()
				lFlipDisplay = False
				if Mouse_Button_Down 
					Mouse_Button_Down 	= False
					Key[KEY_SPACE]    	= True
				ok					
				if key[KEY_ESCAPE] or Key[KEY_SPACE] or Key[KEY_ENTER]
					key[KEY_ESCAPE] 	= False
					key[KEY_SPACE] 		= False
					key[KEY_ENTER] 		= False
					ShowTheFinalStory()
				ok			
			on C_SCREEN_SELECTLEVEL
				HideMouse()
				SelectLevelScreen()				
			on C_SCREEN_HOWTOPLAY
				ShowMouse()
				HowToPlay()
				lFlipDisplay = False
		off

