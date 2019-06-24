class Vector2 x y
	oData = raylib_new_vector2()
	func init (nX,nY)
		x=nX y=nY
	func data 
		raylib_set_vector2_x(oData,x)
		raylib_set_vector2_y(oData,y)
		return oData	

class Vector3 x y z
	oData = raylib_new_vector3()
	func init (nX,nY,nZ)
		x=nX y=nY z=nZ
	func data 
		raylib_set_vector3_x(oData,x)
		raylib_set_vector3_y(oData,y)
		raylib_set_vector3_z(oData,z)
		return oData	

class Vector4 x y z w
	oData = raylib_new_vector4()
	func init (nX,nY,nZ,nW)
		x=nX y=nY z=nZ w=nW
	func data 
		raylib_set_vector4_x(oData,x)
		raylib_set_vector4_y(oData,y)
		raylib_set_vector4_z(oData,z)
		raylib_set_vector4_w(oData,w)
		return oData	
