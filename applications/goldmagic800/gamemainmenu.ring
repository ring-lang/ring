# Gold Magic 800 3D Game
# 2018, Etqan Company

class GameMainMenu

	func MainMenu 

		oGameSound.PlayBackGroundMusic()

		Start2DScreen()
		DrawMainMenuBackGroundImage()

		if lUseGameTitleImage
			DrawGameTitleImage()
		else 
			DrawTitle(Title,80,350)
		ok

		# Mouse Events 

			if lMouseMove
				lMouseMove = False 
				for x = 1 to len(aMenu)
					if lGameStarted = False and (x = 2 or x = 3) 
						loop 
					ok
						if Mouse_Y >= Position2D_Y(SCREEN_H_2D-850+(100*x)) and
						   Mouse_Y <= Position2D_Y(SCREEN_H_2D-850+(100*x)+100) and 
						   Mouse_X >= Position2D_X((SCREEN_W_2D/2)-250) and 
						   Mouse_X <= Position2D_X((SCREEN_W_2D/2)-250+600) 
							if nActiveItem != X
								oGameSound.StopMenuChangeSound()
								oGameSound.PlayMenuChangeSound()
								nActiveItem = X
							ok
						ok
				next 
			ok
			if Mouse_Button_Down 
				Mouse_Button_Down = False
				Key[KEY_SPACE]    = True
			ok					

		for x = 1 to len(aMenu)
			cMenu = aMenu[x]
			if x = nActiveItem
				DrawOption(cMenu,SCREEN_H_2D-850+(100*x),(SCREEN_W_2D/2)-250,True)
			else 
				if lGameStarted = False and (x = 2 or x = 3) 
					DrawDisabledOption(cMenu,SCREEN_H_2D-850+(100*x),(SCREEN_W_2D/2)-250,False)
				else 
					DrawOption(cMenu,SCREEN_H_2D-850+(100*x),(SCREEN_W_2D/2)-250,False)
				ok
			ok
		next

		End2DScreen()

		# Keyboard Events 

			if key[KEY_DOWN] 
				key[KEY_DOWN] = False
				oGameSound.StopMenuChangeSound()
				oGameSound.PlayMenuChangeSound()
				if  nActiveItem < len(aMenu)
					nActiveItem++
					if nActiveItem = 2 and lGameStarted = False 
						nActiveItem = 4
					ok
				else 
					nActiveItem = 1 
					return 
				ok
			ok
			if key[KEY_UP] 
				key[KEY_UP] = False
				oGameSound.StopMenuChangeSound()
				oGameSound.PlayMenuChangeSound()
				if nActiveItem > 1
					nActiveItem--
					if nActiveItem = 3 and lGameStarted = False 
						nActiveItem = 1
					ok
				else 
					nActiveItem = len(aMenu)
					return 
				ok
			ok
			if Key[KEY_SPACE] = True or Key[KEY_ENTER] = True
				Key[KEY_SPACE] = False
				key[KEY_ENTER] = False 
				oGameSound.StopMenuClickSound()
				oGameSound.PlayMenuClickSound()
				switch nActiveItem
					on 1
						nActiveScreen = C_SCREEN_SELECTLEVEL				
					on 2 
						nActiveScreen = C_SCREEN_GAMEPLAY				
					on 3 
						nActiveScreen = C_SCREEN_GAMEPLAY
						DefaultLevelData()
						loadLevel()
						oGameCamera.DefaultCameraData()
						SetCameraAtPlayerPosition()
					on 4
						oGameSound.SoundOnOff()
						ItemOnOff(aMenu,4)
					on 5
						oGameSound.MusicOnOff()
						ItemOnOff(aMenu,5)
					on 6
						nActiveScreen = C_SCREEN_HOWTOPLAY				
					on 7
						ExitFromMainLoop()
				off
			ok
		
	func ItemOnOff aList,nIndex

		if substr(aList[nIndex],"ON")
			aList[nIndex] = substr(aList[nIndex],"ON","OFF")
		else 
			aList[nIndex] = substr(aList[nIndex],"OFF","ON")
		ok

