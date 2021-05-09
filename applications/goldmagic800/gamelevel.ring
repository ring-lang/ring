# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameLevel

	func DefaultLevelData

		nScore = 0 

		if lNoPlayInLarge2D
			oGameCamera.lPlay2D  = False
		ok	

	func PlayLevel

		DrawBackGroundImage()
		LevelStyle()
		oGameCamera.GameLevelCameraView()

		lShowActiveRegionOnly = (nLevel > C_SHOW_ACTIVE_REGION_ONLY_AFTER_LEVEL)

		cDrawingMode = :GamePlay
		DrawLevel()

		if lShow2DMap and nLevel <= C_SHOW_MAP_UP_TO_LEVEL and
			 not oGameCamera.lPlay2D 

			lIs2DMapVisible = True
			oGameCamera.GameMapCameraView()
			lShowActiveRegionOnly = false
			cDrawingMode = :GameMap
			DrawLevel()
		else 
			lIs2DMapVisible = False
		ok
	
		set2DMODE()
		DrawGameName()
		PlayerEvents()

	func LoadLevel 

		if nLevel = 1  nScore = 0 ok
		cFileName = "levels/level"+nLevel+".level"
		if ! fexists(cFileName) return ok
		eval(read(cFileName))
		aLevel=aLevelData
		nActiveDoor = 0
		nDoorsCount = 0
		for t1 = 1 to nRows 
			for t2 = 1 to nCols 
				if aLevel[t1][t2] = C_GOLDMARK or 
					aLevel[t1][t2] = C_PATHMARK
					aLevel[t1][t2] = C_GROUND
				ok
				if aLevel[t1][t2] = C_PLAYER
					nPlayerY = t1
					nPlayerX = t2
				ok
				nPos = find([C_DOOR,C_DOOR2,C_DOOR3,C_DOOR4,C_DOOR5,C_DOOR6,
					C_DOOR7,C_DOOR8,C_DOOR9,C_DOOR10,C_DOOR11,
					C_DOOR12,C_DOOR13,C_DOOR14,C_DOOR15,
					C_DOOR16],aLevel[t1][t2])
				if nPos
					nDoorsCount = max(nDoorsCount,nPos)
				ok
			next 
		next

	func SetCameraAtPlayerPosition

		for t = 1 to (nRows - nPlayerY) oGameCamera.FastmoveUp() next

	func nextlevel 

		nLevel++
		loadlevel()
		DefaultLevelData()
		oGameCamera.DefaultCameraData()
		SetCameraAtPlayerPosition()

	func restartlevel 

		loadlevel()
		oGameCamera.DefaultCameraData()
		SetCameraAtPlayerPosition()
		nScore = 0

	func DrawLevel
		glTranslatef(-21,-3,-30) 
		nMode = :none
		for y=0 to nRows+1 
			for x=0 to nCols+1	
			
				if lShowActiveRegionOnly
					if not ( x >= nPlayerX - C_ACTIVE_REGION_SIZE and 
					   x <= nPlayerX + C_ACTIVE_REGION_SIZE and 
					   y >= nPlayerY - C_ACTIVE_REGION_SIZE and 
					   y <= nPlayerY + C_ACTIVE_REGION_SIZE  )
						loop
					ok
				ok				

				if x=0 or y=0 or x=nCols+1 or y=nRows+1
					glBindTexture(GL_TEXTURE_2D, WallTexture)
					nMode = :Wall
				else
					glBindTexture(GL_TEXTURE_2D, GroundTexture)
					nMode = :Ground 
				ok

				if y >= 1 and x >= 1 and 
				    y <= nRows and x <= nCols 
					switch aLevel[y][x] 
						on C_PLAYER
							glBindTexture(GL_TEXTURE_2D, PlayerTexture)
							nMode = :Player
						on C_GROUND
							glBindTexture(GL_TEXTURE_2D, GroundTexture)
							nMode = :Ground 
						on C_WALL
							glBindTexture(GL_TEXTURE_2D, WallTexture)
							nMode = :Wall
						on C_DOOR 
							glBindTexture(GL_TEXTURE_2D, DoorTexture)
							nMode = :Door
						on C_GOLDGROUND 
							glBindTexture(GL_TEXTURE_2D, GoldGroundTexture)
							nMode = :GoldGround 
						on C_DOOR2 
							glBindTexture(GL_TEXTURE_2D, Door2Texture)
							nMode = :Door2
						on C_GOLDCUBE
							glBindTexture(GL_TEXTURE_2D, TexturenewWall)
							nMode = :GoldCube 
						on C_DOOR3
							glBindTexture(GL_TEXTURE_2D, Door3Texture)
							nMode = :Door3
						on C_DOOR4
							glBindTexture(GL_TEXTURE_2D, Door4Texture)
							nMode = :Door4
						on C_DOOR5
							glBindTexture(GL_TEXTURE_2D, Door5Texture)
							nMode = :Door5
						on C_DOOR6
							glBindTexture(GL_TEXTURE_2D, Door6Texture)
							nMode = :Door6
						on C_DOOR7
							glBindTexture(GL_TEXTURE_2D, Door7Texture)
							nMode = :Door7
						on C_DOOR8
							glBindTexture(GL_TEXTURE_2D, Door8Texture)
							nMode = :Door8
						on C_DOOR9
							glBindTexture(GL_TEXTURE_2D, Door9Texture)
							nMode = :Door9
						on C_DOOR10
							glBindTexture(GL_TEXTURE_2D, Door10Texture)
							nMode = :Door10
						on C_DOOR11
							glBindTexture(GL_TEXTURE_2D, Door11Texture)
							nMode = :Door11
						on C_DOOR12
							glBindTexture(GL_TEXTURE_2D, Door12Texture)
							nMode = :Door12
						on C_DOOR13
							glBindTexture(GL_TEXTURE_2D, Door13Texture)
							nMode = :Door13
						on C_DOOR14
							glBindTexture(GL_TEXTURE_2D, Door14Texture)
							nMode = :Door14
						on C_DOOR15
							glBindTexture(GL_TEXTURE_2D, Door15Texture)
							nMode = :Door15
						on C_DOOR16
							glBindTexture(GL_TEXTURE_2D, Door16Texture)
							nMode = :Door16
					off
				ok

				if x = nPlayerX and Y = nPlayerY
					glBindTexture(GL_TEXTURE_2D, PlayerTexture)
					nMode = :Player
				ok

				lDrawAsCube = DrawAsCube(nMode)

				if lDrawAsCube 
					if (nMode = :Wall or nMode = :GoldCube) and lWallSizeIsSmall
						glTranslatef(0,1,0)
					else 
						glTranslatef(0,2,0)
					ok
				ok

	                        glPushMatrix()
	                        glTranslatef(x*2,0,y*2)
				if ! lDrawAsCube
					DrawGround()
				else 
					DrawCubeFixedSizeNoBottom()
				ok
	                        glPopMatrix()

				if lDrawAsCube
					if (nMode = :Wall or nMode = :GoldCube) and lWallSizeIsSmall
						glTranslatef(0,-1,0)
					else 
						glTranslatef(0,-2,0)
					ok
				ok
	                next
	        next

	func DrawAsCube nMode

		if oGameCamera.nViewType = oGameCamera.C_VIEWTYPE_MAP
			return False 
		ok
		lNotCurrentDoor = not CurrentDoor(nMode)
		if nMode = :Wall or nMode = :Player or nMode = :GoldCube or lNotCurrentDoor
			return True 
		ok
		return False 

	func CurrentDoor nMode

		if find([:Door,:Door2,:Door3,:Door4,:Door5,:Door6,:Door7,
			:Door8,:Door9,:Door10,:Door11,:Door12,
			:Door13,:Door14,:Door15,:Door16],nMode)
			switch nActiveDoor
			on 1
				if nMode = :Door 
					return True 
				ok
			on 2	
				if nMode = :Door2
					return True 
				ok
			on 3
				if nMode = :Door3
					return True 
				ok
			on 4
				if nMode = :Door4
					return True 
				ok
			on 5
				if nMode = :Door5
					return True 
				ok
			on 6
				if nMode = :Door6
					return True 
				ok
			on 7
				if nMode = :Door7
					return True 
				ok
			on 8
				if nMode = :Door8
					return True 
				ok
			on 9
				if nMode = :Door9
					return True 
				ok
			on 10
				if nMode = :Door10
					return True 
				ok
			on 11
				if nMode = :Door11
					return True 
				ok
			on 12
				if nMode = :Door12
					return True 
				ok
			on 13
				if nMode = :Door13
					return True 
				ok
			on 14
				if nMode = :Door14
					return True 
				ok
			on 15
				if nMode = :Door15
					return True 
				ok
			on 16
				if nMode = :Door16
					return True 
				ok
			off 			
			return False 
		ok
		return True 

	func IsWall Y,X

		if aLevel[Y][X] = C_WALL or 
		   aLevel[Y][X] = C_GOLDCUBE or 
		   (aLevel[Y][X] = C_DOOR  and nActiveDoor != 1) or
		   (aLevel[Y][X] = C_DOOR2 and nActiveDoor != 2) or 
		   (aLevel[Y][X] = C_DOOR3 and nActiveDoor != 3) or
		   (aLevel[Y][X] = C_DOOR4 and nActiveDoor != 4) or
		   (aLevel[Y][X] = C_DOOR5 and nActiveDoor != 5) or
		   (aLevel[Y][X] = C_DOOR6 and nActiveDoor != 6) or
		   (aLevel[Y][X] = C_DOOR7 and nActiveDoor != 7) or
		   (aLevel[Y][X] = C_DOOR8 and nActiveDoor != 8) or
		   (aLevel[Y][X] = C_DOOR9 and nActiveDoor != 9) or
		   (aLevel[Y][X] = C_DOOR10 and nActiveDoor != 10) or
		   (aLevel[Y][X] = C_DOOR11 and nActiveDoor != 11) or
		   (aLevel[Y][X] = C_DOOR12 and nActiveDoor != 12) or 
		   (aLevel[Y][X] = C_DOOR13 and nActiveDoor != 13) or
		   (aLevel[Y][X] = C_DOOR14 and nActiveDoor != 14) or
		   (aLevel[Y][X] = C_DOOR15 and nActiveDoor != 15) or
		   (aLevel[Y][X] = C_DOOR16 and nActiveDoor != 16) 
		   return True 
		ok
		return False 
		
	func LevelStyle

		nStyle = ( nLevel % 4 ) + 1
		switch nStyle
			on 1
				GroundTexture   = textureGround2
				WallTexture	= textureWall4
			on 2
				GroundTexture   = textureGround1
				WallTexture	= textureWall2
			on 3
				GroundTexture   = textureGround1
				WallTexture	= textureWall3
			on 4
				GroundTexture   = textureGround3
				WallTexture	= textureWall1
		off

	func ConvertGoldToWall

		for nY = 1 to nRows
			for nX=1 to nCols 
				if aLevel[nY][nX] = C_GOLDGROUND
					aLevel[nY][nX] = C_GOLDCUBE
				ok
			next 
		next 

	func LevelComplete 

		# Wait 1 second so we can see the player position 
		# In the end of the level 

			DrawBackGroundImage()
			oGameCamera.GameLevelCameraView()
			DrawLevel()
			set2DMODE()
			DrawGameName()
			al_flip_display()
			sleep(1)

		# Draw Level Complete Message

			set2DMODE()
			Start2DScreen()
			DrawWinBackGroundImage()
			DrawLevelComplete()
			End2DScreen()
			al_flip_display()
			lFlipDisplay = False
			Sleep(2)

		DefaultLevelData()
		nActiveScreen = C_SCREEN_GAMEPLAY
		if nLevel = nLevelsCount
			nLevel = 0
			nActiveScreen = C_SCREEN_PLAYERWIN	
		ok
		nextlevel()
