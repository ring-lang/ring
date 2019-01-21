# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameMouse 

	func ShowMouse
		if lShowHideMouse
			al_show_mouse_cursor(display)
		ok

	func HideMouse 
		if lShowHideMouse
			al_hide_mouse_cursor(display)
		ok

	func PlayUsingTheMouse 
		PlayUsingTheMouseToMoveBox()

	func AfterMoveByMouse
		AfterMoveByMouseToMoveBox()

	func PlayUsingTheMouseToMoveBox 
		if lPlayUsingMouse
			lMoveByMouse = False 
			if lMouseMove 
				nDiffX1 	= Mouse_X - Last_Mouse_X			
				nDiffX2 	= Last_Mouse_X - Mouse_X
				nDiffY1 	= Mouse_Y - Last_Mouse_Y
				nDiffY2 	= Last_Mouse_Y - Mouse_Y
				nDiffXMax 	= max(nDiffX1,nDiffX2)
				nDiffYMax 	= max(nDiffY1,nDiffY2)
				if nDiffXMax > nDiffYMax
					nDiffY1 = 0
					nDiffY2 = 0
				but nDiffYMax > nDiffXMax
					nDiffX1 = 0
					nDiffX2 = 0
				else 
					return 
				ok
				nDiffConstant = 1
				if nDiffX1 > nDiffConstant 
					key[KEY_RIGHT] 	= True
					lMoveByMouse 	= True
				ok 
				if nDiffX2 > nDiffConstant 
					key[KEY_LEFT] 	= True
					lMoveByMouse 	= True
				ok 
				if nDiffY1 > nDiffConstant 
					key[KEY_DOWN] 	= True
					lMoveByMouse 	= True
				ok 
				if nDiffY2 > nDiffConstant 
					key[KEY_UP] 	= True
					lMoveByMouse 	= True
				ok
			ok					
		ok		

	func AfterMoveByMouseToMoveBox
		if lPlayUsingMouse
			if lMoveByMouse 
				lMoveByMouse = False
				lMouseMove 	= False 
				Last_Mouse_X 	= Mouse_X
				Last_Mouse_Y 	= Mouse_Y
				key[KEY_UP] 	= False
				key[KEY_DOWN] 	= False
				key[KEY_LEFT] 	= False
				key[KEY_RIGHT] 	= False
				al_set_mouse_xy(display,500,500)
				Last_Mouse_X 	= 500
				Last_Mouse_Y 	= 500
				MOUSE_X = 500 
				MOUSE_Y = 500
				al_flush_event_queue(event_queue)
			ok
		ok			

	func PlayUsingTheMouseToMoveCamera

	func AfterMoveByMouseToMoveCamera
