class gameobject from gamebase
	enabled = true
	x=0 y=0	 width=0 height=0 nindex = 0
	animate=true	move=false Scaled=false
	temp = null
	keypress = ""
	mouse = ""
	finger = ""
	state = ""
	draw = ""

	func init

	func draw oGame
		if not draw = ""				 		
				call draw(oGame,Self) 
		ok

	func animate oGame,oSelf
		if not enabled return ok
		if not state = ""				 		
				call state(oGame,oSelf) 
		ok
		if not animate return ok

	func keyboard oGame,nkey
		if not enabled return ok
		if not keypress = ""			
			call keypress(oGame,self,nkey)
		ok
		if not move return ok
		switch nkey
		on key_up	y-=10
		on key_down	y+=10
		on key_left	x-=10
		on key_right	x+=10
		off

	func mouse oGame,nType,aMouseList
		if not enabled return ok
		if not mouse = ""			
			call mouse(oGame,self,nType,aMouseList)
		ok

	func finger oGame,nType
		if not enabled return ok
		if not finger = ""			
			call finger(oGame,self,nType)
		ok

	func rgb r,g,b
		return gl_map_rgb(r,g,b)

	func delete
