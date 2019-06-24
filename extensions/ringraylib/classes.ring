class Vector2 x y
	oData = raylib_new_vector2()
	func init (nX,nY)
		x=nX y=nY
	func data 
		raylib_set_vector2_x(oData,x)
		raylib_set_vector2_y(oData,y)
		return oData	
