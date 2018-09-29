# Gold Magic 800 3D Game
# 2018, Etqan Company

class GamePlayer

	func PlayerEvents

		# Camera 
			oGameCamera.update()

		# Mouse Events 
			PlayUsingTheMouse()

		# Keyboard Events 
			if key[KEY_ENTER] 
				key[KEY_ENTER] = False 
				oGameCamera { lPlay2D = ! lPlay2D }
			ok
			# Don't support playing in Large 2D Map 
				if lNoPlayInLarge2D
					if oGameCamera.lPlay2D return ok
				ok
			if key[key_space]
				key[key_space] = false 
				restartlevel()
			ok
			# Just accept one key of (Up|Down) and (Left|Right)
				if key[key_up] and key[key_down]
					key[key_up] = False
					key[key_down] = False
				ok
				if key[key_left] and key[key_right]
					key[key_left]  = false 
					key[key_right] = false
				ok
			if key[key_left]
				if nPlayerX > 1
					if not IsWall(nPlayerY,nPlayerX-1)
						oGameCamera.FastMoveleft() 
						aLevel[nPlayerY][nPlayerX] = C_GOLDGROUND
						nPlayerX--
						if CheckWin() return ok
						setIsPoint(nPlayerY,nPlayerX)
						aLevel[nPlayerY][nPlayerX] = C_PLAYER
						CheckPointActions()
					ok
				ok
			ok
			if key[key_right]
				if nPlayerX < nCols
					if not IsWall(nPlayerY,nPlayerX+1)
						oGameCamera.FastMoveRight()
						aLevel[nPlayerY][nPlayerX] = C_GOLDGROUND
						nPlayerX++
						if CheckWin() return ok
						setIsPoint(nPlayerY,nPlayerX)
						aLevel[nPlayerY][nPlayerX] = C_PLAYER
						CheckPointActions()
					ok
				ok
			ok
			if key[key_up]
				if nPlayerY > 1
					if not IsWall(nPlayerY-1,nPlayerX)
						oGameCamera.FastMoveUp()
						aLevel[nPlayerY][nPlayerX] = C_GOLDGROUND
						nPlayerY--
						if CheckWin() return ok
						setIsPoint(nPlayerY,nPlayerX)
						aLevel[nPlayerY][nPlayerX] = C_PLAYER
						CheckPointActions()
					ok
				ok
			ok
			if key[key_down]
				if nPlayerY < nRows
					if not IsWall(nPlayerY+1,nPlayerX)
						oGameCamera.FastMoveDown()
						aLevel[nPlayerY][nPlayerX] = C_GOLDGROUND
						nPlayerY++
						if CheckWin() return ok
						setIsPoint(nPlayerY,nPlayerX)
						aLevel[nPlayerY][nPlayerX] = C_PLAYER
						CheckPointActions()
					ok
				ok
			ok


		# Move by mouse 
			AfterMoveByMouse()

	func CheckWin

		lPlayerWin = IsPlayerWin()
		if lPlayerWin
			nActiveScreen = C_SCREEN_LEVELCOMPLETE
		ok
		return lPlayerWin 

	func IsPlayerWin 

		switch nActiveDoor
			on 0
				return False
			on 1
				nCheck = C_DOOR
			on 2
				nCheck = C_DOOR2
			on 3
				nCheck = C_DOOR3
			on 4
				nCheck = C_DOOR4
			on 5
				nCheck = C_DOOR5
			on 6
				nCheck = C_DOOR6
			on 7
				nCheck = C_DOOR7
			on 8
				nCheck = C_DOOR8
			on 9
				nCheck = C_DOOR9
			on 10
				nCheck = C_DOOR10
			on 11
				nCheck = C_DOOR11
			on 12
				nCheck = C_DOOR12
			on 13
				nCheck = C_DOOR13
			on 14
				nCheck = C_DOOR14
			on 15
				nCheck = C_DOOR15
			on 16
				nCheck = C_DOOR16

		off
		if aLevel[nPlayerY][nPlayerX] = nCheck
			oGameSound.PlayLevelSound()
			ConvertGoldToWall()
			if nActiveDoor != nDoorsCount
				nActiveDoor++
			else 
				return True 
			ok
		ok
		return False 

	func SetIsPoint Y,X

		if aLevel[Y][X] = C_GROUND 
			lIsPoint = True 
		ok

	func CheckPointActions

		if lIsPoint 
			lIsPoint = False 
			oGameSound.PlayPointSound()
			nScore += 10
			if nScore = C_MAX_REQUIRED_SCORE_FOR_GOLD and nActiveDoor = 0
					oGameSound.PlayLevelSound()
					nActiveDoor = 1
			ok
			if nScore > C_MAX_REQUIRED_SCORE_FOR_GOLD and nActiveDoor = 1
				oGameSound.PlayHitSound()
				nActiveDoor = 0
			ok

		else 
			oGameSound.StopPointSound()
			oGameSound.StopHitSound()
		ok

	func PlayerWin

		# Draw Level Complete Message
			set2DMODE()
			Start2DScreen()
			DrawWinBackGroundImage()
			DrawPlayerWin()
			End2DScreen()
			al_flip_display()
			lFlipDisplay = False

