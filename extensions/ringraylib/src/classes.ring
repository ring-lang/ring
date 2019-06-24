class Vector2 x y

	oData = raylib_new_vector2()

	func init (nX,nY)
		x=nX y=nY

	func data 
		raylib_set_vector2_x(oData,x)
		raylib_set_vector2_y(oData,y)
		return oData	

	func setdata oStruct 
		x = raylib_get_vector2_x(oStruct)
		y = raylib_get_vector2_y(oStruct)

class Vector3 x y z

	oData = raylib_new_vector3()

	func init (nX,nY,nZ)
		x=nX y=nY z=nZ

	func data 
		raylib_set_vector3_x(oData,x)
		raylib_set_vector3_y(oData,y)
		raylib_set_vector3_z(oData,z)
		return oData	

	func setdata oStruct 
		x = raylib_get_vector3_x(oStruct)
		y = raylib_get_vector3_y(oStruct)
		z = raylib_get_vector3_z(oStruct)

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

	func setdata oStruct 
		x = raylib_get_vector4_x(oStruct)
		y = raylib_get_vector4_y(oStruct)
		z = raylib_get_vector4_z(oStruct)
		w = raylib_get_vector4_w(oStruct)
