# Gold Magic 800 3D Game
# 2018, Etqan Company

Class GameDraw

	func DrawFullScreenImage oBitmap,nWidth,nHeight

		al_draw_scaled_bitmap(oBitmap,0,0,al_get_bitmap_width(oBitmap),
		al_get_bitmap_height(oBitmap),0,0,nWidth,nHeight,1)

	func DrawBackGroundImage

		DrawFullScreenImage(bitmap,SCREEN_W,SCREEN_H)

	func DrawWinBackGroundImage

		DrawFullScreenImage(bitmapWinBackGround,SCREEN_W_2D,SCREEN_H_2D)

	func DrawMainMenuBackGroundImage

		DrawFullScreenImage(bitmapMainMenu,SCREEN_W_2D,SCREEN_H_2D)

	func DrawGameTitleImage

		al_draw_bitmap(BitMapGameTitle,0,0,0)

	func DrawHowToPlayImage

		DrawBitmapInCenter(BitMapHowToPlay)

	func DrawLogoImage

		DrawBitmapInCenter(bitmapLogo)

	func DrawStoryBackGroundImage

		DrawFullScreenImage(bitmapStoryBackGround,SCREEN_W_2D,SCREEN_H_2D)

	func DrawStoryBackGroundImage2

		DrawFullScreenImage(bitmapStoryBackGround2,SCREEN_W_2D,SCREEN_H_2D)

	func DrawStoryBackGroundImage3

		DrawFullScreenImage(bitmapStoryBackGround3,SCREEN_W_2D,SCREEN_H_2D)


	func DrawManyGoldImage

		DrawBitmapInCenter(bitmapManyGold)

	func DrawTheBoxImage

		DrawBitmapInCenter(bitmapTheBox)

	func DrawGameEnvImage

		DrawBitmapInCenter(bitmapGameEnv)


	func DrawRemoteControlImage

		DrawBitmapInCenter(bitmapRemoteControl)

	func DrawBitmapInCenter oBitMap

		X = (SCREEN_W_2D-al_get_bitmap_width(oBitMap))/2
		Y = (SCREEN_H_2D-al_get_bitmap_height(oBitMap))/2
		al_draw_bitmap(oBitMap,X,Y,0)


	func DrawTextWithShadow cText,nY,nX,oFont,oColor

		al_draw_text(oFont,COLOR_GRAY,
			nX,nY,
		ALLEGRO_ALIGN_LEFT,
		cText)
		al_draw_text(oFont,COLOR_BLACK,
			nX-6,nY-6,
		ALLEGRO_ALIGN_LEFT,
		cText)
		al_draw_text(oFont,COLOR_BLACK,
			nX-4,nY-4,
		ALLEGRO_ALIGN_LEFT,
		cText)
		al_draw_text(oFont,oColor,
			nX-5,nY-5,
		ALLEGRO_ALIGN_LEFT,
		cText)

	func DrawTitle cText,nY,nX

		DrawTextWithShadow(cText,nY,nX,fontArial172,COLOR_WHITE)

	func DrawOption cText,nY,nX,lActive

		if lActive 
			oColor = COLOR_ACTIVE
		else 
			oColor = COLOR_NOTACTIVE
		ok

		DrawTextWithShadow(cText,nY,nX,fontArial72,oColor)

	func DrawDisabledOption cText,nY,nX,lActive

		DrawTextWithShadow(cText,nY,nX,fontArial72,COLOR_DISABLED)

	func DrawLevelComplete

		if nLevel < 10
			x = 220
		else 	
			X = 180
		ok
		DrawTitle("Level " + nLevel + " Completed!",(SCREEN_H_2D/2)-100,X)

	func DrawPlayerWin

		DrawTitle("You Win!!!",(SCREEN_H_2D/2)-100,570)

	func DrawGameName

		# Name 
			al_draw_text(fontArial26,COLOR_WHITE,10,10,ALLEGRO_ALIGN_LEFT,Title)
	
		# Level
			al_draw_text(fontArial26,COLOR_WHITE,250,10,ALLEGRO_ALIGN_LEFT,"Level : ")
			al_draw_text(fontArial26,COLOR_WHITE,330,10,ALLEGRO_ALIGN_LEFT,""+nLevel)

		# Check end of level
			if nActiveScreen = C_SCREEN_LEVELCOMPLETE
				return 
			ok

		# Door

			if nActiveDoor = 0
				cDoorToOpen = 1
			else 
				cDoorToOpen = "" + nActiveDoor
			ok
			cDoorToOpen = "Next Door : " + cDoorToOpen
			al_draw_text(fontArial26,COLOR_WHITE,380,10,ALLEGRO_ALIGN_LEFT,"" + cDoorToOpen)
			

		# Score 
			# Score Status 
				if nScore < C_MAX_REQUIRED_SCORE_FOR_GOLD
					cScoreText = "" + nScore + " (Low) "
				but nScore = C_MAX_REQUIRED_SCORE_FOR_GOLD
					cScoreText = "" + nScore + " (Ok)"
				but nScore > C_MAX_REQUIRED_SCORE_FOR_GOLD
					if nActiveDoor <= 1
						cScoreText = "" + nScore + " (Too Much! Use only 800) - Press SPACE To Restart!"
					else 
						cScoreText = "" + nScore 
						return 
					ok
				ok

			al_draw_text(fontArial26,COLOR_WHITE,580,10,ALLEGRO_ALIGN_LEFT,"Gold : ")
			al_draw_text(fontArial26,COLOR_WHITE,670,10,ALLEGRO_ALIGN_LEFT,cScoreText)


	
	func drawcube nSize

		glBegin(GL_QUADS)
			// Front Face
			glTexCoord2f(0.0, 0.0) 		glVertex3f(-nSize, -nSize,  nSize)
			glTexCoord2f(nSize, 0.0) 	glVertex3f( nSize, -nSize,  nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f( nSize,  nSize,  nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f(-nSize,  nSize,  nSize)
			// Back Face
			glTexCoord2f(nSize, 0.0) 	glVertex3f(-nSize, -nSize, -nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f(-nSize,  nSize, -nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f( nSize,  nSize, -nSize)
			glTexCoord2f(0.0, 0.0) 		glVertex3f( nSize, -nSize, -nSize)
			// Top Face
			glTexCoord2f(0.0, nSize) 	glVertex3f(-nSize,  nSize, -nSize)
			glTexCoord2f(0.0, 0.0) 		glVertex3f(-nSize,  nSize,  nSize)
			glTexCoord2f(nSize, 0.0) 	glVertex3f( nSize,  nSize,  nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f( nSize,  nSize, -nSize)
			// Bottom Face
			glTexCoord2f(nSize, nSize) 	glVertex3f(-nSize, -nSize, -nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f( nSize, -nSize, -nSize)
			glTexCoord2f(0.0, 0.0) 		glVertex3f( nSize, -nSize,  nSize)
			glTexCoord2f(nSize, 0.0) 	glVertex3f(-nSize, -nSize,  nSize)
			// Right face
			glTexCoord2f(nSize, 0.0) 	glVertex3f( nSize, -nSize, -nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f( nSize,  nSize, -nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f( nSize,  nSize,  nSize)
			glTexCoord2f(0.0, 0.0) 		glVertex3f( nSize, -nSize,  nSize)
			// Left Face
			glTexCoord2f(0.0, 0.0) 		glVertex3f(-nSize, -nSize, -nSize)
			glTexCoord2f(nSize, 0.0) 	glVertex3f(-nSize, -nSize,  nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f(-nSize,  nSize,  nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f(-nSize,  nSize, -nSize)
		glEnd()

	func DrawCubeNoBottom nSize

		glBegin(GL_QUADS)
			// Front Face
			glTexCoord2f(0.0, 0.0) 		glVertex3f(-nSize, -nSize,  nSize)
			glTexCoord2f(nSize, 0.0) 	glVertex3f( nSize, -nSize,  nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f( nSize,  nSize,  nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f(-nSize,  nSize,  nSize)
			// Back Face
			glTexCoord2f(nSize, 0.0) 	glVertex3f(-nSize, -nSize, -nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f(-nSize,  nSize, -nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f( nSize,  nSize, -nSize)
			glTexCoord2f(0.0, 0.0) 		glVertex3f( nSize, -nSize, -nSize)
			// Top Face
			glTexCoord2f(0.0, nSize) 	glVertex3f(-nSize,  nSize, -nSize)
			glTexCoord2f(0.0, 0.0) 		glVertex3f(-nSize,  nSize,  nSize)
			glTexCoord2f(nSize, 0.0) 	glVertex3f( nSize,  nSize,  nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f( nSize,  nSize, -nSize)
			// Right face
			glTexCoord2f(nSize, 0.0) 	glVertex3f( nSize, -nSize, -nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f( nSize,  nSize, -nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f( nSize,  nSize,  nSize)
			glTexCoord2f(0.0, 0.0) 		glVertex3f( nSize, -nSize,  nSize)
			// Left Face
			glTexCoord2f(0.0, 0.0) 		glVertex3f(-nSize, -nSize, -nSize)
			glTexCoord2f(nSize, 0.0) 	glVertex3f(-nSize, -nSize,  nSize)
			glTexCoord2f(nSize, nSize) 	glVertex3f(-nSize,  nSize,  nSize)
			glTexCoord2f(0.0, nSize) 	glVertex3f(-nSize,  nSize, -nSize)
		glEnd()

	func DrawCubeFixedSize 

		DrawCube(1)

	func DrawCubeFixedSizeNoBottom 

		DrawCubeNoBottom(1)

	func drawGround

		glBegin(GL_QUADS)
			glTexCoord2f(0.0, 1.0) 		glVertex3f(-1.0,  1.0, -1.0)
			glTexCoord2f(0.0, 0.0) 		glVertex3f(-1.0,  1.0,  1.0)
			glTexCoord2f(1.0, 0.0) 		glVertex3f( 1.0,  1.0,  1.0)
			glTexCoord2f(1.0, 1.0) 		glVertex3f( 1.0,  1.0, -1.0)
		glEnd()

