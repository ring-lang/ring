class Vector2 x y

	oData = raylib_new_managed_vector2()

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

	oData = raylib_new_managed_vector3()

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

	oData = raylib_new_managed_vector4()

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

class Quaternion x y z w

	oData = raylib_new_managed_Quaternion()

	func init (nX,nY,nZ,nW)
		x=nX y=nY z=nZ w=nW

	func data 
		raylib_set_Quaternion_x(oData,x)
		raylib_set_Quaternion_y(oData,y)
		raylib_set_Quaternion_z(oData,z)
		raylib_set_Quaternion_w(oData,w)
		return oData	

	func setdata oStruct 
		x = raylib_get_Quaternion_x(oStruct)
		y = raylib_get_Quaternion_y(oStruct)
		z = raylib_get_Quaternion_z(oStruct)
		w = raylib_get_Quaternion_w(oStruct)

class Matrix m0 m1 m2 m3 m4 m5 m6 m7 m8 m9 m10 m11 m12 m13 m14 m15

	oData = raylib_new_managed_Matrix()

	func init (p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
		m0 = p0
		m1 = p1
		m2 = p2
		m3 = p3
		m4 = p4
		m5 = p5
		m6 = p6
		m7 = p7
		m8 = p8
		m9 = p9
		m10= p10
		m11= p11
		m12= p12
		m13= p13
		m14= p14
		m15= p15

	func data 
		raylib_set_Matrix_m0(oData,m0)
		raylib_set_Matrix_m1(oData,m1)
		raylib_set_Matrix_m2(oData,m2)
		raylib_set_Matrix_m3(oData,m3)
		raylib_set_Matrix_m4(oData,m4)
		raylib_set_Matrix_m5(oData,m5)
		raylib_set_Matrix_m6(oData,m6)
		raylib_set_Matrix_m7(oData,m7)
		raylib_set_Matrix_m8(oData,m8)
		raylib_set_Matrix_m9(oData,m9)
		raylib_set_Matrix_m10(oData,m10)
		raylib_set_Matrix_m11(oData,m11)
		raylib_set_Matrix_m12(oData,m12)
		raylib_set_Matrix_m13(oData,m13)
		raylib_set_Matrix_m14(oData,m14)
		raylib_set_Matrix_m15(oData,m15)
		return oData	

	func setdata oStruct 
		m0 = raylib_get_Matrix_m0(oStruct)
		m1 = raylib_get_Matrix_m1(oStruct)
		m2 = raylib_get_Matrix_m2(oStruct)
		m3 = raylib_get_Matrix_m3(oStruct)
		m4 = raylib_get_Matrix_m4(oStruct)
		m5 = raylib_get_Matrix_m5(oStruct)
		m6 = raylib_get_Matrix_m6(oStruct)
		m7 = raylib_get_Matrix_m7(oStruct)
		m8 = raylib_get_Matrix_m8(oStruct)
		m9 = raylib_get_Matrix_m9(oStruct)
		m10 = raylib_get_Matrix_m10(oStruct)
		m11 = raylib_get_Matrix_m11(oStruct)
		m12 = raylib_get_Matrix_m12(oStruct)
		m13 = raylib_get_Matrix_m13(oStruct)
		m14 = raylib_get_Matrix_m14(oStruct)
		m15 = raylib_get_Matrix_m15(oStruct)

class Color r g b a

	oData = raylib_new_managed_Color()

	func init (nR,nG,nB,nA)
		r=nR g=nG b=nB a=nA

	func data 
		raylib_set_Color_r(oData,r)
		raylib_set_Color_g(oData,g)
		raylib_set_Color_b(oData,b)
		raylib_set_Color_a(oData,a)
		return oData	

	func setdata oStruct 
		r = raylib_get_Color_r(oStruct)
		g = raylib_get_Color_g(oStruct)
		b = raylib_get_Color_b(oStruct)
		a = raylib_get_Color_a(oStruct)

class Rectangle x y width height

	oData = raylib_new_managed_Rectangle()

	func init (nX,nY,nWidth,nHeight)
		x=nX y=nY width=nWidth height=nHeight

	func data 
		raylib_set_Rectangle_x(oData,x)
		raylib_set_Rectangle_y(oData,y)
		raylib_set_Rectangle_width(oData,width)
		raylib_set_Rectangle_height(oData,height)
		return oData	

	func setdata oStruct 
		x 	= raylib_get_Rectangle_x(oStruct)
		y 	= raylib_get_Rectangle_y(oStruct)
		width 	= raylib_get_Rectangle_width(oStruct)
		height 	= raylib_get_Rectangle_height(oStruct)

class Image 

	data width  height mipmaps  format
	oData = raylib_new_managed_Image()

	func init p1,p2,p3,p4,p5
		data=p1  width=p2 height=p3 mipmaps=p4 format=p5

	func data 
		raylib_set_Image_data(oData,data)
		raylib_set_Image_width(oData,width)
		raylib_set_Image_height(oData,height)
		raylib_set_Image_mipmaps(oData,mipmaps)
		raylib_set_Image_format(oData,format)
		return oData	

	func setdata oStruct 
		data 	= raylib_get_Image_data(oStruct)
		width 	= raylib_get_Image_width(oStruct)
		height 	= raylib_get_Image_height(oStruct)
		mipmaps = raylib_get_Image_mipmaps(oStruct)
		format 	= raylib_get_Image_format(oStruct)

class Texture2D 

	id width  height mipmaps  format
	oData = raylib_new_managed_Texture2D()

	func init p1,p2,p3,p4,p5
		id=p1  width=p2 height=p3 mipmaps=p4 format=p5

	func data 
		raylib_set_Texture2D_id(oData,id)
		raylib_set_Texture2D_width(oData,width)
		raylib_set_Texture2D_height(oData,height)
		raylib_set_Texture2D_mipmaps(oData,mipmaps)
		raylib_set_Texture2D_format(oData,format)
		return oData	

	func setdata oStruct 
		id 	= raylib_get_Texture2D_id(oStruct)
		width 	= raylib_get_Texture2D_width(oStruct)
		height 	= raylib_get_Texture2D_height(oStruct)
		mipmaps = raylib_get_Texture2D_mipmaps(oStruct)
		format 	= raylib_get_Texture2D_format(oStruct)
	
class Camera3D

	position	= new Vector3
	target		= new Vector3
	up		= new Vector3 
	fovy	type 
	
	oData = raylib_new_managed_Camera3D()

	func init (p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)
		position.x = p1
		position.y = p2
		position.z = p3
		target.x = p4
		target.y = p5
		target.z = p6
		up.x = p7
		up.y = p8
		up.z = p9
		fovy = p10
		type = p11

	func data 
		raylib_set_Camera3D_position_x(oData,position.x)
		raylib_set_Camera3D_position_y(oData,position.y)
		raylib_set_Camera3D_position_z(oData,position.z)
		raylib_set_Camera3D_target_x(oData,target.x)
		raylib_set_Camera3D_target_y(oData,target.y)
		raylib_set_Camera3D_target_z(oData,target.z)
		raylib_set_Camera3D_up_x(oData,up.x)
		raylib_set_Camera3D_up_y(oData,up.y)
		raylib_set_Camera3D_up_z(oData,up.z)
		raylib_set_Camera3D_fovy(oData,fovy)
		raylib_set_Camera3D_type(oData,type)
		return oData	

	func setdata oStruct 
		position.x = raylib_get_Camera3D_position_x(oStruct)
		position.y = raylib_get_Camera3D_position_y(oStruct)
		position.z = raylib_get_Camera3D_position_z(oStruct)
		target.x = raylib_get_Camera3D_target_x(oStruct)
		target.y = raylib_get_Camera3D_target_y(oStruct)
		target.z = raylib_get_Camera3D_target_z(oStruct)
		up.x = raylib_get_Camera3D_up_x(oStruct)
		up.y = raylib_get_Camera3D_up_y(oStruct)
		up.z = raylib_get_Camera3D_up_z(oStruct)
		fovy = raylib_get_Camera3D_fovy(oStruct)
		type = raylib_get_Camera3D_type(oStruct)

	func refresh 
		position.x = raylib_get_Camera3D_position_x(oData)
		position.y = raylib_get_Camera3D_position_y(oData)
		position.z = raylib_get_Camera3D_position_z(oData)
		target.x = raylib_get_Camera3D_target_x(oData)
		target.y = raylib_get_Camera3D_target_y(oData)
		target.z = raylib_get_Camera3D_target_z(oData)
		up.x = raylib_get_Camera3D_up_x(oData)
		up.y = raylib_get_Camera3D_up_y(oData)
		up.z = raylib_get_Camera3D_up_z(oData)
		fovy = raylib_get_Camera3D_fovy(oData)
		type = raylib_get_Camera3D_type(oData)

class Ray

	position	= new Vector3
	direction	= new Vector3

	oData = raylib_new_managed_Ray()

	func init (p1,p2,p3,p4,p5,p6)
		position.x = p1
		position.y = p2
		position.z = p3
		direction.x = p4
		direction.y = p5
		direction.z = p6

	func data 
		raylib_set_Ray_position_x(oData,position.x)
		raylib_set_Ray_position_y(oData,position.y)
		raylib_set_Ray_position_z(oData,position.z)
		raylib_set_Ray_direction_x(oData,direction.x)
		raylib_set_Ray_direction_y(oData,direction.y)
		raylib_set_Ray_direction_z(oData,direction.z)
		return oData	

	func setdata oStruct 
		position.x = raylib_get_Ray_position_x(oStruct)
		position.y = raylib_get_Ray_position_y(oStruct)
		position.z = raylib_get_Ray_position_z(oStruct)
		direction.x = raylib_get_Ray_direction_x(oStruct)
		direction.y = raylib_get_Ray_direction_y(oStruct)
		direction.z = raylib_get_Ray_direction_z(oStruct)

	func refresh 
		position.x = raylib_get_Ray_position_x(oData)
		position.y = raylib_get_Ray_position_y(oData)
		position.z = raylib_get_Ray_position_z(oData)
		directionx = raylib_get_Ray_direction_x(oData)
		direction.y = raylib_get_Ray_direction_y(oData)
		direction.z = raylib_get_Ray_direction_z(oData)

class BoundingBox 

	min	= new Vector3
	max	= new Vector3

	oData = raylib_new_managed_BoundingBox()

	func init (p1,p2,p3,p4,p5,p6)
		min.x = p1
		min.y = p2
		min.z = p3
		max.x = p4
		max.y = p5
		max.z = p6

	func data 
		raylib_set_BoundingBox_min_x(oData,min.x)
		raylib_set_BoundingBox_min_y(oData,min.y)
		raylib_set_BoundingBox_min_z(oData,min.z)
		raylib_set_BoundingBox_max_x(oData,max.x)
		raylib_set_BoundingBox_max_y(oData,max.y)
		raylib_set_BoundingBox_max_z(oData,max.z)
		return oData	

	func setdata oStruct 
		min.x = raylib_get_BoundingBox_min_x(oStruct)
		min.y = raylib_get_BoundingBox_min_y(oStruct)
		min.z = raylib_get_BoundingBox_min_z(oStruct)
		max.x = raylib_get_BoundingBox_max_x(oStruct)
		max.y = raylib_get_BoundingBox_max_y(oStruct)
		max.z = raylib_get_BoundingBox_max_z(oStruct)

	func refresh 
		min.x = raylib_get_BoundingBox_min_x(oData)
		min.y = raylib_get_BoundingBox_min_y(oData)
		min.z = raylib_get_BoundingBox_min_z(oData)
		maxx = raylib_get_BoundingBox_max_x(oData)
		max.y = raylib_get_BoundingBox_max_y(oData)
		max.z = raylib_get_BoundingBox_max_z(oData)
