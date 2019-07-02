func RayLibColor r,b,g,a
	return GetColor( Bytes2Int(  Char(a) + Char(g) + Char(b) + Char(r) ) )

func Vector2 x,y
	oVector = new Vector2(x,y)
	return oVector

func Vector3 x,y,z
	oVector = new Vector3(x,y,z)
	return oVector

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
	oCamera = new Camera3D(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)
	return oCamera

func isKeyDown vKey
	if isNumber(vKey)
		return isKeyDown_2(vKey)
	but isString(vKey)
		return isKeyDown_2(ASCII(vKey[1]))
	else 
		raise("Bad parameter type - IsKeyDown() function")
	ok

# Get Pointer Data 
func GPData vData 
	# We copy the Object to afunc replacing it when using pData = pData.data()
		pData = vData
	if isObject(pData)
		pData = pData.Data()
	ok
	return pData

func BeginMode2D camera
	return BeginMode2D_2(GPData(Camera))

func BeginMode3D camera
	return BeginMode3D_2(GPData(Camera))

func GetMouseRay mousePosition,camera
	return GetMouseRay_2(mousePosition,GPData(Camera))

func GetWorldToScreen position,camera
	return GetWorldToScreen_2(position,GPData(Camera))

func GetCameraMatrix camera
	return GetCameraMatrix_2(GPData(Camera))

func SetCameraMode camera,mode
	return SetCameraMode_2(GPData(camera),mode)

func UpdateCamera camera
	if isObject(camera)
		UpdateCamera_2(camera.Data())
		camera.refresh()
	else
		return UpdateCamera_2(camera)
	ok
	
func DrawBillboard camera,texture,center,size,tint
	return DrawBillboard_2(GPData(camera),texture,center,size,tint)

func DrawBillboardRec camera,texture,sourceRec,center,size,tint
	return DrawBillboardRec_2(GPData(camera),texture,sourceRec,center,size,tint)

func UpdateVrTracking camera
	return UpdateVrTracking_2(GPData(camera))

func DrawPixelV position, color
	return DrawPixelV_2(GPData(position),color)

func DrawLineV startPos, endPos, color
	return DrawLineV_2(GPData(startPos),GPData(endPos),color)

func DrawLineEx startPos, endPos, thick, color
	return DrawLineEx_2(GPData(startPos),GPData(endPos),thick,color)

func DrawLineBezier startPos, endPos, thick, color
	return DrawLineBezier_2(GPData(startPos), GPData(endPos), thick, color)

func DrawLineStrip points, numPoints, color
	return DrawLineStrip_2(points, numPoints, color)

func DrawCircleSector center,radius,startAngle,endAngle,segments,color
	return DrawCircleSector_2(GPData(center),radius,startAngle,endAngle,segments,color)

func DrawCircleSectorLines center,radius,startAngle,endAngle,segments,color
	return DrawCircleSectorLines_2(GPData(center),radius,startAngle,endAngle,segments,color)

func DrawCircleV center, radius, color
	return DrawCircleV_2(GPData(Center), radius, color)

func DrawRing center, innerRadius, outerRadius, startAngle, endAngle, segments, color
	return DrawRing_2(GPData(center), innerRadius, outerRadius, startAngle, endAngle, segments, color)

func DrawRingLines center, innerRadius, outerRadius, startAngle, endAngle, segments, color
	return DrawRingLines_2(GPData(center), innerRadius, outerRadius, startAngle, endAngle, segments, color)

func DrawRectangleV position, size, color
	return DrawRectangleV_2(GPData(position), GPData(size), color)

func DrawTriangle v1, v2, v3, color
	return DrawTriangle_2(GPData(v1), GPData(v2), GPData(v3), color)

func DrawTriangleLines v1, v2, v3, color
	return DrawTriangleLines_2(GPData(v1), GPData(v2), GPData(v3), color)

func DrawTriangleFan points, numPoints, color
	return DrawTriangleFan_2(points, numPoints, color)

func DrawPoly center, sides, radius, rotation, color
	return DrawPoly_2(GPData(center), sides, radius, rotation, color)

func CheckCollisionCircles center1, radius1, center2, radius2
	return CheckCollisionCircles_2(GPData(center1), radius1, GPData(center2), radius2)

func CheckCollisionCircleRec center, radius, rec
	return CheckCollisionCircleRec_2(GPData(center), radius, rec)

func CheckCollisionPointRec point, rec
	return CheckCollisionPointRec_2(GPData(point), rec)

func CheckCollisionPointCircle point, center, radius
	return CheckCollisionPointCircle_2(GPData(point), GPData(center), radius)

func CheckCollisionPointTriangle point, p1, p2, p3
	return CheckCollisionPointTriangle_2(GPData(point), GPData(p1), GPData(p2), GPData(p3))

func ColorFromHSV hsv
	return ColorFromHSV_2(GPData(hsv))

func DrawLine3D startPos, endPos, color
	return DrawLine3D_2(GPData(startPos), GPData(endPos), color)

func DrawCircle3D center, radius, rotationAxis, rotationAngle, color
	return DrawCircle3D_2(GPData(center),radius, GPData(rotationAxis), rotationAngle, color)

func DrawCube position, width,  height, length, color
	return DrawCube_2(GPData(position), width,  height, length, color)

func DrawCubeV position, size, color
	return DrawCubeV_2(GPData(position), GPData(size), color)

func DrawCubeWires position, width, height, length, color
	return DrawCubeWires_2(GPData(position), width, height, length, color)

func DrawCubeWiresV position, size, color
	return DrawCubeWiresV_2(GPData(position), GPData(size), color)

func DrawSphere centerPos, radius, color
	return DrawSphere_2(GPData(centerPos), radius, color)

func DrawSphereEx centerPos, radius, rings, slices, color
	return DrawSphereEx_2(GPData(centerPos), radius, rings, slices, color)

func DrawSphereWires centerPos, radius, rings, slices, color
	return DrawSphereWires_2(GPData(centerPos), radius, rings, slices, color)

func DrawCylinder position, radiusTop, radiusBottom, height,  slices, color
	return DrawCylinder_2(GPData(position), radiusTop, radiusBottom, height,  slices, color)

func DrawCylinderWires position, radiusTop, radiusBottom, height, slices, color
	return DrawCylinderWires_2(GPData(position), radiusTop, radiusBottom, height, slices, color)

func DrawPlane centerPos, size, color
	return DrawPlane_2(GPData(centerPos), GPData(size), color)

func DrawGizmo position
	return DrawGizmo_2(GPData(position))

func GenMeshHeightmap heightmap, size
	return GenMeshHeightmap_2(heightmap, GPData(size))

func GenMeshCubicmap cubicmap, cubeSize
	return GenMeshCubicmap_2(cubicmap, GPData(cubeSize))

func DrawModel model,  position, scale,  tint
	return DrawModel_2(model, GPData(position), scale,  tint)

func DrawModelEx model,  position, rotationAxis,  rotationAngle, scale,  tint
	return DrawModelEx_2(model,  GPData(position), GPData(rotationAxis),  rotationAngle, GPData(scale),  tint)

func DrawModelWires model, position, scale, tint
	return DrawModelWires_2(model, GPData(position), scale, tint)

func DrawModelWiresEx model,  position, rotationAxis,  rotationAngle, scale,  tint
	return DrawModelWiresEx_2(model,  GPData(position), GPData(rotationAxis),  rotationAngle, GPData(scale),  tint)

func CheckCollisionSpheres centerA,  radiusA, centerB,  radiusB
	return CheckCollisionSpheres_2(GPData(centerA),  radiusA, GPData(centerB),  radiusB)

func CheckCollisionBoxSphere box,  centerSphere,  radiusSphere
	return CheckCollisionBoxSphere_2(box, GPData(centerSphere),  radiusSphere)

func CheckCollisionRaySphere ray,  spherePosition,  sphereRadius
	return CheckCollisionRaySphere_2(ray,  GPData(spherePosition),  sphereRadius)

func CheckCollisionRaySphereEx ray, spherePosition, sphereRadius, collisionPoint
	return CheckCollisionRaySphereEx_2(ray, GPData(spherePosition), sphereRadius, GPData(collisionPoint))

func GetCollisionRayTriangle ray, p1, p2, p3
	return GetCollisionRayTriangle_2(ray, GPData(p1), GPData(p2), GPData(p3))

