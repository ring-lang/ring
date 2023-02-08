class RayLibBase 

	oData

	func setdata oStruct 

	func refresh 
		setdata(oData)

class Vector2 from RayLibBase

	x y 

	oData = raylib_new_managed_vector2()

	func init nX,nY
		x=nX y=nY

	func data 
		raylib_set_vector2_x(oData,x)
		raylib_set_vector2_y(oData,y)
		return oData	

	func setdata oStruct 
		oData = oStruct  
		x = raylib_get_vector2_x(oStruct)
		y = raylib_get_vector2_y(oStruct)

class Vector3 from RayLibBase

	x y z

	oData = raylib_new_managed_vector3()

	func init nX,nY,nZ
		x=nX y=nY z=nZ

	func data 
		raylib_set_vector3_x(oData,x)
		raylib_set_vector3_y(oData,y)
		raylib_set_vector3_z(oData,z)
		return oData	

	func setdata oStruct 
		oData = oStruct  
		x = raylib_get_vector3_x(oStruct)
		y = raylib_get_vector3_y(oStruct)
		z = raylib_get_vector3_z(oStruct)

class Vector4 from RayLibBase

	x y z w

	oData = raylib_new_managed_vector4()

	func init nX,nY,nZ,nW
		x=nX y=nY z=nZ w=nW

	func data 
		raylib_set_vector4_x(oData,x)
		raylib_set_vector4_y(oData,y)
		raylib_set_vector4_z(oData,z)
		raylib_set_vector4_w(oData,w)
		return oData	

	func setdata oStruct 
		oData = oStruct  
		x = raylib_get_vector4_x(oStruct)
		y = raylib_get_vector4_y(oStruct)
		z = raylib_get_vector4_z(oStruct)
		w = raylib_get_vector4_w(oStruct)

class Quaternion from RayLibBase

	x y z w

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
		oData = oStruct  
		x = raylib_get_Quaternion_x(oStruct)
		y = raylib_get_Quaternion_y(oStruct)
		z = raylib_get_Quaternion_z(oStruct)
		w = raylib_get_Quaternion_w(oStruct)


class Matrix from RayLibBase

	m0 m1 m2 m3 m4 m5 m6 m7 m8 m9 m10 m11 m12 m13 m14 m15

	oData = raylib_new_managed_Matrix()

	func init p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15
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
		oData = oStruct  
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

class Color from RayLibBase

	r g b a

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
		oData = oStruct  
		r = raylib_get_Color_r(oStruct)
		g = raylib_get_Color_g(oStruct)
		b = raylib_get_Color_b(oStruct)
		a = raylib_get_Color_a(oStruct)

class Rectangle from RayLibBase

	x y width height

	oData = raylib_new_managed_Rectangle()

	func init nX,nY,nWidth,nHeight
		x=nX y=nY width=nWidth height=nHeight

	func data 
		raylib_set_Rectangle_x(oData,x)
		raylib_set_Rectangle_y(oData,y)
		raylib_set_Rectangle_width(oData,width)
		raylib_set_Rectangle_height(oData,height)
		return oData	

	func setdata oStruct 
		oData = oStruct  
		x 	= raylib_get_Rectangle_x(oStruct)
		y 	= raylib_get_Rectangle_y(oStruct)
		width 	= raylib_get_Rectangle_width(oStruct)
		height 	= raylib_get_Rectangle_height(oStruct)


class Image from RayLibBase

	data width  height mipmaps  format

	oData = raylib_new_Managed_Image()

	func init p1,p2,p3,p4,p5
		data=p1  width=p2 height=p3 mipmaps=p4 format=p5

	func data 
		raylib_set_Image_width(oData,width)
		raylib_set_Image_height(oData,height)
		raylib_set_Image_mipmaps(oData,mipmaps)
		raylib_set_Image_format(oData,format)
		return oData	

	func setdata oStruct 
		oData   = oStruct  
		data 	= raylib_get_Image_data(oStruct)
		width 	= raylib_get_Image_width(oStruct)
		height 	= raylib_get_Image_height(oStruct)
		mipmaps = raylib_get_Image_mipmaps(oStruct)
		format 	= raylib_get_Image_format(oStruct)

class Texture2D from RayLibBase

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
		oData 	= oStruct  
		id 	= raylib_get_Texture2D_id(oStruct)
		width 	= raylib_get_Texture2D_width(oStruct)
		height 	= raylib_get_Texture2D_height(oStruct)
		mipmaps = raylib_get_Texture2D_mipmaps(oStruct)
		format 	= raylib_get_Texture2D_format(oStruct)

class RenderTexture2D from RayLibBase

	id 
	texture = new Texture2D 
	depth 	= new Texture2D  
	depthTexture

	oData = raylib_new_managed_RenderTexture2D()

	func init p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12 

		id		= p1
		texture.id	= p2
		texture.width	= p3
		texture.height	= p4
		texture.mipmaps	= p5
		texture.format	= p6
		depth.id	= p7
		depth.width	= p8
		depth.height	= p9
		depth.mipmaps	= p10
		depth.format	= p11
		depthTexture	= p12

	func data 
		raylib_set_RenderTexture2D_id(oData,id)	
		raylib_set_RenderTexture2D_texture_id(oData,texture.id)	
		raylib_set_RenderTexture2D_texture_width(oData,texture.width)	
		raylib_set_RenderTexture2D_texture_height(oData,texture.height)	
		raylib_set_RenderTexture2D_texture_mipmaps(oData,texture.mipmaps)	
		raylib_set_RenderTexture2D_texture_format(oData,texture.format)	
		raylib_set_RenderTexture2D_depth_id(oData,depth.id)	
		raylib_set_RenderTexture2D_depth_width(oData,depth.width)	
		raylib_set_RenderTexture2D_depth_height(oData,depth.height)	
		raylib_set_RenderTexture2D_depth_mipmaps(oData,depth.mipmaps)	
		raylib_set_RenderTexture2D_depth_format(oData,depth.format)	
		raylib_set_RenderTexture2D_depthTexture(oData,depthTexture)	
		return oData

	func setdata oStruct 
		oData 		= oStruct  
		id	 	= raylib_get_RenderTexture2D_id(oStruct)
		texture.id 	= raylib_get_RenderTexture2D_texture_id(oStruct)
		texture.width 	= raylib_get_RenderTexture2D_texture_width(oStruct) 
		texture.height	= raylib_get_RenderTexture2D_texture_height(oStruct)
		texture.mipmaps = raylib_get_RenderTexture2D_texture_mipmaps(oStruct) 
		texture.format  = raylib_get_RenderTexture2D_texture_format(oStruct)
		depth.id 	= raylib_get_RenderTexture2D_depth_id(oStruct)
		depth.width 	= raylib_get_RenderTexture2D_depth_width(oStruct) 
		depth.height	= raylib_get_RenderTexture2D_depth_height(oStruct)
		depth.mipmaps 	= raylib_get_RenderTexture2D_depth_mipmaps(oStruct) 
		depth.format  	= raylib_get_RenderTexture2D_depth_format(oStruct)
		depthTexture	= raylib_get_RenderTexture2D_depthTexture(oStruct)

class NPatchInfo from RayLibBase

	sourceRec = new Rectangle 
	left top  right bottom type 

	oData = raylib_new_managed_NPatchInfo()

	func init p1,p2,p3,p4,p5,p6,p7,p8,p9
		sourceRec.x 		= p1
		sourceRec.y 		= p2
		sourceRec.width		= p3
		sourceRec.height	= p4
		left 			= p5
		top  			= p6
		right 			= p7
		bottom 			= p8
		type 			= p9

	func data 	
		raylib_set_NPatchInfo_sourceRec_x(oData,sourceRec.x)		
		raylib_set_NPatchInfo_sourceRec_y(oData,sourceRec.y)		
		raylib_set_NPatchInfo_sourceRec_width(oData,sourceRec.width)		
		raylib_set_NPatchInfo_sourceRec_height(oData,sourceRec.height)	
		raylib_set_NPatchInfo_left(oData,left)			
		raylib_set_NPatchInfo_top(oData,top)			
		raylib_set_NPatchInfo_right(oData,right)			
		raylib_set_NPatchInfo_bottom(oData,bottom)			
		raylib_set_NPatchInfo_type(oData,type)			
		return oData

	func setdata oStruct 
		oData 			= oStruct  
		sourceRec.x 		= raylib_get_NPatchInfo_sourceRec_x(oStruct)
		sourceRec.y 		= raylib_get_NPatchInfo_sourceRec_y(oStruct)
		sourceRec.width		= raylib_get_NPatchInfo_sourceRec_width(oStruct)
		sourceRec.height	= raylib_get_NPatchInfo_sourceRec_height(oStruct)
		left 			= raylib_get_NPatchInfo_left(oStruct)
		top  			= raylib_get_NPatchInfo_top(oStruct)
		right 			= raylib_get_NPatchInfo_right(oStruct)
		bottom 			= raylib_get_NPatchInfo_bottom(oStruct)
		type 			= raylib_get_NPatchInfo_type(oStruct)

class CharInfo from RayLibBase

	value 
	rec = new Rectangle
	offsetX offsetY advanceX data 

	oData = raylib_new_managed_CharInfo()

	func init p1,p2,p3,p4,p5,p6,p7,p8,p9
		value 		= p1
		rec.x		= p2
		rec.y		= p3
		rec.width	= p4
		rec.height	= p5
		offsetX		= p6
		offsetY		= p7
		advanceX	= p8
		data		= p9

	func data 
		raylib_set_CharInfo_value(oData,value)		
		raylib_set_CharInfo_rec_x(oData,rec.x)		
		raylib_set_CharInfo_rec_y(oData,rec.y)		
		raylib_set_CharInfo_rec_width(oData,rec.width)		
		raylib_set_CharInfo_rec_height(oData,rec.height)
		raylib_set_CharInfo_offsetX(oData,offsetX)		
		raylib_set_CharInfo_offsetY(oData,offsetY)		
		raylib_set_CharInfo_advanceX(oData,advanceX)		
		raylib_set_CharInfo_data(oData,data)				
		return oData

	func setdata oStruct 
		oData 		= oStruct  
		value		= raylib_get_CharInfo_value(oStruct)
		rec.x		= raylib_get_CharInfo_rec_x(oStruct)
		rec.y		= raylib_get_CharInfo_rec_y(oStruct)
		rec.width	= raylib_get_CharInfo_rec_width(oStruct)
		rec.height	= raylib_get_CharInfo_rec_height(oStruct)
		offsetX		= raylib_get_CharInfo_offsetX(oStruct)
		offsetY		= raylib_get_CharInfo_offsetY(oStruct)
		advanceX	= raylib_get_CharInfo_advanceX(oStruct)
		data		= raylib_get_CharInfo_data(oStruct)

class SpriteFont from RayLibBase

	texture = new Texture2D
	baseSize charsCount chars

	oData = raylib_new_managed_SpriteFont()

	func init p1,p2,p3,p4,p5,p6,p7,p8
		texture.id 	= p1
		texture.width 	= p2 
		texture.height	= p3
		texture.mipmaps = p4 
		texture.format  = p5
		baseSize	= p6
		charsCount	= p7
		chars		= p8

	func data 
		raylib_set_SpriteFont_texture_id(oData,texture.id)	
		raylib_set_SpriteFont_texture_width(oData,texture.width)	
		raylib_set_SpriteFont_texture_height(oData,texture.height)	
		raylib_set_SpriteFont_texture_mipmaps(oData,texture.mipmaps)	
		raylib_set_SpriteFont_texture_format(oData,texture.format)	
		raylib_set_SpriteFont_baseSize(oData,baseSize)	
		raylib_set_SpriteFont_charsCount(oData,charsCount)	
		raylib_set_SpriteFont_chars(oData,chars)	
		return oData

	func setdata oStruct 
		oData 		= oStruct  
		texture.id 	= raylib_get_SpriteFont_texture_id(oStruct)
		texture.width 	= raylib_get_SpriteFont_texture_width(oStruct) 
		texture.height	= raylib_get_SpriteFont_texture_height(oStruct)
		texture.mipmaps = raylib_get_SpriteFont_texture_mipmaps(oStruct) 
		texture.format  = raylib_get_SpriteFont_texture_format(oStruct)
		baseSize	= raylib_get_SpriteFont_baseSize(oStruct)
		charsCount	= raylib_get_SpriteFont_charsCount(oStruct)
		chars		= raylib_get_SpriteFont_chars(oStruct)

class Font from RayLibBase

	texture = new Texture2D
	baseSize charsCount chars

	oData = raylib_new_managed_Font()

	func init p1,p2,p3,p4,p5,p6,p7,p8
		texture.id 	= p1
		texture.width 	= p2 
		texture.height	= p3
		texture.mipmaps = p4 
		texture.format  = p5
		baseSize	= p6
		charsCount	= p7
		chars		= p8

	func data 
		raylib_set_Font_texture_id(oData,texture.id)	
		raylib_set_Font_texture_width(oData,texture.width)	
		raylib_set_Font_texture_height(oData,texture.height)	
		raylib_set_Font_texture_mipmaps(oData,texture.mipmaps)	
		raylib_set_Font_texture_format(oData,texture.format)	
		raylib_set_Font_baseSize(oData,baseSize)	
		raylib_set_Font_charsCount(oData,charsCount)	
		raylib_set_Font_chars(oData,chars)	
		return oData

	func setdata oStruct 
		oData 		= oStruct  
		texture.id 	= raylib_get_Font_texture_id(oStruct)
		texture.width 	= raylib_get_Font_texture_width(oStruct) 
		texture.height	= raylib_get_Font_texture_height(oStruct)
		texture.mipmaps = raylib_get_Font_texture_mipmaps(oStruct) 
		texture.format  = raylib_get_Font_texture_format(oStruct)
		baseSize	= raylib_get_Font_baseSize(oStruct)
		charsCount	= raylib_get_Font_charsCount(oStruct)
		chars		= raylib_get_Font_chars(oStruct)

class Camera3D from RayLibBase

	position	= new Vector3
	target		= new Vector3
	up		= new Vector3 
	fovy	type 
	
	oData = raylib_new_managed_Camera3D()

	func init p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11
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
		oData 	   = oStruct  
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

class Mesh from RayLibBase

	vertexCount triangleCount vertices texcoords texcoords2 normals
	tangents colors indices animVertices animNormals boneIds
	boneWeights vaoId

	oData = raylib_new_managed_Mesh()

	func init p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14 

		vertexCount	= p1
		triangleCount	= p2
		vertices	= p3
		texcoords	= p4
		texcoords2	= p5
		normals		= p6
		tangents	= p7
		colors		= p8
		indices		= p9
		animVertices	= p10
		animNormals	= p11
		boneIds		= p12
		boneWeights	= p13
		vaoId		= p14

	func data 
		raylib_set_Mesh_vertexCount(oData,vertexCount)	
		raylib_set_Mesh_triangleCount(oData,triangleCount)	
		raylib_set_Mesh_vertices(oData,vertices)	
		raylib_set_Mesh_texcoords(oData,texcoords)
		raylib_set_Mesh_texcoords2(oData,texcoords2)	
		raylib_set_Mesh_normals(oData,normals)	
		raylib_set_Mesh_tangents(oData,tangents)	
		raylib_set_Mesh_colors(oData,colors)	
		raylib_set_Mesh_indices(oData,indices)	
		raylib_set_Mesh_animVertices(oData,animVertices)	
		raylib_set_Mesh_animNormals(oData,animNormals)	
		raylib_set_Mesh_boneIds(oData,boneIds)	
		raylib_set_Mesh_boneWeights(oData,boneWeights)	
		raylib_set_Mesh_vaoId(oData,vaoId)	
		return oData

	func setdata oStruct 
		oData 		= oStruct  
		vertexCount	= raylib_get_Mesh_vertexCount(oStruct)
		triangleCount	= raylib_get_Mesh_triangleCount(oStruct)
		vertices	= raylib_get_Mesh_vertices(oStruct)
		texcoords	= raylib_get_Mesh_texcoords(oStruct)
		texcoords2	= raylib_get_Mesh_texcoords2(oStruct)
		normals		= raylib_get_Mesh_normals(oStruct)
		tangents	= raylib_get_Mesh_tangents(oStruct)
		colors		= raylib_get_Mesh_colors(oStruct)
		indices		= raylib_get_Mesh_indices(oStruct)
		animVertices	= raylib_get_Mesh_animVertices(oStruct)
		animNormals	= raylib_get_Mesh_animNormals(oStruct)
		boneIds		= raylib_get_Mesh_boneIds(oStruct)
		boneWeights	= raylib_get_Mesh_boneWeights(oStruct)
		vaoId		= raylib_get_Mesh_vaoId(oStruct)

class Shader from RayLibBase

	id

	oData = raylib_new_managed_Shader()

	func init p1
		id = p1

	func data 
		raylib_set_Shader_id(oData,id)	
		return oData

	func setdata oStruct 
		oData 	= oStruct  
		id 	= raylib_get_shader_id(oStruct)

class Material from RayLibBase

	shader = new Shader 
	params

	oData = raylib_new_managed_Material()

	func init p1,p2
		shader.id = p1
		params = p2

	func data 
		raylib_set_Material_Shader_id(oData,Shader.id)	
		raylib_set_Material_params(oData,params)	
		return oData 

	func setdata oStruct 
		oData 		= oStruct  
		shader.id 	= raylib_get_Material_shader_id(oStruct)
		params 		= raylib_get_Material_params(oStruct)

class Transform from RayLibBase

	translation 	= Vector3
	rotation	= Vector3		
	scale 		= Vector3 
	
	oData = raylib_new_managed_Transform()

	func init p1,p2,p3,p4,p5,p6,p7,p8,p9
		translation.x 	= p1
		translation.y 	= p2
		translation.z 	= p3
		rotation.x	= p4
		rotation.y	= p5
		rotation.z	= p6
		scale.x		= p7
		scale.y		= p8
		scale.z		= p9

	func data 
		raylib_set_Transform_translation_x(oData,translation.x)	
		raylib_set_Transform_translation_y(oData,translation.y)	
		raylib_set_Transform_translation_z(oData,translation.z)	
		raylib_set_Transform_rotation_x(oData,rotation.x)	
		raylib_set_Transform_rotation_y(oData,rotation.y)	
		raylib_set_Transform_rotation_z(oData,rotation.z)	
		raylib_set_Transform_scale_x(oData,scale.x)	
		raylib_set_Transform_scale_y(oData,scale.y)	
		raylib_set_Transform_scale_z(oData,scale.z)	
		return oData 

	func setdata oStruct 
		oData = oStruct  
		translation.x = raylib_get_Transform_translation_x(oStruct)
		translation.y = raylib_get_Transform_translation_y(oStruct)
		translation.z = raylib_get_Transform_translation_z(oStruct)
		rotation.x = raylib_get_Transform_rotation_x(oStruct)
		rotation.y = raylib_get_Transform_rotation_y(oStruct)
		rotation.z = raylib_get_Transform_rotation_z(oStruct)
		scale.x = raylib_get_Transform_scale_x(oStruct)
		scale.y = raylib_get_Transform_scale_y(oStruct)
		scale.z = raylib_get_Transform_scale_z(oStruct)

class BoneInfo from RayLibBase

	parent 

	oData = raylib_new_managed_BoneInfo()

	func init p1
		parent = p1

	func data 
		raylib_set_BoneInfo_parent(oData,parent)	
		return oData 

	func setdata oStruct 
		oData 	= oStruct  
		parent 	= raylib_get_Model_parent(oStruct)

class Model from RayLibBase

	transform = new Matrix
 	meshCount meshes materialCount materials 
	meshMaterial boneCount bones bindPose

	oData = raylib_new_managed_Model()

	func init

	func data 
		raylib_set_Model_transform_m0(oData,transform.m0)
		raylib_set_Model_transform_m1(oData,transform.m1)
		raylib_set_Model_transform_m2(oData,transform.m2)
		raylib_set_Model_transform_m3(oData,transform.m3)
		raylib_set_Model_transform_m4(oData,transform.m4)
		raylib_set_Model_transform_m5(oData,transform.m5)
		raylib_set_Model_transform_m6(oData,transform.m6)
		raylib_set_Model_transform_m7(oData,transform.m7)
		raylib_set_Model_transform_m8(oData,transform.m8)
		raylib_set_Model_transform_m9(oData,transform.m9)
		raylib_set_Model_transform_m10(oData,transform.m10)
		raylib_set_Model_transform_m11(oData,transform.m11)
		raylib_set_Model_transform_m12(oData,transform.m12)
		raylib_set_Model_transform_m13(oData,transform.m13)
		raylib_set_Model_transform_m14(oData,transform.m14)
		raylib_set_Model_transform_m15(oData,transform.m15)
  		raylib_set_Model_meshCount(oData,meshCount)
  		raylib_set_Model_meshes(oData,meshes)
  		raylib_set_Model_materialCount(oData,materialCount)
  		raylib_set_Model_materials(oData,materials)
  		raylib_set_Model_meshMaterial(oData,meshMaterial)
  		raylib_set_Model_boneCount(oData,boneCount)
  		raylib_set_Model_bones(oData,bones)
  		raylib_set_Model_bindPose(oData,bindPose)
		return oData

	func setdata oStruct 
		oData = oStruct  
		transform.m0 = raylib_get_Model_transform_m0(oStruct)
		transform.m1 = raylib_get_Model_transform_m1(oStruct)
		transform.m2 = raylib_get_Model_transform_m2(oStruct)
		transform.m3 = raylib_get_Model_transform_m3(oStruct)
		transform.m4 = raylib_get_Model_transform_m4(oStruct)
		transform.m5 = raylib_get_Model_transform_m5(oStruct)
		transform.m6 = raylib_get_Model_transform_m6(oStruct)
		transform.m7 = raylib_get_Model_transform_m7(oStruct)
		transform.m8 = raylib_get_Model_transform_m8(oStruct)
		transform.m9 = raylib_get_Model_transform_m9(oStruct)
		transform.m10 = raylib_get_Model_transform_m10(oStruct)
		transform.m11 = raylib_get_Model_transform_m11(oStruct)
		transform.m12 = raylib_get_Model_transform_m12(oStruct)
		transform.m13 = raylib_get_Model_transform_m13(oStruct)
		transform.m14 = raylib_get_Model_transform_m14(oStruct)
		transform.m15 = raylib_get_Model_transform_m15(oStruct)
		meshCount = raylib_get_Model_meshCount(oStruct)
		meshes = raylib_get_Model_meshes(oStruct)
		materialCount = raylib_get_Model_materialCount(oStruct)
		materials = raylib_get_Model_materials(oStruct)
		meshMaterial = raylib_get_Model_meshMaterial(oStruct)
		boneCount = raylib_get_Model_boneCount(oStruct)
		bones = raylib_get_Model_bones(oStruct)
		bindPose = raylib_get_Model_bindPose(oStruct)

class ModelAnimation from RayLibBase

	boneCount bones frameCount

	oData = raylib_new_managed_ModelAnimation()

	func init p1,p2,p3
		boneCount=p1 bones=p2 frameCount=p3

	func data 
		raylib_set_ModelAnimation_boneCount(oData,boneCount)
		raylib_set_ModelAnimation_bones(oData,bones)
		raylib_set_ModelAnimation_frameCount(oData,frameCount)
		return oData

	func setdata oStruct 
		oData = oStruct  
		boneCount = raylib_get_ModelAnimation_boneCount(oStruct)
		bones = raylib_get_ModelAnimation_bones(oStruct)
		frameCount = raylib_get_ModelAnimation_frameCount(oStruct)

class Ray from RayLibBase

	position	= new Vector3
	direction	= new Vector3

	oData = raylib_new_managed_Ray()

	func init p1,p2,p3,p4,p5,p6
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
		oData = oStruct  
		position.x = raylib_get_Ray_position_x(oStruct)
		position.y = raylib_get_Ray_position_y(oStruct)
		position.z = raylib_get_Ray_position_z(oStruct)
		direction.x = raylib_get_Ray_direction_x(oStruct)
		direction.y = raylib_get_Ray_direction_y(oStruct)
		direction.z = raylib_get_Ray_direction_z(oStruct)

class RayHitInfo from RayLibBase

	hit distance
	position = new Vector3
	normal   = new Vector3

	oData = raylib_new_managed_RayHitInfo()

	func init p1,p2,p3,p4,p5,p6,p7,p8
		hit=p1  distance=p2
		position.x = p3
		position.y = p4
		position.z = p5
		normal.x   = p6
		normal.y   = p7
		normal.z   = p8

	func data 
		raylib_set_RayHitInfo_hit(oData,hit)
		raylib_set_RayHitInfo_distance(oData,distance)
		raylib_set_RayHitInfo_position_x(oData,position.x)
		raylib_set_RayHitInfo_position_y(oData,position.y)
		raylib_set_RayHitInfo_position_z(oData,position.z)
		raylib_set_RayHitInfo_normal_x(oData,normal.x)
		raylib_set_RayHitInfo_normal_y(oData,normal.y)
		raylib_set_RayHitInfo_normal_z(oData,normal.z)
		return oData

	func setdata oStruct 
		oData = oStruct  
		hit = raylib_get_RayHitInfo_hit(oStruct)
		distance = raylib_get_RayHitInfo_distance(oStruct)
		position.x = raylib_get_RayHitInfo_position_x(oStruct)
		position.y = raylib_get_RayHitInfo_position_y(oStruct)
		position.z = raylib_get_RayHitInfo_position_z(oStruct)
		normal.x = raylib_get_RayHitInfo_normal_x(oStruct)
		normal.y = raylib_get_RayHitInfo_normal_y(oStruct)
		normal.z = raylib_get_RayHitInfo_normal_z(oStruct)

class BoundingBox from RayLibBase

	min	= new Vector3
	max	= new Vector3

	oData = raylib_new_managed_BoundingBox()

	func init p1,p2,p3,p4,p5,p6
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
		oData = oStruct  
		min.x = raylib_get_BoundingBox_min_x(oStruct)
		min.y = raylib_get_BoundingBox_min_y(oStruct)
		min.z = raylib_get_BoundingBox_min_z(oStruct)
		max.x = raylib_get_BoundingBox_max_x(oStruct)
		max.y = raylib_get_BoundingBox_max_y(oStruct)
		max.z = raylib_get_BoundingBox_max_z(oStruct)

class Wave from RayLibBase

	sampleCount sampleRate sampleSize channels data

	oData = raylib_new_managed_Wave()

	func init p1,p2,p3,p4,p5

		sampleCount=p1 sampleRate=p2 sampleSize=p3 channels=p4 data=p5

	func data 
		raylib_set_Wave_sampleCount(oData,sampleCount)
		raylib_set_Wave_sampleRate(oData,sampleRate)
		raylib_set_Wave_sampleSize(oData,sampleSize)
		raylib_set_Wave_Channels(oData,Channels)
		raylib_set_Wave_Data(oData,Data)
		return oData

	func setdata oStruct 
		oData = oStruct  
		sampleCount	= raylib_get_Wave_sampleCount(oStruct)
		sampleRate	= raylib_get_Wave_sampleRate(oStruct)
		sampleSize	= raylib_get_Wave_sampleSize(oStruct)
		Channels	= raylib_get_Wave_Channels(oStruct)
		Data		= raylib_get_Wave_Data(oStruct)

class Sound from RayLibBase

	audioBuffer source buffer format

	oData = raylib_new_managed_Sound()

	func init p1,p2,p3,p4
		audioBuffer=p1 source=p2 buffer=p3 format=p4

	func data 
		raylib_set_Sound_audioBuffer(oData,audioBuffer)
		raylib_set_Sound_source(oData,source)
		raylib_set_Sound_buffer(oData,buffer)
		raylib_set_Sound_format(oData,format)
		return oData	

	func setdata oStruct 
		oData = oStruct  
		audioBuffer	= raylib_get_Sound_AudioBuffer(oStruct)
		source		= raylib_get_Sound_Source(oStruct)
		buffer		= raylib_get_Sound_Buffer(oStruct)
		format		= raylib_get_Sound_Format(oStruct)

class Music 

	oData
	
	func init 

	func data 
		return oData 

	func setdata oStruct 
		oData = oStruct  
	

class AudioStream from RayLibBase

	sampleRate sampleSize channels audioBuffer format source

	oData = raylib_new_managed_AudioStream()

	func init p1,p2,p3,p4,p5,p6
		sampleRate=p1 sampleSize=p2 channels=p3 audioBuffer=p4 format=p5 source=p6

	func data 
		raylib_set_AudioStream_sampleRate(oData,sampleRate)
		raylib_set_AudioStream_sampleSize(oData,sampleSize)
		raylib_set_AudioStream_channels(oData,channels)
		raylib_set_AudioStream_audioBuffer(oData,audioBuffer)
		raylib_set_AudioStream_format(oData,format)
		raylib_set_AudioStream_source(oData,source)
		return oData	

	func setdata oStruct 
		oData = oStruct  
		sampleRate 	= raylib_get_AudioStream_sampleRate(oStruct)
		sampleSize 	= raylib_get_AudioStream_sampleSize(oStruct)
		channels 	= raylib_get_AudioStream_channels(oStruct)
		audioBuffer 	= raylib_get_AudioStream_audioBuffer(oStruct)
		format 		= raylib_get_AudioStream_format(oStruct)
		source 		= raylib_get_AudioStream_source(oStruct)

class VrDeviceInfo  from RayLibBase

	hResolution vResolution hScreenSize vScreenSize vScreenCenter 
	eyeToScreenDistance lensSeparationDistance interpupillaryDistance

	oData = raylib_new_managed_VrDeviceInfo()

	func init p1,p2,p3,p4,p5,p6,p7,p8
		hResolution=p1 vResolution=p2 hScreenSize=p3 vScreenSize=p4 vScreenCenter=p5 
		eyeToScreenDistance=p6 lensSeparationDistance=p7 interpupillaryDistance=p8

	func data 
		raylib_set_VrDeviceInfo_hResolution(oData,hResolution)
		raylib_set_VrDeviceInfo_vResolution(oData,vResolution)
		raylib_set_VrDeviceInfo_hScreenSize(oData,hScreenSize)
		raylib_set_VrDeviceInfo_vScreenSize(oData,vScreenSize)
		raylib_set_VrDeviceInfo_vScreenCenter(oData,vScreenCenter)
		raylib_set_VrDeviceInfo_eyeToScreenDistance(oData,eyeToScreenDistance)
		raylib_set_VrDeviceInfo_lensSeparationDistance(oData,lensSeparationDistance)
		raylib_set_VrDeviceInfo_interpupillaryDistance(oData,interpupillaryDistance)
		return oData	

	func setdata oStruct 
		oData = oStruct  
		hResolution = raylib_get_VrDeviceInfo_hResolution(oStruct)
		vResolution = raylib_get_VrDeviceInfo_vResolution(oStruct)
		hScreenSize = raylib_get_VrDeviceInfo_hScreenSize(oStruct)
		vScreenSize = raylib_get_VrDeviceInfo_vScreenSize(oStruct)
		vScreenCenter = raylib_get_VrDeviceInfo_vScreenCenter(oStruct)
		eyeToScreenDistance = raylib_get_VrDeviceInfo_eyeToScreenDistance(oStruct)
		lensSeparationDistance = raylib_get_VrDeviceInfo_lensSeparationDistance(oStruct)
		interpupillaryDistance = raylib_get_VrDeviceInfo_interpupillaryDistance(oStruct)
