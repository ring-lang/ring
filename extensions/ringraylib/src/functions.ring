func RayLibColor r,b,g,a
	return GetColor( Bytes2Int(  Char(a) + Char(g) + Char(b) + Char(r) ) )

func Vector2 x,y
	oData = raylib_new_managed_vector2()
	raylib_set_vector2_x(oData,x)
	raylib_set_vector2_y(oData,y)
	return oData	

func Vector3 x,y,z
	oData = raylib_new_managed_vector3()
	raylib_set_vector3_x(oData,x)
	raylib_set_vector3_y(oData,y)
	raylib_set_vector3_z(oData,z)
	return oData	

func Vector4 x,y,z,w
	oData = raylib_new_managed_vector4()
	raylib_set_vector4_x(oData,x)
	raylib_set_vector4_y(oData,y)
	raylib_set_vector4_z(oData,z)
	raylib_set_vector4_w(oData,w)
	return oData	

func Quaternion x,y,z,w
	oData = raylib_new_managed_Quaternion()	
	raylib_set_Quaternion_x(oData,x)
	raylib_set_Quaternion_y(oData,y)
	raylib_set_Quaternion_z(oData,z)
	raylib_set_Quaternion_w(oData,w)
	return oData

func Matrix m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15
	oData = raylib_new_managed_Matrix()	
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

func Color r,g,b,a
	oData = raylib_new_managed_Color()	
	raylib_set_Color_r(oData,r)
	raylib_set_Color_g(oData,g)
	raylib_set_Color_b(oData,b)
	raylib_set_Color_a(oData,a)
	return oData

func Rectangle x,y,width,height 
	oData = raylib_new_managed_Rectangle()	
	raylib_set_Rectangle_x(oData,x)
	raylib_set_Rectangle_y(oData,y)
	raylib_set_Rectangle_width(oData,width)
	raylib_set_Rectangle_height(oData,height)
	return oData

func Camera3D p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11 
	oData = raylib_new_managed_Camera3D()	
	raylib_set_Camera3D_position_x(oData,p1)
	raylib_set_Camera3D_position_y(oData,p2)
	raylib_set_Camera3D_position_z(oData,p3)
	raylib_set_Camera3D_target_x(oData,p4)
	raylib_set_Camera3D_target_y(oData,p5)
	raylib_set_Camera3D_target_z(oData,p6)
	raylib_set_Camera3D_up_x(oData,p7)
	raylib_set_Camera3D_up_y(oData,p8)
	raylib_set_Camera3D_up_z(oData,p9)
	raylib_set_Camera3D_fovy(oData,p10)
	raylib_set_Camera3D_type(oData,p11)
	return oData

func isKeyDown vKey
	if isNumber(vKey)
		return isKeyDown_2(vKey)
	but isString(vKey)
		return isKeyDown_2(ASCII(vKey[1]))
	else 
		raise("Bad parameter type - IsKeyDown() function")
	ok

func BeginMode2D camera
	if isObject(camera)
		camera = camera.Data()
	ok
	return BeginMode2D_2(camera)

func BeginMode3D camera
	if isObject(camera)
		camera = camera.Data()
	ok
	return BeginMode3D_2(camera)

func GetMouseRay mousePosition,camera
	if isObject(camera)
		camera = camera.Data()
	ok
	return GetMouseRay_2(mousePosition,camera)

func GetWorldToScreen position,camera
	if isObject(camera)
		camera = camera.Data()
	ok
	return GetWorldToScreen_2(position,camera)

func GetCameraMatrix camera
	if isObject(camera)
		camera = camera.Data()
	ok
	return GetCameraMatrix_2(camera)

func SetCameraMode camera,mode
	if isObject(camera)
		camera = camera.Data()
	ok
	return SetCameraMode_2(camera,mode)

func UpdateCamera camera
	if isObject(camera)
		UpdateCamera_2(camera.Data())
		camera.refresh()
	else
		return UpdateCamera_2(camera)
	ok
	
func DrawBillboard camera,texture,center,size,tint
	if isObject(camera)
		camera = camera.Data()
	ok
	return DrawBillboard_2(camera,texture,center,size,tint)

func DrawBillboardRec camera,texture,sourceRec,center,size,tint
	if isObject(camera)
		camera = camera.Data()
	ok
	return DrawBillboardRec_2(camera,texture,sourceRec,center,size,tint)

func UpdateVrTracking camera
	if isObject(camera)
		camera = camera.Data()
	ok
	return UpdateVrTracking_2(camera)

func DrawPixelV position, color
	if isObject(position)
		position = position.Data()
	ok
	return DrawPixelV_2(position,color)

func DrawLineV startPos, endPos, color
	if isObject(startPos)
		startPos = startPos.Data()
	ok
	if isObject(endPos)
		endPos = endPos.Data()
	ok
	return DrawLineV_2(startPos,endPos,color)

func DrawLineEx startPos, endPos, thick, color
	if isObject(startPos)
		startPos = startPos.Data()
	ok
	if isObject(endPos)
		endPos = endPos.Data()
	ok
	return DrawLineEx_2(startPos,endPos,thick,color)

func DrawLineBezier startPos, endPos, thick, color
	if isObject(startPos)
		startPos = startPos.Data()
	ok
	if isObject(endPos)
		endPos = endPos.Data()
	ok
	return DrawLineBezier_2(startPos, endPos, thick, color)

func DrawLineStrip points, numPoints, color
	return DrawLineStrip_2(points, numPoints, color)

func DrawCircleSector center,radius,startAngle,endAngle,segments,color
	if isObject(center)
		center = center.Data()
	ok
	return DrawCircleSector_2(center,radius,startAngle,endAngle,segments,color)

func DrawCircleSectorLines center,radius,startAngle,endAngle,segments,color
	if isObject(center)
		center = center.Data()
	ok
	return DrawCircleSectorLines_2(center,radius,startAngle,endAngle,segments,color)

func DrawCircleV center, radius, color
	pCenter = center
	if isObject(center)
		pCenter = center.Data()
	ok
	return DrawCircleV_2(pCenter, radius, color)

func DrawRing center, innerRadius, outerRadius, startAngle, endAngle, segments, color
	if isObject(center)
		center = center.Data()
	ok
	return DrawRing_2(center, innerRadius, outerRadius, startAngle, endAngle, segments, color)

func DrawRingLines center, innerRadius, outerRadius, startAngle, endAngle, segments, color
	if isObject(center)
		center = center.Data()
	ok
	return DrawRingLines_2(center, innerRadius, outerRadius, startAngle, endAngle, segments, color)

func DrawRectangleV position, size, color
	if isObject(position)
		position = position.Data()
	ok
	if isObject(size)
		size = size.Data()
	ok
	return DrawRectangleV_2(position, size, color)

func DrawTriangle v1, v2, v3, color
	if isObject(v1)
		v1 = v1.Data()
	ok
	if isObject(v2)
		v2 = v2.Data()
	ok
	if isObject(v3)
		v3 = v3.Data()
	ok
	return DrawTriangle_2(v1, v2, v3, color)

func DrawTriangleLines v1, v2, v3, color
	if isObject(v1)
		v1 = v1.Data()
	ok
	if isObject(v2)
		v2 = v2.Data()
	ok
	if isObject(v3)
		v3 = v3.Data()
	ok
	return DrawTriangleLines_2(v1, v2, v3, color)

func DrawTriangleFan points, numPoints, color
	return DrawTriangleFan_2(points, numPoints, color)

func DrawPoly center, sides, radius, rotation, color
	if isObject(center)
		center = center.Data()
	ok
	return DrawPoly_2(center, sides, radius, rotation, color)

func CheckCollisionCircles center1, radius1, center2, radius2
	if isObject(center1)
		center1 = center1.Data()
	ok
	if isObject(center2)
		center2 = center2.Data()
	ok
	return CheckCollisionCircles_2(center1, radius1, center2, radius2)

func CheckCollisionCircleRec center, radius, rec
	if isObject(center)
		center = center.Data()
	ok
	return CheckCollisionCircleRec_2(center, radius, rec)

func CheckCollisionPointRec point, rec
	if isObject(point)
		point = point.Data()
	ok
	return CheckCollisionPointRec_2(point, rec)

func CheckCollisionPointCircle point, center, radius
	if isObject(point)
		point = point.Data()
	ok
	if isObject(center)
		center = center.Data()
	ok
	return CheckCollisionPointCircle_2(point, center, radius)

func CheckCollisionPointTriangle point, p1, p2, p3
	if isObject(point)
		point = point.Data()
	ok
	if isObject(p1)
		p1 = p1.Data()
	ok
	if isObject(p2)
		p2 = p2.Data()
	ok
	if isObject(p3)
		p3 = p3.Data()
	ok
	return CheckCollisionPointTriangle_2(point, p1, p2, p3)

