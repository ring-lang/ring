# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameHowToPlay

	func HowToPlay

		Start2DScreen()
		DrawStoryBackGroundImage()
		DrawHowToPlayImage()
		End2DScreen()
		al_flip_display()
		lFlipDisplay = False

		if KEY[KEY_SPACE] or KEY[KEY_ENTER] or KEY[KEY_ESCAPE] or Mouse_Button_Down 
			Mouse_Button_Down = False
			KEY[KEY_SPACE] 	= False 
			KEY[KEY_ENTER] 	= False
			KEY[KEY_ESCAPE] = False
			nActiveScreen 	= C_SCREEN_MAINMENU
		ok
