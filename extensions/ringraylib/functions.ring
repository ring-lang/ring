func RayLibColor r,b,g,a
	return GetColor( Bytes2Int(  Char(a) + Char(g) + Char(b) + Char(r) ) )

func Vector2 x,y
	oData = raylib_new_vector2()
	raylib_set_vector2_x(oData,x)
	raylib_set_vector2_y(oData,y)
	return oData	

func Vector3 x,y,z
	oData = raylib_new_vector3()
	raylib_set_vector3_x(oData,x)
	raylib_set_vector3_y(oData,y)
	raylib_set_vector3_z(oData,z)
	return oData	

func Vector4 x,y,z,w
	oData = raylib_new_vector4()
	raylib_set_vector4_x(oData,x)
	raylib_set_vector4_y(oData,y)
	raylib_set_vector4_z(oData,z)
	raylib_set_vector4_w(oData,w)
	return oData	
